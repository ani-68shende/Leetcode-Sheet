class Solution {
public:
    string countAndSay(int n) {
        string s = "1";
        vector<string>h(31);
        h[0] = "1";
        h[1] ="1";
        for(int i = 2 ; i <= n ; i++){
            string g = "";
            string tempo = h[i-1];
            for(int j = 0 ; j < tempo.size() ; j++){
                int count = 0;
                string kk = "";
                kk.push_back(tempo[j]);
                int y = j;
                while(y < tempo.size() && tempo[y] == tempo[j]){
                    count++;
                    y++;
                }
                j = y-1;
                //cout << "count " << count << "kk " << kk << "\n";
                g += to_string(count);
                g+= kk;
            }
            h[i] = g;
            //cout << i << " " << tempo << endl;
        }
        return h[n];
    }
};