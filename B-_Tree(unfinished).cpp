#include<iostream>
#include<vector>
using namespace std;
struct node {
    int n;
    vector<node*> p;
    vector<int> k;
}
struct BTree {
    int m;
    node* T;
    void insert(int n);
}
void BTree::insert(int n) {
    if (!T) {
        T = new node;
        T->n = 1;
        T->k.push_back(n);
        T->p.push_back(nullptr);
        T->p.push_back(nullptr);
        return;
    }
    vector<node*> path;
    path.push_back(T);
    int i;
    while (path.back()->p[0]) {
        for (i = 0; i < ptr->n && n > ptr->k[i]; i++);
        if (n == path.back()->k[i]) return;
        path.push_back(path.back()->p[i]);
    }
    for (i = 0; i < path.back()->n && n > path.back()->k[i]; i++);
    if (n == path.back()->k[i]) return;
    path.back()->n++;
    path.back()->k.insert(ptr->k.begin()+i, n);
    path.back()->p.push_back(nullptr);
    while (path.back()->n == m) {
        if (path.size() == 1) {
            
        }
        path.pop_back()
    }
}
int main() {
    
}
