#include<iostream>
using namespace std;
int m;
struct node {
    int k;
    node* p;
    node* next;
    node(int K = 0, node* n = nullptr, node* P = nullptr): k(K), p(P), next(n) {};
}* h = new node;
void insert(int n) {
    node* ptr = h;
    for (; ptr->p; ptr = ptr->p) {
        for (; ptr->next && ptr->next->k < n; ptr = ptr->next);
        if (ptr->next->k == n) {
            return;
        }
    }
    
}
