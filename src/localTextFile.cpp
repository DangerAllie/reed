// Local text file loading and manipulation object
//
// primary author: Allison Bianchi
//
// See LICENSE for use and distribution

#include "localTextFile.h"

#include <fstream>
#include <iostream>
#include <sstream>

#include <stdio.h>

LocalTextFile::LocalTextFile(const std::string& filename)
    : m_valid(false),
      m_filename(filename)
{
    _refresh();
}

LocalTextFile::~LocalTextFile()
{
}

bool
LocalTextFile::valid() const
{
    return m_valid;
}

const std::string&
LocalTextFile::filename() const
{
    return m_filename;
}

const std::string&
LocalTextFile::rawText() const
{
    return m_text;
}

/* static */
LocalTextFile*
LocalTextFile::createNew(const std::string& filename)
{
    if (filename.empty()) {
        return 0;
    }
    else {
        return new LocalTextFile(filename);
    }
}

void
LocalTextFile::_refresh()
{
    std::ifstream f(m_filename.c_str());
    m_valid = f.is_open();

    if (m_valid) {
        std::stringstream buf;
        buf << f.rdbuf();
        f.close();
        m_text = buf.str();
    }
    else {
        m_filename.clear();
        m_text.clear();
    }
}

