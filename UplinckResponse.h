#ifndef UPLINKRESPONSE_H
#define UPLINKRESPONSE_H

#include <string>
#include "DataLinkMessage.h"

class UplinkResponse : public DataLinkMessage
{
public:
    std::string MessageElement;
    URGANCY::Type URGANCYency;
    ALRT::Type alert;
    UplinkResponse(const std::string &mesg);
    ~UplinkResponse();

    void displayResponseDetails();
    std::string toString();
    void assignID();
};

#endif