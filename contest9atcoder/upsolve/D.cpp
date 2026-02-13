/*
In this question we'll solve it fully using strings, becauses no integer type can store the whole thing
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <vector>
#define ll long long
using namespace std;

// method 1: O(n^2)
// string add(string real,string number){
// if(number.size()>real.size()) return add(number,real);

// ll gSize = real.size();
// ll sSize = number.size();
// string answer = "";
// ll j = gSize-1;
// ll carry=0;
// while(j>=0){
//     ll base = 0;
//     if(j-(gSize-sSize)<0){
//         base += real[j]-'0';
//     }
//     else{
//         base += real[j]-'0';
//         base += number[j-(gSize-sSize)] - '0';
//     }
//     base += carry;
//     carry = base / 10;
//     base = base %10;
//     answer = to_string(base) + answer;
//     j--;
// }
// if(carry){
//     answer = to_string(carry) + answer;
// }
// return answer;


// }
/*
approach:
- the earlier naive approach was actually going to O(n^2)
in the below approach we take advantage of the fact that we know that all the nums in the vector b must be 1
so simply we know that for an index i in the answer what are the terms that will contribute to that index
-> the indexes that will contribute are who have 1 at that index or in other words whose size is greater than index i
-> so we can do a binary search approach to find the numbers that have size greater than i
-> after getting the index we can now find the total numbers with size greater than i and then simply multiply number by 1
-> then also add the carry to the number
-> this way we can solve the question in O(nlogn) complexity
*/
int main(){
    ll n;
    cin >> n;
    vector<ll> a(n);
    for(auto&x:a) cin >> x;
    sort(a.begin(),a.end());
    vector<ll> ans;
    ll i=1;
    ll greatest = a.back();
    ll carry=0;

    while(i<=greatest){
        auto lowerIt = lower_bound(a.begin(),a.end(),(i));
        ll lowerIndex = lowerIt - a.begin();
        // cout << lowerIndex;
        ll numberToAdd = n-lowerIndex; 
        ll base = numberToAdd+ carry;
        carry = base / 10;
        base = base %10;
        ans.push_back(base);
        i++;
    }
    if(carry) ans.push_back(carry);
    for(int j=ans.size()-1;j>=0;j--) cout << ans[j];
}