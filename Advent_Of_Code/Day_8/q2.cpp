#include<bits/stdc++.h>
using namespace std;



int calcScore(vector<vector<int>> &arr, int x, int y) {

    int l = 0, r = 0, u = 0, d = 0, n = arr.size(), m = arr[0].size();

    for(int j = y-1; j >= 0; --j) {
        ++l;
        if(arr[x][j] >= arr[x][y]) break;
    }

    for(int j = y+1; j < m; ++j) {
        ++r;
        if(arr[x][j] >= arr[x][y]) break;
    }

    for(int i = x-1; i >= 0; --i) {
        ++u;
        if(arr[i][y] >= arr[x][y]) break;
    }

    for(int i = x+1; i < n; ++i) {
        ++d;
        if(arr[i][y] >= arr[x][y]) break;
    }

    return l*r*u*d;
}

int main() {

    vector<vector<int>> arr;
    fstream myFile;
    myFile.open("input.txt");

    string line;
    while(getline(myFile,line)) {
        vector<int> row;
        for(char c:line) row.push_back(c-'0');
        arr.push_back(row);
    }
        
    int ans = 0;

    for(int i = 1; i < arr.size()-1; ++i) {
        for(int j = 1; j < arr[0].size()-1; ++j) {
           ans = max(ans,calcScore(arr,i,j));
        }
    }

    cout<<ans;
}