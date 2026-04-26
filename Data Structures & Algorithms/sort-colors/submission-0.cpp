class Solution {
public:
    void sortColors(vector<int>& nums) {

        int j=0;
        int i=0;
        int n=nums.size();
        while(i<n)
        {   if(nums[i]==0)
                {
                swap(nums[j],nums[i]);
                j+=1;
                }
                i++;
        }
        i=j;
        while(i<n)
        {   if(nums[i]==1)
                {
                swap(nums[j],nums[i]);
                j+=1;
                }
                i++;
        }

        
    }
};