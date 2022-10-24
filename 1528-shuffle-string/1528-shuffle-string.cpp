class Solution {
public:
    string restoreString(string s, vector<int>& indices) {
        string ans = s;                              // making a new string with same size as the given string
        
        for(int i=0; i<indices.size(); i++){
            int val = indices[i];
            ans[val] = s[i];
        }
        return ans;
    }
};