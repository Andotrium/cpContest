#include<iostream>
#include<vector>
#define ll long long
using namespace std;

void solve(){
        int n;
    cin >> n;
    vector<int> matrix(n);
    for(int i = 0; i < n; i++){
        cin >> matrix[i];
    }
    int pointerToTop = 0;
    for(int i = 1; i < n; i++){
        if(matrix[i] < matrix[pointerToTop]){
            pointerToTop = i;
        }
    }
    int result = 0;
    for(int i = pointerToTop; i > 0; i--){
        if(matrix[i-1] > matrix[i] + 1){
            result += matrix[i-1] - (matrix[i] + 1);
            matrix[i-1] = matrix[i] + 1;
        }
    }
    for(int i = pointerToTop; i < n - 1; i++){
        if(matrix[i+1] > matrix[i] + 1){
            result += matrix[i+1] - (matrix[i] + 1);
            matrix[i+1] = matrix[i] + 1;
        }
    }
    cout << result << endl;
    return ;
}
int main(){
ll t;
cin >> t;
while(t--){
    solve();
}
}