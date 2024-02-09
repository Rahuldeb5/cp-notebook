#include <bits/stdc++.h>
using namespace std;

int main() {
    // ios::sync_with_stdio(0); cin.tie(0);

    freopen("cownomics.in", "r", stdin);
    freopen("cownomics.out", "w", stdout);

    map<char, int> mp {{'A', 0}, {'C', 1}, {'T', 2}, {'G', 3}};

    int n, m; cin >> n >> m;

    vector<string> spot(n), plain(n);
    for(int i=0; i<n; i++) {
        cin >> spot[i];
    }
    for(int i=0; i<n; i++) {
        cin >> plain[i];
    }

    int num {};

    for(int i=0; i<m; i++) {
        for(int j=i+1; j<m; j++) {
            for(int k=j+1; k<m; k++) {
                vector<int> arr(64, 0);
                bool spotty = true;

                for(int x=0; x<spot.size(); x++) {
                    int id = (mp[spot[x][i]]*16) + (mp[spot[x][j]]*4) + (mp[spot[x][k]]);
                    arr[id]++;
                }
                for(int x=0; x<plain.size(); x++) {
                    int id = (mp[plain[x][i]]*16) + (mp[plain[x][j]]*4) + (mp[plain[x][k]]);
                    if(arr[id] >= 1) {
                        spotty = false;
                        break;
                    }
                }
                if(spotty) num++;
            }
        }
    }
    cout << num;
}
