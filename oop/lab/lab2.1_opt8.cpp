#include <string>
#include <iostream>

using namespace std;

class BaseString {
    public:
        string str;
        BaseString(string s) {
            str = s;
        };
        int getLength() {
            return str.size();
        };
};

class SymbolSting: public BaseString {
    public:
        SymbolSting(string s): BaseString(s) {
        };
        bool replace(const string& a, const string& b) {
            size_t start_pos = str.find(a);

            if(start_pos == string::npos) {
                return false;
            }

            str.replace(start_pos, a.length(), b);
            return true;
        }
        string getString() {
            return str;
        };
};

int main() {
    string str, a, b;

    cout << "Enter string: ";
    cin >> str;

    cout << "Enter symbol to replace: ";
    cin >> a;

    cout << "Enter new symbol: ";
    cin >> b;

    SymbolSting strObj(str);
    strObj.replace(a, b);

    cout << "New string = " << strObj.getString() << "\n";
    cout << "New length = " << strObj.getLength() << "\n";

    return 0;
}
