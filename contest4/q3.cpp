#include <iostream>
#include <vector>
#include <set>
#include <unordered_map>
using namespace std;

set<int> primeDivisors(int n){
set<int> ans;
if(n<2) return {1};
for(int i=2;i*i<=n;i++){
    if(n%i == 0){
        ans.insert(i);
        while(n%i==0) n/=i;
    }
}
if(n>1) ans.insert(n);
return ans;
}

int solve(int n,vector<int> arr){
unordered_map<int,int> zeroMP;
    for(int i=0;i<n;i++){
        set<int> temp = primeDivisors(arr[i]);
        for(auto x: temp) {
            if(x!=1 && zeroMP[x]) return 0;
            zeroMP[x] = arr[i];
        }

}
unordered_map<int,int> oneMP;
for(int i=0;i<n;i++){
    set<int> temp = primeDivisors(arr[i]+1);
    for(auto x:temp) {
        if(zeroMP[x]) return 1;
    }
}
return 2;
}
int main(){
int t;
cin >> t;
while(t--){
    int n;
    cin >> n;
    vector<int> arr(n);
    vector<int> b(n);
    for(int i=0;i<n;i++) cin >> arr[i];
    for(int i=0;i<n;i++) cin >> b[i];
    cout<<solve(n,arr)  << endl;
}
}
