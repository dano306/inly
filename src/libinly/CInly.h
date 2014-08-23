#ifndef	__FILE_CINLY_H__
#define	__FILE_CINLY_H__

#include <string>

class	CInly
{
public:
	typedef	std::string	std_string;

	explicit CInly();
	virtual ~CInly();

	/*
		由硬件编码生成的硬件字符串
	*/
	const std_string
	GetHardwareString(void);

	/*
		根据当前的硬件信息输出许可字符串
	*/
	const std_string
	GetLicenseString(void);

	/*
		根据当前的硬件字符串输出许可字符串
	*/
	const std_string
	GetLicenseString(const std_string &r_strHardware);

	/*
		检验许可字符串
	*/
	bool
	CheckLicenseString(const std_string &r_strLicense);

	/*
		显示许可字符串明文
	*/
	const std_string
	DumpLicenseDetail(const std_string &r_strLicense);

	/*
		显示硬件字符串明文
	*/
	const std_string
	DumpHardwareDetail(const std_string &r_strHardware);

	void
	test(const char *pPlain);

};//class CInly

#endif	//__FILE_CINLY_H__

