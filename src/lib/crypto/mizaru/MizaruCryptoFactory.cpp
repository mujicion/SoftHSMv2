/*
 * Copyright (c) 2010 SURFnet bv
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 *
 * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR
 * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY
 * DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE
 * GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER
 * IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR
 * OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN
 * IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

/*****************************************************************************
 MizaruCryptoFactory.cpp

 This is an OpenSSL based cryptographic algorithm factory
 *****************************************************************************/

#include "config.h"
#include "MutexFactory.h"
#include "MizaruCryptoFactory.h"
#include "MizaruRNG.h"
// #include "MizaruAES.h"
// #include "MizaruDES.h"
#include "MizaruSHA256.h"
// #include "MizaruCMAC.h"
// #include "MizaruHMAC.h"
// #include "MizaruRSA.h"
// #include "MizaruECDSA.h"

#include <algorithm>
#include <string.h>

static unsigned nlocks;
static Mutex** locks;

// Constructor
MizaruCryptoFactory::MizaruCryptoFactory()
{
	// // Multi-thread support
	// nlocks = CRYPTO_num_locks();
	// locks = new Mutex*[nlocks];
	// for (unsigned i = 0; i < nlocks; i++)
	// {
	// 	locks[i] = MutexFactory::i()->getMutex();
	// }

	// Initialise the one-and-only RNG
	rng = new MizaruRNG();
}

// Destructor
MizaruCryptoFactory::~MizaruCryptoFactory()
{
	// for (unsigned i = 0; i < nlocks; i++)
	// {
	// 	MutexFactory::i()->recycleMutex(locks[i]);
	// }
	// delete[] locks;
}

// Return the one-and-only instance
MizaruCryptoFactory* MizaruCryptoFactory::i()
{
	if (!instance.get())
	{
		instance.reset(new MizaruCryptoFactory());
	}

	return instance.get();
}

// This will destroy the one-and-only instance.
void MizaruCryptoFactory::reset()
{
	instance.reset();
}

// Create a concrete instance of a symmetric algorithm
SymmetricAlgorithm* MizaruCryptoFactory::getSymmetricAlgorithm(SymAlgo::Type algorithm)
{
	// switch (algorithm)
	// {
	// 	case SymAlgo::AES:
	// 		return new MizaruAES();
	// 	case SymAlgo::DES:
	// 	case SymAlgo::DES3:
	// 		return new MizaruDES();
	// }

	// No algorithm implementation is available
	ERROR_MSG("Unknown algorithm '%i'", algorithm);
	return NULL;
}

// Create a concrete instance of an asymmetric algorithm
AsymmetricAlgorithm* MizaruCryptoFactory::getAsymmetricAlgorithm(AsymAlgo::Type algorithm)
{
// 	switch (algorithm)
// 	{
// 		case AsymAlgo::RSA:
// 			return new MizaruRSA();
// #ifdef WITH_ECC
// 		case AsymAlgo::ECDSA:
// 			return new MizaruECDSA();
// #endif
// 	}

	// No algorithm implementation is available
	ERROR_MSG("Unknown algorithm '%i'", algorithm);
	return NULL;
}

// Create a concrete instance of a hash algorithm
HashAlgorithm* MizaruCryptoFactory::getHashAlgorithm(HashAlgo::Type algorithm)
{
	switch (algorithm)
	{
		case HashAlgo::SHA256:
			return new MizaruSHA256();
	}

	// No algorithm implementation is available
	ERROR_MSG("Unknown algorithm '%i'", algorithm);
	return NULL;
}

// Create a concrete instance of a MAC algorithm
MacAlgorithm* MizaruCryptoFactory::getMacAlgorithm(MacAlgo::Type algorithm)
{
	// switch (algorithm)
	// {
	// 	case MacAlgo::HMAC_SHA256:
	// 		return new MizaruHMACSHA256();
	// 	case MacAlgo::CMAC_DES:
	// 		return new MizaruCMACDES();
	// 	case MacAlgo::CMAC_AES:
	// 		return new MizaruCMACAES();
	// }

	// No algorithm implementation is available
	ERROR_MSG("Unknown algorithm '%i'", algorithm);
	return NULL;
}

// Get the global RNG (may be an unique RNG per thread)
RNG* MizaruCryptoFactory::getRNG(RNGImpl::Type name /* = RNGImpl::Default */)
{
	if (name == RNGImpl::Default)
	{
		return rng;
	}
	else
	{
		// No RNG implementation is available
		ERROR_MSG("Unknown RNG '%i'", name);

		return NULL;
	}
}

