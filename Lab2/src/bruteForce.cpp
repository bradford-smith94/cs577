/* Bradford Smith (bsmith8)
 * CS 577 Lab 2 bruteForce.cpp
 * 09/24/2015
 * "I pledge my honor that I have abided by the Stevens Honor System."
 */

#include "cracker.h"

/* pre: assumes that gl_env.passwordList has been setup
 * post: attempts to crack the hashes in gl_env.passwordList using a brute-force
 *      attack of passwords length 3 to 5
 */
void bruteForce()
{
    std::vector<std::string> chars;
    std::string c[77] = {"", "a", "b", "c", "d", "e", "f", "g",
        "h", "i", "j", "k", "l", "m", "n", "o", "p", "q", "r", "s", "t", "u",
        "v", "w", "x", "y", "z", "A", "B", "C", "D", "E", "F", "G", "H", "I",
        "J", "K", "L", "M", "N", "O", "P", "Q", "R", "S", "T", "U", "V", "W",
        "X", "Y", "Z", "0", "1", "2", "3", "4", "5", "6", "7", "8", "9", "~",
        "!", "@", "#", "$", "%", "^", "&", "*", "-", "_", "+", "=", "?"};
    std::string guess;

    chars.assign(&c[0], &c[0] + 77);

#ifdef DEBUG
    printDebug((char*)"[BruteForce]\tstarting...");
#endif

    for (std::string letter1 : chars)
    {
        for (std::string letter2 : chars)
        {
            for (std::string letter3 : chars)
            {
                if (letter3.empty())
                    continue;
                for (std::string letter4 : chars)
                {
                    if (letter4.empty())
                        continue;
                    for (std::string letter5 : chars)
                    {
                        if (letter5.empty())
                            continue;
                        if (allDone())
                            return;
                        guess = letter1 + letter2 + letter3 + letter4 + letter5;
                        gl_env.passwordsGenerated++;
                        checkAllPasswords(guess, "BruteForce");
                    } /* letter5 */
                } /* letter4 */
            } /* letter3 */
        } /* letter2 */
    } /* letter1 */
#ifdef DEBUG
    printDebug((char*)"[BruteForce]\texhausted");
#endif
}
