#include <iostream>
#include <bits/stdc++.h>

#define long ll;

using namespace std;

void work() {
    int N; 
    cin >> N;
    
    vector<int> arr(N+1, 0);
    vector<int> lastInd(N, -1);
    
    for(int i = 1; i <= N; i++) cin >> arr[i];
    
    lastInd[0] = 0;
    int currSum = 0;
    
    for(int i = 1; i <= N; i++) {
        currSum += arr[i];
        currSum %= N;
        currSum = (currSum + N) % N;
        
        if(lastInd[currSum] != -1) {
            int subarrLen = i - lastInd[currSum];
            cout << subarrLen << endl;
            
            for(int j = lastInd[currSum] + 1; j <= i; j++) {
                cout << j << " ";
                if(j == i) cout << endl;
            }
            return;
        }
        lastInd[currSum] = i;
    }
}

int main() {
	int t;
	cin >> t;
	
	while(t--) {
	  work();
	}
	return 0;
}