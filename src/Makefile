# For making
#
# primary author: Allison Bianchi
#
# See LICENSE for use and distribution

CPPs = localTextFile.cpp cursesFrontEnd.cpp buffer.cpp

reed: reed.cpp $(CPPs)
	g++ -std=c++1z -o ../bin/reed reed.cpp $(CPPs) -lstdc++ -lncurses

tests: tests.cpp $(CPPs)
	g++ -std=c++1z -o ../bin/runtests tests.cpp $(CPPs) -lstdc++ -lncurses

