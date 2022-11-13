class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int result = 0;
        
        sort(intervals.begin(), intervals.end());
        //sort based on start times of intervals
        
        int trackEnd = intervals[0][1];
        
        for(int i=1; i<intervals.size(); i++){
            
            if(intervals[i][0] >= trackEnd){    //if not overlapping
                trackEnd = intervals[i][1];
            }else{  //if overlaps del the one with lesser end
                result += 1;
                trackEnd = min(intervals[i][1], trackEnd);
            }           
        }
        return result;
    }
};