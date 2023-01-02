#include <sys/stat.h>
#include <fcntl.h>
#include <ctype.h>
#include "tlpi_hdr.h"
#ifndef BUF_SIZE
#define BUF_SIZE 1024
#endif

int
main(int argc, char *argv[])
{
    char buffer[BUF_SIZE];
    int opt, stdOutputFd, outputFd, openFlags;
    mode_t filePerms;
    ssize_t numRead;
    
    if (argc != 3 && argc != 2)
        usageErr("Wrong number of arguments\n");

    filePerms = S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH | S_IWOTH; 
    openFlags = O_WRONLY | O_CREAT;

    while ((opt = getopt(argc, argv, ":a")) != -1) {
        switch (opt) {
            case 'a': openFlags = openFlags | O_APPEND; break;
            default: fatal("Unexpected option");
        }
    }
    if (openFlags & O_APPEND) 
        outputFd = open(argv[2], openFlags, filePerms); 
    else {
        openFlags = openFlags | O_TRUNC;
        outputFd = open(argv[1], openFlags, filePerms);
    }

    if (outputFd == -1)
        errExit("opening file %s", argv[1]);

    while ((numRead = read(STDIN_FILENO, buffer, BUF_SIZE)) > 0) {
        if (write(STDOUT_FILENO, buffer, numRead) == -1)
            errExit("Error with STDOUT");

        if (write(outputFd, buffer, numRead) != numRead)
            fatal("couldn't write whole buffer");
   } 
    
    if (numRead == -1)
        errExit("Error with STDIN");
    if (close(outputFd) == -1)
        errExit("close output");

    exit(EXIT_SUCCESS);
         
}
