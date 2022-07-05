class Solution {
public:
    int minNumberOperations(vector<int>& target) {
        int count= 0;
        vector<int>numsv;
        numsv.push_back(0);
        for(int i = 0 ; i < target.size() ; i++){
            numsv.push_back(target[i]);
        }
        for(int i = 1 ; i < numsv.size() ; i++){
            if(numsv[i-1] < numsv[i])count+=numsv[i]-numsv[i-1];
        }
        return count;
    }
};