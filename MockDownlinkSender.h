#ifndef MOCK_DOWNLINK_SENDER_H
#define MOCK_DOWNLINK_SENDER_H

#include <zmq.hpp>
#include <string>
#include <iostream>

#include "DataLinkMessage.h"

class MockDownlinkSender
{

private:



public:
    zmq::socket_t socket;
    zmq::context_t ctx;

    MockDownlinkSender(std::string url, zmq::context_t& context, zmq::socket_type type);
    ~MockDownlinkSender();

    std::string ip = "";

    void send(std::string message);
    void send(DataLinkMessage message);
    void close();

};

#endif