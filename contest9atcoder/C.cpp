#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
bool check(vector<long long> &vc, long long L){
    int low = 0, high = vc.size() - 1;
    while(low <= high){
        if(vc[high] == L){
            high--;
        }
        else if(low < high && vc[low] + vc[high] == L){
            low++;
            high--;
        }
        else{
            return false;
        }
    }
    return true;
}
// real
int main(){
    vector<long long> vc;
    int n;
    cin >> n;
    long long maxx = 0;
    for(int i = 0; i < n; i++){
        long long temp;
        cin >> temp;
        maxx = max(maxx, temp);
        vc.push_back(temp);
    }
    sort(vc.begin(), vc.end());
    vector<long long> ans;
    if(check(vc, maxx)){
        ans.push_back(maxx);
    }
    long long L2 = vc[0] + vc[n-1];
    if(L2 != maxx && check(vc, L2)){
        ans.push_back(L2);
    }
    sort(ans.begin(), ans.end());
    ans.erase(unique(ans.begin(), ans.end()), ans.end());
    for(long long x : ans){
        cout << x << " ";
    }
    return 0;
}