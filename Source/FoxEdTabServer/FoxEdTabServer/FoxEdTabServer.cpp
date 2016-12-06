// FoxEdTabServer.cpp : Definiert den Einstiegspunkt für die Konsolenanwendung.
//

#include "stdafx.h"
#include "NetworkServer.h"
#include "Keyboard.h"
#include "SettingsLoader.h"

int main()
{
	NetworkServer *server = new NetworkServer();
	Keyboard keyboard;
	server->initialiseServer();

	while (true)
		{
		char msg = server->waitForIncomingKey();
		if (msg == 0x1F)	//Connection timed out
			{
			std::cout << "Connection timed out. Waiting for new connection.." << std::endl;
			delete server;

			server = new NetworkServer();
			server->initialiseServer();
			}
		else keyboard.presskeyFromNetworkMessage(msg);
		}
	
	delete server;
	return 0;

}

