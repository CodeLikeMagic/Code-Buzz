class Solution {
public:
    int countSubstrings(string s) {
    int j,count = 0;
    int len = s.size();

    bool t[1001][1001] = {false};

    for(int g = 0; g<len; g++)
    {
        for(int i = 0, j = g; j < len; i++, j++)
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
            else    ///greater
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
                count++;
            }
        }
    }
    return count;
}
    
};
