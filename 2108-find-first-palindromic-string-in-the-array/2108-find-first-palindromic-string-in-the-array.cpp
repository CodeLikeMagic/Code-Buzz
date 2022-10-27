class Solution {
public:
    bool palindrome(string s){
        
        for(int i=0, j=s.size()-1; i<s.size()/2; i++, j--){
            
            if(s[i] != s[j]){
                return false;
            }
        }
        return true;
    }
    string firstPalindrome(vector<string>& words) {
        
        for(auto x : words){
            
            bool result = palindrome(x);
            if(result == true){
                return x;   
            }            
        }
        return "";
    }
};