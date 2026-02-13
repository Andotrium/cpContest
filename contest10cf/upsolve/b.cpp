#include <iostream>
#include <vector>
using namespace std;
int main (){
    int t;
    cin >> t;
    while (t--){
    int n ;
    cin >> n;
    vector<int> p(n),orig(n);
    for (int i=0;i<n;i++){
        cin >> p[i];
    }
    for (int i=0;i<n;i++){
        cin >> orig[i];
    }
    int idx =0;
    for (int i=0;i<n;i++){
        int element = orig[i];
        while (idx < n && p[idx]!=element) idx++;
        if (idx == n) {
            cout << "no" << endl; 
            break;
        }
    }
    if (idx < n)cout << "yes" << endl;
}
    

}
// 6 5 7 4 7 5 
// 1 1 4 8 10  1 1 
