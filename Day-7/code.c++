class Solution {
public:
    int encrypt(int num)
    {
        int res = 0, tmp = num, digit = 0;
        while(tmp != 0)
        {
            int temp = tmp % 10;
            digit = max(digit, temp);
            tmp /= 10;
        }
        while(num)
        {
            res = res*10 + digit;
            num /= 10;
        }
        return res;
    }
    int sumOfEncryptedInt(vector<int>& nums) 
    {
        int res = 0;
        for(int i = 0; i < nums.size(); i++)
        {
            res += encrypt(nums[i]);
        }
        return res;
    }
};