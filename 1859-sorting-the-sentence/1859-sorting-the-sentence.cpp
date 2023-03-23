class Solution {
public:
    string sortSentence(string s) {
        map<int, string>mp;
        string t="";
        for(int i=0;i<s.length();i++){
            if(s[i]==' '){
                continue;
            }
            if(s[i]>='1' and s[i]<='9'){
                mp[s[i]]=t;
                t.clear();
            }
            if(s[i]>='1' and s[i]<='9'){
                continue;
            }
            else{
                t+=s[i];
            }
        }
        string ans="";
        for(auto it:mp){
            //cout<<it.second<<" ";
            ans+=it.second;
            ans+=' ';
            
        }
        ans.erase(ans.length()-1);
        return ans;
    }
};