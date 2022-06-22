// https://leetcode.com/problems/time-needed-to-buy-tickets/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int timeRequiredToBuy(vector<int>& tickets, int k) {
        const int n = tickets.size();
        int sum = 0;
        for (int i = 0; i < n; ++i) {
            if (i <= k)
                sum += min(tickets[i], tickets[k]);
            else
                sum += min(tickets[k] - 1, tickets[i]);
        }
        return sum;
    }
};