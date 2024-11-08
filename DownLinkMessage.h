#ifndef DOWNLINK_MESSAGE_H
#define DOWNLINK_MESSAGE_H

#include "DataLinkMessage.h"

namespace dm{
    enum MessageGroup {
        RESPONSE = 1,
        VERTICAL_REQUEST,
        LATERAL_OFFSET_REQUEST,
        SPEED_REQUEST ,
        VOICE_CONTACT_REQUEST,
        ROUTE_MODIFICATION_REQUEST,
        REPORT,
        NEGOTIATION_REQUEST,
        EMERGENCY_AND_URGENT,
        SYSTEM_MANAGEMENT_MESSAGE,
        ADDITIONAL_MESSAGE,
        NEGOTIATION_RESPONSE
    };


}


class DownLinkMessage: public DataLinkMessage{

private:
    dm::MessageGroup m_messageGroup;

public:
    std::string messageType = MessageCategory::DOWNLINK_MESSAGE;

    dm::MessageGroup getMessageGroup(){ return m_messageGroup;}

    DownLinkMessage(int id, Alert alert, Urgency urgency, dm::MessageGroup messageGroup, PermittedResponseGroup prg):
        DataLinkMessage(MessageCategory::DOWNLINK_MESSAGE, id ,alert, urgency, prg ),
        m_messageGroup(messageGroup)
          {}
};


#endif