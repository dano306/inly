#include <CAesWrapper.h>

const uint8_t CAesWrapper::sm_aesKey[CryptoPP::AES::DEFAULT_KEYLENGTH] = {
	0x00, 0x01, 0x02, 0x03,
	0x10, 0x11, 0x12, 0x13,
	0x20, 0x21, 0x22, 0x23,
	0x30, 0x31, 0x32, 0x33,
};

void
CAesWrapper::encrypt(const uint8_t *pbinPlain, const uint32_t u32LenPlain, const uint8_t * & r_pbinCipher, uint32_t &r_u32LenCipher)
{
	CryptoPP::AESEncryption aesEncryptor;
	
	uint8_t inBlock[CryptoPP::AES::BLOCKSIZE];				//加密后的密文块
	uint8_t outBlock[CryptoPP::AES::BLOCKSIZE];				//加密后的密文块
	uint8_t xorBlock[CryptoPP::AES::BLOCKSIZE];				//必须设定为全零
    aesEncryptor.SetKey(CAesWrapper::aesKey, CryptoPP::AES::DEFAULT_KEYLENGTH);  //设定加密密钥
	
	r_pbinCipher = new uint8_t[200];
	
	const uint8_t	*pbinCur = pbinPlain;
	const uint8_t	*pbinEnd = pbinPlain + u32LenPlain;
	while(pbinCur < pbinEnd){
		uint32_t	u32LenLeft = pbinEnd - pbinCur;
		if(u32LenLeft > CryptoPP::AES::BLOCKSIZE) {
			u32LenLeft = CryptoPP::AES::BLOCKSIZE;
		}
		memset(xorBlock, 0, CryptoPP::AES::BLOCKSIZE);
		memcpy(inBlock, pbinCur, u32LenLeft);
		aesEncryptor.ProcessAndXorBlock( inBlock, xorBlock, outBlock);
		memcpy(r_pbinCipher, outBlock, CryptoPP::AES::BLOCKSIZE);
		break;
	}
}

void
CAesWrapper::decrypt(const uint8_t *pbinCipher, const uint32_t u32LenCipher, const uint8_t * & r_pbinPlain, uint32_t &r_u32LenPlain)
{
	
}
