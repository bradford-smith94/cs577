/* Bradford Smith (bsmith8)
 * CS 577 Lab 2 writeOutput.cpp
 * 09/24/2015
 * "I pledge my honor that I have abided by the Stevens Honor System."
 */

#include "cracker.h"

void writeOutput()
{
    std::ofstream file;
    int i;

#ifdef DEBUG
    printDebug((char*)"opening output file");
#endif
    file.open(gl_env.resultFile.c_str());

    for (i = 0; i < gl_env.passwordList.size(); i++)
    {
        if (!gl_env.passwordList.at(i).plaintext.empty())
        {
            file << gl_env.passwordList.at(i).rawLine
                << "\t" << gl_env.passwordList.at(i).plaintext
                << "\n";
        }
    }

#ifdef DEBUG
    printDebug((char*)"closing output file");
#endif
    file.close();
}
