class Solution {
public:
    int maxArea(vector<int>& height) {
        
        /*
        BF
        
        res = 0
        
        for l in range(len(height)):
            for r in range(l+1, len(height)):
                area = (r-l) * min(height[l], height[r])
                res = max(res, area)
                
        return res
        */
        
        //O(n)
        //T-P approach
        int res = 0, l=0, r = height.size()-1;
        int area = 0;
        while(l < r){
            
            area = (r-l) * min(height[l], height[r]);
            res = max(res, area);
            
            if(height[l] < height[r]){
                l++;
            }else{
                r--;
            }

        }
        return res;        
    }
};