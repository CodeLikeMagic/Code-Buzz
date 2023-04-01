// The API isBadVersion is defined for you.
// bool isBadVersion(int version);
#include <algorithm>
using namespace std;
class Solution {
public:

    int firstBadVersion(int n) {
      int low = 1;
      int high = n;
      while(low <= high){
          int mid = high + (low - high)/2;
          
          if(isBadVersion(mid)){
              high = mid-1;
          }else if(!isBadVersion(mid)){
              low = mid+1;
          }
      }
      return low;
    }
};