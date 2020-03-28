#include <iostream>
#include <clogg/logger.h>
#include <clogg/writer.h>

int main () {

    clogg::Logger& logger = clogg::Logger::getLogger();
    logger.logFormat(LogLevel::ERR, "Hi %i you sly bastard, meet %s.", 13, "Jaco");

    clogg::FileWriter fw = clogg::FileWriter("test.log");
    fw.write();

}