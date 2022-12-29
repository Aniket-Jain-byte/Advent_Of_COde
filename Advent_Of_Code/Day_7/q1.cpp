#include<bits/stdc++.h>
using namespace std;

string line;
fstream myFile;

int ans = 0;

class Dir {
    public:
        vector<Dir*> children;
        int size = 0;
        string key;
    
    Dir(string s) {
        key = s;
    }
};

void make_dir(Dir* root) {

    
    getline(myFile,line);
    getline(myFile,line);

    while(line[0] != '$') {
        if(line[0] == 'd') root->children.push_back(new Dir(line.substr(4)));
        else {
            int size = 0;
            for(int i = 0; line[i] != ' '; ++i) {
                size *= 10;
                size += (line[i]-'0');
            }
            root->size += size;
        }
        getline(myFile,line);
    }

    for(int i = 0; i < root->children.size(); ++i) make_dir(root->children[i]);
    getline(myFile,line);
}

int getSize(Dir* root) {
    if(root->children.size() == 0) return root->size;
    for(int i = 0; i < root->children.size(); ++i) root->size += getSize(root->children[i]);  
    return root->size;
}

void calcAns(Dir* root) {
    if(root->size <= 100000) ans += root->size;
    for(int i = 0; i < root->children.size(); ++i) calcAns(root->children[i]);
}

int main() {

    myFile.open("input.txt");
    Dir* root = new Dir("/");
    
    getline(myFile,line);
    make_dir(root); 

    int totalSize = getSize(root);
    calcAns(root);
    cout<<ans<<endl;
}