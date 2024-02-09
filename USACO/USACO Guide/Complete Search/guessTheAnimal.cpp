#include <bits/stdc++.h>
using namespace std;

int main() {
    // ios::sync_with_stdio(0); cin.tie(0);

    freopen("guess.in", "r", stdin);
    freopen("guess.out", "w", stdout);

    int n; cin >> n;
    vector<vector<string>> arr;

    for(int i=0; i<n; i++) {
        string s; cin >> s;
        int x; cin >> x;
        
        vector<string> temp(x);

        for(int j=0; j<x; j++) {
            cin >> temp[j];
        }
        arr.push_back(temp);
    }

    vector<int> ans;

    for(int i=0; i<n; i++) {
        for(int j=i+1; j<n; j++) {
            int num {};
            
            for(int k=0; k<arr[i].size(); k++) {
                for(int l=0; l<arr[j].size(); l++) {
                    if(arr[i][k] == arr[j][l]) {
                        num++;
                        break;
                    }
                }
            }

            ans.push_back(num);
        }
    }

    int high = *max_element(ans.begin(), ans.end());

    cout << high + 1;
}
