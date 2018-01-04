#include <iostream>
#include "parser.h"
#include "scanner.h"
#include "exp.h"
#include <sstream>

using namespace std;

string& trim(string &s);

int main( int argc , char **argv ) {
	do {
		cout << "?-";
		string input;
		getline(cin, input);
		if (trim(input) == "halt.")
			break;
		if (trim(input) == "")
			continue;
		Scanner s(input);
		Parser p(s);
		try{
			p.buildExpression();
			string result = p.getExpressionTree()->result() + '.';
			cout << result << endl;
		} catch (std::string & msg) {
			cout << msg << endl;
		}
	} while(true);
    return 0;
}

string& trim(string &s) {
    if (s.empty()) {
         return s;
    }
    int index = 0;
    string str="";
    cout<<s<<endl;
    for(int i=0 ; i<s.size() ; i++){
        if(s[i] != ' '){
            index = i;
            str = str + s[i];
        }
    }
    s = str;
    return s;
}