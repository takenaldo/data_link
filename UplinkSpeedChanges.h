#ifndef UPLINKRESPONSE_H
#define UPLINKRESPONSE_H

#include <string>
#include "DataLinkMessage.h"

class UplinkSpeedChanges : public DataLinkMessage
{
public:
    std::string message_element;
    URG::Type urgency;
    ALRT::Type alert;
    UplinkSpeedChanges(const std::string &mesg);
    ~UplinkSpeedChanges();

    void displaySpeedDetails();
    std::string toString();
    void assignID();
};

#endif