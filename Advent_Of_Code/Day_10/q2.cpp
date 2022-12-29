#include<bits/stdc++.h>
using namespace std;

int main() {

    fstream myFile;
    myFile.open("input.txt");

    vector<pair<int,int>> arr;
    string line;
    int x = 1, time = 1;

    while(getline(myFile,line)) {

        if(line == "noop") time += 1;  
        else {
            time += 2;
            x += stoi(line.substr(5));
        }
        arr.push_back({time,x});
    }  
    
    int sprite_pos = 1, counter = 0;

    for(int clock = 1; clock <= 240; ++clock) {

        int x = clock%40 == 0 ? 40 : clock%40;
        if(arr[counter].first == clock) {
            sprite_pos = arr[counter].second;
            ++counter;
        }
        if(x >= sprite_pos && x < (sprite_pos+3)) cout<<'#';
        else cout<<' '; 

        if(clock%40 == 0) cout<<endl;
    }
}