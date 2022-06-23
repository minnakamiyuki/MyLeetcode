// https://leetcode.com/problems/the-skyline-problem/
#include <iostream>
#include <vector>
#include <unordered_map>
#include <set>
using namespace std;

class Solution {
public:
    unordered_map<int, int> map1; //用于离散化的 实际值->序号 映射
    unordered_map<int, int> map2; //用于离散化的 序号->实际值 映射
    vector<int> tree; //非叶子节点用于传播懒标记，叶子节点用于离散化后的序号对应的高度
    int n; //坐标数量（叶子节点数量）
    
    // 离散化
    void discretization(vector<vector<int>>& buildings)
    {
        set<int> s;
        for (auto& bldg : buildings)
        {
            s.insert(bldg[0]);
            s.insert(bldg[1]);
        }
        int k = 0;
        auto it = s.begin();
        while (it != s.end())
        {
            int num = *it;
            map1[num] = k;
            map2[k] = num;
            ++it;
            ++k;
        }
    }
    
    //懒标记传播（从指定坐标向下传递一层，至其两个叶子节点）
    //这个函数只会在查询是对非叶子节点调用
    void pushDown(int idx)
    {
        if (tree[idx] != 0)
        {
            //根据题意我们需要存储最高的楼层
            //这个代码的线段树数组将根节点存储在下标0的位置，使用2i, 2i+1访问左右子树
            tree[idx*2] = max(tree[idx*2], tree[idx]);
            tree[idx*2+1] = max(tree[idx*2+1], tree[idx]);
            tree[idx] = 0;
        }
    }
    
    //区间更新，low和high是离散化后的序号
    void rangeUpdate(int low, int high, int val)
    {
        //low+n，high+n将离散化后的序号转化为线段树数组中对应的叶子节点的序号
        for (low+=n, high+=n; low <= high; low>>=1, high>>=1)
        {
            //奇数下标在0开始的数组中对应的是右子树，如果左边界为右子树
            //如果左边界是右子树，则只应该更新这个节点而不是其父结点
            if (low & 1) 
            {
                tree[low] = max(tree[low], val); 
                ++low;//这个操作将左边界转移到右边的兄弟节点上（是个左子树）
            }
            //如果右边界是左子树，则只应该更新这个节点而不是其父结点
            if (!(high & 1)) 
            {
                tree[high] = max(tree[high], val); 
                --high; //这个操作将右边界转移到左边的兄弟节点上（是个右子树）
            }
        }
    }
    
    void query(vector<vector<int>>& ans)
    {
        //传播所有懒惰标记（从根开始）
        for (int i = 1; i < n; ++i) pushDown(i);
        //顺序遍历每个叶子节点（即楼的开始或截止的坐标序列化后的序号）
        for (int i = n; i < 2*n; ++i) 
        {
            if (ans.empty() || ans.back()[1] != tree[i]) ans.push_back({map2[i-n], tree[i]});
            //else ans.back()[0] = min(ans.back()[0], map2[i-n]);
            //递归的线段树由于不保证节点按序号从小到大访问，需要上面这句，但迭代的线段树是从小到大访问的
        }
    }
    
    vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
        if (buildings.empty()) return {};
        
        discretization(buildings);        
        n = map1.size();

        tree = vector<int>(2*n, 0);
        
        //结束坐标-1是为了方便在大楼右下角能输出(x, 0)
        for (auto& bldg : buildings) rangeUpdate(map1[bldg[0]], map1[bldg[1]]-1, bldg[2]);
        
        vector<vector<int>> ans;
        query(ans);
        return ans;
    }
    
};