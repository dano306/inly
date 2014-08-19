#include <CAesWrapper.h>

#include <cryptopp/cryptlib.h>
using CryptoPP::Exception;

#include <cryptopp/hex.h>
using CryptoPP::HexEncoder;
using CryptoPP::HexDecoder;

#include <cryptopp/filters.h>
using CryptoPP::StringSink;
using CryptoPP::StringSource;
using CryptoPP::StreamTransformationFilter;

//#include <cryptopp/aes.h>	//已经在头文件包含
using CryptoPP::AES;

#include <cryptopp/ccm.h>
//using CryptoPP::CBC_Mode;
using CryptoPP::CTR_Mode;

////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////

const uint8_t CAesWrapper::sm_aesKey[CryptoPP::AES::DEFAULT_KEYLENGTH] = {
	0x00, 0x01, 0x02, 0x03,
	0x10, 0x11, 0x12, 0x13,
	0x20, 0x21, 0x22, 0x23,
	0x30, 0x31, 0x32, 0x33,
};

const uint8_t CAesWrapper::sm_aesIv[CryptoPP::AES::BLOCKSIZE] = {
	0x40, 0x41, 0x42, 0x43,
	0x50, 0x51, 0x52, 0x53,
	0x60, 0x61, 0x62, 0x63,
	0x70, 0x71, 0x72, 0x73,
};

void
CAesWrapper::encrypt(const std::string &r_strPlain, std::string &r_strCipher)
{
	std::string strCipher;
	
	CTR_Mode< AES >::Encryption e;
	e.SetKeyWithIV(CAesWrapper::sm_aesKey, CryptoPP::AES::DEFAULT_KEYLENGTH, CAesWrapper::sm_aesIv);
	
	// The StreamTransformationFilter adds padding
	//  as required. ECB and CBC Mode must be padded
	//  to the block size of the cipher.
	StringSource(r_strPlain, true,				//不能在StreamTransformationFilter再套一层HexEncoder
		new StreamTransformationFilter(e,
			new StringSink(strCipher)
		) // StreamTransformationFilter
	); // StringSource
	
	/*
	//方案1：返回十六进制数值
	r_strCipher.swap(strCipher);
	*/
	
	/*
	//方案2：返回十六进制数值的字符串表达；长度增加一倍，但是对于只能使用字符串的场合非常友好
	//HexEncoder只能在这里使用，不能嵌在上文的StreamTransformationFilter的上层
	*/	
	StringSource (strCipher, strCipher.size(),  
		new HexEncoder(new StringSink(r_strCipher))  
	);
}

void
CAesWrapper::decrypt(const std::string &r_strCipher, std::string &r_strPlain)
{
	std::string strRecovered;

	CTR_Mode< AES >::Decryption d;
	d.SetKeyWithIV(CAesWrapper::sm_aesKey, CryptoPP::AES::DEFAULT_KEYLENGTH, CAesWrapper::sm_aesIv);

	// The StreamTransformationFilter removes
	//  padding as required.
	StringSource(r_strCipher, true,
		new HexDecoder(			//是否使用HexDecoder，需要与encrypt配套
			new StreamTransformationFilter(d,
				new StringSink(strRecovered)
			) // StreamTransformationFilter
		)// HexDecoder
	); // StringSource

	r_strPlain.swap(strRecovered);
}
