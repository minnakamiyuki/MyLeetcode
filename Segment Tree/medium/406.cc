// https://leetcode.com/problems/queue-reconstruction-by-height/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    static bool cmp( vector<int> a, vector<int> b ){
        if ( a[0] == b[0] )
            return a[1] > b[1];
        else
            return a[0] < b[0];
    }
    vector<vector<int> > reconstructQueue(vector<vector<int> >& people) {
 
    const int X = 2048;
    sort(people.begin(), people.end(), cmp);
 
    vector<vector<int>> ans(people.size(), vector<int>(2, -1));
 
    vector<int> tree(4*X+1);
    const int n = people.size();
    int j, location_num;
    // 构建树，这是一颗完全二叉树，如线段树构建数 
    for (int l = 1, i = 2, k = X; i <= 2 * X; i <<= 1,k >>= 1)   // 每一层
        for (j = i >> 1; j--;)                        // 每一层有多少节点
            tree[l++] = k;                       // k为 以当前节点l为根的树，的空位数。  
 
 
    for (int i = 0; i < n;i++){
        for (j = 1, location_num = people[i][1]; j < 2 * X; j <<= 1){    // 注意这里是 j<2*X 不是小于等于，因为构建这棵线段树的所有节点数为2*X-1
 
            if (location_num >= tree[j]) {
                location_num -= tree[j++];
            }
            tree[j]--;
 
        }
        j >>= 1;  // 因为跳出的条件是j<4096，它的前一步为 j<<=1 ，也就是乘以2。只要跳出循环，就说明当前j节点，不在树内，它的上一个(父)节点在树内。j/=2 
        ans[j-X]=people[i];
    }
 
    people = ans;
    return people;
 
    }
};