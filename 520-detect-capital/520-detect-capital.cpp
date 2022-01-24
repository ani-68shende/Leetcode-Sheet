//24/01/2022

class Solution {
public:
    bool detectCapitalUse(string word) {
        int n = word.size();
        // if size <= 1 return true
        if(n<=1)return true;
        int count = 0;
        for(int i = 0 ; i < n ; i++){
            if(word[i]>='A' && word[i]<='Z')count++;
        }
        //here I am checking if the first element is the only one which is capital or not
        //otherwise if all are capital then we can return true 
        //eleif all are small letters then we can simply return true
        
        //** And if nothing of the above is possible then we can return false
        if((count == 1 && word[0] >= 'A' && word[0]<='Z')|| count == n || count == 0)return true;
        else return false;
    }
};