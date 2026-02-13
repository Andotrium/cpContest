#include <iostream>
#include <vector>
#define ll long long
using namespace std;

int main(){
    ll t;
    cin >> t;
    while(t--){
        ll n;
        cin >> n;
        vector<ll>p(n),a(n);
        for(auto &x:p) cin >> x;
        for(auto &x:a) cin >> x;

        ll pI = 0; // p pointer
        for(ll i=0;i<n;i++){
            ll elementToFind = a[i];
            while(pI < n && p[pI] != elementToFind) pI++;
            if(pI == n){
                cout << "No" <<endl;
                break;
            }
        }
        if(pI < n)cout << "Yes" <<endl;
    }
}