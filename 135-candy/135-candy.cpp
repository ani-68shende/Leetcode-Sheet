class Solution {
public:
     int candy(vector<int> &ratings)
     {
         int n=ratings.size();
         if(n<=1)
             return n;
         vector<int>left(n,1) , right(n,1);
         for(int i = 1 ; i < n ; i++){
             if(ratings[i-1] < ratings[i]){
                 left[i] = left[i-1]+1;
             }
         }
         for(int i = n-1 ; i>0 ; i--){
             if(ratings[i-1] > ratings[i]){
                 right[i-1] = right[i]+1;
             }
         }
         int result = 0;
         for(int i = 0 ; i < n ; i++){
             result += max(right[i], left[i]);
         }
         return result;
     }
};