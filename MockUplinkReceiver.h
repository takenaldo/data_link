#include <zmq.hpp>
#include <string>
#include <iostream>

class MockUplinkReceiver
{

private:
    zmq::context_t ctx;
    zmq::socket_t socket;



public:
    MockUplinkReceiver(std::string url, zmq::context_t& context, zmq::socket_type type);
    // ~MockUplinkReceiver();

    std::string ip = "";

    void recieve();
    void close();

};

