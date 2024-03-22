#include <iostream>
#include "aisd_map/aisd_map.h"

using namespace std;
using namespace map_realization;

size_t roman_to_int(string s) {
	Map<char, int> roman(10);
	roman.insert('I', 1);
	roman.insert('V', 5);
	roman.insert('X', 10);
	roman.insert('L', 50);
	roman.insert('C', 100);
	roman.insert('D', 500);
	roman.insert('M', 1000);
	long ans = 0;
	size_t size = s.length();
	for (size_t i = 0; i < size; i++) {
		int cur = *roman.search(s[i]);
		if (i+1<size && *roman.search(s[i]) < *roman.search(s[i + 1])) {
			ans -= cur;
		}
		else {
			ans+= cur;
		}
	}
	return ans;
}
int main() {
	Map<int, string> a(10);
	a.insert(5, "Denis");
	a.insert(3, "Robin");
	a.insert_or_assign(5, "Vlad");
	a.insert(9, "Clown");
	Map<int, string> b(a);
	a.print();
	cout << "LOX" << endl;
	b.print();
	a.erase(9);
	cout << "LOX" << endl;
	a.print();
	cout << "LOX" << endl;
	b.print();
	//cout << "Normalno vce budet" << endl;
	//string a = "III";
	//cout << roman_to_int(a)<<endl;
	//cout << "Test2" << endl;
	//a = "LVIII";
	//cout << roman_to_int(a) << endl;
	//cout << "Test3" << endl;
	//a = "MCMXCIV";
	//cout << roman_to_int(a) << endl;
	return 0;
}