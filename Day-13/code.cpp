class Solution {
public:
    long long satisfy(vector<int>& arr, long long val)
    {
        long long ans = 0; 
        for(int i = 0; i < arr.size(); i++)
        {
            if(arr[i] <= val)
            {
                ans++;
            }
            else 
            {
                ans += ((arr[i] + val - 1) / val);
            }
        }
        return ans;
    }
    int minEatingSpeed(vector<int>& arr, int h) 
    {
        sort(arr.begin(), arr.end());
        int n = arr.size();
        
        int low = 1; 
        int high = arr[n-1]; 
        int minAns = high;
        while(low <= high)
        {
            int mid = low + (high-low)/2;    
            long long hours = satisfy(arr, mid); 
            if(hours <= h)
            {
                minAns = mid;
                high = mid - 1;
            }
            else
            {
                low = mid + 1;
            }
        }
        return minAns;
    }
};