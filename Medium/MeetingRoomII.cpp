
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