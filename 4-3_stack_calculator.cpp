#include<iostream>
#include<string>
using namespace std;
float calculate(string& s) {
	int index = 0, nums_top = 0, ops_top = -1;
	float* nums = new float[s.length()];
	nums[0] = 0;
	char* ops = new char[s.length()];
	for (; index < s.length(); index++) {
		if (s[index] >= '0' && s[index] <= '9') {
			float num = s[index] - '0';
			int exponent = 0;
			while (s[index + 1] >= '0' && s[index + 1] <= '9') {
				num = num * 10 + s[++index] - '0';
			}
			if (s[index] == '.') {
				index++;
				while (s[index] >= '0' && s[index] <= '9') {
					num = num * 10 + s[index++] - '0';
					exponent++;
				}
			}
			while (exponent > 0) {
				num /= 10;
				exponent--;
			}
			nums[++nums_top] = num;
		}
		else if (ops_top == -1) {
			ops[++ops_top] = s[index];
		}
		else if (s[index] == '+' || s[index] == '-') {
			if (ops[ops_top] == '+') {
				nums_top--;
				nums[nums_top] += nums[nums_top + 1];
				ops[ops_top] = s[index];
			}
			else if (ops[ops_top] == '-') {
				nums_top--;
				nums[nums_top] -= nums[nums_top + 1];
				ops[ops_top] = s[index];
			}
			else if (ops[ops_top] == '*') {
				nums_top--;
				nums[nums_top] *= nums[nums_top + 1];
				ops[ops_top] = s[index];
			}
			else if (ops[ops_top] == '/') {
				nums_top--;
				nums[nums_top] /= nums[nums_top + 1];
				ops[ops_top] = s[index];
			}
			else {
				ops[++ops_top] = s[index];
			}
		}
		else if (s[index] == '*' || s[index] == '/') {
			if (ops[ops_top] == '*') {
				nums_top--;
				nums[nums_top] *= nums[nums_top + 1];
				ops[ops_top] = s[index];
			}
			else if (ops[ops_top] == '/') {
				nums_top--;
				nums[nums_top] /= nums[nums_top + 1];
				ops[ops_top] = s[index];
			}
			else {
				ops[++ops_top] = s[index];
			}
		}
		else if (s[index] == ')') {
			for (; ops[ops_top] != '('; ops_top--) {
				if (ops[ops_top] == '+') {
					nums_top--;
					nums[nums_top] += nums[nums_top + 1];
				}
				else if (ops[ops_top] == '-') {
					nums_top--;
					nums[nums_top] -= nums[nums_top + 1];
				}
				else if (ops[ops_top] == '*') {
					nums_top--;
					nums[nums_top] *= nums[nums_top + 1];
				}
				else if (ops[ops_top] == '/') {
					nums_top--;
					nums[nums_top] /= nums[nums_top + 1];
				}
			}
			ops_top--;
		}
		else {
			ops[++ops_top] = s[index];
			if (s[index + 1] == '-' || s[index + 1] == '+') {
				nums[++nums_top] = 0;
			}
		}
	}
	for (; ops_top != -1; ops_top--) {
		if (ops[ops_top] == '+') {
			nums_top--;
			nums[nums_top] += nums[nums_top + 1];
		}
		else if (ops[ops_top] == '-') {
			nums_top--;
			nums[nums_top] -= nums[nums_top + 1];
		}
		else if (ops[ops_top] == '*') {
			nums_top--;
			nums[nums_top] *= nums[nums_top + 1];
		}
		else if (ops[ops_top] == '/') {
			nums_top--;
			nums[nums_top] /= nums[nums_top + 1];
		}
	}
	return nums[nums_top];
}
int main() {
	string s;
	cin >> s;
	cout << calculate(s);
}
/*
#include<iostream>
#include<stdio.h>
#include<stack>
using namespace std;
int main() {
    char c;
    int n = 0;
    bool isnum = 0, is1st = 1;
    stack<int> sn;
    stack<char> so;
    while ((c = getchar()) != EOF) {
        if (is1st) {
            if (c == '-') {
                sn.push(0);
            }
            is1st = 0;
        }
        if ('0' <= c && c <= '9') {
            n = n * 10 + c - '0';
            isnum = 1;
        }
        else {
            if (isnum) {
                sn.push(n);
                isnum = 0;
            }
            if (c == '+' || c == '-') {
                while (!so.empty() && so.top() != '(') {
                    n = sn.top();
                    sn.pop();
                    if (so.top() == '*') {
                        n *= sn.top();
                    }
                    else if (so.top() == '/') {
                        n = sn.top() / n;
                    }
                    else if (so.top() == '+') {
                        n += sn.top();
                    }
                    else {
                        n = sn.top() - n;
                    }
                    sn.pop();
                    sn.push(n);
                    so.pop();
                }
                so.push(c);
            }
            else if (c == '*' || c == '/') {
                if (!so.empty()) {
                    if (so.top() == '*') {
                        so.pop();
                        n = sn.top();
                        sn.pop();
                        n *= sn.top();
                        sn.pop();
                        sn.push(n);
                    }
                    else if (so.top() == '/') {
                        so.pop();
                        n = sn.top();
                        sn.pop();
                        n = sn.top() / n;
                        sn.pop();
                        sn.push(n);
                    }
                }
                so.push(c);
            }
            else if (c == ')') {
                while (so.top() != '(') {
                    n = sn.top();
                    sn.pop();
                    if (so.top() == '*') {
                        n *= sn.top();
                    }
                    else if (so.top() == '/') {
                        n = sn.top() / n;
                    }
                    else if (so.top() == '+') {
                        n += sn.top();
                    }
                    else {
                        n = sn.top() - n;
                    }
                    sn.pop();
                    sn.push(n);
                    so.pop();
                }
                so.pop();
            }
            else {
                is1st = 1;
                so.push(c);
            }
            n = 0;
        }
    }
    if (isnum) {
        sn.push(n);
        isnum = 0;
    }
    while (!so.empty()) {
        n = sn.top();
        sn.pop();
        if (so.top() == '*') {
            n *= sn.top();
        }
        else if (so.top() == '/') {
            n = sn.top() / n;
        }
        else if (so.top() == '+') {
            n += sn.top();
        }
        else {
            n = sn.top() - n;
        }
        sn.pop();
        sn.push(n);
        so.pop();
    }
    printf("%d", sn.top());
}
*/
