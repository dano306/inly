#ifndef	__FILE_CAESWRAPPER_H__
#define	__FILE_CAESWRAPPER_H__

#include <cryptopp/aes.h>
#include <inttypes.h>
#include <string>

class	CAesWrapper
{
public:
	
	/*
		@r_strPlain
			可以通过 string(const_iterator first, const_itertor last)
			或者 assign(const_iterator first, const_itertor last)
			的方式，承载包含\x00在内的字符
			size()返回的长度，会包含\x00字符
		
		@r_strCipher
			密文，可能包含不可见的字符
	*/
	void
	encrypt(const std::string &r_strPlain, std::string &r_strCipher);

	/*
		@r_strCipher & @r_strPlain
			对\x00的支持，与encrypt相同
	*/
	void
	decrypt(const std::string &r_strCipher, std::string &r_strPlain);

protected:

private:
	const static uint8_t sm_aesKey[CryptoPP::AES::DEFAULT_KEYLENGTH];
	const static uint8_t sm_aesIv[CryptoPP::AES::BLOCKSIZE];

};//CAesWrapper

#endif	//__FILE_CAESWRAPPER_H__
