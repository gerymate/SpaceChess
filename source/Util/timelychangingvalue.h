#ifndef TIMELYCHANGINGVALUE_H
#define TIMELYCHANGINGVALUE_H

#include <chrono>

namespace Util {

class TimelyChangingValue
{
    double currentValue;
    double targetValue;
    std::chrono::milliseconds changeDuration;
    double startValue;
    std::chrono::steady_clock::time_point startTime;
public:
    TimelyChangingValue(double theTargetValue, std::chrono::seconds theChangeDuration = std::chrono::seconds(1));
    operator double();
    TimelyChangingValue& operator= (double theNewTargetValue);
};

}

#endif // TIMELYCHANGINGVALUE_H
