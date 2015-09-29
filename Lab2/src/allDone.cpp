/* Bradford Smith (bsmith8)
 * CS 577 Lab 2 allDone.cpp
 * 09/24/2015
 * "I pledge my honor that I have abided by the Stevens Honor System."
 */

#include "cracker.h"

/* pre: assumes gl_env.passwordList has been setup
 * post: checks to see if all passwords in gl_env.passwordList have been cracked
 * return: true if all passwords have been cracked, else false
 */
bool allDone()
{
    int i;

    for (i = 0; i < gl_env.passwordList.size(); i++)
        if (gl_env.passwordList.at(i).plaintext.empty())
            return false;

    return true;
}
