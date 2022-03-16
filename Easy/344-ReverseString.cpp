/**
 * Question: 344. Reverse String
 * 
 * Author Yifan Yuan
 * Date 2022-03-14
 * Description: 
 * Write a function that reverses a string. The input string is given as an array of characters s.
 * 
 * Input:  s = ["H","a","n","n","a","h"]
 * Output: ["h","a","n","n","a","H"]
 * 
 * Source: https://leetcode.com/problems/reverse-string/
 */

// Real life: built in function reverse(), why not?
void reverseString(vector<char>& s) {
    reverse(s.begin(), s.end());
}

// However I need a job so
// Recursion
void reverseString(vector<char>& s, int pos = 0) {
    int mid = s.size()/2;
    if (pos < mid) {
        swap(s[pos], s[s.size() - pos - 1]);
        reverseString(s, pos+1);
    }
}

// Iteration
void reverseString(vector<char>& s) {
    int pos = 0;
    int mid = s.size()/2;
    while (pos < mid) {
        swap(s[pos], s[s.size() - pos - 1]);
        pos++;
    }
}
