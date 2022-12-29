#include<bits/stdc++.h>
using namespace std;

int main() {

    fstream myFile;
    myFile.open("input.txt");

    vector<pair<int,int>> arr;
    string line;
    int x = 1, clock = 0;

    while(getline(myFile,line)) {

        if(line == "noop") clock += 1;  
        else {
            clock += 2;
            x += stoi(line.substr(5));
        }
        arr.push_back({clock,x});
    }  
    
    int ans = 0, target = 20;

    for(int i = 0; i < arr.size(); ++i) {
        if(arr[i].first >= target) {
            ans += target * arr[i-1].second;
            target += 40;
        }
    }

    cout<<ans;
}