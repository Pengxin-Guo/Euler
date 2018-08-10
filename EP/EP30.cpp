/*************************************************************************
	> File Name: EP30.cpp
	> Author: 
	> Mail: 
	> Created Time: 2018年07月31日 星期二 14时59分49秒
 ************************************************************************/

#include <stdio.h>
#include <math.h>
#define MAX_N 354294

int is_valid(int n) {
    int temp = n, num = 0;
    while (temp) {
        num += pow(temp % 10, 5);
        temp /= 10;
    }
    return num == n;
}

int main() {
    int ans = 0;
    for (int i = 2; i < MAX_N; i++) {
        if (!is_valid(i)) continue;
        ans += i;
    }
    printf("%d\n", ans);
    return 0;
}
