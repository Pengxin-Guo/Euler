/*************************************************************************
	> File Name: EP22.cpp
	> Author: gpx
	> Mail: 1457495424@qq.com
	> Created Time: 2019年02月27日 星期三 20时45分14秒
 ************************************************************************/

#include <iostream>
#include <stdio.h>
#include <string.h>
#include <inttypes.h>
#include <algorithm>
#include "22.h"

int main() {
    int64_t i = 0, ans = 0;
    while (nameList[i].length() != 0) i++;
    std::sort(nameList, nameList + i);
    i = 0;
    while (nameList[i].length() != 0) {
        int64_t sum = 0;
        for (int j = 0; j < nameList[i].length(); j++) {
            sum += nameList[i][j] - 'A' + 1;
        }
        ans += sum * (i + 1);
        i++;
    }
    printf("%" PRId64 "\n", ans);
    return 0;
}

