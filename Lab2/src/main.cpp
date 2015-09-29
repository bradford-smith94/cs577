/* Bradford Smith (bsmith8)
 * CS 577 Lab 2 main.cpp
 * 09/24/2015
 * "I pledge my honor that I have abided by the Stevens Honor System."
 */

#include "cracker.h"

/* argv:
 * 0: ./cracker, 1: password_file, 2: results_file, 3: timeout, 4: salt
 */
#define usage "[USAGE]\t./cracker <password_file> <results_file> <timeout_sec> <salt>"

struct s_env gl_env;

/* pre: takes in int argc and char** argv commandline arguments
 * post: runs the password cracker
 */
int main(int argc, char** argv)
{
#ifdef DEBUG
    int i;
#endif

    signal(SIGINT, cleanExit);
    signal(SIGALRM, cleanExit);
    if (argc == 5)
    {
        gl_env.passwordFile = std::string(argv[1]);
        gl_env.resultFile = std::string(argv[2]);
        gl_env.timeout = atoi(argv[3]); /* if timeout is <= 0 assume no timeout */
        gl_env.salt = std::string(argv[4]);
    }
    else if (argc == 4)
    {
        gl_env.passwordFile = std::string(argv[1]);
        gl_env.resultFile = std::string(argv[2]);
        gl_env.timeout = atoi(argv[3]);
        gl_env.salt = ""; /* if salt is empty do cracking in no salt mode */
    }
    else
        printError((char*)usage);
#ifdef DEBUG
        printf("[DEBUG]\tPassword file:%s\tResult file:%s\tTimeout:%d\tSalt:%s\n",
                gl_env.passwordFile.c_str(),
                gl_env.resultFile.c_str(),
                gl_env.timeout,
                gl_env.salt.c_str());
#endif

    /* record start time and start timer for timeout */
    time(&gl_env.startTime);
    if (gl_env.timeout > 0) /* only set alarm if we've been given a positive timeout */
        alarm(gl_env.timeout);

    gl_env.passwordsGenerated = 0;
    gl_env.passwordsAttempted = 0;
    gl_env.passwordList = parseInput();
#ifdef DEBUG
    printf("[DEBUG]\ts_password struct vector:\n");
    for (i = 0; i < gl_env.passwordList.size(); i++)
        printf("\t[%d]\tLine:%s\tHash:%s\tPlaintext:%s\n",
                i,
                gl_env.passwordList.at(i).rawLine.c_str(),
                gl_env.passwordList.at(i).rawHash.c_str(),
                gl_env.passwordList.at(i).plaintext.c_str());
#endif

    dictionary((char*)DICTIONARY_FILE);
    if (!allDone())
        heuristic((char*)DICTIONARY_FILE);
    if (!allDone())
        bruteForce();

    cleanExit(0);
    return 0; /* execution won't ever get here */
}
