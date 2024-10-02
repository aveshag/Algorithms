#include<iostream>
#include<list>

using namespace std;

class LRU {
  private:
    list<int> dl;
    unordered_map<int, list<int>::iterator> hash; 
    int csize;
public:
    LRU(int);
    void get(int);
    void print();
};

LRU::LRU(int n) {
    csize = n;
}
void LRU::get(int e) {
    if(hash.find(e) == hash.end()) {
        if(dl.size() == csize) {
            int last = dl.back();
            dl.pop_back();
            hash.erase(last);
        }
    } else {
        dl.erase(hash[e]);
    }

    dl.push_front(e);
    hash[e] = dl.begin();
}

void LRU::print() {
    for(list<int>::iterator e = dl.begin(); e != dl.end(); e++) {
        cout<<*e<<" ";
    }
    cout<<endl;
}

int main() {
    LRU lru = LRU(3);
    lru.get(2);
    lru.print();
    lru.get(3);
    lru.print();
    lru.get(2);
    lru.print();
    lru.get(4);
    lru.print();
    lru.get(5);
    lru.print();
    lru.get(4);
    lru.print();
    lru.get(5);
    lru.print();
    lru.get(3);
    lru.print();
}
