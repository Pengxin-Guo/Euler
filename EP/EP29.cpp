/*************************************************************************
	> File Name: EP29.cpp
	> Author: 
	> Mail: 
	> Created Time: 2018年08月01日 星期三 11时53分33秒
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#define MAX_N 10000
#define MAX_M 210

int *result[MAX_N];
int ret = 0;

int *cal_num(int a, int b) {
    int *temp = (int *)calloc(sizeof(int), MAX_M);
    temp[0] = temp[1] = 1;
    for (int i = 0; i < b; i++) {
        for (int j = 1; j <= temp[0]; j++) temp[j] *= a;
        for (int j = 1; j <= temp[0]; j++) {
            if (temp[j] < 10) continue;
            temp[j + 1] += temp[j] / 10;
            temp[j] %= 10;
            temp[0] += (j == temp[0]);
        }
    }
    return temp;
}

int find(int *temp) {
    for (int i = 0; i < ret; i++) {
        if (memcmp(result[i], temp, sizeof(int) * MAX_M) == 0) return 1;
    }
    return 0;
}

int main() {
    time_t t;
    char buf[1024];
    time(&t);
    ctime_r(&t, buf);
    printf("%s", buf);
    for (int a = 2; a <= 100; a++) {
        for (int b = 2; b <= 100; b++) {
            int *temp = cal_num(a, b);
            if (!find(temp)){
                result[ret++] = temp;
            } else {
                free(temp);
            }
        }
    }
    printf("%d\n", ret);
    time(&t);
    ctime_r(&t, buf);
    printf("%s", buf);
    return 0;
}
