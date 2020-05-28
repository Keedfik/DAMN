#include <iostream>
#include <vector>
#include <set>
#include <map>

using namespace std;

/*unsigned int CountSet(const set<vector<string>>& s, const string& w){
	unsigned int counter = 0;
	for(const auto& i : s){
		if(i[0] == w || i[1] == w)
			++counter;
	}
	return counter;
}*/

int main(){

	unsigned int q;

	set<vector<string>> synonyms;

	map<string, unsigned int> counters;

	cin >> q;

	while (q){
		string command;
		string word;
		cin >> command >> word;

		string word2;
		cin >> word2;

		vector<string> vec = { word, word2 };
		vector<string> vec2 = { word2, word };
		
		if (command == "ADD"){
			if (!synonyms.count(vec2) && !synonyms.count(vec)){
				synonyms.insert(vec);
				++counters[word];
				++counters[word2];
			}
		}
		else if (command == "CHECK"){
			if (synonyms.count(vec) || synonyms.count(vec2))
				cout << "YES\n";
			else cout << "NO\n";
		}
		q--;
	}

	return 0;
}
