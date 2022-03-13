/**
 * Question: 448. ind All Numbers Disappeared in an Array
 * 
 * Author Yifan Yuan
 * Date 2022-03-12
 * Description: 
 * Given an array nums of n integers where nums[i] is in the range [1, n], 
 * return an array of all the integers in the range [1, n] that do not appear in nums.
 * 
 * Input:  nums = [4,3,2,7,8,2,3,1]
 * Output: [5, 6]
 * 
 * Source: https://leetcode.com/problems/find-all-numbers-disappeared-in-an-array/
 */

/**********************************************************************************
 * Array -- Fixed size
 * How to solve this questions without using extra space?
 * Idea: since we know if all numbers are correct, then we use (nums[num] - 1)
 *       should be able to acess all numbers. We know i<=nums[i]<n
 *       so if there are numbers missing, there will be duplicates.
 *       If we times all numbers with -1, if there are no duplicates, then the
 *       numbers should all be 0, if there are duplicated, we need to use abs()
 *       to make sure that we don't change the dupliated postion back to positive.
 *       After that, the only positive numbers' (position+1) left is missing ones.
 *********************************************************************************/

vector<int> findDisappearedNumbers(vector<int>& nums) {
    vector<int> missing;
    for (const int num : nums) {
        int pos = abs(num) - 1;
        if (nums[pos] > 0) {
            nums[pos] = -nums[pos];
        }
    }
    
    for (int i = 0; i < nums.size(); ++i) {
        if (nums[i] > 0) {
            missing.push_back(i+1);
        }
    }
        
    return missing;
}