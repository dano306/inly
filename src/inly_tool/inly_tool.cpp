#include "CInly.h"
#include <iostream>
#include <string>

int main()
{
	CInly	Inly;
	
	//Inly.test("dano306");
	//std::cout << "hello world, dano306!" << std::endl;
	
	std::string	strHardware;
	strHardware = Inly.GetHardwareString();
	std::cout << "strHardware: " << strHardware << std::endl;

	return (0);
}
