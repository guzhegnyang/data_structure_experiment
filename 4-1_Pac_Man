#include <iostream>
using namespace std;
typedef struct role{
    int grade;
    int move;
}Role;
int main() {
    int N, i, grade, move, top = -1;
    cin >> N;
    Role* stack = new Role[N];
    for(i = 0; i < N; i++) {
        cin >> grade >> move;
        if(move == 1) {
            top++;
            stack[top].grade = grade;
            stack[top].move = move;
        }
        else {
            while(true) {
                if(top == -1 || stack[top].move == 0 || (stack[top].move == 1 && stack[top].grade == grade)) {
                    top++;
                    stack[top].grade = grade;
                    stack[top].move = move;
                    break;
                }
                if(stack[top].grade > grade) {
                    break;
                }
                else {
                    top--;
                }
            }
        }
    }
    cout << top + 1;
}
