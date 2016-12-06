#pragma once

#include <winsock2.h>
#include <Windows.h>
#include <stdio.h> 
#include <iostream>
#include "NetworkMessage.h"
#pragma comment (lib, "Ws2_32.lib")
#pragma comment (lib, "Mswsock.lib")
#pragma comment (lib, "AdvApi32.lib")
#define DEFAULT_BUFFER_LENGTH	512

class NetworkServer
{
public:
	NetworkServer();
	~NetworkServer();

	void initialiseServer();
	char waitForIncomingKey();

private:
	SOCKET serverSocket;
	SOCKET connectedSocket;
};

