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

	return (0);
}
