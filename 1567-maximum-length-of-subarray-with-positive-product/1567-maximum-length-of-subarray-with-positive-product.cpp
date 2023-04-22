class Solution {
public:
    /*
    - all values +ve
    - no. of neg values --> even --> +ve result
    - odd no. of -ve values, 0's
    */
    int getMaxLen(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;
        for(int i=0; i<n;){
            
            int s = i;
            
            while(s<n && nums[s] == 0){
                s++;
            }
            
            int e = s;
            int c = 0;
            int sn = -1, en = -1;
            
            while(e<n && nums[e] != 0){
                ///count of neg values
                if(nums[e] < 0){
                    c++;
                    if(sn == -1){
                        sn = e;
                    }
                    en = e;
                }
                e++;
            }
            
            if(c%2 == 0){
                ans = max(ans, e - s);
            }else{
                if(sn != -1){
                    ans = max(ans, e-sn-1);
                }
                if(en != -1){
                    ans = max(ans, en-s);
                }
            }
            i = e+1;
        }
        return ans;
    }
};