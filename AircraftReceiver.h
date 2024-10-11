#include<string>
#include<iostream>
#include<zmq.hpp>

class AircraftReceiver: public zmq::socket_t
{
private:
      zmq::context_t ctx;
    zmq::socket_t socket;
public:
     AircraftReceiver(std::string url, zmq::context_t& context, zmq::socket_type type);

    std::string ip="";

    std::string recieve();
    void close();
};
