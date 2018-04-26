// reed test suite
//
// primary author: Allison Bianchi
//
// See LICENSE for use and distribution

#include "localTextFile.h"
#include "buffer.h"

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

    //--
    // LocalTextFile
    LocalTextFile* doc = LocalTextFile::createNew("../data/bogus.md");
    ASSERT(not doc->valid(), "Fail to open bogus text file");
    ASSERT(doc->filename() == std::string(), "Invalid document has no filename");

    doc = LocalTextFile::createNew("../data/test.md");
    ASSERT(doc and doc->valid(), "Succeed to open legit text file");
    ASSERT("../data/test.md" == doc->filename(),
           "Document remembers filename");

    delete doc;
    doc = 0;
    //--

    //--
    // Buffer
    Buffer buf(0);
    ASSERT(buf.empty(), "Buffer from invalid file is empty");
    ASSERT(buf.data().empty(), "Empty buffer has no data");

    doc = LocalTextFile::createNew("../data/test.md");
    buf = Buffer(doc);
    ASSERT(buf.data() == "These violent delights have violent ends.\n",
           "Simple data read case");

    delete doc;
    doc = 0;
    //--

    // TODO More tests!

    // All done
    assertReport();
    return assertAllPassed() ? 0 : 1;
}
//--

