// reed test suite
//
// primary author: Allison Bianchi
//
// See LICENSE for use and distribution

#include "localTextFile.h"

#include <stdio.h>
#include <string>

//--
// Simple assert implementation that doesn't terminate on fail
//
// TODO factor to own module or use a 3rd-party assert
static int __totalAsserts = 0;
static int __assertsFailed = 0;

#define ASSERT(cond, descr)                     \
    if ((cond)) {                               \
        printf("   PASSED .. %s\n", descr);     \
    }                                           \
    else {                                      \
        printf("!! FAILED .. %s\n", descr);     \
        ++__assertsFailed;                      \
    }                                           \
    ++__totalAsserts;                           \

bool assertAllPassed()
{
    return __assertsFailed == 0;
}

void assertReport()
{
    printf("\n");

    if (assertAllPassed()) {
        printf("All tests PASSED %d/%d\n",
               __totalAsserts, __totalAsserts);
    }
    else {
        printf("PASSED %d/%d tests\n",
               (__totalAsserts - __assertsFailed),
               __totalAsserts);
        printf("FAILED %d (%.2f%%)\n", __assertsFailed, 
               float(__assertsFailed) / (float)__totalAsserts * 100.0);
    }

    printf("\n");
}
//--

//--
// Test program

int main()
{
    printf("\n");
    printf("reed framework test suite\n");
    printf("\n");

    // Basic document tests
    LocalTextFile* doc = LocalTextFile::createNew("../data/test.md");

    ASSERT(doc, "Open text file");
    ASSERT("../data/test.md" == doc->getFilename(), "Document filename validation");

    delete doc;
    doc = 0;

    // TODO More tests!

    // All done
    assertReport();
    return assertAllPassed() ? 0 : 1;
}
//--

