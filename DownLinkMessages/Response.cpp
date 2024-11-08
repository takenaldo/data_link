#ifndef RESPONSE_CPP
#define RESPONSE_CPP

#include<iostream>
#include<vector>
#include<variant>

#include "../DownLinkMessage.h"
#include "PermittedResponseGroup.cpp"

namespace dm{

class Response: public DownLinkMessage{
private:

public:
    bool responseRequired = false;

Response(int id): 
    DownLinkMessage(
        id,
        Alert::MEDIUM,
        Urgency::NORMAL,
        dm::MessageGroup::RESPONSE,
        PermittedResponseGroup(5, {}, false)

    )
{

}


};

}

#endif