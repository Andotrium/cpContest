#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#define ll long long

using namespace std;

/*
Problem - 2169B Drifting Away
to solve this problem you only have to make one observation, that at any point if > come before any < then you can simply make it infinite
second observation is that only a single * can every be allowed, and that too in the midpoint of <<<<*>>>> and no where else
because any where else and it'll go to infinity
so in the end you simply have to take the max(left,right)+(no. of *) and this is simply the answer
*/

int simulation(string& s, int size){
    int time = 0;
    int left = 0;
    int right = 0;
    int blank = 0; // at max 1
    for(auto x:s){
        if(x == '<') left++;
        else if(x=='>') right++;
        else blank++;
    }
    if(blank>1) return -1;
    for(int i=0;i<size;i++){
        if(i<left){
            if(s[i]!='<') return -1;
        }
        else if(i>left){
            if(s[i]!='>') return -1;
        }
    }
    return blank + max(right,left);

}
int main(){
    int t;
    cin >> t;
    while(t--){
        string s;
        cin >> s;
        cout << simulation(s,s.size())<<endl;
    }
    return 0;
}