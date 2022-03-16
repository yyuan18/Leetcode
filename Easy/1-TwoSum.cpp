/**
 * Question: 1. Two Sum
 * 
 * Author Yifan Yuan
 * Date 2022-03-14
 * Description: 
 * Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.
 * You may assume that each input would have exactly one solution, and you may not use the same element twice.
 * You can return the answer in any order.
 * 
 * Input:  nums = [2,7,11,15], target = 9
 * Output: [0, 1]
 * 
 * Constraints:
 *     2 <= nums.length <= 104
 *     -109 <= nums[i] <= 109
 *     -109 <= target <= 109
 *     Only one valid answer exists.
 * 
 * Source: https://leetcode.com/problems/two-sum/
 */

#include <vector>

vector<int> twoSum(vector<int>& nums, int target) {
    std::unordered_map<int, int> hash;
    vector<int> ans;
    for (std::size_t i = 0; i < nums.size(); ++i) {
        int num = nums[i];
        auto pos = hash.find(target - num);
        if (pos == hash.end()) {
            hash[num] = i;
        }
        else {
            ans.push_back(pos->second);
            ans.push_back(i);
            break;
        }
    }
    return ans;
}