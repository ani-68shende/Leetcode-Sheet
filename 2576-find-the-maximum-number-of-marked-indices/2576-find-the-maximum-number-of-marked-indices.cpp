#define kkkk long long
kkkk mod = (kkkk)1000000007;
class Solution {
public:
    int maxNumOfMarkedIndices(vector<int>& lonis) {
        kkkk sd = lonis.size(), i = 0, as = 0, kh = sd, flag = 0;
        sort(lonis.begin(), lonis.end());
        kkkk j = sd/2;
        if(sd%2==1){
            j++;
        }
        while (i <j && j < sd) {
            if (lonis[i] * 2 <= lonis[j]) {
                i++,j++;
                as++;
            } else
                j++;
        }
        kkkk gg = as*2;
        return gg;         
    }
};