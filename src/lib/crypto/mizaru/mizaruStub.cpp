#include "mizar_api.h"
#include <openssl/rand.h>

mizar_uint32 MizarSdkInit(mizar_uint32 nAutoVerifyPinFlag, mizar_char* szPin) {
    // std::cout << "MizarSdkInit : " << nAutoVerifyPinFlag << " " << szPin << std::endl;
	return 0;    
}

mizar_uint32 MizarDeleteShareObject(void) {
    // std::cout << "MizarDeleteShareObject" << std::endl;
	return 0;    
}

mizar_uint32 MizarGenRnd(mizar_uint32 flag, mizar_uint32 nLen, mizar_uint8* ucRND){
	RAND_seed(&ucRND[0], nLen);

	mizar_uint32 ret = RAND_bytes(&ucRND[0], (int) nLen);
    return ret;
    // return MizarGenRnd(0, len, &ucRND[0]) == 0;
}