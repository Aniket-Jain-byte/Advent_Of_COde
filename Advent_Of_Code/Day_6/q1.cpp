#include<bits/stdc++.h>
using namespace std;

int main() {
    
    unordered_map<int,int> m;
    fstream myFile;
    string line;

    myFile.open("input.txt");
    if(myFile.is_open()) {
        getline(myFile,line);
    }

    int start = 0,end = 0;
    for(; end < 14; ++end) ++m[line[end]];

    for(; end < line.size(); ++end,++start) {
        ++m[line[end]];
        --m[line[start]];
        if(m[line[start]] == 0) m.erase(line[start]);
        if(m.size() == 14) {
            cout<<(end+1);
            return 0;
        }
    }
}