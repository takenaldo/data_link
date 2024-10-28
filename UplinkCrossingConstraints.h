#ifndef UPLINKRESPONSE_H
#define UPLINKRESPONSE_H

#include <string>
#include "DataLinkMessage.h"

class UplinkCrossingConstraints : public DataLinkMessage
{
public:
    std::string MessageElement;
    URGENCY::Type URGENCYency;
    ALRT::Type alert;
    UplinkCrossingConstraints(const std::string &mesg);
    ~UplinkCrossingConstraints();

    void displaycrossingDetails();
    std::string toString();
    void assignID();
};

#endif