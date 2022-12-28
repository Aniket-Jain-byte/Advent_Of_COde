#include <bits/stdc++.h>
using namespace std;


class PacketData {
    public:

        int value = -1;
        PacketData* parent;
        vector<PacketData*> children;

        PacketData(PacketData* parent) {
            this->parent = parent;
        }

        bool isNumber() {
            return !(value == -1);
        }

        bool isIntegerArray() {
            
            if(isNumber()) return false;

            for(int i = 0; i < children.size(); ++i) {
                if(!children[i]->isNumber()) return false;
            }
            return true;
        }
};

int extractNumber(string &line,int &i) {

    int num = 0;
    for(; line[i] >= '0' && line[i] <= '9'; ++i) {
        num *= 10;
        num += line[i]-'0';
    }
    i--;
    return num;
}

void buildPacketData(string &line, PacketData* data) {

    for(int i = 1; i < line.size(); ++i) {
        if(line[i] == ',') continue;
        else if(line[i] == ']') data = data->parent;
        else if(line[i] == '[') {
            PacketData* child = new PacketData(data);
            data->children.push_back(child);
            data = child;
        }
        else {
            PacketData* child = new PacketData(data);
            child->value = extractNumber(line,i);
            data->children.push_back(child);
        }
    }
}

int compareArrayNArray(PacketData* left, PacketData* right) {

    for(int i = 0; i < min(left->children.size(),right->children.size()); ++i) {
        if(left->children[i]->value  < right->children[i]->value) return 1;
        else if(left->children[i]->value > right->children[i]->value) return -1;
    }

    if(left->children.size() < right->children.size()) return 1;
    else if(left->children.size() > right->children.size()) return -1;
    return 0;
}

int isOrderCorrect(PacketData* left, PacketData* right) {

    if(left->isIntegerArray() && right->isIntegerArray()) {
        return compareArrayNArray(left,right);
    }
    else if(left->isIntegerArray() && right->isNumber()) {
        PacketData* rightArr = new PacketData(nullptr);
        rightArr->children.push_back(right);
        return compareArrayNArray(left,rightArr);
    }
    else if(left->isNumber() && right->isIntegerArray()) {
        PacketData* leftArr = new PacketData(nullptr);
        leftArr->children.push_back(left);
        return compareArrayNArray(leftArr,right);
    }
    else if(left->isNumber() && right->isNumber()) {
        if(left->value < right->value) return 1;
        if(left->value = right->value) return 0;
        if(left->value > right->value) return -1;
    }
    else {
        for(int i = 0; i < min(left->children.size(),right->children.size()); ++i) {
            int k = isOrderCorrect(left->children[i],right->children[i]);
            if(k != 0) return k;
        }
        if(left->children.size() < right->children.size()) return 1;
    }

    return -1;
}

int main() {

    fstream myFile;
    myFile.open("input.txt");

    string leftLine,rightLine,blank;
    int ans = 0, counter = 1;

    while(getline(myFile,leftLine)) {

        getline(myFile,rightLine);
        getline(myFile,blank);

        PacketData* left = new PacketData(nullptr);
        PacketData* right = new PacketData(nullptr);

        buildPacketData(leftLine,left);
        buildPacketData(rightLine,right);

        if(isOrderCorrect(left,right) == 1) ans += counter;
        ++counter;
    }

    cout<<ans<<" ";
}
