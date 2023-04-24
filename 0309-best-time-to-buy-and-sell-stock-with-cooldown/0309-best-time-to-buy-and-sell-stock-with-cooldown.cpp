class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int obsp = -prices[0];
        int ossp = 0;
        int ocsp = 0;
        
        for(int i=1; i<prices.size(); i++){
            
            int nbsp = 0;
            int nssp = 0;
            int ncsp = 0;
            
            /////for buy - buy || cooldown
            if(ocsp - prices[i] > obsp){
                nbsp = ocsp - prices[i];
            }else{
                nbsp = obsp;
            }
            
            /////for sol - sol || buy
            if(obsp + prices[i] > ossp){
                nssp = obsp + prices[i];
            }else{
                nssp = ossp;
            }
            
            /////cooldown
            if(ossp > ocsp){
                ncsp = ossp;
            }else{
                ncsp = ocsp;
            }
            
            obsp = nbsp;
            ossp = nssp;
            ocsp = ncsp;
        }
        
        return ossp;
    }
};