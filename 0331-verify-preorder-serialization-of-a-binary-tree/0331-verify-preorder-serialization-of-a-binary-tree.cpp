
class Solution {
public:
    bool isValidSerialization(string preorder) {
        int counto = 1;
        string str;
        stringstream ss(preorder);
        while(getline(ss, str, ',')){
            counto--;
            if(counto<0)return false;
            if(str!="#")counto+=2;
        }
        return counto==0;
    }
};