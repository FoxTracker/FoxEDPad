#pragma once
#define WINVER 0x0500
#include <windows.h>
#include "SettingsLoader.h"
#include "NetworkMessage.h"

class Keyboard
{
public:
	Keyboard();
	~Keyboard();
	
	void presskeyFromNetworkMessage(char msg);
	//void pressKey(char key);

private:
	SettingsLoader settings;

	void pressKey(char key);
};

