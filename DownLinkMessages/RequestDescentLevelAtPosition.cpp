
#ifndef request_descent_level_at_position
#define request_descent_level_at_position
#include <string>
#include <vector>
#include <variant>

#include  "../DownLinkMessage.h"
#include "../DownLinkMessages/PermittedResponseGroup.cpp"

namespace dm::vertical_request{

class RequestDescentLevelAtPosition: public DownLinkMessage{
    private:
        int m_level;
        int m_position;
        std::vector<std::variant<int, float, double, std::string>>m_initializePhrases()
        {
            return{"AT ", m_position, " REQUEST DESCENT TO ", m_level};
        }
    public:
    RequestDescentLevelAtPosition(int level, int position):
        m_level(level),
        m_position(position),
        DownLinkMessage(
            12,
            Alert::LOW_ALERT,
            Urgency::NORMAL,
            dm::MessageGroup::VERTICAL_REQUEST,
            PermittedResponseGroup(1, downlink::permitted_responses::GROUP_YES, true)
        )
        {
            setMessage(buildMessage(m_initializePhrases()));
        }
        int getLevelandposition(){
        return(m_level, m_position);
    }
    void setLevelandposition(int level, int position){
        m_level = level;
        m_position = position;
        setMessage(buildMessage(m_initializePhrases()));
    }   
};
}
#endif