#include<bits/stdc++.h>
using namespace std;

int main() {

    fstream myFile;
    int score = 0;

    unordered_map<char,unordered_map<char,int>> m;

    m['A']['X'] = 3;
    m['A']['Y'] = 4;
    m['A']['Z'] = 8;


    m['B']['X'] = 1;
    m['B']['Y'] = 5;
    m['B']['Z'] = 9;

    m['C']['X'] = 2;
    m['C']['Y'] = 6;
    m['C']['Z'] = 7;

    myFile.open("q1_input.txt");
    if(myFile.is_open()) {
        string line;
        while(getline(myFile,line)) {
            score += m[line[0]][line[2]];
        }
    }

    cout<<score;
}

/*
A Rock -> 1 point
B Paper -> 2 points
C scissor -> 3 points;

6 points for win
3 points for draw
0 points for loose
*/