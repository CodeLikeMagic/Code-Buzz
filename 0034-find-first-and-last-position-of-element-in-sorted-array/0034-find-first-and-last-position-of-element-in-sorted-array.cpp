class Solution {
public:
    int first_occ(vector<int> arr, int N, int ele)
    {
        int result,start,end,mid;
        start = 0;
        end = N-1;
        result = -1;
        while(start <= end)
        {
            mid = start + (end - start)/2;

            if(ele == arr[mid]) ///if found
            {
                result = mid;
                end = mid - 1;  ///search if any present in left portion
            }
            else if(ele < arr[mid])
            {
                end = mid - 1;
            }
            else
            {
                start = mid + 1;
            }
        }
        return result;
    }

    int last_occ(vector<int> arr, int N, int ele)
    {
        int result,start,end,mid;
        start = 0;
        end = N-1;
        result = -1;
        while(start <= end)
        {
            mid = start + (end - start)/2;

            if(ele == arr[mid]) ///if found
            {
                result = mid;
                start = mid + 1;    ///search if any present in right portion
            }
            else if(ele < arr[mid])
            {
                end = mid - 1;
            }
            else
            {
                start = mid + 1;
            }
        }
        return result;

    }
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> result;
        result.push_back(first_occ(nums, nums.size(), target));
        result.push_back(last_occ(nums, nums.size(), target));
        
        return result;
    }
};