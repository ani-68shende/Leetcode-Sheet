class Solution {
public:
    int validSubarrays(vector<int>& nums) {
        int counto = 0;
        stack<int>s;
        //maintain a strictly increasing array
        for(int i = 0 ; i < nums.size() ; i++){
            while(s.size() && s.top() > nums[i]){
                s.pop();
            }
            s.push(nums[i]);
            counto += s.size();
        }
        return counto;
    }
};