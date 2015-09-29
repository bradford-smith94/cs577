/* Bradford Smith (bsmith8)
 * CS 577 Lab 2 parseInput.cpp
 * 09/23/2015
 * "I pledge my honor that I have abided by the Stevens Honor System."
 */

#include "cracker.h"

std::vector<struct s_password> parseInput()
{
    std::vector<struct s_password> vect;
    struct s_password temp;
    std::string line;
    std::ifstream file;

#ifdef DEBUG
    printDebug((char*)"opening input file");
#endif
    file.open(gl_env.passwordFile.c_str());

    while (std::getline(file, line))
    {
        temp.rawLine = line;
        temp.rawHash = parseLine(line);
        temp.plaintext = "";
        temp.attempted = false;
        vect.push_back(temp);
    }

#ifdef DEBUG
    printDebug((char*)"closing input file");
#endif
    file.close();

    return vect;
}
