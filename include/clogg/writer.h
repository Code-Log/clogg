#ifndef CLOGG_WRITER_H
#define CLOGG_WRITER_H

#pragma once

namespace clogg {
    
    class FileWriter {

    private:
        const char* m_Path;

    public:
        FileWriter(const char* path);
        void write();

    };

}

#endif
