/*************************************************************************
	> File Name: EP9.cpp
	> Author: 
	> Mail: 
	> Created Time: 2018年08月05日 星期日 16时29分52秒
 ************************************************************************/

#include <stdio.h>

int main() {
    for (int i = 1; i < 32; i++) {
        for (int j = i + 1; j < 32; j++) {
            int a = 2 * i * j;
            int b = j * j - i * i;
            int c = j * j + i * i;
            if (1000 % (a + b + c) == 0){
                int e = 1000 / (a + b + c);
                printf("%d\n", a * b * c * e * e * e);
                return 0;
            }
        }
    }
    return 0;
}
