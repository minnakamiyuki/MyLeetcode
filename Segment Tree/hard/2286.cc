// https://leetcode.com/problems/booking-concert-tickets-in-groups/
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 50001;

class BookMyShow {
public:
    BookMyShow(int n, int m) {
        memset(tot, 0, sizeof(tot));
        memset(mi, 0, sizeof(mi));
        memset(sum, 0, sizeof(sum));
        
        this->n = n;
        this->m = m;
        c = 0;
    }
    
    vector<int> gather(int k, int maxRow) {
        int l = 0, r = maxRow + 1;
        while (l < r) {
            int mid = (l + r) >> 1;
            if (m - get_min(0, mid, 0, n-1, 1) >= k) r = mid;
            else l = mid + 1;
        }
        
        if (l > maxRow) return {};
        
        vector<int> ans(2);
        ans[0] = l;
        ans[1] = tot[l];
        
        tot[l] += k;
        modify(l, tot[l], 0, n-1, 1);
        
        return ans;
    }
    
    bool scatter(int k, int maxRow) {
        ll s = get_sum(0, maxRow, 0, n-1, 1);
        if ((ll)(m) * (maxRow + 1) - s < k)
            return false;
        
        while (k > 0) {
            if (k >= m - tot[c]) {
                modify(c, m, 0, n-1, 1);
                k -= m - tot[c];
                tot[c] = m;
                c++;
            } else {
                modify(c, tot[c] + k, 0, n-1, 1);
                tot[c] += k;
                k = 0;
            }
        }
        return true;
    }
    
private:
    int tot[N], mi[4 * N];
    ll sum[4 * N];
    
    int n, m, c;
    
    void pushup(int x) {
        int ls = x << 1, rs = x << 1 | 1;
        sum[x] = sum[ls] + sum[rs];
        mi[x] = min(mi[ls], mi[rs]);
    }
    
    void modify(int p, int x, int l, int r, int rt) {
        if (l == r) {
            sum[rt] = x;
            mi[rt] = x;
            
            return;
        }
        
        int mid = (l + r) >> 1;
        
        if (p <= mid) modify(p, x, l, mid, rt << 1);
        else modify(p, x, mid + 1, r, rt << 1 | 1);
        
        pushup(rt);
    }
    
    ll get_sum(int L, int R, int l, int r, int rt) {
        if (L <= l && r <= R) 
            return sum[rt];
        
        int mid = (l + r) >> 1;
        ll res = 0;
        
        if (L <= mid) res += get_sum(L, R, l, mid, rt << 1);
        if (mid < R) res += get_sum(L, R, mid + 1, r, rt << 1 | 1);
        
        return res;
    }
    
    int get_min(int L, int R, int l, int r, int rt) {
        if (L <= l && r <= R) 
            return mi[rt];
        
        int mid = (l + r) >> 1;
        int res = 0x7FFFFFFF;
    
        if (L <= mid) res = min(res, get_min(L, R, l, mid, rt << 1));
        if (mid < R) res = min(res, get_min(L, R, mid + 1, r, rt << 1 | 1));
        
        return res;
    }
};