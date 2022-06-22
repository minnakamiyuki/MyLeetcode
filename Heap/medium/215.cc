// https://leetcode.com/problems/kth-largest-element-in-an-array/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    void heap_Sort(vector<int>& sort, int n, int i) {
		for (int j = n - 1; j >= 0; --j) {
			swap(sort[j], sort[i]);
			heapify(sort, j, 0);
		}
	}

	void heapify(vector<int>& ify, int n, int i) {
		if (n <= i) {
			return;
		}
		int c1 = i * 2 + 1;
		int c2 = i * 2 + 2;
		int max = i;
		if (c1 < n && ify[c1] > ify[max]) {
			max = c1;
		}
		if (c2 < n && ify[c2] > ify[max]) {
			max = c2;
		}
		if (max != i) {
			swap(ify[i],ify[max]);
			heapify(ify, n, max);
		}
	}

	void build_heap(vector<int>& bui, int n) {
		int last_Node = n - 1;
		int parent = (last_Node - 1) >> 1;
		for (int i = parent; i >= 0; --i) {
			heapify(bui, n, i);
		}
	}

	int findKthLargest(vector<int>& nums, int k) {
		int n = nums.size();
		build_heap(nums, n);
		if (k == 1) {
			return nums[0];
		}
		else {
			for (int j = 1; j < k; j++) {
				swap(nums[0], nums[n - j]);
				heapify(nums, n - j, 0);
			}
			return nums[0];
		}
	}
};