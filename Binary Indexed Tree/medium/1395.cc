// https://leetcode.com/problems/count-number-of-teams/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
private:
    int m;

public:
    int query(const vector<int> &f, int x) {
        int tot = 0;
        for (; x; x -= x & -x)
            tot += f[x];

        return tot;
    }

    void add(vector<int> &f, int x, int y) {
        for (; x <= m; x += x & -x)
            f[x] += y;
    }

    int numTeams(vector<int>& rating) {
        int n = rating.size();
        int ans = 0;

        vector<int> s(rating);
        sort(s.begin(), s.end());
        m = unique(s.begin(), s.end()) - s.begin();
        s.resize(m);
        for (int i = 0; i < n; i++)
            rating[i] = lower_bound(s.begin(), s.end(), rating[i]) - s.begin() + 1;

        vector<int> f(m + 1, 0), g(m + 1, 0);

        for (int i = 0; i < n; i++)
            add(g, rating[i], 1);


        for (int i = 0; i < n; i++) {
            int l1 = query(f, rating[i] - 1);
            int l2 = i - query(f, rating[i]);
            int r1 = query(g, rating[i] - 1);
            int r2 = n - i - query(g, rating[i]);

            ans += l1 * r2 + l2 * r1;

            add(f, rating[i], 1);
            add(g, rating[i], -1);
        }

        return ans;
    }
};