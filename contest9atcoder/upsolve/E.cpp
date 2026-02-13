#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#define ll long long

using namespace std;
/*
approach:
variable length sliding window problem
we just have to find that in the given set a new element can be added or not
this can be determined by finding it's position in the set
and checking if it's neighbours have a difference greater than or equal to d with it
*/
int main(){
    ll n,d;
    cin >> n >> d;
    vector<ll> a(n);
    for(auto &x:a) cin >> x;
    set<ll> s;
    // vector<pair<ll,ll>> ranges;
    s.insert((ll)-1e18);
    s.insert(2e18);
    // for(auto x:s) cout << x << " ";
    ll R=0,answer=0;
    for(ll L=0;L<n;L++){
        while(R<n){
            auto it1 = s.lower_bound(a[R]);
            auto it2 = prev(it1);
            if(a[R]-*(it2) < d) break;
            if(*(it1) - a[R] < d) break;
            s.insert(a[R]);
            R++;
        }
        answer += R-L;
        // if(R == n) break;
        s.erase(a[L]);
    }
    cout << answer;
}