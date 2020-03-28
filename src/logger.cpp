#include <iostream>
#include <sstream>
#include <cstring>
#include <cstdarg>
#include <clogg/logger.h>

namespace clogg {

    using namespace std::string_literals;

    Logger Logger::s_Instance;
    Logger::Logger() = default;
    
    Logger& Logger::getLogger() { return s_Instance; }

    void Logger::setLogLevel(int logLevel) { m_LogLevel = logLevel; }
    
    void Logger::logString(int logLevel, const char* msg) {

        if (logLevel < m_LogLevel)
            return;

        std::stringstream stream;

        stream << "[" << getLogLevelString(logLevel) << "]: " << msg << std::endl;

        // If it isn't obious, this part
        // just ensures the string stays in RAM (forever)
        std::string temp_buff = stream.str();
        char* buff = new char[temp_buff.length() + 1];
        std::strcpy(buff, temp_buff.c_str());

        m_LogLines.emplace_back(const_cast<const char*>(buff));
        std::ostream& out_stream = (logLevel >= LogLevel::ERR) ? std::cerr : std::cout;
        out_stream << temp_buff;

    }

    const char* Logger::getLogLevelString(int logLevel) {
        switch (logLevel) {
            case LogLevel::INFO:
                return "INFO";
                break;
            case LogLevel::WARN:
                return "WARN";
                break;
            case LogLevel::DEBUG:
                return "DEBUG";
                break;
            case LogLevel::ERR:
                return "ERROR";
                break;
            default:
                return "INFO";
                break;
        }
    }

    void Logger::logFormat(int logLevel, const char* fMsg, ...) {

        va_list args;
        va_start(args, fMsg);

        std::string sMsg(fMsg);
        std::stringstream stream(""); // Init empty

        int index;
        while ((index = sMsg.find("%")) != std::string::npos) {
        
            stream << sMsg.substr(0, index);

            const char* expr = sMsg.substr(index, 2).c_str();

            if (strcmp(expr, "%s") == 0) {
                stream << va_arg(args, char*);
            } else if (strcmp(expr, "%d") == 0) {
                stream << va_arg(args, double);
            } else if (strcmp(expr, "%i") == 0) {
                stream << va_arg(args, int);
            } else if (strcmp(expr, "%p") == 0) {
                stream << va_arg(args, void*);
            }

            sMsg.erase(0, index + 2);

        }

        if (sMsg.length() != 0)
            stream << sMsg;

        logString(logLevel, stream.str().c_str());

        va_end(args);

    }

    void Logger::logString(const char* msg) { logString(LogLevel::INFO, msg); }

}