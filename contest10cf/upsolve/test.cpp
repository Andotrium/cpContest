#include <iostream>
#include <vector>
using namespace std;

int main() {
	int t;
	cin >> t;
	while (t--){
	    int n;
	    int k;
	    cin >> n >> k;
	   int sum = 0;
	   int mini=INT_MAX;
	    int secmin=INT_MAX;
	    vector<int> a(n);
	    for(auto&x:a) {
	        cin >> x;
	        sum += x;
	        mini=min(mini,x);
	        if (x>mini) secmin=min(secmin,x);
	    }
        sort(a.begin(),a.end());
       secmin = a[1];
	    while (k--){
	       if((mini+secmin)%2 == 0){
	           sum += (mini+secmin)/2;
	           secmin = min(secmin,(mini+secmin)/2);
	       
	       }
	       else {
	           sum += (mini+secmin+1)/2;
	           secmin = min(secmin,(mini+secmin+1)/2);
	           
	       }
	    }
	   cout << sum << endl;
	}

}
