#ifndef AIRCRAFT_H
#define AIRCARFT_H

#include <iostream>
#include <string>
#include <zmq.hpp>

#include "TowerSender.h"
#include "TowerReceiver.h"
#include "DataLinkMessage.h"

class Tower {

private:
    std::string senderIp = "tcp://*:5556";
    std::string receiverIp = "tcp://localhost:5555";

public:

    Tower ();

    void send(std::string);
    void send(DataLinkMessage );

    void startReceiving();

};


#endif