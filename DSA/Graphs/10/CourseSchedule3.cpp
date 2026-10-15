/*
Leetcode 1462
Approach:
1. Build the directed graph where u -> v means u is a prerequisite of v,
   and calculate the indegree of every course.
2. Use Kahn's Topological Sort. Start with courses having indegree 0 because
   they have no prerequisites and can be processed first.
3. For every edge u -> v, add u to the prerequisite set of v. Also, every
   prerequisite of u is automatically a prerequisite of v, so merge s[u]
   into s[v].
4. After processing all courses, s[v] contains every course that is a
   prerequisite of v.
5. For each query [u, v], check s[v].count(u). If it exists, u is a
   prerequisite of v; otherwise it is not.

Time Complexity: O(E * V + Q) average
    E = number of prerequisite edges, V = number of courses,
    Q = number of queries. Each edge may propagate up to V prerequisites,
    and unordered_set insertion/lookup is O(1) on average.

Space Complexity: O(V^2 + E)
    O(E) for the graph and O(V^2) in the worst case for storing all
    prerequisite relationships.
*/

class Solution {
public:
    vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
        vector<int> indegree(numCourses, 0);
        vector<int> adj[numCourses];

        for(auto itr : prerequisites){
            int u = itr[0];
            int v = itr[1];   

            adj[u].push_back(v);
            indegree[v]++;    
        }

        queue<int> q;
        vector<unordered_set<int>> s(numCourses);

        for(int i =0; i < numCourses; i++){
            if(indegree[i] == 0){
                q.push(i);
            }
        }

        while(q.size() > 0){
            int node = q.front();
            q.pop();

            for(auto itr : adj[node]){
                s[itr].insert(node);

                unordered_set<int> temp = s[node];
                s[itr].insert(temp.begin(), temp.end());

                indegree[itr]--;
                if(indegree[itr] == 0){
                    q.push(itr);
                }
            }
        }
        vector<bool> answer;
        for(auto itr : queries){
            int u = itr[0];
            int v = itr[1];

            if(s[v].count(u)){
                answer.push_back(true);
            }
            else{
                answer.push_back(false);
            }
        }

        return answer;
    }
};