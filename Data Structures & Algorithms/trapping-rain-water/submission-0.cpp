class Solution {
public:
    int trap(vector<int>& height) {

        stack<int> st;
    int water=0;

    st.push(0);
    for (int i=1;i<height.size();i++)
    {   while(!st.empty() && height[i]>height[st.top()])
        {
        int curr_height=height[st.top()];
        st.pop();
        if (st.empty()) break;
        int left=st.top();
        int right=i;
        water+=(min(height[left],height[right])-curr_height)*(right-left-1);
        }
    st.push(i);
    }
        
    return water;
    }
};
