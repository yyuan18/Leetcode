# Leetcode
Leetcode questions with solutions in C++ and my study notes. 

## Folders

- Easy, Medium, Hard -- leetcode categorized questions
- Interview -- contains Interview questions I experienced or practice.
- LeetCode 101 -- from the great coding book LeetCode 101
- Note -- things I leant while doing problems

## Format

- All solutions will be referenced by Author, time, description, and URL.
- The cpp file might contain different solutions to one problem.

```
/**
 * Question: 33. Search in Rotated Sorted Array
 * 
 * Author Yifan Yuan
 * Date 2022-03-12
 * Description: 
 * There is an integer array nums sorted in ascending order (with distinct values).
 * The array will be rotated at an unknown pivot index k (1 <= k < nums.length).
 * ex. [1, 2, 3, 4, 5, 6, 7] (rotated at k=3)--> [4, 5, 6, 7, 1, 2, 3]
 * 
 * Input:  nums = [4,5,6,7,0,1,2], target = 0
 * Output: 4
 * 
 * Input:  nums = [4,5,6,7,0,1,2], target = 3
 * Output: -1
 * 
 * You must write an algorithm with O(log n) runtime complexity.
 * 
 * Source: https://leetcode.com/problems/search-in-rotated-sorted-array/
 */

#include<vector>

using namespace std;
int search(vector<int>& nums, int target) {
        
    int start = 0;
    int end = nums.size()-1;
    while (start < end) {
        int mid = (start + end) /2;
        if (nums[mid] > nums[end]) start = mid + 1;
        else end = mid;
    }
    
    cout << "Problem Index: "  << start << endl;
    
    int problem = start;
    start = 0, end = nums.size()-1;
    
    while (start <= end) {
        int mid = (start + end)/2;
        int realmid = (mid + problem)%(nums.size());
        cout << "realmid = " << realmid << endl;
        
        if (nums[realmid] == target) return realmid;
        if (nums[realmid] < target) start = mid + 1; //second half
        else end = mid - 1;
    }
    return -1;
}
```