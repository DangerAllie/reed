// Local text file loading and manipulation object
//
// primary author: Allison Bianchi
//
// See LICENSE for use and distribution

#ifndef LOCALTEXTFILE_H
#define LOCALTEXTFILE_H

#include <string>

class LocalTextFile
{
public:
    static LocalTextFile* createNew(const std::string& filename);
    ~LocalTextFile();

    const std::string& getFilename();

private:
    LocalTextFile(const std::string&);

private:
    std::string m_filename;
};

#endif

