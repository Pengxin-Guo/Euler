/*************************************************************************
	> File Name: Euler7_1.cpp
	> Author: 
	> Mail: 
	> Created Time: 2018年07月24日 星期二 09时49分53秒
 ************************************************************************/

 #include <stdio.h>
 #define MAX_N 10000
 int prime[MAX_N + 5] = {0};

void init() {
    for (int i = 2; i * i <= MAX_N; i++) {
        if (prime[i]) continue;
        for (int j = i; j <= MAX_N; j += i) {
            if (prime[j]) continue;
            prime[j] = i;
        }
    }
}

 int main() {
     init();
     for (int i = 2; i <=MAX_N; i++) {
         printf("%d min prime is %d\n",i,prime[i]);
     }
     return 0;
 }
