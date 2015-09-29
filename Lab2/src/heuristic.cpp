/* Bradford Smith (bsmith8)
 * CS 577 Lab 2 heuristic.cpp
 * 09/24/2015
 * "I pledge my honor that I have abided by the Stevens Honor System."
 */

#include "cracker.h"

/* pre: takes in a char* dictFile and assumes gl_env.passwordList has been setup
 * post: runs a heuristic attack on the passwords in gl_env.passwordList using
 *      the dictionary file provided by dictFile
 */
void heuristic(char* dictFile)
{
    std::string line;
    std::string guess;
    std::ifstream file;
    bool altered;
    int i;

#ifdef DEBUG
    printDebug((char*)"opening dictionary file");
    printDebug((char*)"[Heuristic]\tstarting...");
#endif
    file.open(dictFile);

    while (std::getline(file, line))
    {
        if (allDone())
            return;

        /* word + word */
        gl_env.passwordsGenerated++;
        checkAllPasswords(line + line, "Heuristic 1");

        /* 1337sp34k */
        /* e for 3 */
        altered = false;
        guess = line;
        for (i = 0; i < line.length(); i++)
            if (line.at(i) == 'e' || line.at(i) == 'E')
            {
                guess.at(i) = '3';
                altered = true;
            }
        if (altered)
        {
            gl_env.passwordsGenerated++;
            checkAllPasswords(guess, "Heuristic 2");
        }

        /* 1337sp34k */
        /* a for 4 */
        altered = false;
        guess = line;
        for (i = 0; i < line.length(); i++)
            if (line.at(i) == 'a' || line.at(i) == 'A')
            {
                guess.at(i) = '4';
                altered = true;
            }
        if (altered)
        {
            gl_env.passwordsGenerated++;
            checkAllPasswords(guess, "Heuristic 3");
        }

        /* append a number 0-99 */
        for (i = 0; i < 99; i++)
        {
            gl_env.passwordsGenerated++;
            checkAllPasswords(line + std::to_string(i), "Heuristic 4");
        }
    } /* while */

#ifdef DEBUG
    printDebug((char*)"closing dictionary file");
#endif
    file.close();
}
