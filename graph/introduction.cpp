// Adj.list


#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long
const int MOD =1e9+7;
class Graph{
    public:
    unordered_map<int,vector<int>>adj;
    void create(int u,int v,int direction){
        // direction=0-->undirected graph;
        //direction=1-->directed graph;
        adj[u].push_back(v);
        if(direction==0){
            adj[v].push_back(u);
        }
    }
    void print(){
        for(auto it:adj){
            cout<<it.first<<"-->";
            for(auto ele:it.second){
                cout<<ele<<" ";
            }
            cout<<endl;
        }
    }
};
int main() {
// ios::sync_with_stdio(false);cin.tie(NULL);
int n,m;
cout<<"Enter the no.of nodes:"<<endl;
cin>>n;
cout<<"Enter the no.of edge:"<<endl;
cin>>m;
Graph g;
for(int i=0;i<m;i++){
    int u,v;
    cin>>u>>v;
    g.create(u,v,0);
}
g.print();
return 0;
}