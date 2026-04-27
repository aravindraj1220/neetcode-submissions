class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) 
    {
    int l=0;
    int r=0;
    int sum=0;
    int len=100000;
    while(r < nums.size())
    {
        sum+=nums[r];
        while(sum>=target)
        {   len=min(r-l+1,len);
            sum-=nums[l];
            l+=1;
        }
        r+=1;
    }
    if (len==100000)
      return 0;
      return len;
    }
};