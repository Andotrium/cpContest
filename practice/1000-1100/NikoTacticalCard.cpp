#include <iostream>
#include <vector>
#include <algorithm>
#define ll long long
using namespace std;

/*
Problem 1068(Div.2)-B Niko's Tactical Cards
here at every step we have two options either red(k-a) or blue(b-k)
here we can see that the max at every step is not necessarily the chosen to get the max at the next step
ex: a=[1,0]; b=[2,0]
max1 = 1-0
but max2 = 0-(-2)
so we can notice that to relate the present steps answer to the previous step we simply need to find
the max between red and blue and for red -> k-a (maximize k from previous steps)
blue -> b-k (minimize k from previous steps)
so for O(n) solution, simply keep track of min, and max answer from previous steps
*/

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
