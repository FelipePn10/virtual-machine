/* birchutils.c v1.3.1 */
#include <birchutils.h>
#ifdef _WIN32
    #include <winsock2.h>
    #include <ws2tcpip.h>
#else
    #include <arpa/inet.h>
#endif

#include <stdio.h>
#include <stdint.h>
//#include <birchutils.h>

void copy(int8 *dst, int8 *src, int16 size) {
    int8 *d, *s;
    int16 n;

    for (n=size, d=dst, s=src; n; n--, d++, s++)
        *d = *s;

    return;
}

int16 nstoh(int16 srcport) {
    int16 dstport;
    int8 highByte, lowByte;

    highByte = (srcport & 0xff00) >> 8;
    lowByte = (srcport & 0xff);
    dstport = (lowByte << 8) + highByte;

    return dstport;
}

void zero(int8 *str, int16 size) {
    int8 *ptr = str;

    for (int16 n = 0; n < size; n++, ptr++) {
        *ptr = 0;
    }
}

void printhex(int8 *str, int16 size, int8 delim) {
    for (int16 i = 0; i < size; i++) {
        printf("%.02x", str[i]);
        if (delim) {
            printf("%c", delim);
        }
    }
    printf("\n");
    fflush(stdout);
}

int8 *todotted(uint32_t ip) {
    int8 a, b, c, d;
    static int8 buf[16];

    d = ((ip & 0xff000000) >> 24);
    c = ((ip & 0xff0000) >> 16);
    b = ((ip & 0xff00) >> 8);
    a = ((ip & 0xff));

    // Limpa o buffer e formata o IP
    snprintf((char *)buf, sizeof(buf), "%d.%d.%d.%d", a, b, c, d);

    return buf;
}

// int main() {
//     // Ex
//     uint32_t ip = 0x7f000001;  // IP 127.0.0.1
//     printf("IP: %s\n", todotted(ip));

//     return 0;
// }


#pragma GCC diagnostic pop
#pragma GCC diagnostic push