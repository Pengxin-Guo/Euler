# Euler
#### Euler 50 test

**Problem 1. Multiples of 3 and 5**

 思路：把`3`的倍数加一遍，再把`5`的倍数加一遍，最后把`15`的倍数减一遍。

```c
for (int i = 3; i < MAX_N; i += 3) ans += i;
for (int i = 5; i < MAX_N; i += 5) ans += i;
for (int i = 15; i < MAX_N; i += 15) ans -= i;
```

**Problem 2. Even Fibonacci numbers**

思路：利用循环数组，`num[n % 3] = num[(n - 1) % 3] + num[(n - 2) % 3]`，一个长度为`3`的数组即可解决该问题。关键是数组的初始化，`num[0]`代表第一个斐波那契数`1`，之后要想使`num[1]`为`2`，则`num[2]`应初始化为`1`，`num[1]`初始化为`0`即可，这就是数组的初始化，`num[3] = {1, 0, 1}`。

```c
int ans = 0, n = 0;
while (num[n % 3] <= MAX_N) {
    if(!(num[n % 3] & 1))  ans += num[n % 3];
    n += 1;
    num[n % 3] = num[(n - 1) % 3] + num[(n - 2) % 3];
}
```

**Problem 3. Largest prime factor**

思路：从最小的质因数开始，慢慢增大向上除。

```c
int64_t n = 2, ans, num = 600851475143;
while (n * n < num) {
    if (num % n == 0) ans = n;
    while (num % n == 0) num /= n;
    n++;
}
if (num != 1) ans = num
```

**Problem 4. Largest palindrome product**

思路：暴力求解即可。

```c
int is_palindromic(int n) {
    int temp = n, num = 0;
    while (temp) {
        num = num * 10 + temp % 10;
        temp /= 10;
    }
    return num == n;
}

int main() {
    int ans = 0;
    for (int i = 999; i; i--) {
        for (int j = 999; j; j--) {
            if (!is_palindromic(i * j)) continue;
            if (ans < i * j) ans = i * j;
        }
    }
    printf("%d\n", ans);
    return 0;
}
```



 