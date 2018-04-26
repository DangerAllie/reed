// Local text file loading and manipulation object
//
// primary author: Allison Bianchi
//
// See LICENSE for use and distribution

#include <stdio.h>
#include "localTextFile.h"

LocalTextFile::LocalTextFile(const std::string& filename)
    : m_filename(filename)
{
    _refresh();
}

LocalTextFile::~LocalTextFile()
{
}

const std::string&
LocalTextFile::filename()
{
    return m_filename;
}

const std::string&
LocalTextFile::rawText()
{
    return m_text;
}

/* static */
LocalTextFile*
LocalTextFile::createNew(const std::string& filename)
{
    return new LocalTextFile(filename);
}

