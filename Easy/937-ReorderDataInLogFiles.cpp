/**
 * Question: 937. Reorder Data in Log Files
 * 
 * Author Yifan Yuan
 * Date 2022-4-9
 * Description: 
 * You are given an array of logs. Each log is a space-delimited string of words, 
 * where the first word is the identifier. There are two types of logs:
 * 
 * Letter-logs: All words (except the identifier) consist of lowercase English letters.
 * Digit-logs: All words (except the identifier) consist of digits.
 * Reorder these logs so that:
 * 
 * The letter-logs come before all digit-logs.
 * The letter-logs are sorted lexicographically by their contents. 
 * If their contents are the same, then sort them lexicographically by their identifiers.
 * The digit-logs maintain their relative ordering.
 * Return the final order of the logs.
 * 
 * Input:  logs = ["dig1 8 1 5 1","let1 art can","dig2 3 6","let2 own kit dig","let3 art zero"]
 * Output: ["let1 art can","let3 art zero","let2 own kit dig","dig1 8 1 5 1","dig2 3 6"]
 * 
 * Constrains:
 * 1 <= logs.length <= 100
 * 3 <= logs[i].length <= 100
 * All the tokens of logs[i] are separated by a single space.
 * logs[i] is guaranteed to have an identifier and at least one word after the identifier.
 * 
 * Source: https://leetcode.com/problems/reorder-data-in-log-files/
 */

/**********************************************************************************
 * This one is very important because it appeared in Amazon's OA.
 *********************************************************************************/


