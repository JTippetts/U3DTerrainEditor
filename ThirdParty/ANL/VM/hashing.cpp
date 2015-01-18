#include "hashing.h"

unsigned int fnv_32_a_buf(void *buf, unsigned int len)
{
    unsigned int hval=(unsigned int)FNV_32_INIT;
    unsigned int *bp = (unsigned int *)buf;
    unsigned int *be = bp+len;
    while (bp<be)
    {
        hval ^=*bp++;
        hval*=FNV_32_PRIME;
    }
    return hval;
}

unsigned int fnv_32_a_combine(unsigned int hash, unsigned int val)
{
	hash^=val;
	hash*=FNV_32_PRIME;
	return hash;
}


unsigned char xor_fold_hash(unsigned int hash)
{
    // Implement XOR-folding to reduce from 32 to 8-bit hash
    return (unsigned char)((hash>>8) ^ (hash & FNV_MASK_8));
}


// FNV-based coordinate hashes
unsigned int hash_coords_2(int x, int y, unsigned int seed)
{
    //unsigned int d[3]={(unsigned int)x,(unsigned int)y,seed};
    //return xor_fold_hash(fnv_32_a_buf(d, 3));
	unsigned int hash=FNV_32_INIT;
	hash=fnv_32_a_combine(hash,(unsigned int)x);
	hash=fnv_32_a_combine(hash,(unsigned int)y);
	hash=fnv_32_a_combine(hash,seed);
	return xor_fold_hash(hash);
}
unsigned int hash_coords_3(int x, int y, int z, unsigned int seed)
{
    //unsigned int d[4]={(unsigned int)x,(unsigned int)y,(unsigned int)z,seed};
    //return xor_fold_hash(fnv_32_a_buf(d, 4));
	unsigned int hash=FNV_32_INIT;
	hash=fnv_32_a_combine(hash,(unsigned int)x);
	hash=fnv_32_a_combine(hash,(unsigned int)y);
	hash=fnv_32_a_combine(hash,(unsigned int)z);
	hash=fnv_32_a_combine(hash,seed);
	return xor_fold_hash(hash);
}

unsigned int hash_coords_4(int x, int y, int z, int w, unsigned int seed)
{
    //unsigned int d[5]={(unsigned int)x,(unsigned int)y,(unsigned int)z,(unsigned int)w,seed};
    //return xor_fold_hash(fnv_32_a_buf(d, 5));
	unsigned int hash=FNV_32_INIT;
	hash=fnv_32_a_combine(hash,(unsigned int)x);
	hash=fnv_32_a_combine(hash,(unsigned int)y);
	hash=fnv_32_a_combine(hash,(unsigned int)z);
	hash=fnv_32_a_combine(hash,(unsigned int)w);
	hash=fnv_32_a_combine(hash,seed);
	return xor_fold_hash(hash);
}

unsigned int hash_coords_6(int x, int y, int z, int w, int u, int v, unsigned int seed)
{
    //unsigned int d[7]={(unsigned int)x,(unsigned int)y,(unsigned int)z,(unsigned int)w,(unsigned int)u,(unsigned int)v,seed};
    //return xor_fold_hash(fnv_32_a_buf(d, 7));
	unsigned int hash=FNV_32_INIT;
	hash=fnv_32_a_combine(hash,(unsigned int)x);
	hash=fnv_32_a_combine(hash,(unsigned int)y);
	hash=fnv_32_a_combine(hash,(unsigned int)z);
	hash=fnv_32_a_combine(hash,(unsigned int)w);
	hash=fnv_32_a_combine(hash,(unsigned int)u);
	hash=fnv_32_a_combine(hash,(unsigned int)v);
	hash=fnv_32_a_combine(hash,seed);
	return xor_fold_hash(hash);
}
