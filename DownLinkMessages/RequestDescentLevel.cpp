#ifndef request_descent_level
#define request_descent_level

#include <vector>
#include <variant>
#include <string>

#include "../DownLinkMessage.h"
#include "../DownLinkMessages/PermittedResponseGroup.cpp"

namespace dm::vertical_request{
    
class RequestDescentLevel: public DownLinkMessage
{
private: 
    int m_level;
    std::vector<std::variant<int, float, double, std::string>>  m_insializePheses()
    {
        return{"REQUEST DESCENT TO ", m_level};
    }
public:
    RequestDescentLevel(int level):
        m_level(level),
        DownLinkMessage(
            10,
            Alert::LOW_ALERT,
            Urgency::NORMAL,
            dm::MessageGroup::VERTICAL_REQUEST,
            PermittedResponseGroup(1, downlink::permitted_responses::GROUP_YES, true)
        )
    {
    setMessage(buildMessage(m_insializePheses()));
    }
    int getLevel(){
        return(m_level);
    }
    void setLevel(int level){
        m_level = level;
    setMessage(buildMessage(m_insializePheses()));
    }
};
}
#endif