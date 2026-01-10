class Solution {
  public:
    void sort012(vector<int>& a) 
    {
        int zero = 0, one = 0, two = 0, n = a.size();
        for(int i = 0; i < n; i++)
        {
            if(a[i] == 0)
            {
                zero++;
            }
            else if(a[i] == 1)
            {
                one++;
            }
            else
            {
                two++;
            }
        }
        for(int i = 0; i < n; i++)
        {
            if(zero > 0)
            {
                a[i] = 0;
                zero--;
            }
            else if(one > 0)
            {
                a[i] = 1;
                one--;
            }
            else
            {
                a[i] = 2;
                two--;
            }
        }
    }
};