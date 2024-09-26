#include<iostream>
#include<zmq.hpp>

#include "TowerSender.h"


int main(){
    zmq::context_t ctx(1);

    std::string config_ip = "tcp://*:5556";
    TowerSender t1(config_ip, ctx, zmq::socket_type::push);
    // t1.start();
    t1.send("Up Link LOGON Response");
    t1.close();


    return 0;
}
   
   
    // return 0;
// }
