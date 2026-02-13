#include <iostream>
#include <vector>
#include <set>
#include <unordered_map>
#include <typeinfo>
#define ll long long

using namespace std;

/* 
This approach gives the correct answer but it TLEs
I've even tried to keep the dp intact so that the number of terms doesn't explode
this is the best you can do with this approach and it still TLEs
*/

// O(m3)
void solve(unordered_map<ll,vector<ll>> & um, ll m){
    // O(m)
    for(int i=1;i<=m;i++){
        if(um.find(i) == um.end()) {cout << "NO" << endl;return;}
    }
    vector<vector<vector<ll>>> dp(m);
    if(um.find(1) != um.end()){
        vector<vector<ll>> temp;
        for(auto x:um[1]){
            temp.push_back({x});
        }
        dp[0] = temp;
    }
    else {
        cout << "no"<<endl ;return;
    }
    // O(m*m*m)
    for(int i=1;i<m;i++){
        vector<vector<ll>> temp;
        if(um.find(i+1) == um.end()){
            cout << "no" << endl;
            return;
        }
        // O(m*m)
        for(auto x:dp[i-1]){
            // O(m)
            for(auto y:um[i+1]){
                auto t = x;
                t.insert(t.end(),y);
                temp.push_back(t);
            }
            for(auto y:um[i+1]) x.insert(x.begin(),y);
            temp.push_back(x);
        }
        set<set<ll>> present;
        for(auto x:temp){
            set<ll> real;
            for(auto y:x) real.insert(y);
            present.insert(real);
        }
        vector<vector<ll>> good;
        for(auto& inner:present)good.emplace_back(inner.begin(),inner.end());
        dp[i] = good;
    }
    set<set<ll>> final;
    vector<vector<ll>> ans = dp[m-1];

    for(auto x:ans){
        set<ll> temp;
        for(auto y:x){
            temp.insert(y);
        }
        final.insert(temp);

    }
    set<ll> last;
    // O(m)
    for(auto x:um){
        for(auto y:x.second) last.insert(y);
    }
    final.insert(last);
    if(final.size() < 3) cout << "no" << endl;
    else cout << "yes" << endl;
    return ;


}

// The complexity of our code is O(tnL+tm3)
int main(){
    ll t;
    cin >> t;
    // O(t(n*L+m^3))
    while(t--){
        ll n,m;
        cin >> n >> m;
        unordered_map<ll,vector<ll>> um(m+1);
        // Time Complexity = O(n*L) where L = summation(lengthArray)
        for(int arr=1;arr<=n;arr++){
            ll lengthArray;
            cin >> lengthArray;
            for(int i=0;i<lengthArray;i++){
                ll num;
                cin >> num;
                um[num].push_back(arr);
            }
        }
        // O(m^3)
        solve(um,m);
    }
}