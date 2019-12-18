#include<iostream>
#include<vector>
using namespace std;
struct node {
    int k;
    node* p;
    node* next;
    node(int K = 0, node* n = nullptr, node* P = nullptr): k(K), p(P), next(n) {};
}* h = new node;
int m;
void insert(int n) {
    vector<node*> stack, stack1;
    node* ptr = h, * new_node = new node(n);
    for (; ptr->p; ptr = ptr->p) {
        stack.push_back(ptr);
        for (; ptr->next && ptr->next->k < n; ptr = ptr->next);
        if (ptr->next->k == n) {
            delete new_node;
            return;
        }
        stack1.push_back(ptr);
    }
    stack.push_back(ptr);
    for (ptr = stack.back(); ptr->next && ptr->next->k < n; ptr = ptr->next);
    if (ptr->next->k == n) {
        delete new_node;
        return;
    }
    stack1.push_back(ptr);
    while (!stack.empty()) {
        if (new_node) {
            new_node->next = stack1.back()->next;
            stack1.back()->next = new_node;
            new_node = nullptr;
            stack.top()->k++;
            if (stack.top()->k == m) {
                for(ptr = stack.back(); stack.back()->k > m / 2; ptr = ptr->next, stack.top()->k--);
                stack.top()->k = m - stack.top()->k;
                new_node = ptr;
                ptr = new_node->next;
                new_node->next = nullptr;
                new_node->p = new node(m - stack.top()->k, ptr);
            }
        }
        stack.pop_back();
        stack1.pop_back();
    }
}
int main() {
    
}
