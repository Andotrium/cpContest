#include <iostream>
#include <vector>

using namespace std;

/*
Problem: https://codeforces.com/problemset/problem/2155/B
here a simple idea is that first we have to notice that to make a cell inescapable
there should be at the minimum a pair, a pair that traps Abraham pointing towards each other
so pretty straight forward that let's make this red zone at (0,0) and (0,1) now we'll point all the remaining
number of blocks that have to be inescapable towards this zone
1. if in the first column just point left
2. if in the columns after the first one, just point upwards
3. if the number of inescapable blocks is over then just point Downwards to exit


*/

void answer(int n,int k){
    vector<char> grid(n*n);
    int negativeCells = n*n - k;
    if(negativeCells == 1){
        cout << "NO"<<endl;return;
    }
    cout << "Yes"<<endl;
    int col = 0;
    int row = 0;
    for(int i=0;i<n*n;i++){
        if(negativeCells){
            col = i/n;
            row = i - col*n;
            if(row == 0 && col == 0) {grid[i] = 'R';}
            else if(row == 1 && col == 0) {grid[i] = 'L';}
            else if(col == 0 && row > 1) {grid[i] = 'L';}
            else if(col > 0) {grid[i] = 'U';}
            negativeCells -- ;

        }
        else {
            grid[i] = 'D';
        }

    }
    //printing
    int trig = 0;
    for(char c:grid){
        if(trig!=0&&trig % n == 0){
            cout << endl;
        }
        cout << c ; trig++;
    }
    cout << endl;
    return;

}

int main(){
    int t;
    cin >> t;
    while(t--){
        int n,k;
        cin >> n >> k;
        answer(n,k);
    }
}