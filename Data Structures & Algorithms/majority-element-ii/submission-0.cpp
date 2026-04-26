class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {

        unordered_map<int,int> mp;
        vector<int> result;

        for (int i: nums)
        {
            mp[i]+=1;
        }
        for(auto i :mp)
        {
            if(i.second> nums.size()/3)
                result.push_back(i.first);
        }
        return  result;
        
    }
};