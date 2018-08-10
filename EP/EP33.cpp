/*************************************************************************
	> File Name: EP33.cpp
	> Author: 
	> Mail: 
	> Created Time: 2018年08月01日 星期三 14时54分53秒
 ************************************************************************/

#include <stdio.h>

int gcd(int a, int b) {
    return b ? gcd(b, a % b) : a;
}

int main() {
    int numa = 1, numb = 1;
    for (int i = 11; i < 100; i++) {
        for (int j = i + 1; j < 100; j++) {
            int a[2] = {i / 10, i % 10}, b[2] = {j / 10, j % 10};
            if (a[0] == b[0] || a[1] == b[1]) continue;
            int temp = gcd(i, j);
            if (a[0] == b[1] && i * b[0] == j * a[1]) {
                numa *= i;
                numb *= j;
                continue;
            }
            if (a[1] == b[0] && i * b[1] == j * a[0]){
                numa *= i;
                numb *= j;        }
            
        }
    }
    printf("%d\n", numb / gcd(numa, numb));
    return 0;
}
