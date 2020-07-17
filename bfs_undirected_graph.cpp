//bfs traversal for undirected graph
#include <bits/stdc++.h>
using namespace std;
vector<int> vis;
vector<vector<int>> g;
void addedge(int a,int b){
    g[a].push_back(b);
    g[b].push_back(a);
}
void bfs(int f){
    queue<int> q;
    vis[f]=true;
    q.push(f);
    while(!q.empty()){
        int u=q.front();
        q.pop();
        cout<<u<<" ";
        for(auto i=g[u].begin();i!=g[u].end();i++)
         if(!vis[*i])
          {q.push(*i);
          vis[*i]=true;}
         
    }
}
int main()
{
    int v,e,a,b;
    cin>>v>>e;
    vis.assign(v,false);
    g.assign(v,vector<int>());
    for(int i=0;i<e;i++)
   {
    cin>>a>>b;
    addedge(a,b);
   }
   for(int i=0;i<v;i++)
    if(!vis[i])
    bfs(i);
    return 0;
}

