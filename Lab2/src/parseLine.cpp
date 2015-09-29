/* Bradford Smith (bsmith8)
 * CS 577 Lab 2 parseLine.cpp
 * 09/23/2015
 * "I pledge my honor that I have abided by the Stevens Honor System."
 */

#include "cracker.h"

/* pre: takes in a std::string line
 * post: returns everything after the first ':' in line
 * return: a std::string containing the contents of line after the first ':'
 */
std::string parseLine(std::string line)
{
    return line.substr(line.find(":") + 1);
}
