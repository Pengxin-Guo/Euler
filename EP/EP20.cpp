/*************************************************************************
	> File Name: EP20.cpp
	> Author: 
	> Mail: 
	> Created Time: 2018年08月06日 星期一 09时10分11秒
 ************************************************************************/

#include <stdio.h>
#define MAX_N 1000

int data[MAX_N + 5] = {1, 1};

int main() {
    for (int i = 1; i <= 100; i++) {
        for (int j = 1; j <= data[0]; j++) {
            data[j] *= i;
        }
        for (int j = 1; j <= data[0]; j++) {
            if (data[j] < 10) continue;
            data[j + 1] += data[j] / 10;
            data[j] %= 10;
            data[0] += (j == data[0]);
        }
    }
    int ans = 0;
    for (int i = 1; i <= data[0]; i++) {
        ans += data[i];
    }
    printf("%d\n", ans);
    return 0;
}
