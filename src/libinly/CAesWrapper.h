#ifndef	__FILE_CAESWRAPPER_H__
#define	__FILE_CAESWRAPPER_H__

#include <cryptopp/aes.h>
#include <inttypes.h>
#include <vector>

class	CAesWrapper
{
public:
	
	void
	encrypt(const uint8_t *pbinPlain, const size_t lenPlain, const uint8_t * & r_pbinCipher, size_t &r_lenCipher);
	
	void
	decrypt(const uint8_t *pbinCipher, const size_t lenCipher, const uint8_t * & r_pbinPlain, size_t &r_lenPlain);

protected:
	typedef	std::vector<uint8_t>	vec_bin_type;
	vec_bin_type					m_binPlain;
	vec_bin_type					m_binCipher;
	
private:
	const static uint8_t sm_aesKey[CryptoPP::AES::DEFAULT_KEYLENGTH];
};//CAesWrapper

#endif	//__FILE_CAESWRAPPER_H__
