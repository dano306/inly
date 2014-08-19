#include "CInly.h"

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


}

