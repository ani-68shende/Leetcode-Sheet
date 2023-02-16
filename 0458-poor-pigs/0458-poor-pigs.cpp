class Solution {
public:
    // need more intuition
    int poorPigs(int buckets, int minutesToDie, int minutesToTest) {
        int ans = -1;
        int low = 0;
        int high = buckets;
        while(low <= high){
            int mid = low+(high-low)/2;
            if(pow(minutesToTest/minutesToDie+1, mid) >= buckets){
                ans = mid;
                high = mid - 1;
            }else{
                low = mid + 1;
            }
        }
        return ans;
    }
};