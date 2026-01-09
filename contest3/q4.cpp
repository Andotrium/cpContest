#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
using namespace std;

#define int long long

int ans(vector<int> nums){
vector<int> odd;
vector<int> even;
for(auto x:nums){
if(x%2==0) even.push_back(x);
else odd.push_back(x);
}
int ans=0;
if(odd.size()) {
for(int x:even) ans += x;
}
sort(odd.begin(),odd.end(),greater<int>());
int n = odd.size();
if(n%2 == 0) n /=2;
else n = n/2 + 1;
for(int i=0;i<n;i++){
ans += odd[i];
}
return ans;
}
#undef int
int main(){
#define int long long
int t;
cin >> t;
while(t--){
int n;
cin >> n;
vector<int> fields(n);
for(int i=0;i<n;i++){
cin >> fields[i];
}
cout << ans(fields) <<endl;
}return 0;}
