#include "hashing.h"

unsigned int p191[191]={24, 147, 35, 19, 161, 22, 27, 157, 122, 68, 166, 63, 16, 191, 120, 133, 26, 109, 50, 47, 96, 78, 20, 119, 85, 43, 12, 18, 126, 49, 150, 69, 75, 97, 134, 136, 
98, 28, 84, 177, 188, 34, 115, 46, 48, 184, 86, 42, 4, 155, 39, 163, 174, 160, 36, 141, 172, 25, 73, 38, 66, 51, 32, 11, 143, 57, 13, 14, 116, 118, 31, 169, 53, 130, 2, 107, 45, 106,
 88, 181, 125, 114, 44, 189, 17, 93, 8, 56, 159, 1, 135, 15, 156, 183, 87, 41, 117, 186, 55, 77, 132, 170, 91, 9, 127, 168, 54, 178, 6, 131, 74, 146, 23, 138, 67, 80, 60, 190, 58, 29,
 81, 124, 149, 79, 137, 158, 129, 21, 89, 185, 82, 61, 154, 164, 76, 113, 52, 140, 100, 30, 101, 162, 10, 108, 72, 92, 33, 171, 167, 144, 99, 59, 83, 128, 65, 176, 179, 62, 64, 112, 40,
 111, 105, 103, 152, 151, 71, 173, 3, 187, 90, 180, 95, 145, 5, 70, 94, 7, 165, 153, 110, 102, 182, 148, 142, 37, 123, 139, 121, 175, 104};


unsigned int p192[192]={174, 25, 26, 138, 3, 153, 143, 188, 98, 95, 13, 149, 116, 5, 119, 175, 120, 14, 16, 147, 63, 104, 88, 165, 117, 115, 72, 133, 50, 160, 76, 125, 70, 148, 142, 33,
 87, 123, 94, 86, 112, 101, 57, 103, 22, 177, 167, 92, 187, 113, 173, 151, 23, 77, 6, 144, 184, 105, 137, 11, 69, 108, 30, 58, 8, 35, 157, 81, 78, 28, 24, 155, 79, 189, 178, 49, 55, 20,
 9, 171, 18, 141, 185, 43, 36, 67, 62, 68, 131, 52, 162, 54, 163, 128, 127, 169, 99, 146, 154, 46, 134, 1, 51, 34, 89, 179, 186, 168, 191, 64, 121, 150, 73, 84, 17, 97, 4, 65, 166, 44,
 61, 139, 183, 90, 41, 48, 130, 190, 66, 74, 29, 21, 59, 164, 129, 60, 83, 47, 145, 192, 107, 27, 111, 10, 38, 161, 182, 158, 110, 126, 37, 85, 102, 100, 114, 91, 136, 170, 140, 181, 7,
 15, 12, 40, 96, 82, 180, 93, 176, 152, 71, 19, 39, 75, 45, 132, 106, 118, 2, 156, 80, 159, 32, 124, 42, 56, 109, 31, 135, 53, 122, 172};


unsigned int p193[193]={140, 29, 42, 104, 50, 4, 106, 186, 129, 145, 59, 53, 91, 143, 114, 46, 130, 89, 162, 146, 61, 79, 24, 12, 43, 92, 86, 153, 171, 111, 184, 10, 36, 136, 47, 150, 141,
 56, 65, 45, 32, 164, 138, 113, 17, 40, 68, 174, 37, 100, 34, 193, 66, 1, 131, 99, 5, 18, 58, 116, 8, 172, 188, 22, 75, 165, 105, 123, 96, 169, 182, 83, 78, 135, 30, 16, 147, 64, 94, 26, 133,
 190, 178, 157, 35, 69, 27, 109, 9, 132, 102, 137, 148, 57, 62, 139, 134, 101, 95, 7, 119, 44, 98, 155, 41, 73, 185, 126, 175, 93, 81, 88, 183, 54, 71, 33, 87, 23, 152, 120, 97, 2, 154, 6,
 74, 167, 108, 84, 144, 85, 60, 72, 128, 142, 124, 118, 125, 103, 159, 187, 122, 13, 191, 163, 161, 112, 19, 181, 52, 39, 156, 49, 25, 189, 180, 80, 173, 15, 21, 149, 20, 28, 67, 121, 11, 107,
 90, 170, 158, 77, 51, 82, 14, 160, 3, 177, 38, 63, 127, 48, 117, 179, 176, 192, 31, 55, 115, 110, 76, 168, 70, 151, 166};


unsigned int p197[197]={78, 131, 192, 30, 191, 61, 140, 55, 195, 69, 46, 12, 97, 126, 10, 40, 112, 157, 122, 155, 113, 183, 133, 104, 179, 130, 167, 84, 50, 11, 5, 53, 37, 160, 178, 76, 159, 
129, 182, 7, 81, 164, 132, 181, 87, 148, 137, 143, 83, 74, 48, 119, 28, 102, 136, 19, 139, 105, 22, 95, 117, 66, 92, 151, 9, 141, 51, 99, 35, 96, 150, 172, 73, 168, 120, 186, 16, 145, 108, 
180, 3, 127, 128, 194, 31, 98, 149, 162, 49, 174, 187, 184, 45, 161, 18, 86, 88, 62, 106, 89, 142, 123, 163, 54, 33, 65, 110, 154, 176, 32, 111, 75, 23, 26, 44, 118, 71, 177, 85, 189, 134, 188, 
21, 1, 6, 107, 146, 125, 121, 185, 25, 94, 165, 68, 101, 29, 91, 147, 34, 166, 135, 158, 70, 100, 173, 171, 39, 42, 152, 8, 38, 60, 36, 41, 52, 64, 14, 80, 72, 58, 79, 115, 2, 20, 93, 63, 57, 
43, 124, 67, 196, 59, 27, 193, 156, 170, 4, 153, 13, 169, 175, 77, 109, 144, 47, 138, 24, 90, 103, 114, 56, 15, 116, 82, 17, 190, 197};




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
/*unsigned int hash_coords_2(int x, int y, unsigned int seed)
{
    //unsigned int d[3]={(unsigned int)x,(unsigned int)y,seed};
    //return xor_fold_hash(fnv_32_a_buf(d, 3));
	unsigned int hash=FNV_32_INIT;
	hash=fnv_32_a_combine(hash,(unsigned int)x);
	hash=fnv_32_a_combine(hash,(unsigned int)y);
	hash=fnv_32_a_combine(hash,seed);
	return xor_fold_hash(hash) % 4;
}*/

// Long period hash
unsigned int hash_coords_2(int x, int y, unsigned int seed)
{
	return (p191[(p191[(p191[x%191]+y)%191]+seed)%191]+
	p192[(p192[(p192[x%192]+y)%192]+seed)%192]+
	p193[(p193[(p193[x%193]+y)%193]+seed)%193]+
	p197[(p197[(p197[x%197]+y)%197]+seed)%197]) % 4;
}

/*unsigned int hash_coords_3(int x, int y, int z, unsigned int seed)
{
    //unsigned int d[4]={(unsigned int)x,(unsigned int)y,(unsigned int)z,seed};
    //return xor_fold_hash(fnv_32_a_buf(d, 4));
	unsigned int hash=FNV_32_INIT;
	hash=fnv_32_a_combine(hash,(unsigned int)x);
	hash=fnv_32_a_combine(hash,(unsigned int)y);
	hash=fnv_32_a_combine(hash,(unsigned int)z);
	hash=fnv_32_a_combine(hash,seed);
	return xor_fold_hash(hash) % 12;
}*/

unsigned int hash_coords_3(int x, int y, int z, unsigned int seed)
{
	return (
		p191[(p191[(p191[(p191[x%191]+y)%191]+z)%191]+seed)%191]+
		p192[(p192[(p192[(p192[x%192]+y)%192]+z)%192]+seed)%192]+
		p193[(p193[(p193[(p193[x%193]+y)%193]+z)%193]+seed)%193]+
		p197[(p197[(p197[(p197[x%197]+y)%197]+z)%197]+seed)%197]
	) % 12;
}

/*unsigned int hash_coords_4(int x, int y, int z, int w, unsigned int seed)
{
    //unsigned int d[5]={(unsigned int)x,(unsigned int)y,(unsigned int)z,(unsigned int)w,seed};
    //return xor_fold_hash(fnv_32_a_buf(d, 5));
	unsigned int hash=FNV_32_INIT;
	hash=fnv_32_a_combine(hash,(unsigned int)x);
	hash=fnv_32_a_combine(hash,(unsigned int)y);
	hash=fnv_32_a_combine(hash,(unsigned int)z);
	hash=fnv_32_a_combine(hash,(unsigned int)w);
	hash=fnv_32_a_combine(hash,seed);
	return xor_fold_hash(hash) % 32;
}
*/

unsigned int hash_coords_4(int x, int y, int z, int w, unsigned int seed)
{
	return (
		p191[(p191[(p191[(p191[(p191[x%191]+y)%191]+z)%191]+w)%191]+seed)%191]+
		p192[(p192[(p192[(p191[(p192[x%192]+y)%192]+z)%192]+w)%192]+seed)%192]+
		p193[(p193[(p193[(p193[(p193[x%193]+y)%193]+z)%193]+w)%193]+seed)%193]+
		p197[(p197[(p197[(p197[(p197[x%197]+y)%197]+z)%197]+w)%197]+seed)%197]
	) % 32;
}
/*
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
	return xor_fold_hash(hash) % 192;
}*/

unsigned int hash_coords_6(int x, int y, int z, int w, int u, int v, unsigned int seed)
{
	return (
		p191[(p191[(p191[(p191[(p191[(p191[(p191[x%191]+y)%191]+z)%191]+w)%191]+u)%191]+v)%191]+seed)%191]+
		p192[(p192[(p192[(p192[(p192[(p192[(p192[x%192]+y)%192]+z)%192]+w)%192]+u)%192]+v)%192]+seed)%192]+
		p193[(p193[(p193[(p193[(p193[(p193[(p193[x%193]+y)%193]+z)%193]+w)%193]+u)%193]+v)%193]+seed)%193]+
		p197[(p197[(p197[(p197[(p197[(p197[(p197[x%197]+y)%197]+z)%197]+w)%197]+u)%197]+v)%197]+seed)%197]
	) % 192;
}
