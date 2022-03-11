
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