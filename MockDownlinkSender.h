#include <zmq.hpp>
#include <string>
#include <iostream>

class MockDownlinkSender
{

private:
    zmq::context_t ctx;
    zmq::socket_t socket;



public:
    MockDownlinkSender(std::string url, zmq::context_t& context, zmq::socket_type type);
    ~MockDownlinkSender();

    std::string ip = "";

    void send(std::string message);
    void close();

};

