/*************************************************************************
	> File Name: Euler29.cpp
	> Author: 
	> Mail: 
	> Created Time: 2018年07月31日 星期二 11时05分27秒
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_N 10000
#define MAX_M 210

int *result_num[MAX_N];
int result = 0;

int *calc_num(int a, int b) {
    int *tt = (int *)calloc(sizeof(int), MAX_M);
    tt[0] = tt[1] = 1;
    for (int i = 0; i < b; i++) {
        for (int j = 1; j <= tt[0]; j++) tt[j] *= a;
        for (int j = 1; j <= tt[0]; j++) {
            if (tt[j] < 10) continue;
            tt[j + 1] += tt[j] / 10;
            tt[j] = tt[j] % 10;
            tt[0] += (j == tt[0]);
        }
    }
    return tt;
}

int find_num(int *t) {
    for (int i = 0; i < result; i++) {
        if (memcmp(result_num[i], t, sizeof(int) * MAX_M) == 0) return 1;
    }
    return 0;
}

int main() {
    for (int a = 2; a <= 100; a++) {
        for (int b = 2; b <= 100; b++) {
            int *temp = calc_num(a, b);
            if (!find_num(temp)) {
                result_num[result++] = temp;
            } else {
                free(temp);
            }
        }
    }
    printf("%d\n", result);
    return 0;
}
