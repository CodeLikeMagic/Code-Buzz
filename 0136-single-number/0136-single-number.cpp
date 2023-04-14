class Solution {
public:
    int singleNumber(vector<int>& nums) {
        ///Xor 
        ///x^x = 0
        ///0^y = y
        
        int uniqNum = 0;
        
        for(int index : nums){
            
            uniqNum ^= index;
        }
        
        return uniqNum;
    }
};