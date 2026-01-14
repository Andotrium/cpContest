#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

#define ll long long
using namespace std;

struct state{
    ll sum;
    ll index;
    ll prevC;
    ll presentC;
};

struct cmp{
    bool operator()(const state& a, const state& b){
        return a.sum < b.sum;
    }
};

int main(){
    ll n,k,x;
    cin >> n >> k >> x;
    vector<ll> a(n);
    for(int i=0;i<n;i++) cin >> a[i];

    sort(a.begin(),a.end(),[](auto a, auto b){return a>b;});
    priority_queue<state, vector<state>, cmp> pq;
    pq.push({a[0]*k,0,0,k});
    while(x--){
        auto temp = pq.top();
        cout << temp.sum << endl;
        pq.pop();

        // transition 1
        if(temp.prevC > 0){
            pq.push({temp.sum - a[temp.index-1]+a[temp.index],temp.index,temp.prevC-1,temp.presentC+1});
        }
        if(temp.index+1<n){
            pq.push({temp.sum-a[temp.index]+a[temp.index+1],temp.index+1,temp.presentC-1,1});
        }

    }
}