class Solution {
public:
    static bool cmp(pair<char,int> &a, pair<char,int> &b)
    {
        return a.second>b.second; //return greater freq
    }
    
    string frequencySort(string s) {
        
        unordered_map<char, int> mp;
        string answer;
        vector<pair<char, int>> v;
        
        for(int i = 0; i<s.size(); i++){
            char c = s[i];
            mp[c]++;    
        }
        
        for(auto x : mp){   
            v.push_back({x.first, x.second});        
        }
        
        sort(v.begin(), v.end(), cmp);
        pair<char, int>p;
        
        for(auto it : v){
            p = it;
            char letter = p.first;
            int freq = p.second;
            
            while(freq){
                answer.push_back(letter);
                freq--;
            }
        }    
        return answer;
    }
};