// Recursive Descent Parser (Top-Down Parser)

#include <iostream>
#include <string>
using namespace std;

// Grammar:
// E -> E + T | T
// T -> T * F | F
// F -> ( E ) | id

// Grammar Rules:
// E -> TE'
// E' -> +TE' | e
// T -> FT'
// T' -> *FT' | e
// F -> (E) | id

void E();
void Eprime();
void T();
void Tprime();
void F();
bool match(string);

string input;
int ind = 0;

int main() {
    cout << "Enter an arithmetic expression: ";
    getline(cin, input);
    E();
    if (match("$"))
        cout << "Accepted" << endl;
    else
        cout << "Rejected" << endl;
    return 0;
}

void E() {
    T();
    Eprime();
}

void Eprime() {
    if (match("+")) {
        T();
        Eprime();
    }
}

void T() {
    F();
    Tprime();
}

void Tprime() {
    if (match("*")) {
        F();
        Tprime();
    }
}

void F() {
    if (match("(")) {
        E();
        if (match(")"))
            return;
    }
    else if (match("id"))
        return;
}

bool match(string token) {
    if (input.substr(ind, token.length()) == token) {
        ind += token.length();
        return true;
    }
    return false;
}

// Output

// Enter an arithmetic expression: (id+id)*id$
// Accepted

// Enter an arithmetic expression: (id+id)*id
// Rejected