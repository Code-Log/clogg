#ifndef CLOGG_LOGGER_H
#define CLOGG_LOGGER_H

#pragma once

#include <vector>
#include <functional>

enum LogLevel {

    INFO = 0,
    WARN,
    ERR,
    DEBUG

};

namespace clogg {

    class Logger {
    friend class FileWriter;

    private:
        Logger();
        int m_LogLevel = 0;
        std::vector<const char*> m_LogLines;
        static Logger s_Instance;
        std::vector<std::function<void(int, const char*)>> m_Callbacks;

    public:
        Logger(const Logger&) = delete;
        void setLogLevel(int logLevel);
        void logString(const char* msg);
        void logString(int logLevel, const char* msg);
        void logFormat(int logLevel, const char* fMsg, ...);

        void addLogListener(std::function<void(int, const char*)> func);

        static Logger& getLogger();
        static const char* getLogLevelString(int logLevel);

    };

}

#endif
