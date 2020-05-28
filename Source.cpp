#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

map<char, int> BuildCharCounters(const string& a) { 
    map <char, int> s1; 
    for (const auto& ch : a) { 
        ++s1[ch];
    }      
    return s1; 
}

int main() {
    int i;
    cin >> i; 
    string a, b; 
    vector<string> v; 
    for (i; i > 0; i--) { 
        cin >> a >> b; 
        if (BuildCharCounters(a) == BuildCharCounters(b)) { 
            v.push_back("YES"); 
        }
        else {
            v.push_back("NO"); 
        }
    }
    for (auto r : v) {
        cout << r << endl; 
    }
    return 0;
}