class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int min=1;
        int max=0;
        for (int i: piles)
                if(max<i)
                    max=i;
        int ans=0;
        int mid=0;
        while(min<=max)
        {   int cu=0;
            mid=min+(max-min)/2;
            for(int i: piles)
            {
               if(i<=mid)
                cu+=1;
               else
               {
                if(!(i%mid))
                    cu+=i/mid;
                else
                    cu+=i/mid+1;
               } 
            }
            if(cu<=h)
            {
                ans=mid;
                max=mid-1;
            }
            else
            {
                min=mid+1;
            }

        }
        return ans;
    }
};
