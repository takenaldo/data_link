#ifndef UPLINKRESPONSE_H
#define UPLINKRESPONSE_H

#include <string>
#include "DataLinkMessage.h"

class UplinkNegotiationRequests : public DataLinkMessage
{
public:
    std::string MessageElement;
    URGENCY::Type URGENCYency;
    ALRT::Type alert;
    UplinkNegotiationRequests(const std::string &mesg);
    ~UplinkNegotiationRequests();

    void displayNegotiationDetails();
    std::string toString();
    void assignID();
};

#endif
