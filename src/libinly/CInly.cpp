#include <inly_core.h>
#include <CInly.h>

#include <CAesWrapper.h>

#include <boost/filesystem.hpp>
#include <boost/filesystem/fstream.hpp>
using namespace boost::filesystem;
#include <vector>
#include <set>

NAMESPACE_BEGIN__INLY

CInly::CInly()
{
}

CInly::~CInly()
{
}

const std_string
CInly::GetRawString(void)
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
	std_string		strRaw;
	try
	{
		if (!exists(p))
		{
			return ("");
		}
		
		if (!is_directory(p))
		{
			return ("");
		}
		
		//这个是将path，以/分隔，每次输出一个分量，目前暂时不需要这个功能
		//for (path::iterator it(p.begin()), it_end(p.end()); it != it_end; ++it)
    	//	std::cout << "  " << *it << '\n';
	
		//////////////////////////////
	
		//这里，p肯定是存在的目录
		//开始遍历其下的文件
		typedef	std::set< std::string >		set_str;
		set_str		setMac;
		for (directory_iterator it = directory_iterator(p); it != directory_iterator(); ++it) {
			inly_cout(*it);						//输出的是path的路径，可能带目录
			inly_cout(it->filename());			//输出的是base
			
			std_string	strFileName = it->filename();
			if (0 == strFileName.compare(0, 3, "eth") || 0 == strFileName.compare(0, 2, "em")) {
				path	path_address = path(*it) / "address";
				if (!exists(path_address))
				{
					//理论上不会进入这个分支
					continue;
				}
				
				std_string		strMac;
				boost::filesystem::ifstream	if_mac(path_address);
				getline(if_mac, strMac);
				inly_cout(strMac);
				setMac.insert(strMac);
			} else {
				//do nothing
			}
		}
		
		//setMac.insert("01:23:45:67:89:ab");	//仅仅用于测试分隔符
		for(set_str::const_iterator it = setMac.begin(); it != setMac.end(); ++it){
			if (!strRaw.empty()) {
				//加入分隔线
				strRaw += "|";
			}
			strRaw += *it;
			inly_cout(*it);
		}
		inly_cout(strRaw);
		return (strRaw);
	}
	catch (const filesystem_error& ex)
	{
		//ex.what()
		return ("");
	}
		
}

const std_string
CInly::D_GetRawString(const std_string &r_strHardware)
{
	std_string		strRaw;
	
	CAesWrapper		aes;
	aes.decrypt(r_strHardware, strRaw);
	return (strRaw);
}

const std_string
CInly::GetHardwareString(const std_string &r_strRaw)
{
	/*
		@return
			失败返回""，否则返回硬件字符串[当前的设计下，不可能是""]
	*/

	std_string		strHardware;
	
	CAesWrapper		aes;
	aes.encrypt(r_strRaw, strHardware);

	return (strHardware);
}

const std_string
CInly::GetHardwareString(void)
{
	/*
		@return
			失败返回""，否则返回硬件字符串[当前的设计下，不可能是""]
	*/

	std_string		strRaw = GetRawString();
	std_string		strHardware = GetHardwareString(strRaw);
	return (strHardware);
}

const std_string
CInly::D_GetHardwareString(const std_string &r_strLicense)
{
	std_string		strHardware;
	
	CAesWrapper		aes;
	aes.decrypt(r_strLicense, strHardware);
	return (strHardware);
}

const std_string
CInly::GetLicenseString(void)
{
	/*
		@return
			失败返回""，否则返回硬件字符串[当前的设计下，不可能是""]
	*/
	
	std::string	strHardware;
	strHardware = GetHardwareString();
	if (strHardware.empty()) {
		return ("");
	}
	
	//硬件字符串再一次加密，即得到许可字符串
	std::string	strLicense = GetLicenseString(strHardware);
	return (strLicense);
}

const std_string
CInly::GetLicenseString(const std_string &r_strHardware)
{
	//硬件字符串再一次加密，即得到许可字符串
	std::string	strLicense;
	CAesWrapper		aes;
	aes.encrypt(r_strHardware, strLicense);

	return (strLicense);
}

bool
CInly::CheckHardwareString(const std_string &r_strHardware)
{
	std::string	strHardware;
	strHardware = GetHardwareString();
	
	return (strHardware == r_strHardware);	
}

bool
CInly::CheckLicenseString(const std_string &r_strLicense)
{
	std::string	strLicense;
	strLicense = GetLicenseString();
	
	return (strLicense == r_strLicense);
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
	
	inly_printf__str(strPlain);
	inly_printf__size_t(strPlain.size());
	inly_printf__str(strCipher);
	inly_printf__size_t(strCipher.size());
	inly_printf__str(strFinalPlain);
	inly_printf__size_t(strFinalPlain.size());

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

NAMESPACE_END__INLY
