/* Bradford Smith (bsmith8)
 * CS 577 Lab 2 cleanExit.cpp
 * 09/24/2015
 * "I pledge my honor that I have abided by the Stevens Honor System."
 */

#include "cracker.h"

/* pre: takes in an int sig
 * post: clears existing alarms, prints how long the program ran and exits with
 *      exit code 0
 */
void cleanExit(int sig)
{
#ifdef DEBUG
    int i;
#endif
    double d;

    /* stop any existing alarms */
    alarm(0);
    time(&gl_env.endTime);

    /* ignore SIGINT so we can write the output file without being interrrupted */
    signal(SIGINT, SIG_IGN);

#ifdef DEBUG
    printf("[DEBUG]\ts_password struct vector:\n");
    for (i = 0; i < gl_env.passwordList.size(); i++)
        printf("\t[%d]\tLine:%s\tHash:%s\tPlaintext:%s\n",
                i,
                gl_env.passwordList.at(i).rawLine.c_str(),
                gl_env.passwordList.at(i).rawHash.c_str(),
                gl_env.passwordList.at(i).plaintext.c_str());
#endif

    writeOutput();

    /* print how long the program executed for */
    printf("Generated %lu passwords and attempted to crack %d of the %lu passwords in %f seconds\n",
            gl_env.passwordsGenerated,
            gl_env.passwordsAttempted,
            gl_env.passwordList.size(),
            d = difftime(gl_env.endTime, gl_env.startTime));
    printf("That is %f passwords generated per second and a total of %lu attempts\n",
            gl_env.passwordsGenerated / d,
            gl_env.passwordsGenerated * gl_env.passwordsAttempted);

    /* call exit */
    exit(0);
}
