#pragma once
#include <iostream>
#include <fstream>
#include <string>

class SettingsLoader


{
public:
	SettingsLoader();
	~SettingsLoader();
	char getKey( int networkMessage);
	
private:
	void generateActualDirectXKeys();
	
	char keys[6];
	int KeyArrayLength;
};

