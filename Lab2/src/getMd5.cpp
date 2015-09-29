/* Bradford Smith (bsmith8)
 * CS 577 Lab 2 getMd5.cpp
 * 09/24/2015
 * "I pledge my honor that I have abided by the Stevens Honor System."
 */

#include "cracker.h"

/* this was a bad idea, remove these and define DEBUG for spam */
#ifdef DEBUG
#undef DEBUG
#endif

/* pre: takes in a std::string guess
 * post: computes the MD5 of guess
 * return: the MD5 hash of guess as a hexadecimal string
 */
std::string getMd5(std::string guess)
{
    static const char hexDigits[17] = "0123456789abcdef";
    unsigned char guessResult[MD5_DIGEST_LENGTH];
    unsigned char* s;
    char digest_str[2 * MD5_DIGEST_LENGTH + 1];
    int i;

    s = (unsigned char*)guess.c_str();
    MD5(s, sizeof(s), guessResult);

    for (i = 0; i < MD5_DIGEST_LENGTH; i++)
    {
        digest_str[i * 2] = hexDigits[(guessResult[i] >> 4) & 0xF];
        digest_str[i * 2 + 1] = hexDigits[guessResult[i] & 0xF];
    }
    digest_str[MD5_DIGEST_LENGTH * 2] = '\0';

    return digest_str;
}
