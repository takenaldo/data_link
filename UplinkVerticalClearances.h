#ifndef UPLINKRESPONSE_H
#define UPLINKRESPONSE_H

#include <string>
#include "DataLinkMessage.h"

class UplinkVerticalClearances : public DataLinkMessage
{
public:
    std::string message_element;
    URG::Type urgency;
    ALRT::Type alert;
    UplinkVerticalClearances(const std::string &mesg);
    ~UplinkVerticalClearances();

    void displayClearanceDetails();
    std::string toString();
    void assignID();
};

#endif