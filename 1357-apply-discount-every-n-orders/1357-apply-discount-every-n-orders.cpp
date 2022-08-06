class Cashier {
public:
    /*+*/map<int, int>mp;
    int counter = 0;
    int N;
    int DIStrack;
    Cashier(int n, int discount, vector<int>& products, vector<int>& prices) {
        DIStrack = discount;
        N = n;
        for(int i =0 ; i < products.size() ; i++){
            mp[products[i]] = prices[i];
        }
    }
    
    double getBill(vector<int> product, vector<int> amount) {
        double sum = 0;
        counter++;
        for(int i = 0 ; i < product.size() ; i++){
            sum += mp[product[i]]*amount[i];
        }
        if(counter%N == 0){
            sum = sum * ((double)(100-DIStrack)/100);
        }
        return sum;
    }
};

/**
 * Your Cashier object will be instantiated and called as such:
 * Cashier* obj = new Cashier(n, discount, products, prices);
 * double param_1 = obj->getBill(product,amount);
 */