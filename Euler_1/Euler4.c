/*************************************************************************
	> File Name: Euler4.c
	> Author: 
	> Mail: 
	> Created Time: 2018年07月22日 星期日 09时18分54秒
 ************************************************************************/

#include<stdio.h>
int is_palindromic(int x) {
    int tmp=x,num=0;
    while (x) {
        num = num * 10 + x % 10;
        x /= 10;
    }
    return tmp == num;
}
int main() {
    int ans = 0;
    for (int i = 100; i < 1000; i++ ){
        for (int j = 100; j < 1000; j++) {
            if (i * j < ans) continue;
            if (!is_palindromic(i * j)) continue;
            ans = i * j;
        }
    }
    printf("%d\n",ans);
    return 0;
}
