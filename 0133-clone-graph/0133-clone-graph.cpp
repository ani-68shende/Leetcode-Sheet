class Solution {
public:
    void dfs(Node* node, Node* copy, vector<Node*>& visited){
        visited[copy->val] = copy;
        for(Node *child : node->neighbors){
            if(visited[child->val] == NULL){
                Node* temp = new Node(child->val);
                copy->neighbors.push_back(temp);
                dfs(child, temp, visited);
            }else{
                copy->neighbors.push_back(visited[child->val]);
            }
        }
    }
    Node* cloneGraph(Node* node) {
        if(node == NULL)return node;
        Node* copy = new Node(node->val);
        vector<Node* > visited(101, NULL);
        dfs(node, copy, visited);
        return copy;
    }
};