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

    // FIXME constify
    const std::string& filename() const;
    const std::string& rawText() const;

private:
    LocalTextFile(const std::string&);

    void _refresh();

private:
    std::string m_filename;
    std::string m_text;
};

#endif

