#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

#define ll long long
using namespace std;
/*
problem - https://codeforces.com/problemset/problem/2162/C
This is a pretty straightforward problem once we have made certain observations
1. first we can easily spot that it'll be impossible to make b from a if the length of b(in binary) is greater than a(in binary)
because we can only take XOR from 0 -> a
2. if both numbers same, just take XOR with 0
now we have to make the observation that, any number can be reached from a by taking an XOR with some arbitrary number
but we have to keep the number less than or equal to a
so we can conclude that, we can reach any possible valid state by taking XOR in at max 2 steps
I came to this conclusion based on the following: 
-> we know that a(binary) has n digits(with the nth digit 1 for sure) and b(binary) has less than or equal to n digits;
-> we can make digits 1->(n-1) of a equal to b in a single step, by taking the required number
-> then we can make the nth digit of a and b also equal by taking all the 1->(n-1) digits 0, and the last digit based on our preference
-> we could have done it in a single step as well, but we have to make sure that the taken number is always less than or equal to a, hence we simply take n-1 digits in first step to make sure that it's always less than a

and then to find num1 and num2 we use a simple trick
we know that 
if (a XOR num1) = x then: num1 = a XOR x ;
use the above trick to find num1 and num2 both
*/

vector<ll> binaryMaker(ll number){
    vector<ll> binary(log2(number)+1);
    while(number){
        ll index = log2(number);
        binary[index] = 1;
        number -= pow(2,index);
    }
    return binary;
}
ll decimalMaker(vector<ll>& binary){
    ll ans = 0;
    for(int i=0;i<binary.size();i++){
        ans += binary[i] * pow(2,i);
    }
    return ans;
}

void answer(vector<ll>& a, vector<ll>& b, ll n){
    if(n<b.size()) {cout << -1 << endl; return;}
    if(a==b) {cout << 0 << endl;return;}
    if(b.size()<n){
        while(b.size()!=n) b.insert(b.end(),0);
    }
    
    vector<ll> num1(n,0);
    vector<ll> num2(n,0);

    for(int i=0;i<n-1;i++){
        num1[i] = a[i]^b[i];
    }
    num2[n-1] = a[n-1] ^ b[n-1];
    cout << 2 << endl;
    cout << decimalMaker(num1) << " " << decimalMaker(num2) << endl;

}

int main(){
    ll t;
    cin >> t;
    while(t--){
        ll atemp,btemp;
        cin >> atemp >> btemp;
        vector<ll> a = binaryMaker(atemp);
        vector<ll> b=binaryMaker(btemp);
        answer(a,b,a.size());
    }
}