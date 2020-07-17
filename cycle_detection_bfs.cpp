//detecting cycle using bfs
#include<bits/stdc++.h>
using namespace std;
vector<int> v;
vector<int> p;
vector<vector<int>> g;
void edge(int a,int b){
    g[a].push_back(b);
    g[b].push_back(a);
}
bool cycle_check(int j,int n,vector<vector<int>> &g,vector<int> &v){
    queue<int> q;int u;
    v[j]=true;
    q.push(j);
    vector<int> p(n,-1);
    while(!q.empty()){
        u=q.front();
        q.pop();
        for(auto i=g[u].begin();i!=g[u].end();i++){
        if(!v[*i]){
            q.push(*i);
            v[*i]=true;
            p[*i]=u;
        }
        else if(p[*i]!=u)
        return true;
        }
    }
            return false;
}
bool cycle_exists(int n,vector<vector<int>> &g,vector<int> &v){
    for(int i=0;i<n;i++){
        if(!v[i] && cycle_check(i,n,g,v))
         return true;
        else
         return false;
    }
}
int main(){
    int n,e,a,b;
    cin>>n>>e;
    v.assign(n,false);
    g.assign(n,vector<int>());
   for(int i=0;i<e;i++)
    {
    cin>>a>>b;
    edge(a,b);
    }
    if(cycle_exists(n,g,v))
     cout<<"cycle exists";
    else
    cout<<"no cycle";
    return 0;
}

