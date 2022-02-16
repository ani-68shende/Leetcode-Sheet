class Solution {
public:
    string complexNumberMultiply(string num1, string num2) {
        int i = 0;
        int j = 0;
        int n = num1.size();
        int m = num2.size();
        string v11, v12;
        while (i < n)
        {
            if (num1[i] == '+')
                break;
            v11.push_back(num1[i]);
            i++;
        }
        i++;
        while (i < n)
        {
            if (num1[i] == 'i')
                break;
            v12.push_back(num1[i]);
            i++;
        }
        string v21, v22;
        while (j < m)
        {
            if (num2[j] == '+')
                break;
            v21.push_back(num2[j]);
            j++;
        }
        j++;
        while (j < m)
        {
            if (num2[j] == 'i')
                break;
            v22.push_back(num2[j]);
            j++;
        }
        int a = stoi(v11) * stoi(v21) - stoi(v12) * stoi(v22);
        int b = stoi(v11) * stoi(v22) + stoi(v12) * stoi(v21);
        return to_string(a) + "+" + to_string(b) + "i";
    }
};