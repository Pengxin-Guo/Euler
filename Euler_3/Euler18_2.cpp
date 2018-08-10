/*************************************************************************
	> File Name: Euler18_2.cpp
	> Author: 
	> Mail: 
	> Created Time: 2018年07月29日 星期日 14时49分39秒
 ************************************************************************/
#include <stdio.h>
#define MAX_N 15
#define max(a, b) ((a) > (b) ? (a) : (b))

int num[MAX_N + 5][MAX_N + 5] = {0};

int main() {
    for (int i = 0; i < MAX_N; i++) {
        for (int j = 0; j <= i; j++) {
            scanf("%d", num[i] + j);
        }
    }
    for (int i = MAX_N - 2; i >= 0; i--) {
        for (int j = 0; j <=i; j++) {
            num[i][j] += max(num[i + 1][j], num[i + 1][j + 1]);
        }
    }
    printf("%d\n", num[0][0]);
    return 0;
}
