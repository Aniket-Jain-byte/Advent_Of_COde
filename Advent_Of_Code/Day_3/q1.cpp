#include<bits/stdc++.h>
using namespace std;


int getVal(char c) {
    if(c >= 'a' && c <= 'z') return (c-'a')+1;
    else return (c-'A') + 27;
}

int main() {

    fstream myFile;
    myFile.open("q1_input.txt");
    int ans = 0;

    if(myFile.is_open()) {
        string line;
        while(getline(myFile,line)) {
            unordered_set<char> us;
            for(int i = 0; i < line.size(); ++i) {
                if(i < line.size()/2) us.insert(line[i]);
                else {
                    if(us.find(line[i]) != us.end()) {
                        ans += getVal(line[i]);
                        break;
                    }
                }
            }
        }
    }

    cout<<ans;
}