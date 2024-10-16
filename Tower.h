#ifndef AIRCRAFT_H
#define AIRCARFT_H

#include <iostream>
#include <string>
#include <zmq.hpp>

#include "TowerSender.h"
#include "TowerReceiver.h"
#include "DataLinkMessage.h"

class Tower {
/*
*/
private:
    std::string sender_ip = "tcp://*:5556";
    std::string receiver_ip = "tcp://localhost:5555";

public:

    Tower ();

    void send(std::string);
    void send(DataLinkMessage );

    void startReceiving();

};


#endif