#ifndef UPLINKRESPONSE_H
#define UPLINKRESPONSE_H

#include <string>
#include "DataLinkMessage.h"

class UplinkConfirmationRequests : public DataLinkMessage
{
public:
    std::string MessageElement;
    URGANCY::Type URGANCYency;
    ALRT::Type alert;
    UplinkConfirmationRequests(const std::string &mesg);
    ~UplinkConfirmationRequests();

    void displayComfirmationDetails();
    std::string toString();
    void assignID();
};

#endif
