#ifndef request_level_at_tiime
#define request_level_at_tiime
#include <string>
#include <vector>
#include <variant>

#include  "../DownLinkMessage.h"
#include "../DownLinkMessages/PermittedResponseGroup.cpp"

namespace dm::vertical_request{

class RequestLevelAtTime: public DownLinkMessage{
    private:
        int m_timinmunite;
        int m_level;
        std::vector<std::variant<int, float, double, std::string>>m_initializePhrases()
        {
            return{"AT ",m_timinmunite,"REQUEST CLIMB TO ",m_level};
        }
    public:
        RequestLevelAtTime(int time, int level):
            m_timinmunite(time),
            m_level(level),
            DownLinkMessage(
                13,
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
   int getTime(){
    return(m_timinmunite);
   }
   void setLevel(int level){
    m_level = level;
    setMessage(buildMessage(m_initializePhrases()));
   }
   void setTime(int time){
    m_timinmunite = time;
    setMessage(buildMessage(m_initializePhrases()));
   }
};
}
#endif