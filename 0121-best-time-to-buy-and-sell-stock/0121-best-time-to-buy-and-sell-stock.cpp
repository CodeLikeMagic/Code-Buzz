class Solution {
public:
    int maxProfit(vector<int>& prices) {
        long long int op = 0, pist = 0, lsf = INT_MAX;
        
        for(int i=0; i<prices.size(); i++){
            
            if(prices[i] < lsf){
                lsf = prices[i];
            }
            
            pist = prices[i] - lsf; //profit for that day
            
            if(pist > op){
                op = pist;  //max profit   
            }
        }
        return op;
    }
};