#include "mizar_api.h"

#include <iostream>

mizar_uint32 MizarSdkInit(mizar_uint32 nAutoVerifyPinFlag, mizar_char* szPin) {
    std::cout << "MizarSdkInit : " << nAutoVerifyPinFlag << " " << szPin << std::endl;
	return 0;    
}

mizar_uint32 MizarDeleteShareObject(void) {
    std::cout << "MizarDeleteShareObject" << std::endl;
	return 0;    
};
