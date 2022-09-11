class Solution {
public:
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        int n(products.size());
        vector<vector<string>>ans;
        for(int i =1 ;i <=searchWord.size() ; i++){
            string str = searchWord.substr(0,i);
            priority_queue<string>pq;
            vector<string>temp;
            for(int j = 0 ; j < n ; j++){
                if(str.size()<=products[j].size()){
                    if(str == products[j].substr(0,i)){
                        pq.push(products[j]);
                        if(pq.size()>3)pq.pop();
                    }
                }
            }
            while(pq.size()){
                temp.push_back(pq.top());
                pq.pop();
            }
            sort(temp.begin(), temp.end());
            ans.push_back(temp);
        }
        return ans;
    }
};