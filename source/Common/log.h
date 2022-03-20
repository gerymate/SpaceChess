#ifndef LOG_H
#define LOG_H

#include <string>

class Log
{
public:
    Log(const std::string& logMe = "");
    void operator()(const std::string& logMe = "") const;
    static void that(const std::string& logMe);
    static void that(const std::string& variableName, const double& variable);
    ~Log();
};

#endif // LOG_H
