class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        
        int carry = 1, rem = 0;
        int plus_one = 0;
        for(int i=digits.size()-1; i>=0; i--){
                        
            if(digits[i] <= 8){
                digits[i] = digits[i] + 1;
                return digits;
            }else{
                
                if(carry == 0){
                    break;
                }
                plus_one = digits[i] + carry;
                carry = plus_one / 10;
                rem = plus_one % 10;
                digits[i] = rem;
            }
        }
        if(carry){
            digits.insert(digits.begin(), digits[0]+carry);
        }
        return digits;
    }
};