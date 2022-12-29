#include <bits/stdc++.h>
using namespace std;


bool isAdjacent(pair<int,int> &h, pair<int,int> &t) {
    return (abs(h.first - t.first) <= 1 && abs(h.second - t.second) <= 1);
}

void changeCoordinates(char c, pair<int,int> &p) {
    if(c == 'R') p.second += 1;
    if(c == 'L') p.second -= 1;
    if(c == 'U') p.first += 1;
    if(c == 'D') p.first -= 1;
}

void moveTail(pair<int,int> &h, pair<int,int> &t) {

    if(isAdjacent(h,t)) return;

    if(h.second > t.second) changeCoordinates('R',t);
    else if(h.second < t.second) changeCoordinates('L',t);

    if(h.first > t.first) changeCoordinates('U',t);
    else if(h.first < t.first) changeCoordinates('D',t);

}

int main() {

    fstream myFile;
    myFile.open("input.txt");

    
    pair<int,int> h{0,0};
    pair<int,int> t{0,0};

    unordered_set<string> us;

    string line;
    while(getline(myFile,line)) {
        int steps = 0;
        for(int i = 2; i < line.size(); ++i) {steps *= 10; steps += (line[i]-'0');}
        while(steps--) {
            changeCoordinates(line[0],h);
            moveTail(h,t);
            us.insert(to_string(t.first) + "," + to_string(t.second));
        }
    }

    cout<<us.size();
}   