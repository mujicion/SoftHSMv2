#include "mizar_api.h"

mizar_uint32 MizarSdkInit(mizar_uint32 nAutoVerifyPinFlag, mizar_char* szPin) {
    // std::cout << "MizarSdkInit : " << nAutoVerifyPinFlag << " " << szPin << std::endl;
	return 0;    
}

mizar_uint32 MizarDeleteShareObject(void) {
    // std::cout << "MizarDeleteShareObject" << std::endl;
	return 0;    
}

#include <openssl/rand.h>
mizar_uint32 MizarGenRnd(mizar_uint32 flag, mizar_uint32 nLen, mizar_uint8* ucRND){
	RAND_seed(&ucRND[0], nLen);

	mizar_uint32 ret = RAND_bytes(&ucRND[0], (int) nLen);
    return ret;
    // return MizarGenRnd(0, len, &ucRND[0]) == 0;
}

#include <openssl/sha.h>
static SHA256_CTX sha256;

#include <openssl/evp.h>
static EVP_MD_CTX* curCTX;

mizar_uint32 MizarShaInit(mizar_uint32 nAlg) {
    curCTX = EVP_MD_CTX_new();
    EVP_DigestInit_ex(curCTX, EVP_sha256(), NULL);
    // SHA256_Init(&sha256);
    return 0;
}

mizar_uint32 MizarShaUpdate(mizar_uint32 nAlg, mizar_uint32 nDatalen, mizar_uint8* ucData) {
    EVP_DigestUpdate(curCTX, ucData, nDatalen);
    // SHA256_Update(&sha256, ucData, nDatalen);
    return 0;
}

#include "ByteString.h"
mizar_uint32 MizarShaFinal(mizar_uint32 nAlg, mizar_uint32* nHashlen, mizar_uint8* ucHash) {
    EVP_DigestFinal_ex(curCTX, ucHash, nHashlen);
    EVP_MD_CTX_free(curCTX);
    // SHA256_Final(ucHash, &sha256);
    // *nHashlen = strlen((const char*) ucHash);
    return 0;
}