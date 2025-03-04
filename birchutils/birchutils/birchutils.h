#pragma once

#pragma GCC diagnostic ignored "-Wstringop-truncation"
#pragma GCC diagnostic ignored "-Wformat-truncation="
#pragma GCC diagnostic push

#ifdef _WIN32
    #include <winsock2.h>
    #include <ws2tcpip.h>
#else
    #include <arpa/inet.h>
#endif

#include <stdio.h>
#include <stdlib.h>

typedef unsigned char int8;
typedef unsigned short int int16;
typedef unsigned int int32;

/* Funções */
void copy(int8*, int8*, int16);
int16 nstoh(int16);
void printhex(int8*, int16, int8);
int8* todotted(in_addr_t);
void zero(int8*, int16);

/* Apenas declarações das funções de socket */
void initialize_sockets();
void cleanup_sockets();

#pragma GCC diagnostic pop