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
			if (!strHardware.empty()) {
				//加入分隔线
				strHardware += "|";
			}
			strHardware += *it;
			inly_cout(*it);
		}
		inly_cout(strHardware);
		
		//加密
		std_string		strCipher;
		{
			CAesWrapper		aes;
			aes.encrypt(strHardware, strCipher);
			
			//仅测试
			//strHardware.clear();
			//aes.decrypt(strCipher, strHardware);
			//return (strHardware);
		}
		
		return (strCipher);
	}
	catch (const filesystem_error& ex)
	{
		//ex.what()
		return ("");
	}
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
CInly::CheckLicenseString(const std_string &r_strLicense)
{
	std::string	strLicense;
	strLicense = GetLicenseString();
	
	return (strLicense == r_strLicense);
}

const std_string
CInly::DumpLicenseDetail(const std_string &r_strLicense)
{
	CAesWrapper		aes;
	std::string		strHardwareCipher;
	aes.decrypt(r_strLicense, strHardwareCipher);
	
	std::string		strHardwarePlain = DumpHardwareDetail(strHardwareCipher);
	return (strHardwarePlain);
}

const std_string
CInly::DumpHardwareDetail(const std_string &r_strHardware)
{
	CAesWrapper		aes;
	std::string		strHardwarePlain;	
	aes.decrypt(r_strHardware, strHardwarePlain);
	
	return (strHardwarePlain);	
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

NAMESPACE_END__INLY
