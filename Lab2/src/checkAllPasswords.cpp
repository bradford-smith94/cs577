/* Bradford Smith (bsmith8)
 * CS 577 Lab 2 checkAllPasswords.cpp
 * 09/24/2015
 * "I pledge my honor that I have abided by the Stevens Honor System."
 */

#include "cracker.h"

/* pre: takes in a std::string guess and std::string attack
 * post: checks guess against all passwords in gl_env.passwordList the attack
 *      parameter is just for DEBUG messages
 */
void checkAllPasswords(std::string guess, std::string attack)
{
    std::string hashedGuess;
    int i;

    /* only hash the guess once for all passwords */
    if (!gl_env.salt.empty())
        hashedGuess = getMd5(guess + gl_env.salt);
    else
        hashedGuess = getMd5(guess);

    /* for all hashed passworeds */
    for (i = 0; i < gl_env.passwordList.size(); i++)
    {
        /* if password hasn't been cracked */
        if (gl_env.passwordList.at(i).plaintext.empty())
        {
            /* if password hasn't been attempted */
            if (!gl_env.passwordList.at(i).attempted)
            {
                gl_env.passwordList.at(i).attempted = true;
                gl_env.passwordsAttempted++;
            }
            /* compare */
            if (gl_env.passwordList.at(i).rawHash.compare(hashedGuess) == 0)
            {
                gl_env.passwordList.at(i).plaintext = guess;
#ifdef DEBUG
                printf("[DEBUG]\t[%s]\tfound match!\n", attack.c_str());
                fflush(stdout);
#endif
            }
        }
    }
}
