#include <string>
#include <iostream>
#include <vector>

using namespace std;

class AbstractString {
    public:
        string text;
        string get() {
            return text;
        };
        virtual void add() {
        };
        virtual void del() {
        };
        virtual void clear() {
        };
        virtual void uppercase() {
        };
        virtual void search() {
        };
        virtual void find() {
        };
        AbstractString(string s) {
            text = s;
        };
};

class StringMethods: public AbstractString {
    public:
        void add(string s) {
            text.append(s);
        };

        void del(const string & s) {
            size_t pos = string::npos;

            while ((pos = text.find(s) )!= string::npos) {
                text.erase(pos, s.length());
            }
        };

        void clear() {
            text.clear();
        };

        void uppercase() {
            transform(text.begin(), text.end(), text.begin(), ::toupper);
        };

        int search(string s) {
            if (text.find(s) != string::npos) {
                return text.find(s);
            } else {
                return 0;
            }
        };

        int find(string s) {
            size_t pos = text.find(s);
            int counter = 0;

            while(pos != string::npos) {
                pos = text.find(s, pos + s.size());
                counter++;
            }
            return counter;
        }

        StringMethods(string s): AbstractString(s) {};
};

int main() {
    string str, a, b, c;

    cout << "\nEnter initial string: ";
    getline(cin, str);
    StringMethods s(str);
    cout << "Your string is: " << s.get();

    cout << "\nEnter string to add: ";
    getline(cin, a);
    s.add(a);
    cout << "New string: " << s.get();

    cout << "\nEnter substring to delete: ";
    getline(cin, b);
    s.del(b);
    cout << "New string: " << s.get();

    s.uppercase();
    cout << "\nTo Uppercase: " << s.get();

    cout << "\nEnter substring to find matches: ";
    cin >> c;

    cout << "\n\"" << c << "\" found " << s.find(c) << " times";

    cout << "\nClear string: ";
    s.clear();
    cout << "New string: " << s.get();

    return 0;
}
