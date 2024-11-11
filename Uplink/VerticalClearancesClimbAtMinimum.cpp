#ifndef VERTICAL_CLEARANCE_STOP_CLIMB
#define VERTICAL_CLEARANCE_STOP_CLIMB

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
 class VerticalClearancesClimbAtMinimum : public UpLinkMessage{
    
private:

        std::vector<std::variant<int, float, double, std::string>>  m_initializePhrases(){
            return {" CLIMB AT MINIMUM"};
        }
public:
    bool responseRequired = true;


    EXPECT():
        UpLinkMessage(
            171, 
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
 
