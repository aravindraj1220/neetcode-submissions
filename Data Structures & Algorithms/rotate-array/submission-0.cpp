class Solution {
public:
    void rotate(vector<int>& nums, int k) {

        k=k%nums.size();
        int size=nums.size();
        vector<int> subn;
        for(int i=nums.size()-k;i<nums.size();i++)
        {
            subn.push_back(nums[i]);
        }
        for(int i=subn.size()-1;i>=0;i--)
        {
            nums.insert(nums.begin(),subn[i]);
        }

        nums.resize(size);
        
        
    }
};