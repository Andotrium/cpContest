#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>
#include <set>

#define ll long long
using namespace std;

void bfs(vector<vector<pair<ll,ll>>>& real,ll L,ll s,ll t){
    queue<vector<ll>> q; // queue has the following {next ele, number of edges till now, cost till now}
    set<ll> ans;
    q.push({1,0,0});
    while (!q.empty()) {
        auto temp = q.front();
        q.pop();

        ll node = temp[0];
        ll edges = temp[1];
        ll cost  = temp[2];


        if (edges == L) {
            if (cost >= s && cost <= t) {
                ans.insert(node);
            }
            continue; 
        }

        // expand only if edges < L
        for (auto x : real[node - 1]) {
            ll nextNode = x.first;
            ll nextCost = cost + x.second;

            if (nextCost <= t) {
                q.push({nextNode, edges + 1, nextCost});
            }
        }
    }
    for(auto x:ans){
        cout << x << " ";
    }
    if(ans.empty()) cout << endl;
    return;

}

int main(){
    ll n,m,l,s,t;
    cin >> n >> m >> l >> s >> t;
    // vector<vector<ll>> edges(m,vector<ll>(3));
    vector<vector<pair<ll,ll>>> easierEdges(n);
    for(int i=0;i<m;i++){
        ll u,v,x;
        cin >> u >> v >> x;
        easierEdges[u-1].push_back({v,x});
    }
    bfs(easierEdges,l,s,t);



}