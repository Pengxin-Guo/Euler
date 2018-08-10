/*************************************************************************
	> File Name: Euler9.cpp
	> Author: 
	> Mail: 
	> Created Time: 2018年07月30日 星期一 09时52分47秒
 ************************************************************************/

#include <stdio.h>

int is_triplet(int a, int b, int c) {
    if (a * a + b * b == c * c) return 1;
    else return 0;
}

int main() {
    for (int i = 3; i < 900; i++) {
        for (int j = i + 1; j < 1000; j++) {
            if (!is_triplet(i, j, (1000 - i - j))) continue;
            printf("%d %d %d\n", i, j, (1000 - i - j));
            printf("%d\n",i * j * (1000 - i - j));
            break;
        }
    }
    return 0;
}
