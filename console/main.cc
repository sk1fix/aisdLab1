#pragma once
#include<picture.h>
using namespace tree;
int main()
{
	vector<int> a = { 3, 2, 2, 4 };
	vector<int>new_a = findDuplicates(a);
	for (int i = 0; i < size(new_a); i++) {
		cout << new_a[i];
	}
	return 0;
}