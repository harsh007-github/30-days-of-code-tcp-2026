class Solution {
public:
    int longestConsecutive(vector<int>& nums) 
    {
        unordered_set<int>st;
        int n = nums.size(), maxRes = INT_MIN, cnt = 0;
        for(int i = 0; i < n; i++)
        {
            st.insert(nums[i]);
        }
        for(auto it:st)
        {
            if(st.find(it-1) == st.end())
            {
                int curr =  it;
                cnt = 0;
                while(st.find(curr) != st.end())
                {
                    curr++;
                    cnt++;
                }
                maxRes = max(cnt, maxRes);
            }
        }
        return (maxRes==INT_MIN)?0:maxRes;
    }
};