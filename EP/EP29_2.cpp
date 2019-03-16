/*************************************************************************
	> File Name: EP29_2.cpp
	> Author: gpx
	> Mail: 1457495424@qq.com
	> Created Time: 2019年03月16日 星期六 18时45分38秒
 ************************************************************************/

#include <iostream>
#include <set>
#include <vector>
#include <ctime>
using namespace std;
#define MAX_N 210

set<vector<int>> sv;

vector<int> cal_num(int a, int b) {
    vector<int> temp;
    for (int i = 0; i < MAX_N; i++) {
        temp.push_back(0);
    }
    temp[0] = temp[1] = 1;
    for (int i = 0; i < b; i++) {
        for (int j = 1; j <= temp[0]; j++) temp[j] *= a;
        for (int j = 1; j <= temp[0]; j++) {
            if (temp[j] < 10) continue;
            temp[j + 1] += temp[j] / 10;
            temp[j] %= 10;
            temp[0] += (j == temp[0]);
        }
    }
    return temp;
}

int main() {
    time_t t;
    char buf[1024];
    time(&t);
    ctime_r(&t, buf);
    cout << buf;
    int ans = 0;
    for (int a = 2; a <= 100; a++) {
        for (int b = 2; b <= 100; b++) {
            vector<int> temp = cal_num(a, b);
            if (sv.count(temp)) continue;
            else sv.insert(temp);
            ans++;
        }
    }
    cout << ans << endl;
    time(&t);
    ctime_r(&t, buf);
    cout << buf;
    return 0;
}
