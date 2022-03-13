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