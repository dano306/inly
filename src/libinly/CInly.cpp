#include <CInly.h>
#include <CAesWrapper.h>

#include <stdio.h>
#define	printf(format, args...)	printf("%s %s %d: " format "\n", __FILE__, __FUNCTION__, __LINE__, ##args)
#define	printf_s(var)	printf("%s = %s", #var, var)


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
	const uint8_t	*pbinPlan = (const uint8_t *)pPlain;
	size_t			lenPlan = strlen(pPlain);
	
	const uint8_t	*pbinCipher(NULL);
	size_t			lenCipher((size_t)0);
	
	CAesWrapper		aes;
	aes.encrypt(pbinPlan, lenPlan, pbinCipher, lenCipher);
	
	printf_s(pPlain);
	printf("%u", lenPlan);
	printf("%u", lenCipher);

	//////////
	const uint8_t	*pbinFinalPlain(NULL);
	size_t			lenFinalPlain((size_t)0);
	
	aes.decrypt(pbinCipher, lenCipher, pbinFinalPlain, lenFinalPlain);

	const char *pFinalPlain = (const char *)pbinFinalPlain;
	printf_s(pFinalPlain);
	printf("%u", lenFinalPlain);

	delete [] pbinFinalPlain;
	delete [] pbinCipher;
}
