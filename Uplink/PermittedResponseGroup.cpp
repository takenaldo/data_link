#ifndef UP_PERMITTED_RESPONSE_GROUP_CPP
#define UP_PERMITTED_RESPONSE_GROUP_CPP

#include <string>
#include <typeindex>
#include <typeinfo>
#include<vector>
#include<variant>

#include "../PRG.cpp"

#include "../DownLinkMessages/Wilco.cpp"
#include "../DownLinkMessages/Affirm.cpp"
#include "../DownLinkMessages/Negative.cpp"
#include "../DownLinkMessages/Roger.cpp"
#include "../DownLinkMessages/Standby.cpp"
#include "../DownLinkMessages/Unable.cpp"

namespace uplink::permitted_response_group{
    const std::vector<std::type_index> GROUP_WILCO_UNABLE = {typeid(dm::response::Wilco), typeid(dm::response::Unable), typeid(dm::response::Standby)};
    const std::vector<std::type_index> GROUP_AFFIRM_NEGATIVE = {typeid(dm::response::Affirm), typeid(dm::response::Negative), typeid(dm::response::Standby)};

    const std::vector<std::type_index> GROUP_ROGER = {typeid(dm::response::Roger), typeid(dm::response::Unable), typeid(dm::response::Standby)};
    const std::vector<std::type_index> GROUP_YES = {typeid(dm::response::Wilco), typeid(dm::response::Unable), typeid(dm::response::Standby)};
    const std::vector<std::type_index> GROUP_NO = {};


class WilcoUnableGroup : PermittedResponseGroup{
public:
    WilcoUnableGroup(): 
        PermittedResponseGroup(
            1,
            {typeid(dm::response::Wilco), typeid(dm::response::Unable), typeid(dm::response::Standby)},
            true
        )
    {}
};


class AffirmNegativeGroup : PermittedResponseGroup{
public:
    AffirmNegativeGroup():
        PermittedResponseGroup(
            2,
            {typeid(dm::response::Affirm), typeid(dm::response::Negative), typeid(dm::response::Standby)},
            true
        )
    {}
};

class RogerGroup : PermittedResponseGroup{
public:
    RogerGroup(): 
        PermittedResponseGroup(
            3,
            {typeid(dm::response::Roger), typeid(dm::response::Unable), typeid(dm::response::Standby)},
            true
        )
    {}
};


class YesGroup : PermittedResponseGroup{
public:
    YesGroup(): 
        PermittedResponseGroup(
            4,
            {},
            true
        )
    {}
};

class NoGroup : PermittedResponseGroup{
public:
    NoGroup(): 
        PermittedResponseGroup(
            5,
            {},
            false
        )
    {}
};



// WilcoUnableGroup wilcoUnableGroup;

}

#endif
