#include <stdio.h>

#define LEAP_MASK 0b10000
#define PRIME_MASK 0b00100

typedef struct date {
    unsigned flags:5;
    unsigned day:5;
    unsigned month:4;
    unsigned year;
} Date;

typedef struct dateN {
    unsigned flags;
    unsigned day;
    unsigned month;
    unsigned year;
} DateN;

int main() {
    DateN todayN = {20, 23, 4, 2018};
    Date today = {20, 23, 4, 2018};
    printf("Size of date non-bitfields %lu\n", sizeof(todayN));
    printf("Size of date bitfields %lu\n", sizeof(today));
    printf("Date: %i/%i/%i\n", today.day, today.month, today.year);

    if(today.day ^ 23) {
        printf("Today isn''t 23\n");
    }
    else {
        printf("Today is 23\n");
    }

    if((today.flags & LEAP_MASK) != 0) {
        printf("Is leap\n");
    }

    if((today.flags & (LEAP_MASK | PRIME_MASK)) != 0) {
        printf("Is leap or prime\n");
    }

    if((today.flags & (LEAP_MASK | PRIME_MASK)) == (LEAP_MASK | PRIME_MASK)) {
        printf("Is leap and prime\n");
    }

}