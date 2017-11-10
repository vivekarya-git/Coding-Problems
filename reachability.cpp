
#include <bits/stdc++.h>

using namespace std;

// Finding reachability of a node "q" from node "p" in undirected graph using DFS (assuming no of nodes < 10^6)


void dfs(int src, vector<int> &tempVisited, map<int, vector<int> > adj)
{
    tempVisited[src] = 1;
    for(auto it= adj[src].begin(); it!= adj[src].end(); it++)
    {
        if(tempVisited[*it] != 1)
            dfs(*it, tempVisited, adj);
    }
    return;
}

int main()
{
    int n,m,i,v1,v2;
    map<int, vector<int> > adj;
    cin>>n>>m;
    for(i=0; i<m; i++)
    {
        cin>>v1>>v2;
        adj[v1].push_back(v2);
        adj[v2].push_back(v1);
    }
   for(i=1; i<=n; i++)
    {
        cout<<i<<":";
        for(auto it = adj[i].begin(); it!= adj[i].end(); it++)
        {
            cout<<*it<<" ";
        }
        cout<<endl;
        
    } 
    
    
    /*for(auto it = visited[0].begin(); it!= visited[0].end(); it++)
    {
        cout<<*it<<" ";
    }  */
    
    vector< vector<int> > visited;
    for(i=1; i<=n; i++)
    {
        vector<int> tempVisited(n+1, 0);
        if(tempVisited[i] != 1)
        {
            dfs(i,tempVisited, adj);
            visited.push_back(tempVisited);
        }
        
        //for()
        
    }    
    
    int p,q;
    cin>>p>>q;
    for(i=0; i<visited.size(); i++)
    {
        if(visited[i][p]==1 && visited[i][q] == 1)
        {
            cout<<1<<" Path exist";
            return 1;
        }
            
    }
    
    cout<<0<<" Path doesn't exist";
    return 0;
}
