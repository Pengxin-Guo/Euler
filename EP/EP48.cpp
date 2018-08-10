/*************************************************************************
	> File Name: EP48.cpp
	> Author: 
	> Mail: 
	> Created Time: 2018年08月06日 星期一 16时52分50秒
 ************************************************************************/

#include <stdio.h>
#include <string.h>
#define MAX_N 4000
int ans[MAX_N + 5] = {0};
int data[MAX_N + 5] = {0};

void sum(int *data) {
    ans[0] = ans[0] > data[0] ? ans[0] : data[0];
    for (int i = 1; i <= data[0]; i++) {
        ans[i] += data[i];
    }
    for (int i = 1; i <= ans[0]; i++) {
        if (ans[i] < 10) continue;
        ans[i + 1] += ans[i] / 10;
        ans[i] %= 10;
        ans[0] += (i == ans[0]);
    }
    return ;
}

int main() {
    for (int i = 1; i <= 1000; i++) {
        memset(data, 0, sizeof(int) * MAX_N);
        data[0] = data[1] = 1;
        for (int j = 1; j <= i; j++) {
            for (int k = 1; k <= data[0]; k++) {
                data[k] *= i;
            }
            for (int k = 1; k <= data[0]; k++) {
                if (data[k] < 10) continue;
                data[k + 1] += data[k] / 10;
                data[k] %= 10;
                data[0] += (k == data[0]);
            }
        }
        sum(data);
    }
    for (int i = 10; i >= 1; i--) {
        printf("%d", ans[i]);
    }
    return 0;
}

