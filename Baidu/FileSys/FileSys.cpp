// FileSys.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <map>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

vector<string> split(const string &s, char delim) {
	vector<string> elems;
	stringstream ss(s);
	string item;
	while (getline(ss, item, delim)) {
		elems.push_back(item);
	}
	return elems;
}

string join(const vector<string>& input) {
	string output = "";
	bool has_data = false;
	for (size_t i = 0; i < input.size(); ++i) {
		has_data = true;
		output += input[i];
		output += ", ";
	}
	if (has_data) {
		output = output.substr(0, output.length() - 2);
	}
	return output;
}

class Entry {
public:
	Entry* parent;
	string name;
	string content;
	map<string, Entry*> children;

	Entry(string n, Entry* p) {
		name = n;
		parent = p;
	}
};

class FileSystem {
private:
	Entry* root;
public:
	FileSystem() {
		root = new Entry("/", NULL);
	}
	vector<string> Ls(const string& path) {
		// IMPLEMENT ME
		vector<string> output;
		vector<string> dir = split(path, '/');
		Entry* node = root;
		for (int i = 1; i < dir.size(); i++) {
			if (node->children.count(dir[i])) {
				node = node->children[dir[i]];
				continue;
			}
			else {
				return output;
			}
		}
		if (node->content.size() == 0) {
			typedef map<string, Entry*>::iterator it_type;
			for (it_type iterator = node->children.begin(); iterator != node->children.end(); iterator++) {
				output.push_back(iterator->first);
			}
		}
		else {
			output.push_back(node->name);
		}
		return output;
	}

	void MkdirP(const string& dir_path) {
		// IMPLEMENT ME
		vector<string> dir = split(dir_path, '/');
		Entry* node = root;
		for (int i = 1; i < dir.size(); i++) {
			if (node->children.count(dir[i])) {
				node = node->children[dir[i]];
				continue;
			}
			else {
				Entry* newNode = new Entry(dir[i], node);
				node->children[dir[i]] = newNode;
				node = newNode;
			}
		}
	}

	void AddFileWithContent(const string& file_path, const string& content) {
		// IMPLEMENT ME
		vector<string> dir = split(file_path, '/');
		Entry* node = root;
		for (int i = 1; i < dir.size(); i++) {
			if (node->children.count(dir[i])) {
				node = node->children[dir[i]];
				continue;
			}
			else {
				Entry* newNode = new Entry(dir[i], node);
				node->children[dir[i]] = newNode;
				node = newNode;
			}
			if (i == dir.size() - 1) {
				node->content = content;
			}
		}
	}

	string GetFileContent(const string& file_path) {
		// IMPLEMENT ME
		vector<string> dir = split(file_path, '/');
		Entry* node = root;
		for (int i = 1; i < dir.size(); i++) {
			if (node->children.count(dir[i])) {
				node = node->children[dir[i]];
				continue;
			}
			else {
				Entry* newNode = new Entry("dir[i]", node);
				node->children[dir[i]] = newNode;
				node = newNode;
			}
		}
		return node->content;
	}
};



#ifndef __main__
#define __main__

int main(int argc, char* argv[]) {
	FileSystem fs;

	cout << join(split("/a/b/c", '/')) << endl;

	// should print ""
	cout << join(fs.Ls("/")) << endl;
	fs.MkdirP("/a/b/c");
	fs.AddFileWithContent("/a/b/c/d", "hello world");
	// should print a
	cout << join(fs.Ls("/")) << endl;
	// should print d
	cout << join(fs.Ls("/a/b/c")) << endl;
	// should print d
	cout << join(fs.Ls("/a/b/c/d")) << endl;
	// should print hello world
	cout << fs.GetFileContent("/a/b/c/d") << endl;

	cin.ignore();
}

#endif
