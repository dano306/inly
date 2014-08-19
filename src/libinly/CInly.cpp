#include <CInly.h>
#include <CAesWrapper.h>

#include <stdio.h>
#define	printf(format, args...)	printf("%s %s %d: " format "\n", __FILE__, __FUNCTION__, __LINE__, ##args)
#define	printf__s(var)	printf("%s = %s", #var, var)
#define	printf__size_t(var)	printf("%s = %lu", #var, var)
#define	printf__str(var)	printf("%s = %s", #var, (var).c_str())


CInly::CInly()
{
}

CInly::~CInly()
{
}

bool
CInly::CheckLicenseString(const std_string &r_strLicense)
{
	return (false);
}

const CInly::std_string
CInly::GetHardwareString(void)
{
	/*
		当前版本：仅关联所有网卡mac地址
		明文: 枚举/sys/class/net/目录，除lo之外，eth'X'/em'X'目录下的address文件内容，然后以'|'分隔，各mac地址按从小到大排序
		`cat /sys/class/net/eth0/address`|`cat /sys/class/net/eth1/address`|...|`cat /sys/class/net/ethN/address`
	*/

	return ("");
}

void
CInly::test(const char *pPlain)
{

	CAesWrapper		aes;
	//std_string		strPlain = "h\0ello, dano306!";
	std_string		strCipher;
	std_string		strFinalPlain;
	
	const char *p = "h\0ello, dano306!hahahahahaha";
	std_string strPlain(p, p + 24);
	
	aes.encrypt(strPlain, strCipher);
	aes.decrypt(strCipher, strFinalPlain);
	
	printf__str(strPlain);
	printf__size_t(strPlain.size());
	printf__str(strFinalPlain);
	printf__size_t(strFinalPlain.size());

	fprintf(stdout, "strCipher's byte:\n");
	for(size_t i = 0; i < 24; ++i){
		fprintf(stdout, "%02X ", (uint8_t)strCipher[i]);
	}
	fprintf(stdout, "\n");
	
	fprintf(stdout, "strFinalPlain's byte:\n");
	for(size_t i = 0; i < 24; ++i){
		fprintf(stdout, "%02X ", (uint8_t)strFinalPlain[i]);
	}
	fprintf(stdout, "\n");
}
