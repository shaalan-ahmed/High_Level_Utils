#include "HighLevelUtils.h"

vector<char> operators = {
    '+', '-', '*', '/', '^'
};

vector<char> allowed_symbols = {
    '0', '1', '2', '3', '4', '5', '6', '7', '8', '9',
    '+', '-', '^', '/', '*', '.', '(', ')'
};

bool isSymbolValid(char c) {
    for (int i = 0; i < allowed_symbols.size(); i++) {
        if (allowed_symbols[i] == c)
            return true;
    }

    return false;
}

bool isExpressionValid(string& expression) {
    if (emptyBrackets(expression))
        return false;

    if (! AreParanthesesBalanced(expression))
        return false;

    for (int i = 0; i < expression.size(); i++) {
        if (! isSymbolValid(expression.at(i)))
            return false;
    }

    return true;
}

bool emptyBrackets(string& exp) {
    for (int i = 0; i < exp.length() - 1; i++) {
        if (exp[i] == '(' && exp[i + 1] == ')')
            return true;
    }

    return false;
}

bool ArePair(char opening, char closing) {
	if(opening == '(' && closing == ')') 
        return true;

	return false;
}

bool AreParanthesesBalanced(string exp) {
	stack<char>  S;

	for(int i = 0; i < exp.length(); i++) {
		if(exp[i] == '(')
			S.push(exp[i]);

		else if(exp[i] == ')') {
			if(S.empty() || ! ArePair(S.top(), exp[i]))
				return false;
			else
				S.pop();
		}
	}

	return S.empty() ? true : false;
}

void pop(vector<char>& v, int index) {
    for (int i = index; i < v.size() - 1; i++) {
        v.at(i) = v.at(i + 1);
    }

    v.pop_back();
}

void pop(vector<float>& v, int index) {
    for (int i = index; i < v.size() - 1; i++) {
        v.at(i) = v.at(i + 1);
    }

    v.pop_back();
}

int findPriorityI(vector<char>& v2) {
    for (int i = 0; i < v2.size(); i++) {
        if (v2.at(i) == '^') return i;
    }

    return -1;
}

int findPriorityII(vector<char>& v2) {
    for (int i = 0; i < v2.size(); i++) {
        if (v2.at(i) == '*' || v2.at(i) == '/') return i;
    }

    return -1;
}

int findPriorityIII(vector<char>& v2) {
    for (int i = 0; i < v2.size(); i++) {
        if (v2.at(i) == '+' || v2.at(i) == '-') return i;
    }

    return -1;
}

vector<string> split(const string& str, char delimiter) {
    vector<string> tokens;
    stringstream ss(str);
    string item;

    while (getline(ss, item, delimiter))
        tokens.push_back(item);

    return tokens;
}

bool isOp(char c) {
    for (int i = 0; i < operators.size(); i++) {
        if (operators[i] == c)
            return true;
    }

    return false;
}

string getSubstring(const string& str, int x, int y) {
    return str.substr(x, y - x + 1);
}

float eval (string exp, float& resu) {
    if (! isExpressionValid(exp))
        return 1;

    int last_open = -1, first_close = -1;

    string t;

    vector<float> numbers;
    vector<char> operations;
    vector<string> results;

    bool quit = false;

    results.push_back(exp);

    int z = 0;

    while (! quit) {
        last_open = -1;
        first_close = -1;

        numbers.clear();
        operations.clear();

        string now = results.at(z);

        for (int i = 0; i < now.length(); i++) {
            char c = now[i];

            if (c == '(')
                last_open = i;

            if (c == ')') {
                first_close = i;

                t = getSubstring(now, last_open + 1, first_close - 1);

                break;
            }
        }

        if (first_close == -1 && last_open == -1) t = getSubstring(now, 0, now.length() - 1);

        for (int i = 0; i < t.length(); i++) {
            char c = t[i];

            if (isOp(c)) {
                if ((c == '-' && i > 0 && t[i - 1] == ' ') || (i == 0 && c == '-'))
                    continue;
                
                operations.push_back(c);

                t[i] = ' ';
            }
        }


        vector<string> splits = split(t, ' ');

        for (int i = 0; i < splits.size(); i++)
            numbers.push_back(stof(splits.at(i)));

        while (numbers.size() > 1) {
            int i = findPriorityI(operations);

            if (i == -1) {
                i = findPriorityII(operations);

                if (i == -1) {
                    i = findPriorityIII(operations);
                }
            }

            float op1 = numbers.at(i);
            float op2 = numbers.at(i + 1);
            float res = 0;

            char operation = operations.at(i);

            switch(operation) {
                case '+': res = op1 + op2;     break;
                case '-': res = op1 - op2;     break;
                case '*': res = op1 * op2;     break;
                case '/': res = op1 / op2;     break;
                case '^': res = pow(op1, op2); break;
            }

            pop(operations, i);

            numbers.at(i) = res;

            pop(numbers, i + 1);
        }

        string temp = "";
        if (last_open == -1 && first_close == -1) {
            temp += formatFloat(to_string(numbers.at(0)), 2);
        }
        else {
            for (int i = 0; i < last_open; i++) {
                temp += now[i];
            }

            temp += formatFloat(to_string(numbers.at(0)), 2);

            for (int i = first_close + 1; i < now.length(); i++) {
                temp += now[i];
            }
        }
        
        z++;

        results.push_back(temp);
        
        quit = finish(temp);
    }

    resu = stof(results.at(results.size() - 1));

    return 0;
}

string formatFloat(const string& floatStr, int precision) {
    float number = std::stof(floatStr);
    
    ostringstream out;
    out << fixed << setprecision(precision) << number;
    
    return out.str();
}

bool finish(const string& temp) {
    for (int k = 0; k < temp.length(); k++) {
        char c = temp[k];

        if ((isOp(c) && c != '-' && k != 0) || c == '(' || c == ')') return false; 
    }

    return true;
}