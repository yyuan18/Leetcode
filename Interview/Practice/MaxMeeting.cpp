/**
 * Question: Find Maximum Meetings in one room
 * 
 * Author Yifan Yuan
 * Date 2022-03-12
 * Description: 
 * One meeting room, N meetings in the form of (StartTime[i], FinishTime[i]).
 * Find the maximum meeting in this room.
 * 
 * Input:  s[] = {1, 3, 0, 5, 8, 5}, f[] = {2, 4, 6, 7, 9, 9}
 * Output: 4
 * 
 * Source: geeksforgeeks
 */

/**********************************************************************************
 * Greedy algorithm -- need to sort it first with finish time (make pair).
 *********************************************************************************/

#include <vector>
using namespace std;

bool sortbysec(const pair<int, int> &p1, const pair<int, int> &p2) {
    return (p1.second < p2.second);
}

int maxMeetings(int start[], int end[], int n) {
    vector<pair<int, int>> meetings;

    int max = 1;
    int prev = 0;

    for (int i = 0; i < n; ++i) {
        meetings.push_back(make_pair(start[i], end[i]));
    }

    sort(meetings.begin(), meetings.end(), sortbysec);
    // Or just save finish time first cause sort would sort by first

    for (int i = 0; i < n; ++i) {
        if (meetings[i].first > meetings[i].second) {
            max++;
            prev = i;
        }
    }

    return max;
}