#define uplink_negative
#define uplink_negative

#include<iostream>
#include<typeindex>
#include<typeinfo>
#include<vector>
#include<variant>


#include "../Uplink/PermittedResponseGroup.cpp"
#include "../UpLinkMessage.h"


#include "../PRG.cpp"

namespace um::acknowledgement{

class Negative: public UpLinkMessage{
    
private:

        std::vector<std::variant<int, float, double, std::string>>  m_initializePhrases(){
            return {"NEGATIVE"};
        }




public:
    bool responseRequired = true;


    Negative():
        UpLinkMessage(
            5, 
            Alert::LOW_ALERT, 
            Urgency::NORMAL, 
            UM::MessageGroup::ACKNOWLEDGEMENT, 
            PermittedResponseGroup(5, uplink::permitted_response_group::GROUP_NO, false ) 
        )
 
    {
        setMessage(buildMessage(m_initializePhrases()));
    }
};

}
