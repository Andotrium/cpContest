#include <iostream>
#include <vector>
#include <algorithm>
#define ll long long

using namespace std;

ll score(vector<ll>& swords,vector<ll>& b,ll xIndex,ll n){
    ll x = swords[xIndex];
    ll levels = 0;
    ll presentIndex = xIndex;
    for(ll i=0;i<n;i++){
        presentIndex += b[i];
        if(presentIndex > n){
            return i*x;
        }
    }
    return x*n;
    
}

int main(){
    ll t;
    cin >> t;
    while(t--){
        ll n;
        cin >> n;
        vector<ll> swords(n);
        vector<ll> b(n);
        for(auto &x:swords) cin >> x;
        for(auto &x:b) cin >> x;

        sort(swords.begin(),swords.end());
        ll prevScore = 0;
        for(int i=0;i<n;i++){
            ll x = swords[i];
            ll presentScore = score(swords,b,i,n);
            // cout << presentScore << " ";
            if(presentScore < prevScore ){

                cout << prevScore << endl;
                break;
            }
            // cout << "B";
            prevScore = presentScore;
        }
    }
}
