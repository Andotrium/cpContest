#include <iostream>
#include <vector>
#include <set>
#include <unordered_map>
#include <algorithm>
using namespace std;

// Macros
#define inc(a) sort(a.begin(),a.end())
#define dec(a) sort(a.rbegin(),a.rend())
#define all(a) a.begin(),a.end()
#define ll long long
#define pll pair<ll,ll>
#define vi vector<int>
#define vll vector<ll>
#define sll set<ll>
#define umll um<ll,ll>

// functions
ll gcd(ll a,ll b){
    return b==0?a:gcd(b%a,a);
}
ll lcm(ll a,ll b){
    return ((a*b)/gcd(a,b));
}

void kiki();

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    ll t;
    cin >> t;
    while(t--){
      kiki(); 
    }
}
void kiki(){
    ll n;
    cin >> n;
    vll a(n);
    for(auto &x:a) cin >> x;

    vll factors;

    for(int i=1;i*i<=n;i++){
        if(n%i == 0) {factors.push_back(i);factors.push_back(n/i);}
    }

    vll pref(n+1,0);
    for(int i=1;i<=n;i++){
        pref[i] = pref[i-1]+a[i-1];
    }
    ll maxDiff = 0;
    for(auto x:factors){
        ll maxW=LLONG_MIN;
        ll minW = LLONG_MAX;
        for(int i=0;i+x<=n;i+=x){
            ll w = pref[i+x]-pref[i];
            maxW = max(maxW,w);
            minW = min(minW,w);
        }
        maxDiff = max(maxDiff,maxW-minW);
    }
    cout << maxDiff << endl;

}

