#ifndef UPLINKRESPONSE_H
#define UPLINKRESPONSE_H

#include <string>
#include "DataLinkMessage.h"

class UplinkSpeedChanges : public DataLinkMessage
{
public:
    std::string MessageElement;
    URGANCY::Type URGANCYency;
    ALRT::Type alert;
    UplinkSpeedChanges(const std::string &mesg);
    ~UplinkSpeedChanges();

    void displaySpeedDetails();
    std::string toString();
    void assignID();
};

#endif