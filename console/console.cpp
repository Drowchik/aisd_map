#include <iostream>
#include "aisd_map/aisd_map.h"

using namespace std;
using namespace map_realization;

int main() {
	Map<int, string> a(10);
	a.insert(5, "�����");
	a.insert(3, "Rbhb");
	a.insert(5, "�����");
	a.insert(9, "42��");

	a.print();
	return 0;
}