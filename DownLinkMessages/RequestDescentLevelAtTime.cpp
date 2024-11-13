#ifndef request_descent_level_at_time
#define request_descent_level_at_time
#include <vector>
#include <variant>
#include <string>

#include "../DownLinkMessage.h"
#include "../DownLinkMessages/PermittedResponseGroup.cpp"

namespace dm::vertical_request{

class RequestDescentLevelAtTime: public DownLinkMessage{
    private:
        int m_timeinminute;
        int  m_level;
        std::vector<std::variant<int, float, double, std::string>>m_intializePhrases()
        {
            return{"AT", m_timeinminute,  "REQUEST DESCENT TO", m_level};
        }
    public:
     RequestDescentLevelAtTime(int time, int level):
        m_timeinminute(time),
        m_level(level),
        DownLinkMessage(
                14,
                Alert::LOW_ALERT,
                Urgency::NORMAL,
                dm::MessageGroup::VERTICAL_REQUEST,
              PermittedResponseGroup(1, downlink::permitted_responses::GROUP_YES, true)
            )
            {
                setMessage(buildMessage(m_intializePhrases()));
            }
    int getTimeandlevel(){
        return(m_timeinminute,m_level);
    }
    void setTimeandlevel(int time, int level){
        m_timeinminute = time;
        m_level = m_level;
    }
};
}
#endif