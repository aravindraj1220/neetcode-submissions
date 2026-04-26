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

    bool makesquare(vector<int>& matchsticks) 
    {
        int sum=0;
        for(auto i : matchsticks)
            sum+=i;
        if(sum%4!=0)
            return false;
        int ss=sum/4;
        vector<int> used(matchsticks.size(),0);
        return help(matchsticks,used,0,4,0,0,ss);


      
    }
};