#include "stdafx.h"
#include "NetworkServer.h"


NetworkServer::NetworkServer()
{
}


NetworkServer::~NetworkServer()
	{
	closesocket(connectedSocket);
	closesocket(serverSocket);
	WSACleanup();
	}

void NetworkServer::initialiseServer()
{
	WSADATA wsa;
	SOCKADDR_IN addr;
	int serverPort = 1800;

	int status = WSAStartup(MAKEWORD(2, 0), &wsa);
	if (status != 0) std::cout << "Error in int status = WSAStartup(MAKEWORD(2, 0), &wsa)" << std::endl;

	serverSocket = socket(AF_INET, SOCK_STREAM, 0);
	if (serverSocket == INVALID_SOCKET)
		{
		std::cout << "Error in SOCKET s = socket(AF_INET, SOCK_STREAM, 0);" << std::endl;
		}

	memset(&addr, 0, sizeof(SOCKADDR_IN));
	addr.sin_family = AF_INET;
	addr.sin_port = htons(serverPort);
	addr.sin_addr.s_addr = ADDR_ANY;
	status = bind(serverSocket, (SOCKADDR*)&addr, sizeof(SOCKADDR_IN));
	if (status == SOCKET_ERROR)
		{
		std::cout << "Error in status = bind(serverSocket, (SOCKADDR*)&addr, sizeof(SOCKADDR_IN));" << std::endl;
		}

	status = listen(serverSocket, 10);
	if (status == SOCKET_ERROR)
		{
		std::cout << "Error in status = bind(serverSocket, (SOCKADDR*)&addr, sizeof(SOCKADDR_IN));" << std::endl;
		}
	else
		{
		std::cout << "Server started.." << std::endl;
		}

	connectedSocket = accept(serverSocket, NULL, NULL);
	if (connectedSocket == INVALID_SOCKET)
		{
		std::cout << "Error in accept(serverSocket, NULL, NULL); Errorcode: " << WSAGetLastError() << std::endl;
		}
	else
		{
		std::cout << "Incoming connection.." << std::endl;
		}
	
}

char NetworkServer::waitForIncomingKey()
{
	char recvbuf[DEFAULT_BUFFER_LENGTH];
	int bytesReceived = recv(connectedSocket, recvbuf, DEFAULT_BUFFER_LENGTH, 0);
	if (bytesReceived > 0)
	{
		char msg[DEFAULT_BUFFER_LENGTH];
		//std::cout << "hab was empfangen^^" << std::endl;	//Debug only
		//std::cout << recvbuf << std::endl;	//Debug only
		std::string message(recvbuf, DEFAULT_BUFFER_LENGTH);
		if (message.find(NetworkMessage::APPLICATION_NETWORK_CONSTANT) != std::string::npos) 
			{
			return message[NetworkMessage::APPLICATION_NETWORK_CONSTANT.length()];
			}
		else std::cout << "I didnt understand the client's message. Perhaps update your program" << std::endl;
	}

	return 0x1F;
}
