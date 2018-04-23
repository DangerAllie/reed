#include <assert.h>
#include <stdio.h>

#include "localTextFile.h"

#include <string>

int main()
{
    LocalTextFile* doc = LocalTextFile::createNew("../data/test.md");

    assert(doc);
    assert("../data/test.md" == doc->getFilename());

    delete doc;
    doc = 0;

    printf("All tests PASSED\n");
    return 0;
}

