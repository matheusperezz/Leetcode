//
// Created by mdperez on 6/26/25.
//
#include <vector>
#include <iostream>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> m;
        for (int i = 0; i < nums.size(); i++) {
            int c = target - nums[i];
            if (m.find(c) != m.end()) {
                return {m[c], i};
            }
            m[nums[i]] = i;
        }

        return {};
    }
};


int main() {
    Solution s;
    vector nums = {3,2,4};
    int target = 6;
    vector<int> result = s.twoSum(nums, target);
    for (int i : result) {
        cout << i << " ";
    }
    return 0;
}
