#ifndef uplink_expect_level
#define uplink_expect_level

#include <iostream>
#include <typeindex>
#include <typeinfo>
#include <vector>
#include <variant>

#include "../Uplink/PermittedResponseGroup.cpp"
#include "../UpLinkMessage.h"

#include "../PRG.cpp"

namespace um::acknowledgement
{

    class ExpectLevel : public UpLinkMessage
    {

    private:
        int m_level;

        std::vector<std::variant<int, float, double, std::string>> m_initializePhrases()
        {
            return {"EXPECT", m_level};
        }

    public:
        bool responseRequired = true;

        ExpectLevel(int lvl) : m_level(lvl),
                               UpLinkMessage(
                                   6,
                                   Alert::LOW_ALERT,
                                   Urgency::URGENT,
                                   UM::MessageGroup::VERTICAL_CLEARANCE,
                                   PermittedResponseGroup(5, uplink::permitted_response_group::GROUP_ROGER, false))
        {
            setMessage(buildMessage(m_initializePhrases()));
        }

        void setLevel(int level)
        {
            m_level = level;
            setMessage(buildMessage(m_initializePhrases()));
        }
    };
}

#endif