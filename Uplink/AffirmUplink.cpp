#ifndef uplink_affirm
#define uplink_affirm

#include<iostream>
#include <typeindex>
#include <typeinfo>
#include<vector>
#include<variant>

#include "../Uplink/PermittedResponseGroup.cpp"
#include "../UpLinkMessage.h"


namespace um::acknowledgement{

class AffirmUplink: public UpLinkMessage{
    
private:

        std::vector<std::variant<int, float, double, std::string>>  m_initializePhrases(){
            return {"AFFIRM"};
        }

public:
    bool responseRequired = true;


    AffirmUplink():
        UpLinkMessage(
            6, 
            Alert::LOW_ALERT, 
            Urgency::URGENT, 
            UM::MessageGroup::ACKNOWLEDGEMENT,
            PermittedResponseGroup(3, uplink::permitted_response_group::GROUP_ROGER, true)



        )
    {
        setMessage(buildMessage(m_initializePhrases()));
    }
};

}

#endif