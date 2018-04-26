// internal structure/API for loaded documents
//
// primary author: Allison Bianchi
//
// See LICENCE for use and distribution

#include "buffer.h"
#include "localTextFile.h"

Buffer::Buffer(LocalTextFile* src)
{
    if (src and src->valid()) {
        m_data = src->rawText();
    }
}

Buffer::~Buffer()
{
}

bool
Buffer::empty() const
{
    return m_data.empty();
}

const std::string&
Buffer::data() const
{
    return m_data;
}

