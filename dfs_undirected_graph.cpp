//dfs traversal in undirected graph
#include<bits/stdc++.h>
using namespace std;
vector<int> vis;
vector<vector<int>> g;
void addedge(int a,int b){
    g[a].push_back(b);
    g[b].push_back(a);
}
void dfs(int f){
    vis[f]=true;
    cout<<f<<" ";
    for (auto i=g[f].begin(); i!=g[f].end(); i++) 
		if (vis[*i] == false) 
			dfs(*i); 
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
      dfs(i);
}
