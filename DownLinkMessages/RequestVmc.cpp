#ifndef  request_vmc
#define request_vmc

#include <vector>
#include <variant>
#include <string>

#include "../DownLinkMessage.h"
#include "../DownLinkMessages/PermittedResponseGroup.cpp"

namespace dm::vertical_request{

// Visual Meteorological Conditions.
class RequestVmc: public DownLinkMessage{
    private:
        std::vector<std::variant<int, float, double, std::string>>m_initilizePhrases()
        {
            return{" REQUEST VMC DESCENT"};
        }
    public:
        RequestVmc():
            DownLinkMessage(
                69,
                Alert::LOW_ALERT,
                Urgency::NORMAL,
                dm::MessageGroup::VERTICAL_REQUEST,
                PermittedResponseGroup(1, downlink::permitted_responses::GROUP_YES, true)
            )
            {
                setMessage(buildMessage(m_initilizePhrases()));
            }
};
}
#endif