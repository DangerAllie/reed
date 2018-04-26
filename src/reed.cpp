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
        // Prompt and read input
        printf("reed@ ");

        if (not std::getline(std::cin, cmd)) {
            // User ctrl-d'd, newline so quit messages get formatted
            // properly and falsify a quit command for the logic below
            printf("\n");
            cmd = "quit";
        }

        // Tokenize command
        std::vector<std::string> toks;
        std::string tok;
        std::stringstream tokstream(cmd);
        while (not tokstream.eof()) {
            tokstream >> tok;
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
            return;
        }
        else if (top == "about") {
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

    printf("go with god\n");
    return 0;
}

