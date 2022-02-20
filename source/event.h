// (C) Máté Gergely - gerymate@gmail.com
#ifndef EVENT_H
#define EVENT_H

#include<string>

class Event
{
    std::string sender, message, parameters;
public:
    Event(std::string theSender, std::string theMessage = "", std::string parameters = "");
    std::string getSender() {return sender;}
    std::string getMessage() {return message;}
    std::string getParameters() {return parameters;}
    ~Event();
};


#endif // EVENT_H
