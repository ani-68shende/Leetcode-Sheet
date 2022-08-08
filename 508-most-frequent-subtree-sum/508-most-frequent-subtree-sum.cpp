/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int find(TreeNode* root, vector<int>& curr, int sum){
        if(!root)return 0;
        int left = find(root->left, curr, sum);
        int right = find(root->right, curr, sum);
        sum+= root->val + left + right;
        curr.push_back(sum);
        return sum;
    }
    vector<int> findFrequentTreeSum(TreeNode* root) {
        int sum = 0;
        vector<int>curr;
        vector<int>dummy;
        int y = find(root, curr, sum);
        for(auto &c : curr){
            cout << c << " ";
        }cout << endl;
        vector<int>v;
        unordered_map<int, int>mp;
        for(auto x: curr)
            mp[x]++;
        int maxu = 0;
        for(auto y : mp){
            maxu = max(maxu, y.second);
        }
        for(auto x : mp){
            if(x.second == maxu){
                v.push_back(x.first);
            }
        }
        // sort(v.begin(), v.end(),greater<pair<int,int>>());
        // for(int i = 0 ;i < v.size() ; i++){
        //     if(maxu == v[i].first){
        //         dummy.push_back(v[i].second);
        //     }
        // }
        return v;
    }
};