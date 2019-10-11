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
