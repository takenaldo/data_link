#ifndef UPLINKRESPONSE_H
#define UPLINKRESPONSE_H

#include <string>
#include "DataLinkMessage.h"

class UplinkResponse : public DataLinkMessage
{
public:
    std::string MessageElement;
    URGENCY::Type urgent;
    ALERT::Type alert;
    UplinkResponse(const std::string &mesg);
    ~UplinkResponse();

    void displayResponseDetails();
    std::string toString();
    void assignID();
};

#endif