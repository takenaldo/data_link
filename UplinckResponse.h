#ifndef UPLINKRESPONSE_H
#define UPLINKRESPONSE_H

#include <string>
#include "DataLinkMessage.h"

class UplinkResponse : public DataLinkMessage
{
public:
    std::string message_element;
    URG::Type urgency;
    ALRT::Type alert;
    UplinkResponse(const std::string &mesg);
    ~UplinkResponse();

    void displayResponseDetails();
    std::string toString();
    void assignID();
};

#endif