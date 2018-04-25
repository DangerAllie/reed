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
}

LocalTextFile::~LocalTextFile()
{
}

const std::string&
LocalTextFile::getFilename()
{
    return m_filename;
}

/* static */
LocalTextFile*
LocalTextFile::createNew(const std::string& filename)
{
    return new LocalTextFile(filename);
}

