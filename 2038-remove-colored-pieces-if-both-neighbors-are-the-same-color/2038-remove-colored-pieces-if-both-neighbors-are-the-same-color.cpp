class Solution {
public:
    bool winnerOfGame(string colors) {
        int ca = 0, cb = 0;
        int n= colors.size(), i(0);
        while(i < n){
            int a = 0, b = 0;
            if(colors[i] == 'A'){
                while(i < n and colors[i] == 'A'){
                    i++;
                    a++;
                }
                if(a>=3)ca+=a-2;
            }
            else{
                while(i < n and colors[i] == 'B'){
                    i++;
                    b++;
                }
                if(b>=3)cb+=b-2;
            }
        }
        // cout << ca << " " << cb << endl;
        return ca > cb;
    }
};