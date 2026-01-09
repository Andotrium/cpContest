#include <iostream>
#include <vector>
#include <algorithm>
#define ll long long
using namespace std;

ll ans(vector<ll>& first, vector<ll>& second, ll& size){
    vector<ll> maxScore(1,0);
    vector<ll> minScore(1,0);
    for(int i=0;i<size;i++){
        minScore.push_back(min(minScore[i]-first[i],second[i]-maxScore[i]));
        maxScore.push_back(max(maxScore[i]-first[i],second[i]-minScore[i]));
    }
    return *(maxScore.end()-1);
}

int main(){
    ll t;
    cin >> t;
    while(t--){
        ll size;
        cin >> size;
        vector<ll> first(size),second(size);
        for(ll i=0;i<size;i++){
            cin >> first[i];
        }
        for(ll i=0;i<size;i++){
            cin >> second[i];
        }
        cout<< ans(first,second,size) << endl;

    }
    return 0;
}
