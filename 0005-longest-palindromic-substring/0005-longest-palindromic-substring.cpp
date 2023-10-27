class Solution {
public:
     string longestPalindrome(string s) {
        int x = 0;
        int j,count = 0,len = s.size();
        string ans;
        bool t[1001][1001] = { false };
        
        for(int g = 0; g< s.size(); g++)
        {
            for(int i = 0,j = g; j<len; i++,j++)
            {
                if(g == 0)
                {
                    t[i][j] = true;
                }
                else if(g == 1)
                {
                    if(s[i] == s[j])
                    {
                        t[i][j] = true;
                    }
                    else
                    {
                        t[i][j] = false;
                    }
                }
                else 
                {
                    if(s[i] == s[j] && t[i+1][j-1] == true)
                    {
                        t[i][j] = true;
                    }
                    else
                    {
                        t[i][j] = false;
                    }
                }
                
                if(t[i][j])
                {
                    x = 0;
                    x = i;
                    count = g + 1;
                }
            }
        }
        while(count--)
        {
            ans.push_back(s[x]);
            x++;
        }
        return ans;
    }
};