// internal structure/API for loaded documents
//
// primary author: Allison Bianchi
//
// See LICENCE for use and distribution

#ifndef BUFFER_H
#define BUFFER_H

#include <string>

class LocalTextFile;

class Buffer
{
public:
    Buffer(LocalTextFile*);
    ~Buffer();

    const std::string& data() const;

private:
    std::string m_data;
};

#endif

