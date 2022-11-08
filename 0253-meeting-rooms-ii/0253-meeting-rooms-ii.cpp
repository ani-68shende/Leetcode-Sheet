class Solution {
public:
    int minMeetingRooms(vector<vector<int>>& intervals) {
        vector<int>arr,depar;
        int i = 1, j =0;
        int maxu = 1;
        int count = 1;
        int n = intervals.size();
        for(int i = 0 ; i < n ; i++){
            arr.push_back(intervals[i][0]);
            depar.push_back(intervals[i][1]);
        }
        sort(arr.begin(), arr.end());
        sort(depar.begin(), depar.end());
        while(i < n && j < n){
            if(arr[i] < depar[j]){
                count++;
                i++;
            }else{
                count--;
                j++;
            }
            maxu = max(maxu, count);
        }
        return maxu;
    }
};