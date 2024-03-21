#include <iostream>
#include "aisd_map/aisd_map.h"

using namespace std;
using namespace map_realization;

int main() {
	Map<int, string> a(10);
	a.insert(5, "Denis");
	a.insert(3, "Robin");
	a.insert(5, "Vlad");
	a.insert(9, "Clown");
	Map<int, string> b(a);
	a.print();
	cout << "LOX" << endl;
	b.print();
	a.erase(9);
	a.erase(3);
	a.erase(5);
	cout << "LOX" << endl;
	a.print();
	cout << "LOX" << endl;
	b.print();
	cout << "Normalno vce budet" << endl;
	return 0;
}