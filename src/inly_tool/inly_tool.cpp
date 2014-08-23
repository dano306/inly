#include <inly.h>

#include <string>
#include <boost/program_options.hpp>
#include <cstdlib>

NAMESPACE_USING__INLY

int m2raw()
{
	CInly	Inly;

	std::string	strRaw = Inly.GetRawString();
	if (strRaw.empty()) {
		return (EXIT_FAILURE);
	}
	std::cout << strRaw << std::endl;
	
	return (EXIT_SUCCESS);
}

int m2hw()
{
	CInly	Inly;

	std::string	strHardware = Inly.GetHardwareString();
	if (strHardware.empty()) {
		return (EXIT_FAILURE);
	}
	std::cout << strHardware << std::endl;
	
	return (EXIT_SUCCESS);
}

int m2lic()
{
	CInly	Inly;

	std::string	strLicense = Inly.GetLicenseString();
	if (strLicense.empty()) {
		return (EXIT_FAILURE);
	}
	std::cout << strLicense << std::endl;
	
	return (EXIT_SUCCESS);
}

int raw2hw(const std_string &r_strRaw)
{
	CInly	Inly;

	std::string	strHardware = Inly.GetHardwareString(r_strRaw);
	if (strHardware.empty()) {
		return (EXIT_FAILURE);
	}
	std::cout << strHardware << std::endl;
	
	return (EXIT_SUCCESS);	
}

int raw2lic(const std_string &r_strRaw)
{
	CInly	Inly;

	std::string	strHardware = Inly.GetHardwareString(r_strRaw);
	if (strHardware.empty()) {
		return (EXIT_FAILURE);
	}

	std::string	strLicense = Inly.GetLicenseString(strHardware);
	if (strLicense.empty()) {
		return (EXIT_FAILURE);
	}
	std::cout << strLicense << std::endl;
	
	return (EXIT_SUCCESS);
}

int main(int argc, char **argv)
{
	namespace po = boost::program_options;
		
	po::options_description desc("inly_tool args description");
	desc.add_options()
    	("help,h", "show this message and exit")
    	("version,v", "show version and exit")
    	
    	//字符串系列的选项开关
    	("m2raw", "input: none/null; output: raw machine string")
    	("m2hw", "input: none/null; output: hardware string")
    	("m2lic", "input: none/null; output: license string")
    	("raw2hw", po::value< std::string >(), "input: raw machine string; output: hardware string")
    	("raw2lic", po::value< std::string >(), "input: raw machine string; output: license string")
    	("hw2lic", po::value< std::string >(), "input: hardware string; output: license string")
    	("hw2raw", po::value< std::string >(), "input: hardware string; output: raw machine string")
    	("lic2raw", po::value< std::string >(), "input: license string; output: raw machine string")
    	("lic2hw", po::value< std::string >(), "input: license string; output: raw hardware string")

		//检验系列的选项开关
		//不再开放其它的(x7y)，一方面它不是直接所需的接口，另一方面，通过x2y系列的接口可以等价地实现
    	("m7hw", po::value< std::string >(), "check: hardware string with current machine")
    	("m7lic", po::value< std::string >(), "check: license string with current machine")
	;
	
	po::variables_map vm;
	po::store(po::parse_command_line(argc, argv, desc), vm);
	po::notify(vm);

	if (vm.count("help")) {
		desc.print(std::cout);
	    std::exit(EXIT_SUCCESS);
	} else if (vm.count("version")) {
		std::cout << "inly_tool 1.0.0" << std::endl;
		std::exit(EXIT_SUCCESS);
	} else if (vm.count("m2raw")) {
		int iRet = m2raw();
		std::exit(iRet);
	} else if (vm.count("m2hw")) {
		int iRet = m2hw();
		std::exit(iRet);
	} else if (vm.count("m2lic")) {
		int iRet = m2lic();
		std::exit(iRet);
	} else if (vm.count("raw2hw")) {
		int iRet = raw2hw(vm["raw2hw"].as< std::string >());
		std::exit(iRet);
	} else if (vm.count("raw2lic")) {
		int iRet = raw2lic(vm["raw2lic"].as< std::string >());
		std::exit(iRet);
	} 
	
	return (0);

}

/*
在main函数还未增加选项开关之前的相关测试代码片断

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

*/
