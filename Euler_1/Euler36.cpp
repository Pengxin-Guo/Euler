/*************************************************************************
	> File Name: Euler36.cpp
	> Author: 
	> Mail: 
	> Created Time: 2018年07月22日 星期日 14时48分01秒
 ************************************************************************/

#include<stdio.h>

int is_palindromic(int x, int n) {
    int temp=x,num=0;
    while(x) {
        num = num * n + x % n;
        x /=n;
    }
    return temp == num;   //最后得出来的num还是十进制数
}
int main() {
    int ans;
    for(int i = 1; i < 1000000; i++){
        if(is_palindromic(i,2) && is_palindromic(i,10)) ans += i;
    }
    printf("%d\n",ans);
    return 0;
}

