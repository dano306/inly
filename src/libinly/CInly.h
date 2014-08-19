#ifndef	__FILE_CINLY_H__
#define	__FILE_CINLY_H__

#include <string>

class	CInly
{
public:
	typedef	std::string	std_string;

	explicit CInly();
	virtual ~CInly();

	bool
	CheckLicense(const std_string &r_strLicense);

	std_string
	GetLicense(void);

	std_string
	DumpLicenseDetail(const std_string &r_strLicense);

};//class CInly

#endif	//__FILE_CINLY_H__

