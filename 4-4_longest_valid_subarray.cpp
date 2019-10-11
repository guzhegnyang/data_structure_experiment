#include <iostream>
#include <string>
using namespace std;
int main() {
	string s;
	cin >> s;
    char* stack = new char[s.length()];
    int* istack = new int[s.length()];
	int i = 0, top = -1, itop = -1;
	for (; i < s.length(); i++) {
		if (s[i] == '(') {
            top++;
			stack[top] = s[i];
            itop++;
            istack[itop] = i;
		}
		else {
			if (stack[top] == '(') {
				top--;
                itop--;
			}
            else {
                top++;
			    stack[top] = s[i];
                itop++;
                istack[itop] = i;
            }
		}
	}
    int max = 0;
    int lasti = -1;
    if (istack[0] == 0) {
        lasti = 0;
    }
    for(i = 0; i <= itop; i++) {
        if (istack[i] - lasti - 1 > max) {
            max = istack[i] - lasti - 1;
        }
        lasti = istack[i];
    }
    if (s.length() - lasti - 1 > max) {
        max = s.length() - lasti - 1;
    }
	cout << max;
}
