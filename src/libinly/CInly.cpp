#include <CInly.h>
#include <CAesWrapper.h>

#include <boost/filesystem.hpp>
using namespace boost::filesystem;
#include <vector>
#include <set>
#include <iostream>
using namespace std;

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

	/*
		@return
			失败返回""，否则返回硬件字符串[当前的设计下，不可能是""]
	*/

	path			p("/sys/class/net");
	std_string		strHardware;
	try
	{
		if (!exists(p))    // does p actually exist?
		{
			return ("");
		}
		
		if (!is_directory(p))      // is p a directory?
		{
			return ("");
		}
		
		//这里，p肯定是存在的目录
		//开始遍历其下的文件
		for (path::iterator it(p.begin()), it_end(p.end()); it != it_end; ++it)
    		cout << "  " << *it << '\n';
		
		
		
//		typedef vector<path> vec;             // store paths,
//		vec v;                                // so we can sort them later
//		
//		copy(directory_iterator(p), directory_iterator(), back_inserter(v));
//		
//		sort(v.begin(), v.end());             // sort, since directory iteration
//		  // is not ordered on some file systems
//		for (vec::const_iterator it (v.begin()); it != v.end(); ++it)
//		{
//		cout << "   " << *it << '\n';
//		}
//		}
//		
//		else
//		cout << p << " exists, but is neither a regular file nor a directory\n";

	}
	catch (const filesystem_error& ex)
	{
		cout << ex.what() << '\n';
	}


	return ("");
}

void
CInly::test(const char *pPlain)
{
	CAesWrapper		aes;

	std_string		strCipher;
	std_string		strFinalPlain;

	//std_string		strPlain = "with cryptopp: hello, dano306!";	
	const char *p = "h\0ello, dano306!hahahahahaha";
	std_string strPlain(p, p + 24);
	
	aes.encrypt(strPlain, strCipher);
	aes.decrypt(strCipher, strFinalPlain);
	
	printf__str(strPlain);
	printf__size_t(strPlain.size());
	printf__str(strCipher);
	printf__size_t(strCipher.size());
	printf__str(strFinalPlain);
	printf__size_t(strFinalPlain.size());

	fprintf(stdout, "strCipher's byte:\n");
	for(size_t i = 0; i < strCipher.size(); ++i){
		fprintf(stdout, "%02X ", (uint8_t)strCipher[i]);
	}
	fprintf(stdout, "\n");
	
	fprintf(stdout, "strFinalPlain's byte:\n");
	for(size_t i = 0; i < strFinalPlain.size(); ++i){
		fprintf(stdout, "%02X ", (uint8_t)strFinalPlain[i]);
	}
	fprintf(stdout, "\n");
}
