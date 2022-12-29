#include<bits/stdc++.h>
using namespace std;

class monkey {
    public:
        queue<int> items;
        pair<char,int> operation;
        int test, ifTrue, ifFalse;
};

int main() {

    fstream myFile;
    myFile.open("input.txt");

    vector<monkey> monkeys;
    string line;

    while(getline(myFile,line)) {

        monkey m; int x = 0;
        for(char c:line) {
            if(c == ',') { m.items.push(x); x = 0;}
            else {x *= 10; x += c-'0';}
        }

        getline(myFile,line); x = 0;
        for(int i = 1; i < line.size(); ++i) {x *= 10; x += line[i]-'0';}
        m.operation = {line[0],x};

        getline(myFile,line); x = 0;
        for(int i = 0; i < line.size(); ++i) {x *= 10; x += line[i]-'0';}
        m.test = x;

        getline(myFile,line);
        m.ifTrue = line[0]-'0';

        getline(myFile,line);
        m.ifFalse = line[0]-'0';

        getline(myFile,line);
        monkeys.push_back(m);
    }   

    
    vector<int> ans(monkeys.size());

    for(int round_number = 1; round_number <= 10000; ++round_number) {
        
        for(int i = 0; i < monkeys.size(); ++i) {
            while(!monkeys[i].items.empty()) {

                long long int item = monkeys[i].items.front(); monkeys[i].items.pop();
                if(monkeys[i].operation.first == '+') item += monkeys[i].operation.second;
                else if(monkeys[i].operation.first == '*') item *= monkeys[i].operation.second;
                else item *= item;

                item %= 9699690;
                ++ans[i];
                
                if(item % monkeys[i].test == 0) monkeys[monkeys[i].ifTrue].items.push(item);
                else monkeys[monkeys[i].ifFalse].items.push(item);
            }
        }      
    }

    sort(ans.begin(),ans.end(),greater<int>());
    cout<<((long long int)ans[0]) * ans[1];
}



/*
79,98,
*19
23
2
3

54,65,75,74,
+6
19
2
0

79,60,97,
^1
13
1
3

74,
+3
17
0
1
*/