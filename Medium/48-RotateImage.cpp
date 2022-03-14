/**
 * Question: 48. Rotate Image
 * 
 * Author Yifan Yuan
 * Date 2022-03-12
 * Description: 
 * You are given an n x n 2D matrix representing an image, rotate the image by 90 degrees (clockwise)
 * Do not allocate another 2D matrix and do the rotation.
 * 
 * Input:  matrix = [[1,2,3],[4,5,6],[7,8,9]]
 * Output: [[7,4,1],[8,5,2],[9,6,3]]
 * ex: [1, 2, 3]    [7, 4, 1]
 *     [4, 5, 6] -> [8, 5, 2]
 *     [7, 8, 9]    [9, 6, 3]
 * 
 * Constraints:
 *     1. n == matrix.length == matrix[i].length
 *     2. 1 <= n <= 20
 *     3. -1000 <= matrix[i][j] <= 1000
 * 
 * Source: https://leetcode.com/problems/rotate-image/
 */

/**********************************************************************************
 * How to solve this questions in the given matrix?
 * Idea: rotating is the same with flipping it by the diagonal
 *       then flip it from the middle
 * ex. [1, 2, 3]    [1, 4, 7]    [7, 4, 1]
 *     [4, 5, 6] -> [2, 5, 8] -> [8, 5, 2]
 *     [7, 8, 9]    [3, 6, 9]    [9, 6, 3]
 *********************************************************************************/

// Runtime: 0 ms, faster than 100.00% of C++ online submissions for Rotate Image.
void rotate(vector<vector<int>>& matrix) {
    int n = matrix.size();
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < i; ++j) { // j<1 or will flip back
            // flip by diagonal
            swap(matrix[i][j], matrix[j][i]);
        }
    }
    
    for (int i = 0; i < n; ++i) {
        // flip it by middle
        reverse(matrix[i].begin(), matrix[i].end());
    }
}