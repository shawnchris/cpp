// Baidu.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <memory>
#include <string>
#include <stack>
#include <chrono>
#include <thread>
#include <map>

using namespace std;

class ParserException : public std::exception
{
	int m_Pos;

public:
	ParserException(const std::string& message, int pos) :
		std::exception(message.c_str()),
		m_Pos(pos)
	{
	}
};

enum TokenType
{
	Error,
	Plus,
	Minus,
	Mul,
	Div,
	EndOfText,
	OpenParenthesis,
	ClosedParenthesis,
	Number
};

struct Token
{
	TokenType	Type;
	double		Value;
	char		Symbol;

	Token() :Type(Error), Value(0), Symbol(0)
	{}
};

enum ASTNodeType
{
	Undefined,
	OperatorPlus,
	OperatorMinus,
	OperatorMul,
	OperatorDiv,
	UnaryMinus,
	NumberValue,
	Variable
};

class ASTNode
{
public:
	ASTNodeType Type;
	double      Value;
	ASTNode*    Left;
	ASTNode*    Right;

	ASTNode()
	{
		Type = Undefined;
		Value = 0;
		Left = NULL;
		Right = NULL;
	}

	~ASTNode()
	{
		delete Left;
		delete Right;
	}
};

class Parser
{
	Token m_crtToken;
	const char* m_Text;
	size_t m_Index;

private:

	ASTNode* Expression()
	{
		ASTNode* tnode = Term();
		ASTNode* e1node = Expression1();

		return CreateNode(OperatorPlus, tnode, e1node);
	}

	ASTNode* Expression1()
	{
		ASTNode* tnode;
		ASTNode* e1node;

		switch (m_crtToken.Type)
		{
		case Plus:
			GetNextToken();
			tnode = Term();
			e1node = Expression1();

			return CreateNode(OperatorPlus, e1node, tnode);

		case Minus:
			GetNextToken();
			tnode = Term();
			e1node = Expression1();

			return CreateNode(OperatorMinus, e1node, tnode);
		}

		return CreateNodeNumber(0);
	}

	ASTNode* Term()
	{
		ASTNode* fnode = Factor();
		ASTNode* t1node = Term1();

		return CreateNode(OperatorMul, fnode, t1node);
	}

	ASTNode* Term1()
	{
		ASTNode* fnode;
		ASTNode* t1node;

		switch (m_crtToken.Type)
		{
		case Mul:
			GetNextToken();
			fnode = Factor();
			t1node = Term1();
			return CreateNode(OperatorMul, t1node, fnode);

		case Div:
			GetNextToken();
			fnode = Factor();
			t1node = Term1();
			return CreateNode(OperatorDiv, t1node, fnode);
		}

		return CreateNodeNumber(1);
	}

	ASTNode* Factor()
	{
		ASTNode* node;
		switch (m_crtToken.Type)
		{
		case OpenParenthesis:
			GetNextToken();
			node = Expression();
			Match(')');
			return node;

		case Minus:
			GetNextToken();
			node = Factor();
			return CreateUnaryNode(node);

		case Number:
		{
			double value = m_crtToken.Value;
			GetNextToken();
			return CreateNodeNumber(value);
		}

		default:
		{
			//std::stringstream sstr;
			//sstr << "Unexpected token '" << m_crtToken.Symbol << "' at position " << m_Index;
			throw ParserException("Unexpected token", m_Index);
		}
		}
	}

	ASTNode* CreateNode(ASTNodeType type, ASTNode* left, ASTNode* right)
	{
		ASTNode* node = new ASTNode;
		node->Type = type;
		node->Left = left;
		node->Right = right;

		return node;
	}

	ASTNode* CreateUnaryNode(ASTNode* left)
	{
		ASTNode* node = new ASTNode;
		node->Type = UnaryMinus;
		node->Left = left;
		node->Right = NULL;

		return node;
	}

	ASTNode* CreateNodeNumber(double value)
	{
		ASTNode* node = new ASTNode;
		node->Type = NumberValue;
		node->Value = value;

		return node;
	}

	void Match(char expected)
	{
		if (m_Text[m_Index - 1] == expected)
			GetNextToken();
		else
		{
			//std::stringstream sstr;
			//sstr << "Expected token '" << expected << "' at position " << m_Index;
			throw ParserException("Unexpected token", m_Index);
		}
	}

	void SkipWhitespaces()
	{
		while (isspace(m_Text[m_Index])) m_Index++;
	}

	void GetNextToken()
	{
		SkipWhitespaces();

		m_crtToken.Value = 0;
		m_crtToken.Symbol = 0;

		if (m_Text[m_Index] == 0)
		{
			m_crtToken.Type = EndOfText;
			return;
		}

		if (isdigit(m_Text[m_Index]))
		{
			m_crtToken.Type = Number;
			m_crtToken.Value = GetNumber();
			return;
		}

		m_crtToken.Type = Error;

		switch (m_Text[m_Index])
		{
		case '+': m_crtToken.Type = Plus; break;
		case '-': m_crtToken.Type = Minus; break;
		case '*': m_crtToken.Type = Mul; break;
		case '/': m_crtToken.Type = Div; break;
		case '(': m_crtToken.Type = OpenParenthesis; break;
		case ')': m_crtToken.Type = ClosedParenthesis; break;
		}

		if (m_crtToken.Type != Error)
		{
			m_crtToken.Symbol = m_Text[m_Index];
			m_Index++;
		}
		else
		{
			//std::stringstream sstr;
			//sstr << "Unexpected token '" << m_Text[m_Index] << "' at position " << m_Index;
			throw ParserException("Unexpected token", m_Index);
		}
	}

	double GetNumber()
	{
		SkipWhitespaces();

		int index = m_Index;
		while (isdigit(m_Text[m_Index])) m_Index++;
		if (m_Text[m_Index] == '.') m_Index++;
		while (isdigit(m_Text[m_Index])) m_Index++;

		if (m_Index - index == 0)
			throw ParserException("Number expected but not found!", m_Index);

		char buffer[32] = { 0 };
		memcpy(buffer, &m_Text[index], m_Index - index);

		return atof(buffer);
	}

	ASTNode* Parse(const string text)
	{
		m_Text = text.c_str();
		m_Index = 0;
		GetNextToken();

		return Expression();
	}

	double Eval(ASTNode * root) {
		if (!root) return 0;
		switch (root->Type)
		{
		case NumberValue:
			return root->Value;
		case OperatorPlus:
			return Eval(root->Left) + Eval(root->Right);
		case OperatorMinus:
			return Eval(root->Left) - Eval(root->Right);
		case OperatorMul:
			return Eval(root->Left) * Eval(root->Right);
		case OperatorDiv:
			return Eval(root->Left) / Eval(root->Right);
		default:
			return 0;
		}
	}

public:
	
	double Solve(const string text) {
		return Eval(Parse(text));
	}
	
};

int evalRPN(vector<string> &tokens) {
	stack<int> stack;
	for (auto s : tokens) {
		if (s.size()>1 || isdigit(s[0])) stack.push(stoi(s));
		else {
			auto x2 = stack.top(); stack.pop();
			auto x1 = stack.top(); stack.pop();
			switch (s[0]) {
			case '+': x1 += x2; break;
			case '-': x1 -= x2; break;
			case '*': x1 *= x2; break;
			case '/': x1 /= x2; break;
			}
			stack.push(x1);
		}
	}
	return stack.top();
}

double eval(ASTNode * root) {
	if (!root) return 0;
	switch (root->Type)
	{
	case NumberValue:
		return root->Value;
	case OperatorPlus:
		return eval(root->Left) + eval(root->Right);
	case OperatorMinus:
		return eval(root->Left) - eval(root->Right);
	case OperatorMul:
		return eval(root->Left) * eval(root->Right);
	case OperatorDiv:
		return eval(root->Left) / eval(root->Right);
	default:
		return 0;
	}
}

string ReplaceAll(string str, const string& from, const string& to) {
	size_t start_pos = 0;
	while ((start_pos = str.find(from, start_pos)) != std::string::npos) {
		str.replace(start_pos, from.length(), to);
		start_pos += to.length(); // Handles case where 'to' is a substring of 'from'
	}
	return str;
}

string ReplaceVariable(string str, map<string, string> var_map) {
	typedef map<string, string>::iterator it_type;
	for (it_type iterator = var_map.begin(); iterator != var_map.end(); iterator++) {
		str = ReplaceAll(str, iterator->first, iterator->second);
	}
	return str;
}

int _tmain(int argc, _TCHAR* argv[])
{
	vector<string> test1;
	test1.push_back("1");
	test1.push_back("2");
	test1.push_back("+");
	cout << evalRPN(test1) << endl;

	Parser p = Parser();
	cout << p.Solve("(2+2)*3/6") << endl;

	map<string, string> my_map = {
		{ "A", "1.1" },
		{ "B", "2.2" },
		{ "PI", "3.14" }
	};

	cout << p.Solve(ReplaceVariable("(A+B)*PI", my_map)) << endl;

	std::this_thread::sleep_for(std::chrono::milliseconds(5000));
	return 0;
}

