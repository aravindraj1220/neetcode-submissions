class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {

        vector<pair<int,int>> mp;
        vector<int> result;
        for(int i: arr)
        {
           int  b=i-x;
            if (b<0)
                b=-b;
            mp.push_back({b,i});
        }
        sort(mp.begin(),mp.end());
    int i=0;
        while(i<k)
        {   auto a= mp[i];
            result.push_back(a.second);
            i++;
        }
        sort(result.begin(),result.end());
        return result;
    }
    
};