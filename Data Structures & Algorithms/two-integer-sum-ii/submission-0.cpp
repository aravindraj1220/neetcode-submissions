class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        unordered_map<int,int>mp;
        int j=1;
        for(int i:numbers)
        {
            mp[i]=j;
            j++;
        }
        for(int i : numbers)
        {
            if(mp.count(target-i) && mp[i]!=mp[target-1])
            {
                
                return vector<int>{mp[i],mp[target-i]};
            }
        }
        
    }
};
