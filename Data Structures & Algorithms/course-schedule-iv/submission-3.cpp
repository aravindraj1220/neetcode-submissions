class Solution {
public:
    bool dfs(vector<vector<int>> &graph,vector<bool> & visited,int course, int prereq)
    {
        if (course==prereq)
            return true;
        if(visited[course])
            return false;
        visited[course]=true;
        if(graph[course].size())
            for(auto nei: graph[course])
            {
                if(dfs(graph,visited,nei,prereq))
                  return true;
             }
    return false;
    }
    vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
        vector<bool> result;
        vector<vector<int>> graph(numCourses);

        for(auto a: prerequisites)
        {
        graph[a[1]].push_back(a[0]);
        }

        for(auto a: queries)
        {
            vector<bool> visited(numCourses,false);
            result.push_back(dfs(graph,visited,a[1],a[0]));
        }

    return result;
    }
};