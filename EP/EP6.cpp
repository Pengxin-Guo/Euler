/*************************************************************************
	> File Name: EP6.cpp
	> Author: 
	> Mail: 
	> Created Time: 2018年07月31日 星期二 14时51分15秒
 ************************************************************************/

#include <stdio.h>
#include <inttypes.h>
#define MAX_N 100

int main() {
    int64_t num1 = MAX_N * (MAX_N + 1) / 2, num2 = MAX_N * (MAX_N + 1) * (2 * MAX_N + 1) / 6;
    printf("%" PRId64 "\n", num1 * num1 - num2);
    return 0;
}
