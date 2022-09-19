class Solution {
public:
    // learn hi karlo simple
    int totalHammingDistance(vector<int>& nums) {
        int count(0);
        for(int i = 0 ; i < 32 ; i++){
            int c0(0), c1(0);
            int mask = 1 << i;
            for(auto ele : nums){
                if((ele & mask) == 0)c0++;
                else c1++;
            }
            count+=c1*c0;
        }
        return count;
    }
};