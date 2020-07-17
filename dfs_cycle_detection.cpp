//dfs cycle detection
#include<bits/stdc++.h>
using namespace std;
vector<int> v;
vector<int> s;
vector<vector<int>> g;
void edge(int a,int b){
    g[a].push_back(b);
}
bool dfsutil(int n){
    v[n]=true;
    s[n]=true;
    for(auto i=g[n].begin();i!=g[n].end();i++){
        if ( !v[*i] && dfsutil(*i) ) 
                return true; 
        else if (s[*i]) 
                return true; 
    }
    s[n]=false;
    return false;
}
bool dfs(int n){
    for(int i=0;i<n;i++)
    {
        if(dfsutil(i))
         return true;
    }
    return false;
}
int main(){
    int n,e,a,b;
    cin>>n>>e;
    v.assign(n,false);
    s.assign(n,false);
    g.assign(n,vector<int>());
    for(int i=0;i<e;i++){
        cin>>a>>b;
        edge(a,b);
    }
    if(dfs(n))
     cout<<"cycle";
    else
    cout<<"no cycle";
    return 0;
}




