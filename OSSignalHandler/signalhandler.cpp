#include <csignal>

#include "signalhandler.h"

/**
* Sets exit signal to true.
* Sends crash report to server.
*/
void SignalHandler::exitSignalHandler(int err_code)
{
        std::string msg = error_message(err_code);
        throw SignalException(msg);
}

/**
* Prepare Error report for err_code
* and return QByteArrya of json object
*/
std::string SignalHandler::error_message(int err_code)
{
    std::string err_code_str = "Process terminated with ";
    switch (err_code) {
    case -1:
        err_code_str += "ASSERTION";
        break;
    case SIGFPE:
        err_code_str += "SIGFPE";
        break;
    case SIGSEGV:
        err_code_str += "SIGSEGV";
        break;
    case SIGILL:
        err_code_str += "SIGILL";
        break;
    case SIGABRT:
        err_code_str += "SIGABRT";
        break;
    case SIGINT:
        err_code_str += "SIGINT";
        break;
    case SIGTERM:
        err_code_str += "SIGTERM";
        break;
    default:
        err_code_str += std::string("UNKNOWN - ERR_CODE : ") /*+ QString::number(err_code);*/;
        break;
    }
    err_code_str += " signal";
    
	return err_code_str;
}

/**
* Set up the signal handlers.
*/
void SignalHandler::setupSignalHandlers()
{
    signal((int) SIGFPE, SignalHandler::exitSignalHandler); // floating point exception
    signal((int) SIGSEGV, SignalHandler::exitSignalHandler); // segment violation
    signal((int) SIGILL, SignalHandler::exitSignalHandler); // illegal instruction - invalid function image
    signal((int) SIGABRT, SignalHandler::exitSignalHandler); // abnormal termination triggered by abort call
    signal((int) SIGINT, SignalHandler::exitSignalHandler); // interrupt
    signal((int) SIGTERM, SignalHandler::exitSignalHandler); // Software termination signal from kill
	signal((int) SIGBREAK, SignalHandler::exitSignalHandler); // Ctrl-Break sequence
}
