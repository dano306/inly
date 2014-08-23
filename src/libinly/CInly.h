#ifndef	__FILE_CINLY_H__
#define	__FILE_CINLY_H__

NAMESPACE_BEGIN__INLY

class	CInly
{
public:

	explicit CInly();
	virtual ~CInly();

	/*
		machine --(read plain info)--> raw string --(aes encrypt)--> hardware string --(aes encrypt)--> license string
		Getxxx函数，沿着aes encrypt的方向，但不跨级，比如，不能从raw string直接到license string
		D_Getxxx函数，沿着aes decrypt的方向，但不跨级
	*/

	////////////////////////////////////////////////////////

	/*
		返回表示硬件编码的原始字符串
	*/
	const std_string
	GetRawString(void);

	/*
		返回表示硬件编码的原始字符串，从指定的硬件字符串进行解码
	*/
	const std_string
	D_GetRawString(const std_string &r_strHardware);

	/*
		由硬件编码[从参数获取]生成的硬件字符串
	*/
	const std_string
	GetHardwareString(const std_string &r_strRaw);

	/*
		由硬件编码[从当前机器获取]生成的硬件字符串
	*/
	const std_string
	GetHardwareString(void);

	/*
		从许可字符串获取硬件字符串
	*/
	const std_string
	D_GetHardwareString(const std_string &r_strLicense);

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
		检验硬件字符串
	*/
	bool
	CheckHardwareString(const std_string &r_strHardware);

	/*
		检验许可字符串
	*/
	bool
	CheckLicenseString(const std_string &r_strLicense);

private:
	/*
		仅调试时使用，发布时作为私有函数
	*/
	void
	test(const char *pPlain);

};//class CInly

NAMESPACE_END__INLY

#endif	//__FILE_CINLY_H__

