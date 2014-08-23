#include "CInly.h"
#include <iostream>
#include <string>

int main()
{
	CInly	Inly;
	
	//Inly.test("dano306");
	//std::cout << "hello world, dano306!" << std::endl;
	
	{
		std::string	strHardware;
		strHardware = Inly.GetHardwareString();
		std::cout << "strHardware: " << strHardware << std::endl;
	}

	{
		std::string	strLicense;
		strLicense = Inly.GetLicenseString();
		std::cout << "strLicense: " << strLicense << std::endl;		
	}

	{
		std::string	strHardware = "4007D2B98B95BD4AE2B444C64A57816EC2";
		std::string	strLicense;
		strLicense = Inly.GetLicenseString(strHardware);
		std::cout << "strLicense: " << strLicense << std::endl;	
	}

	{
		std::string	strLicense = "4407D8BEAC9DCD4AE0954AC93E258F4CE198263A0F5666093B6BB5A52199157D327E";
		bool	bRet = Inly.CheckLicenseString(strLicense);
		std::cout << "CheckLicenseString: " << bRet << std::endl;
	}

	{
		std::string	strLicense = "4407D8BEAC9DCD4AE0954AC93E258F4CE198263A0F5666093B6BB5A52199157D327E";
		std::string	strHardwarePlain = Inly.DumpLicenseDetail(strLicense);
		std::cout << "strHardwarePlain: " << strHardwarePlain << std::endl;
	}

	{
		std::string	strHardware = "4007D2B98B95BD4AE2B444C64A57816EC2";
		std::string	strHardwarePlain = Inly.DumpHardwareDetail(strHardware);
		std::cout << "strHardwarePlain: " << strHardwarePlain << std::endl;
	}

	return (0);
}
