#include <iostream>
#include <vector>
#include <algorithm>

#define ll long long
using namespace std;

int main(){
    ll n,k,x;
    cin >> n >> k >> x;
    vector<ll> contains(n);
    for(auto &x: contains) cin >> x;
    sort(contains.begin(),contains.end());
    ll ans = n-k;
    ll drank = 0;
    for(int i=k-1;i>=0;i--){
        drank += contains[i];
        if(drank >= x){
            ans += k-i;
            break;
        }
    }
    if(drank < x) {
        cout << -1 ;
    }
    else {
        cout << ans ;
    }
    
}