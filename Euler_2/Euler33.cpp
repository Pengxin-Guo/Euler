/*************************************************************************
	> File Name: Euler33.cpp
	> Author: 
	> Mail: 
	> Created Time: 2018年07月28日 星期六 09时33分18秒
 ************************************************************************/

#include <stdio.h>

int gcb(int a, int b) {
    if (!b) return a;
    return gcb(b, a % b);
}

int is_valid(int a, int b) {
    int x = a / gcb(a, b), y = b / gcb(a, b);
    int x1 = a / 10, y1 = a % 10, x2 = b / 10, y2 = b % 10;
    if (x1 != x2 && x1 != y2 && y1 != x2 && y1 != y2) return 0;
    if (x1 / gcb(x1, y2) == x && y2 / gcb(x1, y2) == y) return 1;
    if (y1 / gcb(y1, x2) == x && x2 / gcb(y1, x2) == y) return 1;
    return 0;
}

int main() {
    int numerator = 1, denominator = 1;
    for (int i = 11; i < 99; i++) {
        for (int j = i + 1; j < 100; j++) {
            if (gcb(i, j) == 1) continue;
            if (i % 10 == i / 10 || j % 10 == j / 10) continue;
            if (i % 10 == j % 10 || i / 10 == j / 10) continue;
            if (!is_valid(i, j)) continue;
            numerator *= i;
            denominator *= j;
            printf("%d/%d\n",i,j);
        }
    }
    printf("%d\n",denominator /= gcb(numerator, denominator));
    return 0;
}
