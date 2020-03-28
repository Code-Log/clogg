#include <iostream>
#include <clogg/writer.h>
#include <clogg/logger.h>
#include <utility>
#include <fstream>

namespace clogg {

    FileWriter::FileWriter(const char* path) : m_Path(path) {}

    void FileWriter::write() {

        std::ofstream fs;
        fs.open(m_Path);

        if (!fs.is_open()) {
            
            Logger::getLogger().logString(LogLevel::ERR, "Could not open file for writing log!");
            return;

        }

        std::vector<const char*>& logLines = Logger::getLogger().m_LogLines;

        for (const char* line : logLines) {
            // Every line *should* already have a \n
            fs << line;
        }

        fs.close();

    }

}