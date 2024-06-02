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
 MizaruSHA256.h

 Mizaru SHA256 implementation
 *****************************************************************************/

#include "config.h"
#include "MizaruSHA256.h"
#include "mizaru/mizar_api.h"

// Hashing functions
bool MizaruSHA256::hashInit()
{
	if (!HashAlgorithm::hashInit())
	{
		return false;
	}

	if (0 != MizarShaInit(3))
	{
		ERROR_MSG("MizarShaInit failed");

		ByteString dummy;
		HashAlgorithm::hashFinal(dummy);

		return false;
	}

	return true;
}

bool MizaruSHA256::hashUpdate(const ByteString& data)
{
	if (!HashAlgorithm::hashUpdate(data))
	{
		return false;
	}

	if (data.size() == 0)
	{
		return true;
	}

	if (0 != MizarShaUpdate(3, data.size(), (mizar_uint8*) data.const_byte_str()))
	{
		ERROR_MSG("MizarShaUpdate failed");

		ByteString dummy;
		HashAlgorithm::hashFinal(dummy);

		return false;
	}

	return true;
}

bool MizaruSHA256::hashFinal(ByteString& hashedData)
{
	if (!HashAlgorithm::hashFinal(hashedData))
	{
		return false;
	}

	hashedData.resize(getHashSize());
	unsigned int outLen = 0;

	if (0 != MizarShaFinal(3, &outLen, &hashedData[0]))
	{
		ERROR_MSG("MizarShaFinal failed");

		return false;
	}
	hashedData.resize(outLen);

	return true;
}

int MizaruSHA256::getHashSize()
{
	return 32;
}

