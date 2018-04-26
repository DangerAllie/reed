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

static void
_tokenize(const std::string& str, std::vector<std::string>* toks)
{
    // Split str into tokens by whitespace
    std::stringstream tokstream(str);
    std::string tok;
    char c;

    while (tokstream.get(c)) {
        if (isspace(c)) {
            if (tok.empty()) {
                // Eat whitespace between tokens
                continue;
            }
            else {
                // New token
                toks->push_back(tok);
                tok.clear();
            }
        }
        else {
            // Part of the next token
            tok += c;
        }
    }

    if (tokstream.eof() and not tok.empty()) {
        // Push final token
        toks->push_back(tok);
    }
}

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

        // Parse and execute command
        std::vector<std::string> toks;
        _tokenize(cmd, &toks);
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
                printf("\n");
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
                    printf("\n");
                }
            }
            else {
                printf("Failed to open '%s'\n", filename.c_str());
                printf("\n");
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

