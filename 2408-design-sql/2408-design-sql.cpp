class SQL {
public:
    map<string, vector<vector<string>>>mp;
    SQL(vector<string>& names, vector<int>& columns) {
        
    }
    
    void insertRow(string name, vector<string> row) {
        if(mp.find(name)==mp.end()){
            int j = 1;
            row.insert(row.begin(),to_string(j));
            mp[name].push_back(row);
        }else{
            string id = mp[name].back()[0];
            row.insert(row.begin(),to_string(stoi(id)+1));
            mp[name].push_back(row);   
        }
    }
    
    void deleteRow(string name, int rowID) {
        // for(int i = 0 ; i < mp[name].size() ; i++){
        //     if(stoi(mp[name][i][0]) == rowID){
        //         mp[name].erase(mp[name].begin()+i);
        //         break;
        //     }
        // }
    }
    
    string selectCell(string name, int rowID, int columnID) {
        for(int i = 0 ; i < mp[name].size() ; i++){
            if(stoi(mp[name][i][0]) == rowID){
                return mp[name][i][columnID];
            }
        }
        return "";
    }
};

/**
 * Your SQL object will be instantiated and called as such:
 * SQL* obj = new SQL(names, columns);
 * obj->insertRow(name,row);
 * obj->deleteRow(name,rowId);
 * string param_3 = obj->selectCell(name,rowId,columnId);
 */