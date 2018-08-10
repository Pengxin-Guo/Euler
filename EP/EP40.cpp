/*************************************************************************
	> File Name: EP40.cpp
	> Author: 
	> Mail: 
	> Created Time: 2018年08月05日 星期日 09时33分50秒
 ************************************************************************/

#include <stdio.h>
#include <math.h>
#define MAX_N 1000000
int data[MAX_N + 5] = {0};
int n = 1;

int digit(int n) {
    return floor(log10(n)) + 1;
}

void deal(int x) {
    int temp = x;
    for (int i = 0; i < digit(x); i++) {
        int num = digit(temp);
        data[n] = temp / (int)pow(10, num - 1);
        n += 1;
        temp = temp % (int)pow(10, num - 1);
    }
}

int main() {
    int ans;
    for (int i = 1; (n <= MAX_N + 2) && i < MAX_N; i++) {
        deal(i);
    }
    ans = data[1] * data[10] * data[100] * data[1000] * data[10000] * data[100000] * data[1000000];
    printf("%d\n", ans);
    return 0;
}
