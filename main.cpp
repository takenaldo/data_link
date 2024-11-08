#include<iostream>
// #include<zmq.hpp>
#include<iostream>
#include <typeindex>
#include <typeinfo>
#include<vector>
#include<variant>

#include "TowerSender.h"


#include "DownLinkMessages/Affirm.cpp"
#include "DownLinkMessages/Negative.cpp"
#include "DownLinkMessages/Roger.cpp"
#include "DownLinkMessages/Standby.cpp"
#include "DownLinkMessages/Wilco.cpp"
#include "DownLinkMessages/Unable.cpp"
#include "Uplink/ExpectLevel.cpp"

int main(){
    zmq::context_t ctx(1);

    std::string config_ip = "tcp://*:5556";
    TowerSender t1(config_ip, ctx, zmq::socket_type::push);
    t1.send("Up Link LOGON Response");
    t1.close();
    return 0;

    
    um::acknowledgement::ExpectLevel upLinkExpectlevel{11200};

    // upLinkExpectlevel.setLevel(21);

    // std::cout<<"\nUrgency: "<<upLinkExpectlevel.getUrgency();
    // std::cout<<"\nAlert: "<<upLinkExpectlevel.getAlert();

    // std::cout<<"\n\n>> Message: "<<upLinkExpectlevel.getMessage();
    // std::cout<<"\n\n>> Message Group: "<<upLinkExpectlevel.getMessageGroup();


    // std::cout<<"\n\n>> Message Category: "<<wilco.getTypeInfo()<< "message group: "<< wilco.getMessageGroup();

    // std::cout<<"\nEXPECT ID: "<<std::to_string(upLinkExpectlevel.getID())<<"\n====";
    // std::cout<<"\nWILCO  ID: "<<std::to_string(wilco.getID())<<"\n====";



    dm::response::Wilco wilco;
    dm::response::Affirm affirm;
    dm::response::Negative negative;
    dm::response::Roger roger;
    dm::response::Standby standby;
    dm::response::Unable unable;

    std::cout<<"\n\n>> Affirm   Message: "<<affirm.getMessage()<<" REQ: " <<std::to_string(affirm.getPermittedResponseGroup().isResponseRequired());
    std::cout<<"\n\n>> Negative Message: "<<negative.getMessage()<<" REQ: " <<std::to_string(negative.getPermittedResponseGroup().isResponseRequired());
    std::cout<<"\n\n>> Roger    Message: "<<roger.getMessage()<<" REQ: " <<std::to_string(roger.getPermittedResponseGroup().isResponseRequired());
    std::cout<<"\n\n>> StandBy  Message: "<<standby.getMessage()<<" REQ: " <<std::to_string(standby.getPermittedResponseGroup().isResponseRequired());
    std::cout<<"\n\n>> Unable   Message: "<<unable.getMessage()<<" REQ: " <<std::to_string(unable.getPermittedResponseGroup().isResponseRequired());
    std::cout<<"\n\n>> Wilco    Message: "<<wilco.getMessage()<<" REQ: " <<std::to_string(wilco.getPermittedResponseGroup().isResponseRequired());


    std::cout<<"\n\n\n\n>> Expect Message: "<<upLinkExpectlevel.getPermittedResponseGroup().getPrecedence()<<" REQ: " <<std::to_string(upLinkExpectlevel.getPermittedResponseGroup().isResponseRequired());
    std::cout<<"\n\n\n\n>> Expect Message: "<<upLinkExpectlevel.getPermittedResponseGroup().getResponses().size();


    std::cout<<"\n"<<std::to_string((wilco.getPermittedResponses()).size())<<"\n\n";
    std::vector<std::type_index> classTypes = upLinkExpectlevel.getPermittedResponses();

    // Variable to check
    dm::response::Roger var;

    bool is_permitted = upLinkExpectlevel.isResponsePermitted(typeid(var));



    
    
    return 0;

}

