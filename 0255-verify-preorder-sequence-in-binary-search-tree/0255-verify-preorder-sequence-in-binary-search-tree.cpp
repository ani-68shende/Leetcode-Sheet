class Solution {
public:
    //dicsuss is helping
    bool verifyPreorder(vector<int>& preorder) {
        //for intuition see second dicuss post
        stack<int>s;
        s.push(preorder[0]);
        int n = preorder.size();
        int lowerbound = INT_MIN;
        for(int i = 1 ; i < n ; i++){
            if(s.empty() || preorder[i-1] > preorder[i]){
                if(preorder[i] < lowerbound)return false;
                s.push(preorder[i]);
            }else{
                while(s.size() && s.top() < preorder[i]){
                    //last one to stand till war ends
                    lowerbound = s.top();
                    s.pop();
                }
                s.push(preorder[i]);
            }
        }
        return true;
    }
};