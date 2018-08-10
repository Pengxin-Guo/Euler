/*************************************************************************
	> File Name: EP16.cpp
	> Author: 
	> Mail: 
	> Created Time: 2018年08月06日 星期一 08时54分28秒
 ************************************************************************/

#include <stdio.h>

int data[300] = {1, 1};

int main() {
    int ans = 0;
    for (int i = 0; i < 1000; i++) {
        for (int j = 1; j <= data[0]; j++) {
            data[j] *= 2;
        }
        for (int j = 1; j <= data[0]; j++) {
            if (data[j] < 10) continue;
            data[j + 1] += data[j] / 10;
            data[j] %= 10;
            data[0] += (j == data[0]);
        }
    }
    for (int i = 1; i <= data[0]; i++) {
        ans += data[i];
    }
    printf("%d\n", ans);
    return 0;
}
