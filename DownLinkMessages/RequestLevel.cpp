#ifndef downlink_request_level
#define downlink_request_level

#include <iostream>
#include <typeindex>
#include <typeinfo>
#include <vector>
#include <variant>

#include "../DownLinkMessage.h"
#include "../DownLinkMessages/PermittedResponseGroup.cpp"

namespace dm::vertical_request
{

class RequestLevel: public DownLinkMessage {

private:
    int m_level;
    std::vector<std::variant<int, float, double, std::string>> m_initializePhrases()
    {
        return {"REQUEST",m_level};
    }
public:

    RequestLevel(int lvl): m_level(lvl),
        DownLinkMessage(
            6, 
            Alert::LOW_ALERT,
             Urgency::NORMAL, 
             dm::MessageGroup::VERTICAL_REQUEST, 
             PermittedResponseGroup(1, downlink::permitted_responses::GROUP_YES, true)
        )
    {
        setMessage(buildMessage(m_initializePhrases()));
    }

    int getLevel(){
        return m_level;
    }

    void setLevel(int lvl){
        m_level = lvl;
        setMessage(buildMessage(m_initializePhrases()));
    }


};


}

#endif