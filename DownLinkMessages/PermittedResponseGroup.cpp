#ifndef DOWN_PERMITTED_RESPONSE_GROUP_CPP
#define DOWN_PERMITTED_RESPONSE_GROUP_CPP

#include <typeindex>
#include <typeinfo>
#include <variant>
#include <vector>

#include "../PRG.cpp"


namespace downlink::permitted_responses{
    const std::vector<std::type_index> GROUP_YES = {};
    const std::vector<std::type_index> GROUP_NO = {};


class YesGroup : PermittedResponseGroup{
public:
    YesGroup(): 
        PermittedResponseGroup(
            1,
            {},
            true
        )
    {}
};

class NoGroup : PermittedResponseGroup{
public:
    NoGroup(): 
        PermittedResponseGroup(
            2,
            {},
            false
        )
    {}
};

}
#endif
