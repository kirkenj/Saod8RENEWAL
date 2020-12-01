#include <string>
#include <map>
#include <iostream>
using namespace std;

int count(string text, char ch) {
	int count = 0;
	for (int i = 0; i < text.length(); i++) {
		if (text[i] == ch) {
			count++;
		}
	}
	return count;
}
bool IsKeysOfDict(map<char, int> dict, char ch) {
	map<char, int>::iterator it;
	for (it = dict.begin(); it != dict.end(); it++) {
		if (it->first == ch) {
			return true;
		}
	}
	return false;
}

void printDict(map<char, int>dict) {
	map<char, int>::iterator it;
	for (it = dict.begin(); it != dict.end(); it++) {
		cout << it->first << "\t" << it->second << endl;
	}
}


void main() {
	map<char, int>* charDict = new map<char, int>();
	string text = "aaaaaaaaaaaaabbbbbbbbbbbbbbbbbbbbwwwwwwwwwwwwwcccccc";
	for (int i = 0; i < text.length(); i++) {
		if (!IsKeysOfDict(*charDict, text[i])) {
			charDict->insert(make_pair(text[i], count(text, text[i])));
		}
	}
	printDict(*charDict);

}