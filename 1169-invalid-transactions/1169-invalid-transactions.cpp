#include<bits/stdc++.h>
class Solution {
    public:
    vector<string> invalidTransactions(vector<string>& zzz) {
        vector<vector<string>>valid;
        vector<string>invalid;
        int n = zzz.size();
        vector<vector<string>>t;
        for(int i = 0 ; i < zzz.size() ; i++){
            string temp, h = zzz[i];
            vector<string>f;
            for(int j = 0 ; j < h.size() ; j++){
                if(h[j] == ','){
                    f.push_back(temp);
                    temp = "";
                }else{
                    temp.push_back(h[j]);
                }
            }
            f.push_back(temp);
            t.push_back(f);
        }
        unordered_map<string, vector<vector<string>>>mp;
        for(int i = 0 ; i < t.size(); i++){
            int cost = stoi(t[i][2]);
            // if(cost > 1000){
            //     invalid.push_back(zzz[i]);
            // }else{
                vector<string>temp;
                temp.push_back(t[i][1]);
                temp.push_back(t[i][2]);
                temp.push_back(t[i][3]);
                mp[t[i][0]].push_back(temp);
            // }
        }
        // for(auto x : t){
        //     for(auto y : x){
        //         cout << y << " ";
        //     }
        //     cout << "\n";
        // }
        for(auto x : mp){
            string s = x.first;
            vector<vector<string>> vec = x.second;
            int n2 = vec.size();
            vector<int>visited(n2,0);
            // cout << x.first << endl;
            // for(auto r : x.second){
            //    for(auto y : r)cout << y << " ";
            // }cout << "\n";
            for(int i = 0 ; i < vec.size() ; i++){
                int timei = stoi(vec[i][0]);
                int costo = stoi(vec[i][1]);
                if(costo > 1000){
                    visited[i] = 1;
                }
                for(int j = i+1 ; j < vec.size() ; j++){
                    int timej = stoi(vec[j][0]);
                    if(abs(timei-timej)<=60 && vec[i][2] != vec[j][2]){
                        visited[i] = 1;
                        visited[j] = 1;
                    }
                }
            }
            for(int i = 0 ; i < visited.size() ; i++){
                if(visited[i]){
                    string hh;
                    hh += (x.first);
                    for(int j =0 ; j < 3 ; j++){
                        hh.push_back(',');
                        hh += (vec[i][j]);
                    }
                    invalid.push_back(hh);
                }
            }
        }
        return invalid;
    }
};