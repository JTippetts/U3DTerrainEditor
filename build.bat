"bin\tolua++.exe" -o BindTerrainEdit.cpp BindTerrainEdit.pkg
call cmake_mingw.bat ../U3DBGL -DURHO3D_64BIT=1 -DURHO3D_LUAJIT=1 -DURHO3D_OPENGL=1 -DURHO3D_HOME=C:\Users\JTippetts\Projects\Urho3D\BuildMGWGL -DCMAKE_BUILD_TYPE=RelWithDebInfo
cd ..\U3DBGL\
mingw32-make.exe
copy bin\TEdit.exe ..\U3DTerrainEditor\Bin
cd ..\U3DTerrainEditor
