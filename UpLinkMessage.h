#ifndef UPLINK_MESSSAGE_H
#define UPLINK_MESSSAGE_H

#include <typeindex>
#include <typeinfo>

#include "DataLinkMessage.h"
// #include "DownLinkMessages/Response.cpp"

// #include "DownLinkMessages/Wilco.cpp"
// #include "DownLinkMessages/Affirm.cpp"
// #include "DownLinkMessages/Negative.cpp"
// #include "DownLinkMessages/Roger.cpp"
// #include "DownLinkMessages/Standby.cpp"
// #include "DownLinkMessages/Unable.cpp"



namespace UM{
    enum MessageGroup {
        ACKNOWLEDGEMENT = 1,
        VERTICAL_CLEARANCE,
        CROSSING_CONSTRAINT,
        LATERAL_OFFSET,
        ROUTE_MODIFICATION,
        SPEED_CHANGE,
        CMS,
        REPORT_CONFIRM_REQUEST,
        NEGOTIATION_REQUEST,
        AIR_TRAFFIC_ADVISORY,
        SYSTEM_MANAGEMENT_MESSAGE,
        ADDITIONAL_MESSAGE
    };
}





class UpLinkMessage: public DataLinkMessage{

private:
    UM::MessageGroup m_messageGroup;
public:
    std::string messageType = MessageCategory::UPLINK_MESSAGE; // TODO: remove this

    UM::MessageGroup getMessageGroup(){ return m_messageGroup;}

    // UpLinkMessage(){
    //     messageType = MessageCategory::UPLINK_MESSAGE;
    // }

    UpLinkMessage(int id, Alert alert, Urgency urgency, UM::MessageGroup messageGroup, PermittedResponseGroup prg)
        :
        DataLinkMessage(MessageCategory::UPLINK_MESSAGE, id, alert, urgency, prg),
        m_messageGroup(messageGroup)
        {}


};


#endif