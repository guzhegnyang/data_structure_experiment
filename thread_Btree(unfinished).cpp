#include<iostream>
using namespace std;
template <class t>
struct node {
    t v;
    node<t>* l;
    node<t>* r;
    bool ltag;
    bool rtag;
    node(t v, node* l = nullptr, node* r = nullptr, bool ltag = 0, bool rtag = 0): \
    v(v), l(l), r(r), ltag(ltag), rtag(rtag) {};
    void insert(t n);
    void preorder(node<t>* (&last));
};
template <class t>
void node<t>::insert(t n) {
    if (n < v) {
        if (!l || ltag) {
            ltag = 0;
            l = new node(n);
        }
        else {
            l->insert(n);
        }
    }
    else if (n > v) {
        if (!r || rtag) {
            rtag = 0;
            r = new node(r);
        }
        else {
            r->insert(n);
        }
    }
}
template <class t>
node<t>* last = nullptr;
template <class t>
void node<t>::preorder(node<t>* (&last) = last) {
    if (last && last->rtag && !last->r) {
        last->r = this;
    }
    cout << v << ' ';
    last = this;
    if (!ltag) {
        if (!l) {
            ltag = 1;
            l = last;
        }
        else {
            l->preorder();
        }
    }
    if (!rtag) {
        if (!r) {
            rtag = 1;
        }
        else {
            r->preorder();
        }
    }
}
int main() {
    
}
