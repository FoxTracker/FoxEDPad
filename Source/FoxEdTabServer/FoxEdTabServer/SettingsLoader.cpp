#include "stdafx.h"
#include "SettingsLoader.h"



SettingsLoader::SettingsLoader()
{
	KeyArrayLength = sizeof(keys) / sizeof(keys[0]);
	keys[0] = 0;
	std::ifstream myfile;
	myfile.open("keys.config", std::ios::in);
	
	std::string line;
	int arrayCounter = 1;	//Array starts with 1, since 0 is hello and is not an actual key
	if (myfile.is_open()) 
		{
		while (getline(myfile, line))
			{
			if (line[0] == '/');	//Ignore this line
			else
				{
				//std::cout << line << std::endl;	//debug only
				if (arrayCounter < KeyArrayLength) keys[arrayCounter] = line[0];
				arrayCounter++;
				}
			}
		}
	else std::cout << "Error on open of config file. Please check if it exists" << std::endl;
		
	myfile.close();

	generateActualDirectXKeys();
}


SettingsLoader::~SettingsLoader()
{
}

char SettingsLoader::getKey(int networkMessage)
{
	if (networkMessage < KeyArrayLength) return keys[networkMessage];
	else return '0';
}

void SettingsLoader::generateActualDirectXKeys()
{
for (int i = 1; i < KeyArrayLength; i++)	//start with index 1, since index 0 = 0;
	{
	char tmpKey = keys[i];
	if ((tmpKey == 'a') || (tmpKey == 'A')) keys[i] = 0x1E;			//Full List under http://www.flint.jp/misc/?q=dik&lang=en
	else if ((tmpKey == 'b') || (tmpKey == 'B')) keys[i] = 0x30;
	else if ((tmpKey == 'c') || (tmpKey == 'C')) keys[i] = 0x2E;
	else if ((tmpKey == 'd') || (tmpKey == 'D')) keys[i] = 0x20;
	else if ((tmpKey == 'e') || (tmpKey == 'E')) keys[i] = 0x12;
	else if ((tmpKey == 'f') || (tmpKey == 'F')) keys[i] = 0x21;
	else if ((tmpKey == 'g') || (tmpKey == 'G')) keys[i] = 0x22;
	else if ((tmpKey == 'h') || (tmpKey == 'H')) keys[i] = 0x23;
	else if ((tmpKey == 'i') || (tmpKey == 'I')) keys[i] = 0x17;
	else if ((tmpKey == 'j') || (tmpKey == 'J')) keys[i] = 0x24;
	else if ((tmpKey == 'k') || (tmpKey == 'K')) keys[i] = 0x25;
	else if ((tmpKey == 'l') || (tmpKey == 'L')) keys[i] = 0x26;
	else if ((tmpKey == 'm') || (tmpKey == 'M')) keys[i] = 0x32;
	else if ((tmpKey == 'n') || (tmpKey == 'N')) keys[i] = 0x31;
	else if ((tmpKey == 'o') || (tmpKey == 'O')) keys[i] = 0x18;
	else if ((tmpKey == 'p') || (tmpKey == 'P')) keys[i] = 0x19;
	else if ((tmpKey == 'q') || (tmpKey == 'Q')) keys[i] = 0x10;
	else if ((tmpKey == 'r') || (tmpKey == 'R')) keys[i] = 0x13;
	else if ((tmpKey == 's') || (tmpKey == 'S')) keys[i] = 0x1F;
	else if ((tmpKey == 't') || (tmpKey == 'T')) keys[i] = 0x14;
	else if ((tmpKey == 'u') || (tmpKey == 'U')) keys[i] = 0x16;
	else if ((tmpKey == 'v') || (tmpKey == 'V')) keys[i] = 0x2F;
	else if ((tmpKey == 'w') || (tmpKey == 'W')) keys[i] = 0x11;
	else if ((tmpKey == 'x') || (tmpKey == 'X')) keys[i] = 0x2D;
	else if ((tmpKey == 'y') || (tmpKey == 'Y')) keys[i] = 0x15;
	else if ((tmpKey == 'z') || (tmpKey == 'Z')) keys[i] = 0x2C;
	else std::cout << "Error in config file. Please only edit with letters from a-z" << std::endl;










	}



}

