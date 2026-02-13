#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int sol(int n,vector<int> arr){
// first change every even number to the max uptil that point
// then iterate once through the odd digits, and find min num you must subtract
// to make it smaller than it's neighbours
stack<int>temp;
for(int i=0;i<n;i++){
while(!temp.empty() && arr[i]>temp.top()) temp.pop();
if(temp.empty()) temp.push(arr[i]);
if(i%2 == 1) arr[i] = temp.top();
}
int ans = 0;
for(int i=0;i<n;i+=2){
    int leftE = 0,rightE=0;
    if(i==0){rightE = arr[i+1];leftE=rightE;}
    else if(i==n-1) {leftE = arr[i-1];rightE = leftE;}
    else {leftE = arr[i-1];rightE = arr[i+1];}
    int a = min(leftE,rightE);
    ans += max(0, arr[i]-a+1);

}
return ans;
}

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<int> array(n);
        for(int i=0;i<n;i++){
        cin >> array[i];
        }
        cout <<sol(n,array) <<endl;
    }

}
