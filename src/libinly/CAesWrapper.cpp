#include <CAesWrapper.h>

const uint8_t CAesWrapper::sm_aesKey[CryptoPP::AES::DEFAULT_KEYLENGTH] = {
	0x00, 0x01, 0x02, 0x03,
	0x10, 0x11, 0x12, 0x13,
	0x20, 0x21, 0x22, 0x23,
	0x30, 0x31, 0x32, 0x33,
};

void
CAesWrapper::encrypt(const uint8_t *pbinPlain, const size_t lenPlain, const uint8_t * & r_pbinCipher, size_t &r_lenCipher)
{
	CryptoPP::AESEncryption aesEncryptor;
	
	uint8_t inBlock[CryptoPP::AES::BLOCKSIZE];				//���ܺ�����Ŀ�
	uint8_t outBlock[CryptoPP::AES::BLOCKSIZE];				//���ܺ�����Ŀ�
	uint8_t xorBlock[CryptoPP::AES::BLOCKSIZE];				//�����趨Ϊȫ��
    aesEncryptor.SetKey(CAesWrapper::sm_aesKey, CryptoPP::AES::DEFAULT_KEYLENGTH);  //�趨������Կ
	
	r_pbinCipher = new uint8_t[200];
	
	const uint8_t	*pbinCur = pbinPlain;
	const uint8_t	*pbinEnd = pbinPlain + lenPlain;
	while(pbinCur < pbinEnd){
		size_t	lenLeft = pbinEnd - pbinCur;
		if(lenLeft > CryptoPP::AES::BLOCKSIZE) {
			lenLeft = CryptoPP::AES::BLOCKSIZE;
		}
		memset(xorBlock, 0, CryptoPP::AES::BLOCKSIZE);
		memcpy(inBlock, pbinCur, lenLeft);
		aesEncryptor.ProcessAndXorBlock( inBlock, xorBlock, outBlock);
		memcpy((void *)r_pbinCipher, outBlock, CryptoPP::AES::BLOCKSIZE);
		break;
	}
}

void
CAesWrapper::decrypt(const uint8_t *pbinCipher, const size_t lenCipher, const uint8_t * & r_pbinPlain, size_t &r_lenPlain)
{
	
}
