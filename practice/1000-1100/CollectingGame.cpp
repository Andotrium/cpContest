#include <iostream>
#include <vector>
#include <set>
#include <unordered_map>
#include <algorithm>
using namespace std;

// Macros
#define print(a) for(auto x:a) cout << x << " "
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
    vector<pll> real(n);
    for(int i=0;i<n;i++){
        real[i] = {a[i],i};
    }
    sort(all(real),[](auto a,auto b){
        return a.first < b.first;
    });
    vll pref(n+1,0);
    for(int i=1;i<=n;i++){
        pref[i] = pref[i-1]+real[i-1].first;
    }
    vll ans(n);
    ans[real[n-1].second] = n-1;
    for(int i=n-1;i>=1;i--){
        if(pref[i] >= real[i].first){
            ans[real[i-1].second] = ans[real[i].second];
        }
        else{
            ans[real[i-1].second] = i-1;
        }
    }
    // ans[real[n-1].second] = n-1;
    print(ans);cout << endl;
}

/*
we basically just have to see that if the sums of numbers smaller than a specific number, where is it located if we put it in the array
also another observation we have to make is that first we make a prefix sum array and later compare it to element if prefsum uptil there greater then
the element less than present will also have same value
for ex:
for the question
5
20 5 1 4 2

first sort
1 2 4 5 20
now form prefix sum
0 1 3 7 12 32

now compare
0 1 3 7 12 32
1 2 4 5 20 <- start from last, we already know for the last element the answer is n-1
compare for i=4, 20 > 12 -> so i=3 will have value (present(i) - 1)
compare for i=3 7 > 5 -> here it's interesting to see that i=2 will have value = value(present i) (i.e i=2 will have same value as i=3, and that is 3, which we 
have found in the above step.)
this way we can solve it in a single pass
but starting from the end
*/