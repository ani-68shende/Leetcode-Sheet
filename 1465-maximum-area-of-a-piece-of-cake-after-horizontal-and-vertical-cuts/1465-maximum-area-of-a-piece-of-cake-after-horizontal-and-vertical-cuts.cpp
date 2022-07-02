class Solution {
public:
    int maxArea(int h, int w, vector<int>& hc, vector<int>& vc) {
        hc.push_back(0);
        vc.push_back(0);
        hc.push_back(h);
        vc.push_back(w);
        cout << vc.size() << endl;
        sort(hc.begin(),hc.end());
        sort(vc.begin(),vc.end());
        long int maxu1 = 0;
        long int  maxu2 = 0;
        for(int i = 1 ; i < hc.size() ; i++){
            cout << hc[i]-hc[i-1] << " ";
            if(maxu1<= hc[i]-hc[i-1])
                maxu1 = hc[i]-hc[i-1]; 
        }
        for(int i = 1 ; i < vc.size() ; i++){
            cout << vc[i]-vc[i-1] << " ";
            if(maxu2<= vc[i]-vc[i-1])
                maxu2 = vc[i]-vc[i-1]; 
        }
        return (maxu1*maxu2)%(1000000007);
    }
};