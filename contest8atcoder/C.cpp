#include <iostream>
#include <vector>
#include <algorithm>
#define ll long long

using namespace std;

int main(){
    ll n,t;
    cin >> n >> t;
    vector<ll> times(n);
    for(auto& x:times) cin >> x;

    ll presentTime = 0;
    ll totalTime = 0;
    for(auto x:times){
        if(x >= presentTime){
            // cout << x-presentTime << endl;
            totalTime += x-presentTime;
            presentTime = x+100;
        }
    }
    if(presentTime <= t){
        // cout << t-presentTime << endl;
        totalTime += t-presentTime;
    }
    cout << totalTime;

}