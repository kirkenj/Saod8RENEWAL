#include <iostream>
#include <iterator>
#include <string>
#include <list>
using namespace std;

int findInList(string str, list <string>* code) {
    int count = 0;
    list <string> ::iterator it;
    for (it = code->begin(); it != code->end(); ++it, count++) {
        if (str == *it) {
            return count;
        }
    }
    return 0;
}


string LZW(string str, list <string>* code) {
    string res = "";
    string part = "";
    int ind;
    for (int i = 0; i < str.length(); i++) {
        part = str[i];
        ind = findInList(part, code);
        if (ind == 0) {
            code->push_back(part);
            res += to_string(ind) + part;
        }
        else {
            for (int j = i + 1; j < str.length(); j++) {
                part += str[j];
                if (findInList(part, code) != 0 && j != str.length() - 1) {
                    ind = findInList(part, code);
                }
                else {
                    code->push_back(part);
                    part = str[j];
                    i += j - i;
                    break;
                }
            }
            res += to_string(ind) + part;
        }
    }
    return res;
}

void print(list <string>* code) {
    list <string> ::iterator it;
    for (it = code->begin(); it != code->end(); ++it) {
        cout << *it << endl;
    }
}

string give_dec(int i, list <string>* code) {
    int count = 0;
    list <string> ::iterator it;
    for (it = code->begin(); it != code->end(); ++it, count++) {
        if (count == i) {
            return *it;
        }
    }
    return "";
}

string dec(string str, list <string>* code) {
    string res = "";
    string path = "";
    string h = "";
    int k;
    int i = 0;
    while (i < str.length()) {
        if (str[i] == '0' and h == "") {
            res += str[i + 1];
            i += 2;
        }
        else {
            h += str[i];
            if (to_string(atoi(h.c_str())).length() == h.length()) {
                path = h;
                k = atoi(h.c_str());
                i++;
            }
            else {
                res += give_dec(k, code) + str[i];
                h = "";
                path = "";
                i++;
            }
        }
    }

    return res;
}

void main1()
{
    list <string>* code = new list<string>;
    code->push_back("0");
    string start = "ABBCACBCDBCFBCD";
    string encr = LZW(start, code);
    string decode = dec(encr, code);
    print(code);
    cout << "Start: " << start << endl;
    cout << "Coded: " << encr << endl;
    cout << "Decoded: " << decode << endl;
}
