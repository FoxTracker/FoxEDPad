#include "stdafx.h"
#include "NetworkMessage.h"


const std::string NetworkMessage::APPLICATION_NETWORK_CONSTANT = "FoxEdPad:";
const int NetworkMessage::HELLO = 0;
const int NetworkMessage::CHAFF = 1;
const int NetworkMessage::HEAT = 2;
const int NetworkMessage::LASTWAY = 3;
const int NetworkMessage::HIGHWAKE = 4;
const int NetworkMessage::LOWWAKE = 5;


NetworkMessage::NetworkMessage()
{
}


NetworkMessage::~NetworkMessage()
{
}
