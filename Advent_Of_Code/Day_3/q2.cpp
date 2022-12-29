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
        vector<string> arr(3);

        for(int count = 0; getline(myFile,line); ++count) {
            arr[count%3] = line;
            if(count%3 == 2) {

                unordered_set<char> us1;
                for(char c:arr[0]) us1.insert(c);

                unordered_set<char> us2;
                for(char c:arr[1]) us2.insert(c);

                unordered_set<char> us3;
                for(char c:arr[2]) us3.insert(c);

                for(auto c:us1) {
                    if(us3.find(c) != us3.end() && us2.find(c) != us2.end()) {
                        ans += getVal(c);
                    }
                }
            }
        }
    }
    cout<<ans;
}