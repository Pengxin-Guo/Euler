/*************************************************************************
	> File Name: Euler5.cpp
	> Author: 
	> Mail: 
	> Created Time: 2018年07月22日 星期日 15时29分59秒
 ************************************************************************/

#include <stdio.h>

int gcd(int a,int b) {
    if(!b) return a;
    return gcd(b,a % b);
}

int main() {
    int ans=1;
    for (int i = 1; i <=20; i++) {
        if (ans % i == 0) continue;
        ans = ans * i / gcd(ans,i);
    }
    printf("%d\n",ans);
    return 0;
}
