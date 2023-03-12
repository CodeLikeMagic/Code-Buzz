class Solution {
public:
    int maximum69Number (int num) {
        
        string numString = to_string(num);
        
        for(auto &ch : numString){
            
            if(ch == '6'){
                ch = '9';
                break;
            }
        }
        
        return stoi(numString);
    }
};