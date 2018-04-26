// reed entry point and event loop
//
// primary author: Allison Bianchi
//
// See LICENSE for use and distribution

#include "buffer.h"
#include "localTextFile.h"

#include <iostream>
#include <string>

#include <stdio.h>

void eventLoop()
{
    std::string cmd;

    while (1) {
        printf("reed@ ");
        std::getline(std::cin, cmd);

        if (cmd == "q" or cmd == "quit") {
            return;
        }
        else if (cmd == "about") {
            printf("\n");
            printf("reed is a ridiculously extensible editor\n");
            printf("\n");
        }
        else if (cmd == "dump") {
            LocalTextFile* f = LocalTextFile::createNew("../data/test.md");
            printf("%s\n", Buffer(f).data().c_str());
            delete f;
        }
        else if (not cmd.empty()) {
            printf("Unknown: '%s'\n", cmd.c_str());
            printf("\n");
        }
    }
}

int main(int argc, char** argv)
{
    eventLoop();
    return 0;
}

