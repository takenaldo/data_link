#ifndef AIRCRAFT_H
#define AIRCRAFT_H

#include <iostream>
#include <string>
#include <zmq.hpp>

#include "MockDownlinkSender.h"
#include "MockUplinkReceiver.h"
#include "DataLinkMessage.h"
#include "AircraftReceiver.h"

class Aircraft {
/*
*/
private:
    std::string sender_ip = "tcp://*:5555";
    std::string receiver_ip = "tcp://localhost:5556";
    // connector reciver 
    zmq::context_t sender_ctx;
    zmq::socket_t sender_socket;
    zmq::context_t receiver_ctx;
    zmq::socket_t receiver_socket;

public:
    std::string identification;
    std::string registeration; //// i edited the name
    std::string aircraft_address;
    std::string departure;
    std::string destination;

    Aircraft ();
    Aircraft (
        std::string identification, // code assigned by the operator eg. Ethiopian Airline
        std::string registration, // code assigned to the aircraft by the ANSP, eg: Ethiopian civil aviation authority
        std::string address, // a unique code assigned to the transponder in the aircraft by ICAO
        std::string departure,
        std::string destination
    );


    void send(std::string);
    void send(DataLinkMessage );
    void startReceiving();
    void startResponse();

    
};


#endif

