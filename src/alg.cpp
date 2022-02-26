// Copyright 2022 NNTU-CS
#include <cstdint>
#include "alg.h"


bool checkPrime(uint64_t value) {
for (int i = 2; i < value; i++) {
        if (value % i == 0) {
            return false;
        }
    }
    return true;
}

uint64_t nPrime(uint64_t n) {
    const int size = 100000;
    int schet = 1;
    int chislo = 2;
    int* a = new int[size];
    for (int i = 2; i < size; i++) {
        a[i] = 1;
    }
    while (schet != n) {
        for (int i = 2 * chislo; i < size; i += chislo) {
            a[i] = 0;
        }
        for (int i = chislo + 1; i < size; i++) {
            if (a[i] == 1) {
                chislo = i;
                break;
            }
        }
        schet++;
    }
    return chislo;
}

uint64_t nextPrime(uint64_t value) {
    const int size = 100000;
    int* a = new int[size];
    for (int i = 0; i < size; i++) {
        a[i] = i;
    }
    for (int i = 2; i * i < size; i++) {
        if (a[i]) {
            for (int j = i * i; j <= size; j += i) {
                a[j] = 0;
            }
        }
    }
    for (int i = value + 1; i < size; i++) {
        if (a[i]) {
            return a[i];
            break;
        }
    }
}

uint64_t sumPrime(uint64_t hbound) {
    const int size = hbound;
    int* a = new int[size];
    int sum = 0;
    for (int i = 0; i < size; i++) {
        a[i] = i;
    }
    for (int i = 2; i * i < size; i++) {
        if (a[i]) {
            for (int j = i * i; j < size; j += i) {
                a[j] = 0;
            }
        }
    }
    for (int i = 2; i < size; i++) {
        if (a[i]) {
            sum += a[i];
        }
    }
    return sum;
    break;
}
