#include "vm.h"
#include "kernel.h"
#include "utility.h"
#include <iostream>

namespace anl
{
    CNoiseExecutor::CNoiseExecutor(CKernel *kernel) : kernel_(kernel->getKernel()), evaluated_(kernel->getKernel()->size(), false), coordcache_(kernel->getKernel()->size()), cache_(kernel->getKernel()->size())
    {
    }

    SVMOutput CNoiseExecutor::evaluate(CCoordinate &coord)
    {
        SVMOutput out;
        if(!kernel_) {std::cout<<"duh"<<std::endl;return out;}
        if(kernel_->size()==0) {std::cout<<"ruh roh"<<std::endl;return out;}

        // Clear evaluated
        //for(bool& e : evaluated_) e=false;
        for(auto i=evaluated_.begin(); i!=evaluated_.end(); ++i) *i=false;

        // Evaluate the last one to start the chain
        evaluateInstruction(*kernel_, evaluated_, coordcache_, cache_, kernel_->size()-1, coord);
        //out.outfloat_=kernel[kernel.size()-1].outfloat_;
        //return out;
        return cache_[kernel_->size()-1];
    }

    SVMOutput CNoiseExecutor::evaluateAt(CCoordinate &coord, CInstructionIndex index)
    {
        SVMOutput out;
        if(!kernel_) {std::cout<<"duh"<<std::endl;return out;}
        if(kernel_->size()==0) {std::cout<<"ruh roh"<<std::endl;return out;}
        if(index.index_>=kernel_->size()) return out;

        // Clear evaluated
        //for(bool& e : evaluated_) e=false;
        for(auto i=evaluated_.begin(); i!=evaluated_.end(); ++i) *i=false;

        // Evaluate the instruction at the specified index
        evaluateInstruction(*kernel_, evaluated_, coordcache_, cache_, index.index_, coord);
        //out.outfloat_=kernel[kernel.size()-1].outfloat_;
        //return out;
        return cache_[index.index_];
    }

    double CNoiseExecutor::evaluateParameter(InstructionListType &kernel, EvaluatedType &evaluated, CoordCacheType &coordcache, CacheType &cache, unsigned int index, CCoordinate &coord)
    {
        if(index>=kernel.size()) return 0;

        evaluateInstruction(kernel, evaluated, coordcache, cache, index, coord);
        //return kernel[index].outfloat_;
        return cache[index].outfloat_;
    }

	SRGBA CNoiseExecutor::evaluateRGBA(InstructionListType &kernel, EvaluatedType &evaluated, CoordCacheType &coordcache, CacheType &cache, unsigned int index, CCoordinate &coord)
    {
        if(index>=kernel.size()) return 0;

        evaluateInstruction(kernel, evaluated, coordcache, cache, index, coord);
        //return kernel[index].outfloat_;
        return cache[index].outrgba_;
    }

    void CNoiseExecutor::evaluateInstruction(InstructionListType &kernel, EvaluatedType &evaluated, CoordCacheType &coordcache, CacheType &cache, unsigned int index, CCoordinate &coord)
    {
        if(index>=kernel.size()) return;
        SInstruction &i=kernel[index];

        if(evaluated[index]==true && coordcache[index]==coord) return;

		coordcache[index]=coord;

        switch(i.opcode_)
        {
            case OP_NOP:
            case OP_Constant: evaluated[index]=true; cache[index].set(i.outfloat_); return; break;

            case OP_ValueBasis:
                {
                // Parameters
                // 0=Interpolation
                int interp=(int)evaluateParameter(kernel,evaluated,coordcache,cache,i.sources_[0],coord);
                switch(coord.dimension_)
                {
                case 2:
                    switch(interp)
                    {
                        case 0: cache[index].set(value_noise2D(coord.x_,coord.y_,i.seed_,noInterp)); break;
                        case 1: cache[index].set(value_noise2D(coord.x_,coord.y_,i.seed_,linearInterp)); break;
                        case 2: cache[index].set(value_noise2D(coord.x_,coord.y_,i.seed_,hermiteInterp)); break;
                        default: cache[index].set(value_noise2D(coord.x_,coord.y_,i.seed_,quinticInterp)); break;
                    }; break;
                case 3:
                    switch(interp)
                    {
                        case 0: cache[index].set(value_noise3D(coord.x_,coord.y_,coord.z_,i.seed_,noInterp)); break;
                        case 1: cache[index].set(value_noise3D(coord.x_,coord.y_,coord.z_,i.seed_,linearInterp)); break;
                        case 2: cache[index].set(value_noise3D(coord.x_,coord.y_,coord.z_,i.seed_,hermiteInterp)); break;
                        default: cache[index].set(value_noise3D(coord.x_,coord.y_,coord.z_,i.seed_,quinticInterp)); break;
                    }; break;
                case 4:
                    switch(interp)
                    {
                        case 0: cache[index].set(value_noise4D(coord.x_,coord.y_,coord.z_,coord.w_,i.seed_,noInterp)); break;
                        case 1: cache[index].set(value_noise4D(coord.x_,coord.y_,coord.z_,coord.w_,i.seed_,linearInterp)); break;
                        case 2: cache[index].set(value_noise4D(coord.x_,coord.y_,coord.z_,coord.w_,i.seed_,hermiteInterp)); break;
                        default: cache[index].set(value_noise4D(coord.x_,coord.y_,coord.z_,coord.w_,i.seed_,quinticInterp)); break;
                    }; break;
                default:
                    switch(interp)
                    {
                        case 0: cache[index].set(value_noise6D(coord.x_,coord.y_,coord.z_,coord.w_,coord.u_,coord.v_,i.seed_,noInterp)); break;
                        case 1: cache[index].set(value_noise6D(coord.x_,coord.y_,coord.z_,coord.w_,coord.u_,coord.v_,i.seed_,linearInterp)); break;
                        case 2: cache[index].set(value_noise6D(coord.x_,coord.y_,coord.z_,coord.w_,coord.u_,coord.v_,i.seed_,hermiteInterp)); break;
                        default: cache[index].set(value_noise6D(coord.x_,coord.y_,coord.z_,coord.w_,coord.u_,coord.v_,i.seed_,quinticInterp)); break;
                    }; break;
                }

                evaluated[index]=true;
                return;
                break;
                }
            case OP_GradientBasis:
                {
                // Parameters
                // 0=Interpolation
                int interp=(int)evaluateParameter(kernel,evaluated,coordcache,cache,i.sources_[0],coord);
                switch(coord.dimension_)
                {
                case 2:
                    switch(interp)
                    {
                        case 0: cache[index].set(gradient_noise2D(coord.x_,coord.y_,i.seed_,noInterp)); break;
                        case 1: cache[index].set(gradient_noise2D(coord.x_,coord.y_,i.seed_,linearInterp)); break;
                        case 2: cache[index].set(gradient_noise2D(coord.x_,coord.y_,i.seed_,hermiteInterp)); break;
                        default: cache[index].set(gradient_noise2D(coord.x_,coord.y_,i.seed_,quinticInterp)); break;
                    }; break;
                case 3:
                    //std::cout << "(" << coord.x_ << "," << coord.y_ << "," << coord.z_ << std::endl;
                    switch(interp)
                    {
                        case 0: cache[index].set(gradient_noise3D(coord.x_,coord.y_,coord.z_,i.seed_,noInterp)); break;
                        case 1: cache[index].set(gradient_noise3D(coord.x_,coord.y_,coord.z_,i.seed_,linearInterp)); break;
                        case 2: cache[index].set(gradient_noise3D(coord.x_,coord.y_,coord.z_,i.seed_,hermiteInterp)); break;
                        default: cache[index].set(gradient_noise3D(coord.x_,coord.y_,coord.z_,i.seed_,quinticInterp)); break;
                    }; break;
                case 4:
                    switch(interp)
                    {
                        case 0: cache[index].set(gradient_noise4D(coord.x_,coord.y_,coord.z_,coord.w_,i.seed_,noInterp)); break;
                        case 1: cache[index].set(gradient_noise4D(coord.x_,coord.y_,coord.z_,coord.w_,i.seed_,linearInterp)); break;
                        case 2: cache[index].set(gradient_noise4D(coord.x_,coord.y_,coord.z_,coord.w_,i.seed_,hermiteInterp)); break;
                        default: cache[index].set(gradient_noise4D(coord.x_,coord.y_,coord.z_,coord.w_,i.seed_,quinticInterp)); break;
                    }; break;
                default:
                    switch(interp)
                    {
                        case 0: cache[index].set(gradient_noise6D(coord.x_,coord.y_,coord.z_,coord.w_,coord.u_,coord.v_,i.seed_,noInterp)); break;
                        case 1: cache[index].set(gradient_noise6D(coord.x_,coord.y_,coord.z_,coord.w_,coord.u_,coord.v_,i.seed_,linearInterp)); break;
                        case 2: cache[index].set(gradient_noise6D(coord.x_,coord.y_,coord.z_,coord.w_,coord.u_,coord.v_,i.seed_,hermiteInterp)); break;
                        default: cache[index].set(gradient_noise6D(coord.x_,coord.y_,coord.z_,coord.w_,coord.u_,coord.v_,i.seed_,quinticInterp)); break;
                    }; break;
                }
                evaluated[index]=true;
                return;
                break;
                }
            case OP_SimplexBasis:
                {
                // Parameters

                // Simplex noise isn't interpolated, so interp does nothing
                switch(coord.dimension_)
                {
                case 2: cache[index].set(simplex_noise2D(coord.x_,coord.y_,i.seed_,noInterp)); break;
                case 3: cache[index].set(simplex_noise3D(coord.x_,coord.y_,coord.z_,i.seed_,noInterp)); break;
                case 4: cache[index].set(simplex_noise4D(coord.x_,coord.y_,coord.z_,coord.w_,i.seed_,noInterp)); break;
                default: cache[index].set(simplex_noise6D(coord.x_,coord.y_,coord.z_,coord.w_,coord.u_,coord.v_,i.seed_,noInterp)); break;
                };
                evaluated[index]=true;
                return;
                break;
                }
            case OP_CellularBasis:
                {
                    unsigned int dist=(unsigned int)evaluateParameter(kernel,evaluated,coordcache,cache,i.sources_[0],coord);
                    double f1=evaluateParameter(kernel,evaluated,coordcache,cache,i.sources_[1],coord);
                    double f2=evaluateParameter(kernel,evaluated,coordcache,cache,i.sources_[2],coord);
                    double f3=evaluateParameter(kernel,evaluated,coordcache,cache,i.sources_[3],coord);
                    double f4=evaluateParameter(kernel,evaluated,coordcache,cache,i.sources_[4],coord);
                    double d1=evaluateParameter(kernel,evaluated,coordcache,cache,i.sources_[5],coord);
                    double d2=evaluateParameter(kernel,evaluated,coordcache,cache,i.sources_[6],coord);
                    double d3=evaluateParameter(kernel,evaluated,coordcache,cache,i.sources_[7],coord);
                    double d4=evaluateParameter(kernel,evaluated,coordcache,cache,i.sources_[8],coord);
                    double f[4], d[4];
                    switch(coord.dimension_)
                    {
                    case 2:
                        switch(dist)
                        {
                        case 0: cellular_function2D(coord.x_, coord.y_, i.seed_, f, d, distEuclid2); break;
                        case 1: cellular_function2D(coord.x_, coord.y_, i.seed_, f, d, distManhattan2); break;
                        case 2: cellular_function2D(coord.x_, coord.y_, i.seed_, f, d, distGreatestAxis2); break;
                        case 3: cellular_function2D(coord.x_, coord.y_, i.seed_, f, d, distLeastAxis2); break;
                        default: cellular_function2D(coord.x_, coord.y_, i.seed_, f, d, distEuclid2); break;
                        }; break;
                    case 3:
                        switch(dist)
                        {
                        case 0: cellular_function3D(coord.x_, coord.y_, coord.z_, i.seed_, f, d, distEuclid3); break;
                        case 1: cellular_function3D(coord.x_, coord.y_, coord.z_, i.seed_, f, d, distManhattan3); break;
                        case 2: cellular_function3D(coord.x_, coord.y_, coord.z_, i.seed_, f, d, distGreatestAxis3); break;
                        case 3: cellular_function3D(coord.x_, coord.y_, coord.z_, i.seed_, f, d, distLeastAxis3); break;
                        default: cellular_function3D(coord.x_, coord.y_, coord.z_, i.seed_, f, d, distEuclid3); break;
                        }; break;
                    case 4:
                        switch(dist)
                        {
                        case 0: cellular_function4D(coord.x_, coord.y_, coord.z_, coord.w_, i.seed_, f, d, distEuclid4); break;
                        case 1: cellular_function4D(coord.x_, coord.y_, coord.z_, coord.w_, i.seed_, f, d, distManhattan4); break;
                        case 2: cellular_function4D(coord.x_, coord.y_, coord.z_, coord.w_, i.seed_, f, d, distGreatestAxis4); break;
                        case 3: cellular_function4D(coord.x_, coord.y_, coord.z_, coord.w_, i.seed_, f, d, distLeastAxis4); break;
                        default: cellular_function4D(coord.x_, coord.y_, coord.z_, coord.w_, i.seed_, f, d, distEuclid4); break;
                        }; break;
                    default:
                        switch(dist)
                        {
                        case 0: cellular_function6D(coord.x_, coord.y_, coord.z_, coord.w_, coord.u_, coord.v_, i.seed_, f, d, distEuclid6); break;
                        case 1: cellular_function6D(coord.x_, coord.y_, coord.z_, coord.w_, coord.u_, coord.v_, i.seed_, f, d, distManhattan6); break;
                        case 2: cellular_function6D(coord.x_, coord.y_, coord.z_, coord.w_, coord.u_, coord.v_, i.seed_, f, d, distGreatestAxis6); break;
                        case 3: cellular_function6D(coord.x_, coord.y_, coord.z_, coord.w_, coord.u_, coord.v_, i.seed_, f, d, distLeastAxis6); break;
                        default: cellular_function6D(coord.x_, coord.y_, coord.z_, coord.w_, coord.u_, coord.v_, i.seed_, f, d, distEuclid6); break;
                        }; break;
                    };

                    cache[index].set(f1*f[0]+f2*f[1]+f3*f[2]+f4*f[3]+d1*d[0]+d2*d[1]+d3*d[2]+d4*d[3]);
                    return;
                    break;
                }
            case OP_Add:
                {
                    double s1=evaluateParameter(kernel,evaluated,coordcache,cache,i.sources_[0],coord);
                    double s2=evaluateParameter(kernel,evaluated,coordcache,cache,i.sources_[1],coord);
                    cache[index].set(s1+s2);
                    evaluated[index]=true;
                    return;
                    break;
                }
            case OP_Subtract:
                {
                    double s1=evaluateParameter(kernel,evaluated,coordcache,cache,i.sources_[0],coord);
                    double s2=evaluateParameter(kernel,evaluated,coordcache,cache,i.sources_[1],coord);
                    cache[index].set(s1-s2);
                    evaluated[index]=true;
                    return;
                } break;
            case OP_Multiply:
                {
                    double s1=evaluateParameter(kernel,evaluated,coordcache,cache,i.sources_[0],coord);
                    double s2=evaluateParameter(kernel,evaluated,coordcache,cache,i.sources_[1],coord);
                    cache[index].set(s1*s2);
                    evaluated[index]=true;
                    return;
                    break;
                }
            case OP_Divide:
                {
                    double s1=evaluateParameter(kernel,evaluated,coordcache,cache,i.sources_[0],coord);
                    double s2=evaluateParameter(kernel,evaluated,coordcache,cache,i.sources_[1],coord);
                    cache[index].set(s1/s2);
                    evaluated[index]=true;
                    return;
                    break;
                } break;
			case OP_Bias:
				{
					double s1=evaluateParameter(kernel,evaluated,coordcache,cache,i.sources_[0],coord);
                    double s2=evaluateParameter(kernel,evaluated,coordcache,cache,i.sources_[1],coord);
                    cache[index].set(bias(s1,s2));
                    evaluated[index]=true;
                    return;
                    break;
				} break;
			case OP_Gain:
				{
					double s1=evaluateParameter(kernel,evaluated,coordcache,cache,i.sources_[0],coord);
                    double s2=evaluateParameter(kernel,evaluated,coordcache,cache,i.sources_[1],coord);
                    cache[index].set(gain(s1,s2));
                    evaluated[index]=true;
                    return;
                    break;
				} break;
            case OP_Max:
                {
                    double s1=evaluateParameter(kernel,evaluated,coordcache,cache,i.sources_[0],coord);
                    double s2=evaluateParameter(kernel,evaluated,coordcache,cache,i.sources_[1],coord);
                    cache[index].set(std::max(s1,s2));
                    evaluated[index]=true;
                    return;
                    break;
                }
            case OP_Min:
                {
                    double s1=evaluateParameter(kernel,evaluated,coordcache,cache,i.sources_[0],coord);
                    double s2=evaluateParameter(kernel,evaluated,coordcache,cache,i.sources_[1],coord);
                    cache[index].set(std::min(s1,s2));
                    evaluated[index]=true;
                    return;
                    break;
                }
            case OP_Abs:
                {
                    double s1=evaluateParameter(kernel,evaluated,coordcache,cache,i.sources_[0],coord);
                    cache[index].set(std::abs(s1));
                    evaluated[index]=true;
                    return;
                    break;
                }
            case OP_Pow:
                {
                    double s1=evaluateParameter(kernel,evaluated,coordcache,cache,i.sources_[0],coord);
                    double s2=evaluateParameter(kernel,evaluated,coordcache,cache,i.sources_[1],coord);
                    evaluated[index]=true;
                    cache[index].set(std::pow(s1,s2));
                    return;
                    break;
                }
            case OP_Cos:
                {
                    double s1=evaluateParameter(kernel,evaluated,coordcache,cache,i.sources_[0],coord);
                    evaluated[index]=true;
                    cache[index].set(std::cos(s1));
                    return;
                } break;
            case OP_Sin:
                {
                    double s1=evaluateParameter(kernel,evaluated,coordcache,cache,i.sources_[0],coord);
                    evaluated[index]=true;
                    cache[index].set(std::sin(s1));
                    return;
                } break;
            case OP_Tan:
                {
                    double s1=evaluateParameter(kernel,evaluated,coordcache,cache,i.sources_[0],coord);
                    evaluated[index]=true;
                    cache[index].set(std::tan(s1));
                    return;
                } break;
            case OP_ACos:
                {
                    double s1=evaluateParameter(kernel,evaluated,coordcache,cache,i.sources_[0],coord);
                    evaluated[index]=true;
                    cache[index].set(std::acos(s1));
                    return;
                } break;
            case OP_ASin:
                {
                    double s1=evaluateParameter(kernel,evaluated,coordcache,cache,i.sources_[0],coord);
                    evaluated[index]=true;
                    cache[index].set(std::asin(s1));
                    return;
                } break;
            case OP_ATan:
                {
                    double s1=evaluateParameter(kernel,evaluated,coordcache,cache,i.sources_[0],coord);
                    evaluated[index]=true;
                    cache[index].set(std::atan(s1));
                    return;
                } break;
			case OP_Tiers:
				{
					int numsteps=(int)evaluateParameter(kernel,evaluated,coordcache,cache,i.sources_[1],coord);
					double val=evaluateParameter(kernel,evaluated,coordcache,cache,i.sources_[0],coord);
					double Tb=std::floor(val*(double)numsteps);
					evaluated[index]=true;
                    cache[index].set(Tb);
				} break;
			case OP_SmoothTiers:
				{
					int numsteps=(int)evaluateParameter(kernel,evaluated,coordcache,cache,i.sources_[1],coord)-1;
					double val=evaluateParameter(kernel,evaluated,coordcache,cache,i.sources_[0],coord);
					double Tb=std::floor(val*(double)numsteps);
					double Tt=Tb+1.0;
					double t=quintic_blend(val*(double)numsteps-Tb);
					Tb/=(double)numsteps;
					Tt/=(double)numsteps;
					evaluated[index]=true;
                    cache[index].set(Tb+t*(Tt-Tb));
				} break;
            case OP_ScaleDomain:
                {
                    CCoordinate scale(1,1,1,1,1,1);
                    switch(coord.dimension_)
                    {
                    case 2:
                        {
                        double sx=evaluateParameter(kernel, evaluated, coordcache,cache,i.sources_[1],coord);
                        double sy=evaluateParameter(kernel, evaluated, coordcache,cache,i.sources_[2],coord);
                        scale.set(sx,sy);
                        break;
                        }
                    case 3:
                        {
                        double sx=evaluateParameter(kernel, evaluated, coordcache,cache,i.sources_[1],coord);
                        double sy=evaluateParameter(kernel, evaluated, coordcache,cache, i.sources_[2],coord);
                        double sz=evaluateParameter(kernel, evaluated, coordcache,cache, i.sources_[3],coord);
                        scale.set(sx,sy,sz);
                        break;
                        }
                    case 4:
                        {
                        double sx=evaluateParameter(kernel, evaluated, coordcache,cache,i.sources_[1],coord);
                        double sy=evaluateParameter(kernel, evaluated, coordcache,cache, i.sources_[2],coord);
                        double sz=evaluateParameter(kernel, evaluated, coordcache,cache, i.sources_[3],coord);
                        double sw=evaluateParameter(kernel, evaluated, coordcache,cache, i.sources_[4],coord);
                        scale.set(sx,sy,sz,sw);
                        break;
                        }
                    default:
                        {
                        double sx=evaluateParameter(kernel, evaluated, coordcache,cache,i.sources_[1],coord);
                        double sy=evaluateParameter(kernel, evaluated, coordcache,cache, i.sources_[2],coord);
                        double sz=evaluateParameter(kernel, evaluated, coordcache,cache, i.sources_[3],coord);
                        double sw=evaluateParameter(kernel, evaluated, coordcache, cache,i.sources_[4],coord);
                        double su=evaluateParameter(kernel, evaluated, coordcache,cache, i.sources_[5],coord);
                        double sv=evaluateParameter(kernel, evaluated, coordcache,cache, i.sources_[6],coord);
                        scale.set(sx,sy,sz,sw,su,sv);
                        break;
                        }
                    };

                    CCoordinate c=coord*scale;
                    cache[index].set(evaluateParameter(kernel, evaluated, coordcache,cache, i.sources_[0], c));
                    evaluated[index]=true;
                    return;
                    break;
                }
            case OP_ScaleX:
            {
                double s=evaluateParameter(kernel, evaluated, coordcache, cache,i.sources_[1], coord);
                CCoordinate scale(s,1,1,1,1,1);
                CCoordinate c=coord*scale;
                cache[index].set(evaluateParameter(kernel, evaluated, coordcache, cache,i.sources_[0], c));
                evaluated[index]=true;
                return;
            } break;

            case OP_ScaleY:
            {
                double s=evaluateParameter(kernel, evaluated, coordcache, cache,i.sources_[1], coord);
                CCoordinate scale(1,s,1,1,1,1);
                CCoordinate c=coord*scale;
                cache[index].set(evaluateParameter(kernel, evaluated, coordcache,cache, i.sources_[0], c));
                evaluated[index]=true;
                return;
            } break;

            case OP_ScaleZ:
            {
                double s=evaluateParameter(kernel, evaluated, coordcache,cache, i.sources_[1], coord);
                CCoordinate scale(1,1,s,1,1,1);
                CCoordinate c=coord*scale;
                cache[index].set(evaluateParameter(kernel, evaluated, coordcache, cache,i.sources_[0], c));
                evaluated[index]=true;
                return;
            } break;

            case OP_ScaleW:
            {
                double s=evaluateParameter(kernel, evaluated, coordcache, cache,i.sources_[1], coord);
                CCoordinate scale(1,1,1,s,1,1);
                CCoordinate c=coord*scale;
                cache[index].set(evaluateParameter(kernel, evaluated, coordcache,cache, i.sources_[0], c));
                evaluated[index]=true;
                return;
            } break;

            case OP_ScaleU:
            {
                double s=evaluateParameter(kernel, evaluated, coordcache,cache, i.sources_[1], coord);
                CCoordinate scale(1,1,1,1,s,1);
                CCoordinate c=coord*scale;
                cache[index].set(evaluateParameter(kernel, evaluated, coordcache,cache, i.sources_[0], c));
                evaluated[index]=true;
                return;
            } break;

            case OP_ScaleV:
            {
                double s=evaluateParameter(kernel, evaluated, coordcache,cache, i.sources_[1], coord);
                CCoordinate scale(1,1,1,1,1,s);
                CCoordinate c=coord*scale;
                cache[index].set(evaluateParameter(kernel, evaluated, coordcache,cache, i.sources_[0], c));
                evaluated[index]=true;
                return;
            } break;

            case OP_TranslateX:
            {
                double t=evaluateParameter(kernel, evaluated, coordcache, cache,i.sources_[1], coord);
                CCoordinate trans(t,0,0,0,0,0);
                CCoordinate c=coord+trans;
                cache[index].set(evaluateParameter(kernel, evaluated, coordcache,cache, i.sources_[0], c));
                evaluated[index]=true;
                return;
            } break;

            case OP_TranslateY:
            {
                double t=evaluateParameter(kernel, evaluated, coordcache, cache,i.sources_[1], coord);
                CCoordinate trans(0,t,0,0,0,0);
                CCoordinate c=coord+trans;
                cache[index].set(evaluateParameter(kernel, evaluated, coordcache, cache,i.sources_[0], c));
                evaluated[index]=true;
                return;
            } break;

            case OP_TranslateZ:
            {
                double t=evaluateParameter(kernel, evaluated, coordcache, cache,i.sources_[1], coord);
                CCoordinate trans(0,0,t,0,0,0);
                CCoordinate c=coord+trans;
                cache[index].set(evaluateParameter(kernel, evaluated, coordcache, cache,i.sources_[0], c));
                evaluated[index]=true;
                return;
            } break;

            case OP_TranslateW:
            {
                double t=evaluateParameter(kernel, evaluated, coordcache, cache,i.sources_[1], coord);
                CCoordinate trans(0,0,0,t,0,0);
                CCoordinate c=coord+trans;
                cache[index].set(evaluateParameter(kernel, evaluated, coordcache, cache,i.sources_[0], c));
                evaluated[index]=true;
                return;
            } break;

            case OP_TranslateU:
            {
                double t=evaluateParameter(kernel, evaluated, coordcache, cache,i.sources_[1], coord);
                CCoordinate trans(0,0,0,0,t,0);
                CCoordinate c=coord+trans;
                cache[index].set(evaluateParameter(kernel, evaluated, coordcache, cache,i.sources_[0], c));
                evaluated[index]=true;
                return;
            } break;

            case OP_TranslateV:
            {
                double t=evaluateParameter(kernel, evaluated, coordcache, cache,i.sources_[1], coord);
                CCoordinate trans(0,0,0,0,0,t);
                CCoordinate c=coord+trans;
                cache[index].set(evaluateParameter(kernel, evaluated, coordcache, cache,i.sources_[0], c));
                evaluated[index]=true;
                return;
            } break;


            case OP_TranslateDomain:
            {
                    CCoordinate scale(1,1,1,1,1,1);
                    switch(coord.dimension_)
                    {
                    case 2:
                        {
                        double sx=evaluateParameter(kernel, evaluated, coordcache,cache,i.sources_[1],coord);
                        double sy=evaluateParameter(kernel, evaluated, coordcache, cache,i.sources_[2],coord);
                        scale.set(sx,sy);
                        break;
                        }
                    case 3:
                        {
                        double sx=evaluateParameter(kernel, evaluated, coordcache,cache,i.sources_[1],coord);
                        double sy=evaluateParameter(kernel, evaluated, coordcache, cache,i.sources_[2],coord);
                        double sz=evaluateParameter(kernel, evaluated, coordcache, cache,i.sources_[3],coord);
                        scale.set(sx,sy,sz);
                        break;
                        }
                    case 4:
                        {
                        double sx=evaluateParameter(kernel, evaluated, coordcache,cache,i.sources_[1],coord);
                        double sy=evaluateParameter(kernel, evaluated, coordcache, cache,i.sources_[2],coord);
                        double sz=evaluateParameter(kernel, evaluated, coordcache, cache,i.sources_[3],coord);
                        double sw=evaluateParameter(kernel, evaluated, coordcache, cache,i.sources_[4],coord);
                        scale.set(sx,sy,sz,sw);
                        break;
                        }
                    default:
                        {
                        double sx=evaluateParameter(kernel, evaluated, coordcache,cache,i.sources_[1],coord);
                        double sy=evaluateParameter(kernel, evaluated, coordcache, cache,i.sources_[2],coord);
                        double sz=evaluateParameter(kernel, evaluated, coordcache, cache,i.sources_[3],coord);
                        double sw=evaluateParameter(kernel, evaluated, coordcache, cache,i.sources_[4],coord);
                        double su=evaluateParameter(kernel, evaluated, coordcache,cache, i.sources_[5],coord);
                        double sv=evaluateParameter(kernel, evaluated, coordcache, cache,i.sources_[6],coord);
                        scale.set(sx,sy,sz,sw,su,sv);
                        break;
                        }
                    };

                    CCoordinate c=coord+scale;
                    cache[index].set(evaluateParameter(kernel, evaluated, coordcache,cache, i.sources_[0], c));
                    evaluated[index]=true;
                    return;
            } break;
            case OP_RotateDomain:
            {
                double angle=evaluateParameter(kernel, evaluated, coordcache, cache, i.sources_[1], coord);
                double ax=evaluateParameter(kernel, evaluated, coordcache, cache, i.sources_[2], coord);
                double ay=evaluateParameter(kernel, evaluated, coordcache, cache, i.sources_[3], coord);
                double az=evaluateParameter(kernel, evaluated, coordcache, cache, i.sources_[4], coord);

                double len=std::sqrt(ax*ax+ax*ay+az*az);
                ax/=len;
                ay/=len;
                az/=len;

                double cosangle=cos(angle);
                double sinangle=sin(angle);

                double rotmatrix[3][3];

                rotmatrix[0][0] = 1.0 + (1.0-cosangle)*(ax*ax-1.0);
                rotmatrix[1][0] = -az*sinangle+(1.0-cosangle)*ax*ay;
                rotmatrix[2][0] = ay*sinangle+(1.0-cosangle)*ax*az;

                rotmatrix[0][1] = az*sinangle+(1.0-cosangle)*ax*ay;
                rotmatrix[1][1] = 1.0 + (1.0-cosangle)*(ay*ay-1.0);
                rotmatrix[2][1] = -ax*sinangle+(1.0-cosangle)*ay*az;

                rotmatrix[0][2] = -ay*sinangle+(1.0-cosangle)*ax*az;
                rotmatrix[1][2] = ax*sinangle+(1.0-cosangle)*ay*az;
                rotmatrix[2][2] = 1.0 + (1.0-cosangle)*(az*az-1.0);

                double nx, ny, nz;
                nx = (rotmatrix[0][0]*coord.x_) + (rotmatrix[1][0]*coord.y_) + (rotmatrix[2][0]*coord.z_);
                ny = (rotmatrix[0][1]*coord.x_) + (rotmatrix[1][1]*coord.y_) + (rotmatrix[2][1]*coord.z_);
                nz = (rotmatrix[0][2]*coord.x_) + (rotmatrix[1][2]*coord.y_) + (rotmatrix[2][2]*coord.z_);
                CCoordinate newcoord=CCoordinate(nx,ny,nz,coord.w_,coord.u_,coord.v_);
                newcoord.dimension_=coord.dimension_;
                cache[index].set(evaluateParameter(kernel, evaluated, coordcache,cache, i.sources_[0], newcoord));
                evaluated[index]=true;
            } break;
            case OP_Blend:
            {
                double low,high,control;
                low=evaluateParameter(kernel, evaluated, coordcache,cache, i.sources_[0], coord);
                high=evaluateParameter(kernel, evaluated, coordcache,cache, i.sources_[1], coord);
                control=evaluateParameter(kernel, evaluated, coordcache,cache, i.sources_[2], coord);
                cache[index].set(low+control*(high-low));
                evaluated[index]=true;
                return;
            } break;
            case OP_Select:
            {
                evaluated[index]=true;
                double low,high,control,threshold,falloff;
                low=evaluateParameter(kernel,evaluated,coordcache,cache,i.sources_[0],coord);
                high=evaluateParameter(kernel,evaluated,coordcache,cache,i.sources_[1],coord);
                control=evaluateParameter(kernel,evaluated,coordcache,cache,i.sources_[2],coord);
                threshold=evaluateParameter(kernel,evaluated,coordcache,cache,i.sources_[3],coord);
                falloff=evaluateParameter(kernel,evaluated,coordcache,cache,i.sources_[4],coord);

                if(falloff>0.0)
                {
                    if(control<(threshold-falloff))
                    {
                        cache[index].set(low);
                    }
                    else if(control>(threshold+falloff))
                    {
                        cache[index].set(high);
                    }
                    else
                    {
                        double lower=threshold-falloff;
                        double upper=threshold+falloff;
                        double blend=quintic_blend((control-lower)/(upper-lower));
                        cache[index].set(lerp(blend,low,high));
                    }
                }
                else
                {
                    if(control<threshold) cache[index].set(low);
                    else cache[index].set(high);
                }
            } break;

            case OP_X:
            {
                cache[index].set(coord.x_);
                evaluated[index]=true;
                return;
            } break;

            case OP_Y:
            {
                cache[index].set(coord.y_);
                evaluated[index]=true;
                return;
            } break;

            case OP_Z:
            {
                cache[index].set(coord.z_);
                evaluated[index]=true;
                return;
            } break;

            case OP_W:
            {
                cache[index].set(coord.w_);
                evaluated[index]=true;
                return;
            } break;

            case OP_U:
            {
                cache[index].set(coord.u_);
                evaluated[index]=true;
                return;
            } break;

            case OP_V:
            {
                cache[index].set(coord.v_);
                evaluated[index]=true;
                return;
            } break;

            case OP_Radial:
            {
                double len=0;
                switch(coord.dimension_)
                {
                case 2:
                    len=std::sqrt(coord.x_*coord.x_+coord.y_*coord.y_);
                    break;
                case 3:
                    len=std::sqrt(coord.x_*coord.x_+coord.y_*coord.y_+coord.z_*coord.z_);
                    break;
                case 4:
                    len=std::sqrt(coord.x_*coord.x_+coord.y_*coord.y_+coord.z_*coord.z_+coord.w_*coord.w_);
                    break;
                default:
                    len=std::sqrt(coord.x_*coord.x_+coord.y_*coord.y_+coord.z_*coord.z_+coord.w_*coord.w_+coord.u_*coord.u_+coord.v_*coord.v_);
                    break;
                };
                cache[index].set(len);
                evaluated[index]=true;
                return;
            } break;

            case OP_Clamp:
            {
                double val=evaluateParameter(kernel,evaluated,coordcache,cache,i.sources_[0],coord);
                double low=evaluateParameter(kernel,evaluated,coordcache,cache,i.sources_[1],coord);
                double high=evaluateParameter(kernel,evaluated,coordcache,cache,i.sources_[2],coord);

                cache[index].set(std::max(low,std::min(high,val)));
                evaluated[index]=true;
                return;
            } break;

			case OP_ExtractRed:
			{
				SRGBA c=evaluateRGBA(kernel,evaluated,coordcache,cache,i.sources_[0],coord);
				cache[index].set(c.x());
				evaluated[index]=true;
				return;
			} break;

			case OP_ExtractGreen:
			{
				SRGBA c=evaluateRGBA(kernel,evaluated,coordcache,cache,i.sources_[0],coord);
				cache[index].set(c.y());
				evaluated[index]=true;
				return;
			} break;

			case OP_ExtractBlue:
			{
				SRGBA c=evaluateRGBA(kernel,evaluated,coordcache,cache,i.sources_[0],coord);
				cache[index].set(c.z());
				evaluated[index]=true;
				return;
			} break;

			case OP_ExtractAlpha:
			{
				SRGBA c=evaluateRGBA(kernel,evaluated,coordcache,cache,i.sources_[0],coord);
				cache[index].set(c.w());
				evaluated[index]=true;
				return;
			} break;

			case OP_Grayscale:
			{
				double v=evaluateParameter(kernel,evaluated,coordcache,cache,i.sources_[0],coord);
				cache[index].set(v);
				evaluated[index]=true;
				return;
			} break;

			case OP_CombineRGBA:
			{
				double r=evaluateParameter(kernel,evaluated,coordcache,cache,i.sources_[0],coord);
				double g=evaluateParameter(kernel,evaluated,coordcache,cache,i.sources_[1],coord);
				double b=evaluateParameter(kernel,evaluated,coordcache,cache,i.sources_[2],coord);
				double a=evaluateParameter(kernel,evaluated,coordcache,cache,i.sources_[3],coord);
				cache[index].outrgba_=SRGBA(r,g,b,a);
				evaluated[index]=true;
				return;
			} break;

            default: evaluated[index]=true; return; break;
        };
    }
};
