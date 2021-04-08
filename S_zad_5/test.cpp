#include <iostream>
#include <string>
using namespace std;

bool is_glasnaya(char s) {
    return (s == 'a' ||  s == 'e' || s == 'i' || s == 'o' || s == 'u' || s == 'y');
}

int main() {
    
    string a;
    cin >> a;

    if (is_glasnaya (a[0]) == true) {

        if(a.length() % 2 != 0) {
            if(is_glasnaya(a[a.length() - 2]) != false && is_glasnaya(a[a.length() - 1]) != true) {
                cout << "NO";
                return 0;
            }
        }

        for (int i = 0; i < a.length() - 1; i+=2) {

            if (!(is_glasnaya(a[i]) == true && is_glasnaya(a[i+1]) == false)) {
                cout << "NO";
                return 0;
            }
        }
    }
    
    else {
        for (int i = a.length(); i > 1; i -= 2) {

            if ((is_glasnaya(a[i]) != true && is_glasnaya(a[i-1]) != false)) {
                cout << "NO" << endl;
                return 0;
            }   

        }
    }
    
    cout << "YES" << a.length();
    
    return 0;

}