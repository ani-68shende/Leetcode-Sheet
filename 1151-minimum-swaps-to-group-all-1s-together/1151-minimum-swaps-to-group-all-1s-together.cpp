class Solution {
public:
    int minSwaps(vector<int>& data) {
        int countones = 0;
        for(auto xd : data)if(xd)countones++;
        int i = 0, j =0;
        int n = data.size();
        int count = 0;
        int mini = n+1;
        if(countones == 0)return 0;
        // in short k = countones
        int k = countones;
        while(j < n){
            if(!data[j])count++;
            if(j-i+1 == k){
                mini = min(mini, count);
                if(data[i]==0)count--;
                i++;
            }
            j++;
        }
        return mini;
    }
};