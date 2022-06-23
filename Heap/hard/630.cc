// https://leetcode.com/problems/course-schedule-iii/submissions/
#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

class Solution {
public:
    int scheduleCourse(std::vector<std::vector<int>>& courses) {
        const int n = courses.size();
        sort(courses.begin(), courses.end(), [](const auto &c1, const auto &c2){ 
            return c1[1] < c2[1]; 
            }); // 按课程结束时间排序
        int time = 0; // 上课总共花费的时间
        std::priority_queue<int> PQ; // 创建优先队列来存储上课时间
        for (auto &course : courses) {
            int t = course[0], end = course[1];
            PQ.emplace(t); // 将t加入优先队列
            time += t; // 总上课时间增加
            if (time > end) {
            time -= PQ.top();
            PQ.pop(); // 移除上课时间最多的课程，选择上第i门课程
            }
        }
        return PQ.size();
    }
};