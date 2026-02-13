#include <iostream>
#include <vector>
#include <queue>
#include <set>
#define ll long long
using namespace std;

void bfs(vector<vector<pair<ll,ll>>>& edges, ll L, ll s, ll t){
    queue<vector<ll>> q; // we'll push in {next vertice, length, cost}
    q.push({1,0,0});
    set<ll> ans;
    while(!q.empty()){
        auto temp = q.front();
        q.pop();
        if(temp[1] < L){
            ll length = temp[1]+1;
            for(auto x: edges[temp[0]-1]){
                ll cost = temp[2]+x.second;
                if(length == L){
                    if(cost >= s && cost <= t){
                        ans.insert(x.first);
                    }
                    continue;
                }
                q.push({x.first, length, cost});
            }
        }
    }
    if(ans.size() == 0) {
        cout << endl;
        return;
    }
    for(auto x:ans){
        cout << x << " ";
    }

}

int main(){
    ll n,m,l,s,t;
    cin >> n >> m >> l >> s >> t;
    vector<vector<pair<ll,ll>>> Edges(n);
    for(int i=0;i<m;i++){
        ll t1,t2,t3;
        cin >> t1 >> t2 >> t3;
        Edges[t1-1].push_back({t2,t3});
    }
    bfs(Edges, l, s, t);


}