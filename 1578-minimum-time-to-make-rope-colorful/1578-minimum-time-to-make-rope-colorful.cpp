class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        // vector<pair<char, int>>v;
        int n = colors.size();
        if(n == 1)return 0;
        // for(int i = 0 ; i < n ; i++){
        //     v.push_back({colors[i], neededTime[i]});
        // }
        int count =0 ;
        for(int i = 1 ;i < n ; i++){
            if(i < n && colors[i-1] == colors[i]){
                vector<int>v;
                while(i < n && colors[i-1] == colors[i]){
                    v.push_back(neededTime[i-1]);
                    i++;
                }
                v.push_back(neededTime[i-1]);
                //cout << v.size() << endl;
                sort(v.begin(), v.end());
                for(int j = 0 ; j < v.size()-1 ; j++){
                    //cout << " Number : " << v[i] << " ";
                    count+= v[j]; 
                }
                //cout << endl;
            }
        }
        return count;
    }
};