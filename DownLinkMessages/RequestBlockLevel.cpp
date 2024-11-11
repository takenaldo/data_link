#ifndef downlink_requuest_block_level
#define downlink_requuest_block_level

#include <vector>
#include <variant>
#include <string>

#include "../DownLinkMessage.h"
#include "../DownLinkMessages/PermittedResponseGroup.cpp"

namespace dm::vertical_request{


class RequestBlockLevel: public DownLinkMessage{
private:
    int m_initialLevel;
    int m_requestedLevel;
    std::vector<std::variant<int, float, double, std::string>> m_initializePhrases()
    {
        return{" REQUEST BLOCK ", m_initialLevel, "TO", m_requestedLevel};

    }
public:
    RequestBlockLevel(int initialLevel, int requestLevel): 
        m_initialLevel(initialLevel),
        m_requestedLevel(requestLevel),
        DownLinkMessage(
            7,
            Alert::LOW_ALERT,
            Urgency::NORMAL,dm::MessageGroup::VERTICAL_REQUEST,
            PermittedResponseGroup(1, downlink::permitted_responses::GROUP_YES, true)
        )
        {
        setMessage(buildMessage(m_initializePhrases()));
    }
        int getLevel(){
        return (m_initialLevel, m_requestedLevel);
    }
    void setLevel(int initialLevel, int requestLevel){
        m_initialLevel = initialLevel;
        m_requestedLevel = requestLevel;
        setMessage(buildMessage(m_initializePhrases()));
    }
};
}
#endif