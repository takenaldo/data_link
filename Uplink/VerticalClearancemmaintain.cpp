#ifndef VERTICAL_CLEARANCE_MAINTAIN
#define VERTICAL_CLEARANCE_MAINTAIN 

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
 class VerticalClearancemmaintain: public UpLinkMessage{
    
private:

        std::vector<std::variant<int, float, double, std::string>>  m_initializePhrases(){
            return {"MAINTAIN"};
        }
public:
    bool responseRequired = true;


    EXPECT():
        UpLinkMessage(
            19, 
            Alert:: MEDIUM, 
            Urgency:: NORMAL, 
            UM::MessageGroup::VERTICAL_CLEARANCE,
            PermittedResponseGroup(1, uplink::permitted_response_group::GROUP_WILCO_UNABLE, true)



        )
    {
        setMessage(buildMessage(m_initializePhrases()));
    }
};

}

#endif        
 
