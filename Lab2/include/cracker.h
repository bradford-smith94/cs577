/* Bradford Smith (bsmith8)
 * CS 577 Lab 2 cracker.h
 * 09/24/2015
 * "I pledge my honor that I have abided by the Stevens Honor System."
 */

#ifndef _CRACKER_H_
#define _CRACKER_H_

#include <unistd.h>
#include <cstdlib>
#include <cstdio>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <csignal>
#include <ctime>
#include <openssl/md5.h>

#define DICTIONARY_FILE "../dictionary.txt"

struct s_password
{
    std::string rawLine;
    std::string rawHash;
    std::string plaintext;
    bool attempted;
};

struct s_env
{
    std::vector<s_password> passwordList;
    std::string passwordFile;
    std::string resultFile;
    int timeout;
    std::string salt;
    time_t startTime;
    time_t endTime;
    unsigned long passwordsGenerated;
    int passwordsAttempted;
};

extern s_env gl_env;

/* This is the header file for CS 577 Lab 2: password cracker for passwords
 * hashed with md5 (with and without a salt)
 */
int                             main(int, char**);
void                            cleanExit(int);
void                            printError(char*);
void                            printDebug(char*);
std::vector<struct s_password>  parseInput();
std::string                     parseLine(std::string);
std::string                     getMd5(std::string);
bool                            allDone();
void                            bruteForce();
void                            dictionary(char*);
void                            heuristic(char*);
void                            checkAllPasswords(std::string, std::string);
void                            writeOutput();

#endif /* _CRACKER_H_ */
