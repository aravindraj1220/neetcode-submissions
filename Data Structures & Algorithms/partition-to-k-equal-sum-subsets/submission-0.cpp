class Solution {
public:
    bool help(vector<int>& nums,vector<int>& used,int sum, int k, int curr,int j, int req)
    {   
        if(sum==req && curr==k-1)
            return true;
        else if (sum==req)
             return help(nums, used, 0, k, curr + 1, 0, req);
        else if (sum>req)
            return false;
        for(int i=j;i<nums.size();i++)
        {   if(used[i])
                continue;
            sum+=nums[i];
            used[i]=1;
            if(help(nums,used,sum,k,curr,j+1,req))
                return true;
            sum-=nums[i];
            used[i]=0;       
            
         }
        return false;

    }
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int sum=0;
        for(auto i : nums)
            sum+=i;
        if(sum%k!=0)
            return false;
        int ss=sum/k;
        vector<int> used(nums.size(),0);
        return help(nums,used,0,k,0,0,ss);


        
    }
};