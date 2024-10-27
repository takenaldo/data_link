#ifndef UPLINKRESPONSE_H
#define UPLINKRESPONSE_H

#include <string>
#include "DataLinkMessage.h"

class UplinkLateralOffsets : public DataLinkMessage
{
public:
    std::string message_element;
    URG::Type urgency;
    ALRT::Type alert;
    UplinkLateralOffsets(const std::string &mesg);
    ~UplinkLateralOffsets();

    void displayOffsetDetails();
    std::string toString();
    void assignID();
};

#endif