class Solution {
public:
    int lenLongestFibSubseq(vector<int>& num) {
        unordered_map<int, int>mp;
        for(auto x : num){
            mp[x]++;
        }
        int maxu = 1;
        for(int i = 0 ; i < num.size() ; i++){
            for(int j = i + 1 ; j < num.size() ; j++){
                int count = 2;
                int a = num[i];
                int b = num[j];
                int c = a+b;
                while(mp.find(c)!=mp.end()){
                    a=b;
                    b=c;
                    c=a+b;
                    count++;
                }
                maxu = max(maxu, count);
            }
        }
        return maxu>2 ? maxu : 0;
    }
};