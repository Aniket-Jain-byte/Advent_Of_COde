#include<bits/stdc++.h>

using namespace std;

int main()
{

   priority_queue<int,vector<int>,greater<int>> pq;
   int sum = 0;

    fstream myfile;
    myfile.open("q1_input.txt",ios::in);
    if(myfile.is_open()) {
        string line;
        while(getline(myfile,line)) {
            if(line.size() == 0) {
                pq.push(sum);
                if(pq.size() == 4) pq.pop();
                sum = 0;
            }
            else {
                sum += stoi(line);
            }
        }
    }

    pq.push(sum);
    if(pq.size() == 4) pq.pop();

    int ans = 0;
    while(!pq.empty()) {
        ans += pq.top();
        pq.pop();
    }

    cout<<ans;
}