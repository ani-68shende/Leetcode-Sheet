class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        //Bayers Moore Voting Algorithm
        
        //do the checking of the elements at the start man otherwise the answer will go wrong 
        //if possible plz watch the video for better understanding
        int elem = -1;
        int ele = -1;
        int count1 = 0;
        int count2 = 0;
        int n = nums.size();
        for(int i = 0 ; i < n ; i++){
            if(elem == nums[i])count1++;
            else if(ele == nums[i])count2++;
            
            else if(count1 == 0){
                elem = nums[i];
                count1++;
            }
            else if(count2 == 0){
                ele = nums[i];
                count2++;
            }
            else{
                count1--;
                count2--;
            }
        }
        vector<int>v;
        count1 = 0;
        count2 = 0;
        for(auto c : nums){
            if(c == ele)count2++;
            else if(c == elem)count1++;
        }
        if(count1>n/3)v.push_back(elem);
        if(count2>n/3)v.push_back(ele);
        return v;
    }
};