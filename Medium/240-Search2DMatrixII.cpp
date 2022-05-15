/**
 * Question: 240. Search a 2D Matrix II
 * 
 * Author Yifan Yuan
 * Date 2022-05-15
 * Description: 
 * Write an efficient algorithm that searches for a value target in an m x n integer matrix matrix. This matrix has the following properties:
 *       1. Integers in each row are sorted in ascending from left to right.
 *       2. Integers in each column are sorted in ascending from top to bottom.
 * 
 * Input:  matrix = [[1,4,7,11,15],[2,5,8,12,19],[3,6,9,16,22],[10,13,14,17,24],[18,21,23,26,30]], target = 5
 * Output: true
 * ex: 5 exists in the matrix, so return true, if the target does not exists, return false.
 * 
 * Constraints:
 *     1. m == matrix.length
 *     2. n == matrix[i].length
 *     3. 1 <= n, m <= 300
 *     4. -109 <= matrix[i][j] <= 109
 *     5. All the integers in each row are sorted in ascending order.
 *     6. All the integers in each column are sorted in ascending order.
 *     7. -109 <= target <= 109
 * 
 * Source: https://leetcode.com/problems/search-a-2d-matrix-ii/
 */

/**********************************************************************************
 * How to quickly identify this?
 *********************************************************************************/

// Runtime: 105 ms, faster than 84.53% of C++ online submissions for Search a 2D Matrix II.
// Memory Usage: 14.7 MB, less than 88.38% of C++ online submissions for Search a 2D Matrix II.

bool searchMatrix(vector<vector<int>>& matrix, int target) {
    // matrix is m x n so find m and n.
    int m = matrix.size();
    int n = matrix[0].size();
    if (m == 0 || n == 0) {
        return false;
    }
    int i = 0;
    int j = n - 1;
    
    while (i < m && j >= 0) {
        if (matrix[i][j] == target) {
            return true;
        }
        else if (matrix[i][j] > target) {
            --j;
        }
        else {
            ++i;
        }
    }
    return false;
}