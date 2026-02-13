#include <iostream>
#include <vector>
#include <algorithm>
#define ll long long

using namespace std;

int main(){
    ll t;
    cin >> t;
    while(t--){
        ll n,q;
        cin >> n >> q;
        vector<ll> a(n);
        vector<ll> b(n);
        for(auto &x:a) cin >> x;
        for(auto &x:b) cin >> x;
        for(ll i=n-1;i>=0;i--){
            if(i==n-1){
                a[i] = max(a[i],b[i]);
            }
            else {
                a[i] = max(a[i],b[i]);
                a[i] = max(a[i],a[i+1]);
            }
        }
        vector<ll> prefSum(n+1,0);
        for(ll i=1;i<n+1;i++){
            prefSum[i] = prefSum[i-1] + a[i-1];
        }
        while(q--){
            ll l,r;
            cin >> l >> r;
            cout << prefSum[r]-prefSum[l-1] << " ";
        }
        cout << endl;

    }
}