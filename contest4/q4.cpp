#include <iostream>
#include <unordered_map>
#include <vector>
#include <set>

using namespace std;
set<int> primeDivisors(int num){
    if(num < 2) return {1};
    set<int> ans;
    for(int i=2;i*i<=num;i++){
        if(num%i == 0)
            ans.insert(i);
        while(num%i == 0 && num != 0) num /= i;
    }
    if(num > 1) ans.insert(num);
    return ans;
}
int solve(int n,vector<int> a, vector<int> b){
unordered_map<int,int> zeroMp;
for(int i=0;i<n;i++){
    set<int> temp = primeDivisors(a[i]);
    for(auto x:temp) {
        if(zeroMp[x] && x != 1) return 0;
        zeroMp[x] = a[i];
    }
    
}
int ans = INT_MAX ;
for(int i=0;i<n;i++) {
set<int> temp = primeDivisors(a[i] + 1);
for(auto x:temp) {
    if(zeroMp[x]) ans = min(ans, b[i]);
}
}
vector<pair<int,int>> newArray; //a,b
for(int i=0;i<n;i++) {
    newArray.push_back({a[i],b[i]});
}
sort(newArray.begin(),newArray.end(),[](pair<int,int>& a,pair<int,int>&b){
        if(a.second == b.second) return a.first < b.first;
        return a.second>b.second;});
if(newArray.size()>1) {
    ans = min(ans, newArray[0].second + newArray[1].second);
    if(newArray[1].first>newArray[0].first) ans = min(ans, (newArray[1].first-newArray[0].first)*newArray[0].second);
}
return ans;
}

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<int> a(n); vector<int> b(n);
        for(int i=0;i<n;i++){
            cin >> a[i];
        }
        for(int i=0;i<n;i++){
            cin >> b[i];
        }
        cout << "ans:" << solve(n,a,b) << endl;
    }
}
