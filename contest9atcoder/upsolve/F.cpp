#include <iostream>
#include <vector>
#include <set>

#define ll long long
using namespace std;
/*
approach: first find all the numbers that can actually be arrived by dividing by 2
then we'll binary search on the answer, we need m number of elements to be greater than 2X-1
*/
int countGreater(vector<ll>&a, ll x){
    auto it = lower_bound(a.begin(),a.end(),2*x-1);
    auto index = distance(a.begin(),it);
    return a.size()-index-1;
    
}
int main(){
    ll t;
    cin >> t;
    while(t--){
        ll n,m;
        cin >> n >> m;
        vector<ll> a(n);
        for(auto &x:a) cin >> x;
        sort(a.begin(),a.end());
        ll low=1,high=a.back();
        while(low+1<high){
            ll mid=(low+high)/2;
            if(countGreater(a,mid)>=(n+m+1)/2){
                low = mid;
            }
            else{
                high = mid;
            }
        }
        cout << low << "," << high<<endl;

    }
}