
/**
 * Given an array of meeting time intervals where intervals[i] = [start, end], return min number of conference rooms required.
 * ex. intervals = [[0,30], [5,10], [15,20]], return: 2
 */

 int minMeetingRooms(vector<vector<int>>& intervals) {
    if (intervals.empty()) return 0;
    
    int r = 0;
    int f = 0;
    int e = 0;
    
    int size = intervals.size();
    vector<int> start(size);
    vector<int> finish(size);
    
    for (int i = 0; i < size; ++i) {
        start[i] = intervals[i][0];
        finish[i] = intervals[i][1]；
    }
    sort(start.begin(), start.end());
    sort(finish.begin(),finish.end());
    
    for (int i = 0; i < size; ++i) {
        int time = start[i];
        while (e < size && finish[e] <= time) {
            e++;
            f++;
        }
        
        if (f > 0) f--;
        else r++;
    }
    return r;
    
 }

 // Dylan's solution
bool predicate(vector<int>& v1, vector<int>& v2) {
    if (v1[0] == v2[0]) {
        return v1[1] < v2[1];
    }
    return v1[0] < v2[0];
}

class Solution {
public:
    int minMeetingRooms(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), predicate);
        int res = 0;
        int i = 0;
        int size = intervals.size();
        int prevVal;
        priority_queue<int, vector<int>, greater<int>> pq;
        while (i < size) {
            while (!pq.empty() && intervals[i][0] >= pq.top()) {
                pq.pop();
            }
            pq.push(intervals[i][1]);
            int currSize = pq.size();
            res = max(currSize, res);
            i++;
        }
        return res;
    }
};