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

    ll presentSum=a[0];
    ll maxSum=presentSum;
    for(int i=1;i<n;i++){
        if(abs(a[i]%2)==abs(a[i-1]%2)){
            presentSum = a[i];
            maxSum = max(presentSum,maxSum);
            continue;
        }
        presentSum += a[i];
        presentSum = max(a[i],presentSum);
        maxSum = max(presentSum,maxSum);  
    }
    cout << maxSum << endl;
}

