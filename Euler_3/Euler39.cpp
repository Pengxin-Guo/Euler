/*************************************************************************
	> File Name: Euler39.cpp
	> Author: 
	> Mail: 
	> Created Time: 2018年07月31日 星期二 20时38分04秒
 ************************************************************************/

#include <stdio.h>
#define MAX_N 1000

int gcb(int a, int b) {
    if (!b) return a;
    return gcb(b, a % b);
}

int solutions(int p) {
    int num = 0;
    for (int i = 1; i < 32; i++) {
        for (int j = i + 1; j < 32; j++) {
            if (gcb(i, j) != 1) continue;
            int a = 2 * i * j;
            int b = j * j - i * i;
            int c = j * j + i * i;
            if (p % (a + b + c)) continue;
            num += 1;
        }
    }
    return num;
}

int main() {
    int ans = 0, num = 0;
    for (int p = 12; p <= MAX_N; p++) {
        if (num < solutions(p)) {
            num = solutions(p);
            ans = p;
        }
    }
    printf("%d\n", ans);
    return 0;
}
