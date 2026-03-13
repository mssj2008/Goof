#include <bits/stdc++.h>
#include "lexer.h"
//#include "parser.h"
//#include "interpreter.h"

using namespace std;

int main() {
    Lexer lexer("Int x = Int(in());\nIf(x<0) { out(\"number must be bigger than 0!\"); }\nInt ans = 1;\nLoop(x > 0)\n\n{\n\nans = ans * x;\nx--;}\nout(ans);");
    vector<Token> tokens;
    lexer.Tokenize(tokens);
    for(auto x : tokens) {
        cout << "Token: " << x.text << " Type: " << (int)x.type << endl;
    }
    return 0;
}

