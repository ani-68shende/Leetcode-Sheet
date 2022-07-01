class Solution {
public:
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        vector<pair<int, int>>v;
        for(auto x : boxTypes){
            v.push_back({x[1],x[0]});
        }
        for(auto x : v){
            cout << x.first << " " << x.second << endl;
        }
        sort(v.begin(), v.end(), greater<pair<int,int>>());
        for(auto x : v){
            cout << x.first << " " << x.second << endl;
        }
        int count = 0;
        int siz = truckSize;
        for(auto t : v){
            if(siz>=t.second){
                count+= t.second*t.first;
                siz -= t.second;
            }
            else{
                while(siz!=0 && t.second>0){
                    count+= t.first;
                    siz--;
                    t.second--;
                }
                break;
            }
            cout << "count :" << count << endl;
        }
        return count;
    }
};