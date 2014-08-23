#ifndef	__FILE_CINLY_H__
#define	__FILE_CINLY_H__

NAMESPACE_BEGIN__INLY

class	CInly
{
public:

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

private:
	/*
		仅调试时使用，发布时作为私有函数
	*/
	void
	test(const char *pPlain);

};//class CInly

NAMESPACE_END__INLY

#endif	//__FILE_CINLY_H__

