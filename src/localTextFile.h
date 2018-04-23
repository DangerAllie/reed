#ifndef LOCAL_TEXT_FILE_H
#define LOCAL_TEXT_FILE_H

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

