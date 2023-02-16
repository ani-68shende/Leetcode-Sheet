class Solution {
public:
    string orderlyQueue(string s, int k) {
        int n = s.size();
        if(k>1){
            sort(s.begin(), s.end());
        }else{
            string temp = s;
            for(int i = 0 ; i < n ; i++){
                string h = temp.substr(1);
                h+=temp[0];
                s = min(s, h);
                temp = h;
            }
        }
        return s;
    }
};