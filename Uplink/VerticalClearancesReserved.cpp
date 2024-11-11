#ifndef VERTICAL_CLEARANCE_RESERVED
#define VERTICAL_CLEARANCE_RESERVED

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
 class  VerticalClearancesReserved: public UpLinkMessage{
    
private:

        std::vector<std::variant<int, float, double, std::string>>  m_initializePhrases(){
            return {" CLIMB AT MINIMUM"};
        }
public:
    bool responseRequired = true;


    EXPECT():
        UpLinkMessage(
            40, 
            Alert:: LOW_ALERT, 
            Urgency:: LOW, 
            UM::MessageGroup::VERTICAL_CLEARANCE,
            PermittedResponseGroup(4, uplink::permitted_response_group::GROUP_YES, true)



        )
    {
        setMessage(buildMessage(m_initializePhrases()));
    }
};

}

#endif        
 
