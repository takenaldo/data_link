#ifndef VERTICAL_CLEARANCE_EXPECT
#define VERTICAL_CLEARANCE_EXPECT 

#include <iostream>
#include <typeindex>
#include <typeinfo>
#include <vector>
#include <variant>

#include "../Uplink/PermittedResponseGroup.cpp"
#include "../UpLinkMessage.h"
#include "../PRG.cpp"

namespace um::VERTICAL_CLEARANCE
{
 class VerticalClearanceExpect: public UpLinkMessage{
    
private:

        std::vector<std::variant<int, float, double, std::string>>  m_initializePhrases(){
            return {"EXPECT"};
        }
public:
    bool responseRequired = true;


    EXPECT():
        UpLinkMessage(
            6, 
            Alert::LOW_ALERT, 
            Urgency::LOW, 
            UM::MessageGroup::VERTICAL_CLEARANCE,
            PermittedResponseGroup(3, uplink::permitted_response_group::GROUP_ROGER, true)



        )
    {
        setMessage(buildMessage(m_initializePhrases()));
    }
};

}

#endif        
 
