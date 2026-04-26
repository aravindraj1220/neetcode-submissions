class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        sort(people.begin(),people.end());
        int size=people.size();
        int l=0;
        int r=size-1;
        int result=0;
        while(l<=r)
        {
            if(people[l]+people[r]> limit)
            {   result+=1;
                r-=1;
            }
            else
            {
                result+=1;
                  l+=1;
                  r-=1;
                }
        }
    return result;
    }
};