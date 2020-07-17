//bfs traversal in directed graph
#include<bits/stdc++.h>
using namespace std;
vector<int> v;
vector<vector<int>> g;
void edge(int a,int b){
    g[a].push_back(b);
}
void bfs(int a){
    queue<int> q;int f;
    q.push(a);
    v[a]=true;
    while(!q.empty()){
        f=q.front();
        q.pop();
        cout<<f<<" ";
        for(auto i=g[f].begin();i!=g[f].end();i++)
        {
            if(!v[*i])
            {
                q.push(*i);
                v[*i]=true;
            }
        }
    }
}
int main(){
    int n,e;
    cin>>n>>e;
   v.assign(n,false);
    g.assign(n,vector<int>());
    
    for(int i=0;i<e;i++){
    int a,b;
    cin>>a>>b;
    edge(a,b);
    }
    for(int i=0;i<n;i++)
    {
        if(!v[i])
         bfs(i);
    }
    return 0;
}


