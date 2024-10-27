#ifndef UPLINKRESPONSE_H
#define UPLINKRESPONSE_H

#include <string>
#include "DataLinkMessage.h"

class UplinkSurveillanceRequests : public DataLinkMessage
{
public:
    std::string message_element;
    URG::Type urgency;
    ALRT::Type alert;
    UplinkSurveillanceRequests(const std::string &mesg);
    ~UplinkSurveillanceRequests();

    void displaySurcillanceDetails();
    std::string toString();
    void assignID();
};

#endif