class Solution {
public:
    string removeDuplicateLetters(string s) {
        int freq[26] = {0};
        bool exists[26] = {false};
        stack<char> st;
        
        for(int i=0; i<s.size(); i++){
            char val = s[i];
            freq[val - 'a']++;
        }//freq array
        
        
        for(int i=0; i<s.size(); i++){
            char val = s[i];
            freq[val - 'a']--;  //reduce freq
            if(exists[val -'a']) continue; //already added
            
            while(st.size() > 0 && st.top() > val && freq[st.top() - 'a'] > 0){
                
                char rem = st.top();              
                st.pop();
                exists[rem - 'a'] = false;
            }
            
            st.push(val);
            exists[val - 'a'] = true;
        }
        
        string answer;
        while(st.size() > 0){
            answer.push_back(st.top());
            st.pop();
        }
        reverse(answer.begin(), answer.end());
        return answer;
    }
};