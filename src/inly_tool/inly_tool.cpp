#include <inly.h>

NAMESPACE_USING__INLY

int main()
{
	CInly	Inly;
	
	//Inly.test("dano306");
	//std::cout << "hello world, dano306!" << std::endl;
	
	{
		std::string	strHardware;
		strHardware = Inly.GetHardwareString();
		inly_cout(strHardware);
	}

	{
		std::string	strLicense;
		strLicense = Inly.GetLicenseString();
		inly_cout(strLicense);
	}

	{
		std::string	strHardware = "4007D2B98B95BD4AE2B444C64A57816EC2";
		std::string	strLicense;
		strLicense = Inly.GetLicenseString(strHardware);
		inly_cout(strLicense);
	}

	{
		std::string	strLicense = "4407D8BEAC9DCD4AE0954AC93E258F4CE198263A0F5666093B6BB5A52199157D327E";
		bool	bRet_CheckLicenseString = Inly.CheckLicenseString(strLicense);
		inly_cout(bRet_CheckLicenseString);
	}

	{
		std::string	strLicense = "4407D8BEAC9DCD4AE0954AC93E258F4CE198263A0F5666093B6BB5A52199157D327E";
		std::string	strHardwarePlain = Inly.DumpLicenseDetail(strLicense);
		inly_cout(strHardwarePlain);
	}

	{
		std::string	strHardware = "4007D2B98B95BD4AE2B444C64A57816EC2";
		std::string	strHardwarePlain = Inly.DumpHardwareDetail(strHardware);
		inly_cout(strHardwarePlain);
	}

	return (0);
}
