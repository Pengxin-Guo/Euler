/*************************************************************************
	> File Name: EP24_2.cpp
	> Author: gpx
	> Mail: 1457495424@qq.com
	> Created Time: 2019年03月16日 星期六 16时43分19秒
 ************************************************************************/

#include <iostream>
#include <algorithm>
using namespace std;
#define MAX_N 1000000

int main() {
    int num[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    for (int i = 0; i < MAX_N - 1; i++) {
        next_permutation(num, num + 10);
    }
    for (int i = 0; i < 10; i++) {
        cout << num[i];
    }
    cout << endl;
    return 0;
}
