class Solution {
public:
    bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) {
        string ans1 = ""; 
        string ans2 = "";
        
        for(auto x : word1){
            ans1 += x;
        }
        
        for(auto x : word2){
            ans2 += x;
        }
        
        cout<<ans1<<" "<<ans2<<endl;
        
        if(ans1 == ans2){
            return true;
        }else{
            return false;
        }
    }
};