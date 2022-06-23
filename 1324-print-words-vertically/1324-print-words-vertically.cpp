class Solution {
public:
    vector<string> printVertically(string s) {
        vector<string>vv;
        string ss;
        int n = s.size();
        for(int i = 0 ; i < n ; i++){
            if(s[i] == ' '){
                vv.push_back(ss);
                ss = "";
            }else{
                ss.push_back(s[i]);
            }
        }
        vv.push_back(ss);
        int maxu = 0;
        for(auto x :vv){
            int siz = x.size();
            maxu = max(maxu, siz);
        }
        vector<string>temp;
        vector<string>ans;
        for(auto x : vv){
            int si = x.size();
            string h = x;
            int y = maxu-si;
            while(y>0){
                h.push_back(' ');
                y--;
            }
            temp.push_back(h);
        }
        // for(auto x : temp){
        //     for(auto d : x){
        //         cout << d << " ";
        //     }
        //     cout << "\n";
        // }
        for(int i = 0 ; i < maxu ; i++){
            string tempo = "";
            for(int j = 0 ; j < temp.size() ; j++){
                tempo.push_back(temp[j][i]);
            }
            //reverse(tempo.begin(), tempo.end());
            while(tempo[tempo.size()-1] == ' '){
                tempo.pop_back();
            }
            //reverse(tempo.begin(), tempo.end());
            ans.push_back(tempo);
        }
        return ans;
    }
};