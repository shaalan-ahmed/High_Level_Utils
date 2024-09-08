#pragma once

#include <iostream>
#include <vector>
#include <sstream>
#include <iomanip>
#include <cstdlib>
#include <cmath>
#include <array>
#include <stack>
#include <string>
#include <algorithm>

using namespace std;

int findPriorityI(vector<char>& v2);
int findPriorityII(vector<char>& v2);
int findPriorityIII(vector<char>& v2);

bool isOp(char c);
void pop(vector<char>& v, int index);
void pop(vector<float>& v, int index);

vector<string> split(const string& str, char delimiter);
float eval(string exp, float& resu);
string getSubstring(const string& str, int x, int y);
string formatFloat(const string& floatStr, int precision);

bool finish(const string& temp);
bool isSymbolValid(char c);
bool isEquationValid(string& equation);
bool emptyBrackets(string& exp);
bool AreParanthesesBalanced(string exp);
bool ArePair(char opening, char closing);

extern vector<char> operators;
extern vector<char> allowed_symbols;