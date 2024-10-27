#ifndef UPLINKRESPONSE_H
#define UPLINKRESPONSE_H

#include <string>
#include "DataLinkMessage.h"

class UplinkSystemManagementMessages : public DataLinkMessage
{
public:
    std::string message_element;
    URG::Type urgency;
    ALRT::Type alert;
    UplinkSystemManagementMessages(const std::string &mesg);
    ~UplinkSystemManagementMessages();

    void displayManagementDetails();
    std::string toString();
    void assignID();
};

#endif
