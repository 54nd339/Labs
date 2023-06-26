// Program to simulate a LL(1) parser
// Grammar is taken from grammar.txt
// Another string input is taken from console
// and checked if it is accepted by the grammar
// Grammar is represented as 'A -> aBc'
// where A is the non-terminal and aBc is the production
// Non-terminals are represented as capital letters
// Terminals are represented as small letters
// Epsilon is represented as 'e'
// First and Follow sets are calculated
// Parsing table is constructed
// Parsing is done using the parsing table

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>
#include <map>
#include <set>
#include <stack>
#include <sstream>
#include <iterator>

using namespace std;

