/*************************************************************************
	> File Name: Euler9_2.cpp
	> Author: 
	> Mail: 
	> Created Time: 2018年07月30日 星期一 10时21分14秒
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {
    int flag = 1;
    int a, b, c, e;
    for (int i = 1; i < 25 && flag; i++) {
        for (int j = i + 1; j <= 25 && flag; j++) {
            a = 2 * i * j;
            b = j * j - i * i;
            c = j * j + i * i;
            if (1000 % (a + b + c) ==0) {
                e = (int)pow(1000 / (a + b +c), 3);
                printf("%d %d %d %d\n",a, b, c, e);
                printf("%d\n", e * a * b * c);
                flag = 0;
            }
        }
    }
    return 0;
}
