// Eval.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <stack>
#include <string>
#include <vector>

#include <map>
#include <set>

using namespace std;

class ASTNode {
public:
	int weight;
	string value;
	ASTNode* left;
	ASTNode* right;

	ASTNode(int w, string v) {
		weight = w;
		value = v;
		left = NULL;
		right = NULL;
	}

	~ASTNode() {
		delete left;
		delete right;
	}
};

class Parser {
private:
	int get(string a, int base) {
		if (a[0] == '+' || a[0] == '-')
			return 1 + base;
		if (a[0] == '*' || a[0] == '/')
			return 2 + base;

		return INT_MAX;
	}
	
	double eval(ASTNode* root) {
		if (!root) return 0;
		switch (root->value[0]) {
		case '+':
			return eval(root->left) + eval(root->right);
		case '-':
			return eval(root->left) - eval(root->right);
		case '*':
			return eval(root->left) * eval(root->right);
		case '/':
			return eval(root->left) / eval(root->right);
		default:
			return stod(root->value);
		}
	}

public:
	double evaluateExpression(vector<string>& expression) {
		stack<ASTNode*> stack;
		int weight = 0;
		int base = 0;
		for (unsigned i = 0; i <= expression.size(); i++) {
			if (i != expression.size()) {
				if (expression[i][0] == '(') {
					base += 10;
					continue;
				}
				if (expression[i][0] == ')') {
					base -= 10;
					continue;
				}
				weight = get(expression[i], base);
			}
			ASTNode* right = i == expression.size() ? new ASTNode(INT_MIN, ""):
				new ASTNode(weight, expression[i]);
			while (stack.size() != 0) {
				if (right->weight <= stack.top()->weight) {
					ASTNode* nodeNow = stack.top();
					stack.pop();
					if (stack.size() == 0) {
						right->left = nodeNow;
					}
					else {
						ASTNode* left = stack.top();
						if (left->weight < right->weight) {
							right->left = nodeNow;
						}
						else {
							left->right = nodeNow;
						}
					}
				}
				else {
					break;
				}
			}
			stack.push(right);
		}
		return eval(stack.top()->left);
	}

	double evaluateExpression(vector<string>& expression, map<string, string> var_map) {
		for (unsigned i = 0; i < expression.size(); i++) {
			if (var_map.count(expression[i])) {
				expression[i] = var_map[expression[i]];
			}
		}
		return evaluateExpression(expression);
	}

	double evaluateExpression(string expression) {
		vector<string> exp;
		const char* str = expression.c_str();
		size_t i = 0, j;
		set<char> tokens;
		tokens.insert('+');
		tokens.insert('-');
		tokens.insert('*');
		tokens.insert('/');
		tokens.insert('(');
		tokens.insert(')');
		while (str[i] != 0) {
			if (str[i] == ' ') {
				i++;
				continue;
			}
			j = i + 1;
			if (!tokens.count(str[i])) {
				while (str[j] != 0 && !tokens.count(str[j])) {
					j++;
				}
			}
			exp.push_back(expression.substr(i, j - i));
			i = j;
		}
		return evaluateExpression(exp);
	}
};

int _tmain(int argc, _TCHAR* argv[])
{
	Parser* p = new Parser();
	vector<string> test1;
	test1.push_back("1");
	test1.push_back("+");
	test1.push_back("2");
	test1.push_back("*");
	test1.push_back("3");
	cout << p->evaluateExpression(test1) << endl;

	vector<string> test2;
	test2.push_back("(");
	test2.push_back("1");
	test2.push_back("+");
	test2.push_back("2");
	test2.push_back(")");
	test2.push_back("*");
	test2.push_back("3");
	cout << p->evaluateExpression(test2) << endl;

	map<string, string> var_map = {
		{ "A", "1.1" },
		{ "B", "2.2" },
		{ "PI", "3.14" }
	};
	vector<string> test3;
	test3.push_back("A");
	test3.push_back("+");
	test3.push_back("B");
	test3.push_back("*");
	test3.push_back("PI");
	cout << p->evaluateExpression(test3, var_map) << endl;

	cout << p->evaluateExpression("15/(1 + 2)") << endl;
	cout << p->evaluateExpression("15/((1 + 2) * 3)") << endl;

	cin.ignore();

	return 0;
}

