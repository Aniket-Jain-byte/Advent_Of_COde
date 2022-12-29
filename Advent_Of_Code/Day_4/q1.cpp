#include<bits/stdc++.h>
using namespace std;

int main() {

    fstream myFile;
    myFile.open("input.txt");

    int count = 0;

    if(myFile.is_open()) {
        string line;
        while(getline(myFile,line)) {

            vector<int> a(2);
            vector<int> b(2);
            int i = 0;

            for(; line[i] != '-'; ++i) { a[0] *= 10; a[0] += (line[i] - '0');}
            for(i = i+1; line[i] != ','; ++i) { a[1] *= 10; a[1] += (line[i] - '0');}
            for(i = i+1; line[i] != '-'; ++i) { b[0] *= 10; b[0] += (line[i] - '0');}
            for(i = i+1;  i < line.size(); ++i) { b[1] *= 10; b[1] += (line[i] - '0');

            if(a[0] <= b[0] && (a[1] >= b[0])) ++count;
            else if(b[0] <= a[0] && (b[1] >= a[0])) ++count;
        }
    }

    cout<<count;
}