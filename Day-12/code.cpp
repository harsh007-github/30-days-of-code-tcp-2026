class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int key) 
    {
        int n = nums.size();
        vector<int>v(2, -1);    
        int low = 0, high = n-1;
        while(low <= high)
        {
            int mid = low + (high-low)/2;
            if(nums[mid] <= key)
            {
                if(nums[mid] == key)
                    v[0] = mid;
                low = mid + 1;
            }
            else
            {
                high = mid - 1;
            }
        }
        low = 0, high = n-1;
        while(low <= high)
        {
            int mid = low + (high-low)/2;
            if(nums[mid] >= key)
            {
                if(nums[mid] == key)
                    v[1] = mid;
                high = mid - 1;
            }
            else
            {
                low = mid + 1;
            }
        }
        sort(v.begin(), v.end());
        return v;
    }
};