class Solution {
public:
    vector<int> minOperations(string boxes) {
        vector<int>v;
        for(int i = 0 ; i < boxes.size() ; i++){
            int count = 0;
            for(int j = 0 ; j < boxes.size() ; j++){
                if(i!=j){
                    if(boxes[j] == '1'){
                        count+= abs(j-i);
                    }
                }
            }
            v.push_back(count);
        }
        return v;
    }
};