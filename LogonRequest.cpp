#include "LogonRequest.h"

LogonRequest::LogonRequest(
    int ident,
    std::string atsu,
    std::string reg,
    std::string address,
    std::string departure,
    std::string destination
){
    id = ident;
    this->atsu_icao_code = atsu;
    this->registeration = reg;
    this->aircraft_address = address;
    this->departure = departure;
    this->destination = destination;
    this->min = 1;
    this->mrn = 1;


    this->message = this->atsu_icao_code + " " +
                    this->registeration + " " + 
                    this->aircraft_address + " " + 
                    this->departure + " " + 
                    this->destination + " " + 
                    this->registeration;
}



std::string LogonRequest::toString() {
    std::string msg =  messageType + " , " + std::to_string(id) + " , "+ message;
    return msg;
}
