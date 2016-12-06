#pragma once
#include <iostream>

class NetworkMessage
{
public:
	NetworkMessage();
	~NetworkMessage();
	static const std::string APPLICATION_NETWORK_CONSTANT;
	static const int HELLO; 
	static const int CHAFF;
	static const int HEAT;
	static const int LASTWAY;
	static const int HIGHWAKE;
	static const int LOWWAKE;


};

