/*************************************************************************
	> File Name: EP18.cpp
	> Author: 
	> Mail: 
	> Created Time: 2018年08月06日 星期一 09时04分34秒
 ************************************************************************/

#include <stdio.h>
#define MAX_N 15

int data[MAX_N + 5][MAX_N + 5] = {0};

int main() {
    for (int i = 0; i < MAX_N; i++) {
        for (int j = 0; j <= i; j++) {
            scanf("%d", data[i] + j);
        }
    }
    for (int i = MAX_N - 2; i >= 0; i--) {
        for (int j = 0; j <= i; j++) {
            data[i][j] += (data[i + 1][j] > data[i + 1][j + 1]) ? data[i + 1][j] : data[i + 1][j + 1];
        }
    }
    printf("%d\n", data[0][0]);
    return 0;
}
