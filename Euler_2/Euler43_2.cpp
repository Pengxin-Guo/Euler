/*************************************************************************
	> File Name: Euler43_2.cpp
	> Author: 
	> Mail: 
	> Created Time: 2018年07月28日 星期六 17时25分17秒
 ************************************************************************/

#include <stdio.h>
#include <inttypes.h>
#include <algorithm>
using namespace std;

int64_t is_valid(int *a) {
    if (a[0] == 0) return 0;
    int p[7] = {2, 3, 5, 7, 11, 13, 17}, j = 0;
    int64_t num = a[0], ret = a[0];
    for (int i = 1; i < 10; i++) {
        ret = ret * 10 + a[i];
        num = num * 10 + a[i];
        if (i < 3) continue;
        num -= 1000 * a[i - 3];
        if (num % p[j++]) return 0;
    }
    return ret;
}

int main() {
    int a[10] = {0};
    for (int i = 0; i < 10; i++) {
        a[i] = i;
    }
    int64_t sum = 0, temp;
    do {
        sum += is_valid(a);
    } while (next_permutation(a, a + 10));
    printf("%" PRId64 "\n", sum);
    return 0;
}
