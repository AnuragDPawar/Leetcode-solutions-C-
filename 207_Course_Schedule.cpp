#include <bits/stdc++.h>
using namespace std;

class Solutions
{
    public:
        bool isCycle(int n, vector<vector<int>> &pre);
};

bool isLoop(int i,vector<vector<int>> &graph,vector<int> &visited)
{
    if(visited[i]==1) return true; //cycle is detected as we found the previously visited node
    if(visited[i]==0) //first time visit to a node
    {
        visited[i]=1;
        for(auto e: graph[i]) //ith row io graph will be checked recursively
        {
            if(isLoop(e,graph,visited)) return true;
        }
    }
    visited[i]=2; //node is fully processed, there is no dependency
    return false;
}
bool Solutions::isCycle(int n, vector<vector<int>> &pre)
{
    if(pre.size()==0) return true;
    vector<vector<int>> graph (n);
    for(auto x: pre)
        graph[x[1]].push_back(x[0]); //created a directed graph
    vector<int> visited (n,0);
    for(int i=0;i<n;i++)
    {
        if(isLoop(i,graph,visited)) return false;
    }
    return true;


}

int main()
{
    Solutions sa;
    vector<vector<int>> pre {{1,0},{0,1}};
    cout<<sa.isCycle(2,pre);
    return 0;
}

/*
Algorithm
1. Create a nested vector to store the directed graph.
2. Traverse the input matrix ahe keep storing the elements into graph vector.
3. Create a visited vector of size n and initialize with 0 i.e. every node is unvisited.
4. Call a helper function to detect cycle.
5. Use recursion to traverse the ith row in the graph in the helper function.
*/