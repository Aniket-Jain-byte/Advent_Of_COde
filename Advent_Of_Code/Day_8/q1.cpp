#include<bits/stdc++.h>
using namespace std;


int main() {

    vector<vector<int>> arr;
    fstream myFile;
    myFile.open("input.txt");

    
    if(myFile.is_open()) {
        string line;
        while(getline(myFile,line)) {
            vector<int> row;
            for(char c:line) row.push_back(c-'0'); 
            arr.push_back(row);
        }
    }
    int ans = 0, n = arr.size(), m = arr[0].size();

    vector<vector<int>> maxL(n,vector<int>(m-1));
    vector<vector<int>> maxR(n,vector<int>(m,-1));
    vector<vector<int>> maxU(n,vector<int>(m,-1));
    vector<vector<int>> maxD(n,vector<int>(m,-1));

    for(int i = 1; i < arr.size(); ++i) {
        for(int j = 1; j < arr[0].size(); ++j) {
            maxL[i][j] = max(arr[i][j-1],maxL[i][j-1]);
            maxR[i][m-j-1] = max(arr[i][m-j],maxR[i][m-j]);
            maxU[i][j] = max(arr[i-1][j],maxU[i-1][j]);
            maxD[n-i-1][j] = max(arr[n-i][j],maxD[n-i][j]);
        }
    }

    for(int i = 0; i < arr.size(); ++i) {
        for(int j = 0; j < arr[0].size(); ++j) {
            ans += (arr[i][j] > maxL[i][j] || arr[i][j] > maxR[i][j] || arr[i][j] > maxU[i][j] || arr[i][j] > maxD[i][j]);
        }
    }

    cout<<ans;
    return 0;   
}