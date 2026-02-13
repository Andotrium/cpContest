/*
Kadane's Algorithm is a method of finding the maximum sum of a subarray in single search
Time complexity: O(n)
Space complexity: */

#include <iostream>
#include <vector>

using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int> a(n);
    for(auto &x:a) cin >> x;

    int presentSum=a[0];
    int maxSum = presentSum;
    for(int i=1;i<n;i++){
        presentSum += a[i];
        presentSum = max(a[i],presentSum);
        maxSum = max(presentSum,maxSum);
    }
    cout << maxSum << endl;
}