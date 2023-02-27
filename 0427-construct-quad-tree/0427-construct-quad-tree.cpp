/*
// Definition for a QuadTree node.
class Node {
public:
    bool val;
    bool isLeaf;
    Node* topLeft;
    Node* topRight;
    Node* bottomLeft;
    Node* bottomRight;
    
    Node() {
        val = false;
        isLeaf = false;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf, Node* _topLeft, Node* _topRight, Node* _bottomLeft, Node* _bottomRight) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = _topLeft;
        topRight = _topRight;
        bottomLeft = _bottomLeft;
        bottomRight = _bottomRight;
    }
};
*/

/*
// Definition for a QuadTree node.
class Node {
public:
    bool val;
    bool isLeaf;
    Node* topLeft;
    Node* topRight;
    Node* bottomLeft;
    Node* bottomRight;
    
    Node() {
        val = false;
        isLeaf = false;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf, Node* _topLeft, Node* _topRight, Node* _bottomLeft, Node* _bottomRight) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = _topLeft;
        topRight = _topRight;
        bottomLeft = _bottomLeft;
        bottomRight = _bottomRight;
    }
};
*/

class Solution {
public:
    
    int values(vector<vector<int>>& grid)
    {
        
       int zeros=0,ones=0;
        
        for(auto a:grid)
        {
            for(auto b:a)
            {
                if(b)
                {
                    ones++;
                }
                else
                {
                    zeros++;
                }
            }
        }
        
        if(!zeros)
            return 1;
        
        if(!ones)
            return 0;
        
        return -1;
    
    }
    
    vector<vector<vector<int>>> split(vector<vector<int>>& grid)
    {
        
        int n=grid.size()/2;
        
        vector<vector<int>> top(grid.begin(),grid.begin()+n);
        
        vector<vector<int>> bottom(grid.begin()+n,grid.end());

        vector<vector<int>> tright,tleft,bright,bleft;
        
        
        for(auto a:top)
        {
            
            vector<int> l(a.begin(),a.begin()+n);
            
            vector<int> r(a.begin()+n,a.end());
            
            tleft.push_back(l);
            tright.push_back(r);
            
        }
        
        
        for(auto a:bottom)
        {

           
            vector<int> l(a.begin(),a.begin()+n);
            
            vector<int> r(a.begin()+n,a.end());
            
            bleft.push_back(l);
            bright.push_back(r);
            
        
        }
        
        return {tleft,tright,bleft,bright};
        
    }

    
    Node* construct(vector<vector<int>>& grid) {
    
        auto v=values(grid);
        
        if(v==0||v==1)
        {
            Node* lf=new Node(v,true);
            return lf;
        }
        
        auto sp=split(grid);
        
        
        vector<Node*> vec;
        
        for(auto a:sp)
        {
        vec.push_back(construct(a));
        }
        
    
        Node* par=new Node(1,false,vec[0],vec[1],vec[2],vec[3]);
       
        return par;
        
    }
};