#include<bits/stdc++.h>
using namespace std;

int main() {

    vector<stack<char,vector<char>>> arr(10);
    arr[1] = *(new stack<char,vector<char>>({'H','R','B','D','Z','F','L','S'}));
    arr[2] = *(new stack<char,vector<char>>({'T','B','M','Z','R'}));
    arr[3] = *(new stack<char,vector<char>>({'Z','L','C','H','N','S'}));
    arr[4] = *(new stack<char,vector<char>>({'S','C','F','J'}));
    arr[5] = *(new stack<char,vector<char>>({'P','G','H','W','R','Z','B'}));
    arr[6] = *(new stack<char,vector<char>>({'V','J','Z','G','D','N','M','T'}));
    arr[7] = *(new stack<char,vector<char>>({'G','L','N','W','F','S','P','Q'}));
    arr[8] = *(new stack<char,vector<char>>({'M','Z','R'}));
    arr[9] = *(new stack<char,vector<char>>({'M','C','L','G','V','R','T'}));

    fstream myFile;
    myFile.open("input.txt");

    if(myFile.is_open()) {
        string line;
        while(getline(myFile,line)) {
            int x = 0, s1 = 0, s2 = 0,i;
            for(i = 5; line[i] != ' '; ++i) { x *= 10; x += (line[i]-'0');}
            for(i = i+6; line[i] != ' '; ++i) { s1 *= 10; s1 += (line[i]-'0');}
            for(i = i +4; i < line.size(); ++i) { s2 *= 10; s2 += (line[i]-'0');}

            while(x--) {
                arr[s2].push(arr[s1].top());
                arr[s1].pop();
            }
        }
    }

    for(int i = 1; i <= 9; ++i) {
        cout<<arr[i].top();
    }
}