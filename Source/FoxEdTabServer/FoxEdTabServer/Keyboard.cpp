#include "stdafx.h"
#include "Keyboard.h"


Keyboard::Keyboard()
{

}


Keyboard::~Keyboard()
{
}


void Keyboard::pressKey(char key)
{
	INPUT inp;
	inp.type = INPUT_KEYBOARD;
	inp.ki.dwFlags = KEYEVENTF_SCANCODE;
	Sleep(100);
	inp.ki.wScan = key;      
	SendInput(1, &inp, sizeof(INPUT));

	Sleep(100);
	
	inp.ki.dwFlags |= KEYEVENTF_KEYUP;      
	SendInput(1, &inp, sizeof(INPUT));
}

void Keyboard::presskeyFromNetworkMessage(char _msg)
{
	int msg = _msg  - '0';
	if (msg == NetworkMessage::HELLO);	//Dont do anything here
	else if (msg == NetworkMessage::CHAFF)		pressKey(settings.getKey(msg));
	else if (msg == NetworkMessage::HEAT)		pressKey(settings.getKey(msg));
	else if (msg == NetworkMessage::LASTWAY)	pressKey(settings.getKey(msg));
	else if (msg == NetworkMessage::HIGHWAKE)	pressKey(settings.getKey(msg));
	else if (msg == NetworkMessage::LOWWAKE)	pressKey(settings.getKey(msg));
	}
