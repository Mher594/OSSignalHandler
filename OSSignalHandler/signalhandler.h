#ifndef SIGNALHANDLER_H
#define SIGNALHANDLER_H

#include <stdexcept>
#include <string>

using std::runtime_error;

class SignalException : public runtime_error
{
public:
    SignalException(const std::string& message) :
        std::runtime_error(message)
    {}

}; // SignalException class


class SignalHandler
{
public:
    static void setupSignalHandlers();
    static void exitSignalHandler(int err_code);
    static std::string error_message(int err_code);

}; // SignalHandler class

#endif // SIGNALHANDLER_H
