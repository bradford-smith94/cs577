/* Bradford Smith (bsmith8)
 * CS 577 Lab 2 dictionary.cpp
 * 09/24/2015
 * "I pledge my honor that I have abided by the Stevens Honor System."
 */

#include "cracker.h"

/* pre: takes in a char* dictFile and assumes gl_env.passwordList has been setup
 * post: runs a dictionary attack on the passwords in gl_env.passwordList using
 *      the dictionary file provided by dictFile
 */
void dictionary(char* dictFile)
{
    std::string line;
    std::ifstream file;

#ifdef DEBUG
    printDebug((char*)"opening dictionary file");
    printDebug((char*)"[Dictionary]\tstarting...");
#endif
    file.open(dictFile);

    while (std::getline(file, line))
    {
        if (allDone())
            return;
        gl_env.passwordsGenerated++;
        checkAllPasswords(line, "Dictionary");
    } /* while */

#ifdef DEBUG
    printDebug((char*)"closing dictionary file");
#endif
    file.close();
}
