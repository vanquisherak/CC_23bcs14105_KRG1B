#include<bits/stdc++.h>
using namespace std;
vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
    vector<vector<int>> graph(numCourses);
    vector<int> indegree(numCourses, 0);
    for (auto& p : prerequisites) {
        int a = p[0], b = p[1];
        graph[b].push_back(a);
        indegree[a]++;
    }
    queue<int> q;
    for (int i = 0; i < numCourses; i++)
        if (indegree[i] == 0) q.push(i);
    vector<int> order;
    while (!q.empty()) {
        int node = q.front(); q.pop();
        order.push_back(node);
        for (int next : graph[node])
            if (--indegree[next] == 0) q.push(next);
    }
    return (int)order.size() == numCourses ? order : vector<int>{};
}
int main(){
    int numCourses, p;
    cin >> numCourses >> p;
    vector<vector<int>> prerequisites(p, vector<int>(2));
    for (int i = 0; i < p; i++)
        cin >> prerequisites[i][0] >> prerequisites[i][1];
    vector<int> order = findOrder(numCourses, prerequisites);
    if (order.empty()) {
        cout << "IMPOSSIBLE (cycle detected)\n";
    } else {
        for (int i = 0; i < (int)order.size(); i++) {
            if (i) cout << " ";
            cout << order[i];
        }
        cout << "\n";
    }
    return 0;
}