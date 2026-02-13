#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int main(){
int t;
cin >> t;
while(t--){
int n,m;
cin >> n >> m;
vector<pair<int,int > > stamps; // time, position
for(int i=0;i<n;i++){
int temp1, temp2;
cin >> temp1 >> temp2;
stamps.push_back({temp1,temp2});
}
int ipos = 0, itime = 0;
int ans = 0;
for(auto x:stamps){
if( abs(x.first-itime)%2 == abs(ipos-x.second)) {
ans += x.first-itime;
ipos = x.second;
itime = x.first;
}
else {
ans += max(0, x.first-itime-1);
ipos = x.second;
itime = x.first;
}}
if(itime != m) {
ans += abs(m-itime);
}
cout << ans << endl;
}
}
