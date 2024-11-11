#ifndef request_cruise_level
#define request_cruise_level

#include <vector>
#include <variant>
#include <string>

#include "../DownLinkMessage.h"
#include "../DownLinkMessages/PermittedResponseGroup.cpp"

namespace dm::vertical_request{
class RequestCruiseLevel: public DownLinkMessage
{
private:
    int m_level;
    std::vector<std::variant<int, float, double, std::string>> m_initializePhrases()
    {
        return{" REQUEST CRUISE CLIMB TO ", m_level};
    }
public:
    RequestCruiseLevel(int level):
     m_level(level),
     DownLinkMessage(
            8,
            Alert::LOW_ALERT,
            Urgency::NORMAL,
            dm::MessageGroup::VERTICAL_REQUEST,
            PermittedResponseGroup(1, downlink::permitted_responses::GROUP_YES, true)
        )
        {
            setMessage(buildMessage(m_initializePhrases()));
        }    
    int getLevel(){
        return(m_level);
    }
    void setLevel(int level){
        m_level = level;
        setMessage(buildMessage(m_initializePhrases()));
    }
};
}
#endif