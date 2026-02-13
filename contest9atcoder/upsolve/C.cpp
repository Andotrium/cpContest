#include <iostream>
#include <vector>
#include <algorithm>
#define ll long long

using namespace std;


int main(){
    ll n;
    cin >> n;
    vector<ll> a(n,0);
    for(int i=0;i<n;i++) {
        ll temp;
        cin >> temp;
        a[i]=temp;
    }
    sort(a.begin(),a.end());
    ll maxVal = a[n-1];
    if(n%2 == 1){
        cout << maxVal ;
    }
    else{
        ll sum = a[0] + maxVal;
        ll aSum = 0;
        for(auto x:a) aSum +=x;
        ll numMax = 0;
        for(ll i=n-1;i>=0;i--){
            if(a[i] == maxVal) {numMax++;}
            else{
                break;
            }
        }
        ll i=0;
        ll j=n-1;
        while(a[j]==maxVal) j--;
        bool trig=true;
        while(i<j){
            if((a[i]+a[j])!=maxVal){
                trig = false;
                break;
            }
            else{
                i++;
                j--;
            }
        }
        if(trig && i > j) cout << maxVal << " ";
        i=0;j=n-1;
        trig =true;
        while(i<j){
            if(a[i]+a[j] != sum) {
                trig = false;
                break;
            }
            else{
                i++;
                j--;
            }
        }
        if(trig) cout << sum;
        // if(aSum == sum*(n/2)) cout << sum ;
    }
}