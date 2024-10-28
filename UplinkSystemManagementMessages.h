#ifndef UPLINKRESPONSE_H
#define UPLINKRESPONSE_H

#include <string>
#include "DataLinkMessage.h"

class UplinkSystemManagementMessages : public DataLinkMessage
{
public:
    std::string MessageElement;
    URGENCY::Type URGENCYency;
    ALRT::Type alert;
    UplinkSystemManagementMessages(const std::string &mesg);
    ~UplinkSystemManagementMessages();

    void displayManagementDetails();
    std::string toString();
    void assignID();
};

#endif
