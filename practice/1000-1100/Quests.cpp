#include <iostream>
#include <vector>
#define ll long long
using namespace std;

/*
learning:
A nice type of question that teaches you, that actually instead of thinking of some problems in a way too complex way
just try to think, how does it behave at a certain instance in time, like here we thought how it'll behave when we decide to 
actually play i levels, and repeat k-i times.
Instead of thinking of it like creating a graph or trying to figure out something extremely complex such as 
how to make a decision as to when replay a level or when to move on to the next level
think simple and elegantly 
also read the question better, it was written that you could replay any level less than j, but I thought
you could only replay the current level, and can't replay a past level, read the question carefully as well.

*/

int main(){
    ll t;
    cin >> t;
    while(t--){
        ll n,k;
        cin >> n >> k;
        vector<ll> a(n);
        for(auto&x:a)cin >> x;
        vector<ll> bm(n); // let's just store the max vaue of b uptil that point, because that's of our interest
        // all the original value of b are not of our interest
        ll maxb = INT_MIN;
        for(ll i=0;i<n;i++){
            ll temp;
            cin >> temp;
            maxb = max(maxb,temp);
            bm[i] = maxb;
        }

        // now we'll iterate over i from 0 to n assuming that i levels are completed first
        // this automatically means that the max b is completed k-i times;
        vector<ll> prefSum(n+1,0);
        for(int i=1;i<=n;i++){
            prefSum[i] = prefSum[i-1]+a[i-1];
        }
        ll ans = INT_MIN;
        for(int i=0;(i<n && i+1<=k);i++){
            ll redone = k-(i+1);
            ans = max(ans,(redone*bm[i]+prefSum[i+1]));
        }
        cout <<ans<<endl;
        
    }
}