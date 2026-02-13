#include <iostream>
#include <vector>
#include <unordered_map>
#include <set>
#define ll long long

using namespace std;

int main(){
    ll t;
    cin >> t;
    while(t--){
        ll n,m;
        cin >> n >> m;
        unordered_map<ll,vector<ll>> um(m+1);
        for(int arr=1;arr<=n;arr++){
            ll lengthArray;
            cin >> lengthArray;
            for(int i=0;i<lengthArray;i++){
                ll num;
                cin >> num;
                um[num].push_back(arr);
            }
        }
        bool trigger = false;
        for(ll i=1;i<=m;i++){
            if(um.find(i) == um.end()){
                cout << "No"<<endl;
                trigger = true;
                break;
            }
        }
        if(!trigger){
            set<ll> es; // essential sets
            for(auto x:um){
                if(x.second.size() == 0){
                    cout << "No2"<<endl;
                    continue;
                }
                else if(x.second.size() == 1){
                    es.insert(x.second[0]);
                }
            }
            ll numEs = es.size();
    
            ll freeSets = n-numEs;
            if(freeSets >= 2) cout << "Yes" << endl;
            else cout << "No"<<endl;
        }
    }
    
}