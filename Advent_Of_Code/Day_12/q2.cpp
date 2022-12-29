#include <bits/stdc++.h>
using namespace std;

bool isValid(pair<int,int> coord, pair<int,int> newCoord, vector<vector<char>> arr) {
    return((newCoord.first >= 0 && newCoord.second >= 0 && newCoord.first < arr.size() && newCoord.second < arr[0].size()) &&
        (arr[newCoord.first][newCoord.second] - arr[coord.first][coord.second] >= -1)
    );
}

int main() {

    vector<vector<char>> arr;
    
    fstream myFile;
    myFile.open("input.txt");
    string line;

    pair<int,int> start;

    int a[] = {1,-1,0,0};
    int b[] = {0,0,-1,1};

    while(getline(myFile,line)) {
        arr.push_back({}); int n = arr.size();
        for(int i = 0; i < line.size(); ++i) {
            arr[n-1].push_back(line[i]);
            if(line[i] == 'S') arr[n-1][i] = 'a';
            else if(line[i] == 'E') start = {n-1,i};
        }
    }

    arr[start.first][start.second] = 'z';

    vector<vector<int>> vis(arr.size(),vector<int>(arr[0].size(),0));

    queue<pair<pair<int,int>,int>> q;   
    q.push({start,0});

    while(!q.empty()) {

        auto p = q.front(); q.pop();
        pair<int,int> coord = p.first;
        int steps = p.second;

        if(arr[coord.first][coord.second] == 'a') {
            cout<<steps<<" ";
            break;
        }

        for(int i = 0; i < 4; ++i) {
            pair<int,int> newCoord = {coord.first+a[i],coord.second+b[i]};
            if(isValid(coord,newCoord,arr) && !vis[newCoord.first][newCoord.second]) {
                q.push({newCoord,steps+1});
                vis[newCoord.first][newCoord.second] = 1;
            }
        }
    }
}   