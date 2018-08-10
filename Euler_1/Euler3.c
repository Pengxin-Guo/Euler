/*************************************************************************
	> File Name: Euler3.c
	> Author: 
	> Mail: 
	> Created Time: 2018年07月21日 星期六 21时29分01秒
 ************************************************************************/

#include<stdio.h>
#include<inttypes.h>
#define MAX 600851475143
int main(){
    int64_t n=2,num=MAX,ans;
    while(n*n<num){
        if(num%n==0) ans=n;
        while(num % n == 0) num /= n;
        n++;
    }
    if(num!=1) ans = num;
    printf("% "PRId64,ans);
    return 0;
}
