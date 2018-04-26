// reed entry point and event loop
//
// primary author: Allison Bianchi
//
// See LICENSE for use and distribution

#include "buffer.h"
#include "localTextFile.h"

#include <iostream>
#include <sstream>
#include <string>
#include <vector>

#include <stdio.h>

void eventLoop()
{
    std::string cmd;

    while (1) {
        // Read input
        printf("reed@ ");
        std::getline(std::cin, cmd);

        // Tokenize command
        std::vector<std::string> toks;
        std::string tok;
        std::stringstream cmdStream(cmd);
        while (not cmdStream.eof()) {
            cmdStream >> tok;
            if (not tok.empty()) {
                toks.push_back(tok);
            }
        }

        // Execute
        if (toks.empty()) {
            continue;
        }

        const std::string& top = toks[0];

        if (top == "q" or top == "quit") {
            printf("go with god\n");
            return;
        }
        else if (top == "about") {
            printf("\n");
            printf("reed is a ridiculously extensible editor\n");
            printf("\n");
        }
        else if (top == "dump") {
            if (toks.size() < 2) {
                printf("usage: dump FILENAME\n");
                continue;
            }

            const std::string& filename = toks[1];
            LocalTextFile* f = LocalTextFile::createNew(filename);
            if (f->valid()) {
                Buffer buf(f);
                if (not buf.empty()) {
                    printf("%s", buf.data().c_str());
                }
                else {
                    printf("[no data]\n");
                }
            }
            else {
                printf("Failed to open '%s'\n", filename.c_str());
            }

            delete f;
        }
        else {
            printf("Dubious: '%s'\n", cmd.c_str());
            printf("\n");
        }
    }
}

int main(int argc, char** argv)
{
    eventLoop();
    return 0;
}

