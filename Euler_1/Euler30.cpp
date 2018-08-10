/*************************************************************************
	> File Name: Euler30.cpp
	> Author: 
	> Mail: 
	> Created Time: 2018年07月22日 星期日 11时08分03秒
 ************************************************************************/

#include<stdio.h>
#include<math.h>
#define MAX 354294

int is_equal(int x) {
    int tmp = x, sum = 0;
    while (x) {
        sum += (int)pow(x % 10, 5);
        x/=10;
    }
    return sum == tmp;
}

int main() {
    int sum = 0,i;
    for (i = 2; i < MAX; i++) {
        if (!is_equal(i)) continue;
        sum += i;
    }
    printf("%d\n",sum);
    return 0;
}
