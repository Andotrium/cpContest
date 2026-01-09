#include <iostream>
#include <vector>
#define ll long long
using namespace std;

/*
Problem - Codeforces Round 1065 div.3 - c1. Renako Amaori and XOR Game(easy version)
we can solve this easily by bruteforcing in O(n^2) by simulating the game greedily, the person simply swaps 
if currently the score is not 1 for their array

we can do it in linear time by instead of finding the XOR of whole array on every step, just take a boolean if 
odd number of 1s (positive), and at every step, play greedily as the quadratic approach, but instead of calculating 
whole array XOR at every step simply flip the boolean on every swap.
*/

bool highstate(vector<ll> arr){
    bool ans = 0;
    for(auto x:arr){
        ans ^= x;
    }
    return ans;
}
void ans(vector<ll>& first, vector<ll>& second, ll &size){
    bool oneFirst = highstate(first); // true for odd number of 1s in first , false for even 1s
    bool oneSecond = highstate(second); // true for odd number of 1s in second, false for even 1s
    for(int i=0;i<size;i++){
        if(i%2 == 0){
            if(!oneFirst){
                if(first[i] != second[i]) {oneFirst = !oneFirst;
                    oneSecond = !oneSecond;
                    swap(first[i],second[i]);
                }
            }
        }
        else{
            if(!oneSecond){
                if(first[i]!=second[i]) {oneSecond = !oneSecond;
                    oneFirst = !oneFirst;
                    swap(first[i],second[i]);
                }
            }
        }
    }

}

int main(){
int t;
cin >> t;
while(t--){
    ll size;
    cin >> size;
    vector<ll> first(size), second(size);
    for(ll i=0;i<size;i++){
        cin >> first[i];
    }
    for(ll i=0;i<size;i++){
        cin >> second[i];
    }
    ans(first,second,size);
    int t1 = highstate(first);
    int t2 = highstate(second);
    if(t1>t2){
        cout << "Ajisai" << endl;
    }
    else if(t2>t1){
        cout << "Mai" << endl;
    }
    else {
        cout << "Tie" << endl;
    }

}
return 0;
}