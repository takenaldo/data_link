#ifndef UPLINKRESPONSE_H
#define UPLINKRESPONSE_H

#include <string>
#include "DataLinkMessage.h"

class UplinkRoutemodifications : public DataLinkMessage
{
public:
    std::string message_element;
    URG::Type urgency;
    ALRT::Type alert;
    UplinkRoutemodifications(const std::string &mesg);
    ~UplinkRoutemodifications();

    void displayRouteDetails();
    std::string toString();
    void assignID();
};

#endif
