/*************************************************************************
	> File Name: Euler34.cpp
	> Author: 
	> Mail: 
	> Created Time: 2018年07月22日 星期日 11时48分52秒
 ************************************************************************/

#include<stdio.h>
#define MAX 2540160
int factorial(int n) {
    int t=1;
    while(n > 1) {
        t=t*n;
        n--;
    }
    return t;
}

int is_equal(int x) {
    int temp=x,sum=0;
    while(x) {
        sum += factorial(x % 10);
        x /=10;
    }
    return temp == sum;
}

int main() {
    int sum=0;
    for(int i =3; i < MAX; i++) {
        if(is_equal(i)) sum += i;
    }
    printf("%d\n",sum);
    return 0;
}

