#include <iostream>
#include <algorithm>
#include <vector>
#include <numeric>

// 普通筛法TLE
class Solution {
public:
    int idealArrays(int n, int maxValue) {
        std::vector<int> dp(10000);
        const int mod = 1e9+7, div = maxValue >> 1;
        std::fill(std::begin(dp), std::begin(dp) + maxValue, 1);
        for (int i = 1; i < n; ++i)
            for (int j = 1; j <= div; ++j) {
                for (int k = 2 * j; k <= div; k += j)
                    dp[j - 1] = (dp[j - 1] + dp[k - 1]) % mod;
                dp[j - 1] = (dp[j - 1] + maxValue / j - (maxValue >> 1) / j) % mod;
            }
        return std::accumulate(
                            std::begin(dp), 
                            std::begin(dp) + maxValue, 0, 
                            [&](int s, int n) { return (s + n) % mod; }
                            );
    }
};

// 杜教筛优化
using ll = long long;
constexpr int64_t mod = 1e9+7;

class Solution {
    int idealArrays(int n, int maxValue) {
        std::vector<int> primes(10005), cnt(10005), div(10005), I(20);
        std::vector<bool> is_not_prime(10005);
        int m = 0, i, j, ans = maxValue;
        for (I[1] = 1, i = 2; i < 20; ++i) 
            I[i] = (ll) (mod - mod / i) * I[mod%i]%mod;
        for (cnt[1] = 1, i = 2; i <= maxValue; ++i) {
            if (!is_not_prime[i]) {
                cnt[primes[m++]=i] = n - 1;
                div[i] = 1;
            }
            ans = (ans + (ll)maxValue / i * cnt[i])%mod;
            for (j = 0; j < m && i * primes[j] <= maxValue; ++j) {
                is_not_prime[i * primes[j]] = 1;
                if (i%primes[j]) {
                    cnt[i * primes[j]] = (ll)cnt[i] * (n - 1)%mod;
                    div[i * primes[j]] = 1;
                } else {
                    cnt[i * primes[j]] = (ll)cnt[i] * (div[i] + n - 1)%mod * I[div[i] + 1]%mod;
                    div[i * primes[j]] = div[i] + 1;
                    break;
                }
            }
        }
        return ans;
    }
};
