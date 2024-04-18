#pragma once
#include<picture.h>
using namespace tree;
int main()
{
	vector<int> a = { 3, 2, 2, 4 };
	vector<int>new_a = findDuplicates<int>(a);
	for (int i = 0; i < size(new_a); i++) {
		cout << new_a[i] << endl;
	}
	/*BinarySearchTree<int> tree;
	vector<int>new_a = findDuplicates<int>(a, tree);*/

	BinarySearchTree<int> bst;
	bst.insert(3);
	bst.insert(45);
	bst.insert(8);
	bst.insert(4);
	bst.insert(47);
	bst.insert(87);
	bst.print();
	bst.erase(47);
	bst.print();
	//bst.fillTreeWithRandomNumbers(1000);
	//Time taken to fill the tree with 1000 random numbers: 0.000800439 seconds
	//Time taken to fill the vec with 1000 random numbers : 0.000129292 seconds
	//bst.fillTreeWithRandomNumbers(10000);
	//Time taken to fill the tree with 10000 random numbers: 0.00919021 seconds
	//Time taken to fill the vec with 10000 random numbers : 0.00108887 seconds
	//bst.fillTreeWithRandomNumbers(100000);
	//Time taken to fill the tree with 100000 random numbers: 0.0797373 seconds
	//Time taken to fill the vec with 100000 random numbers : 0.0109607 seconds
	//bst.containsTreeWithRandomNumbers(1000);
	//Time taken to contains the tree with 1000 random numbers: 1.364e-07 seconds
	//Time taken to contains the vec with 1000 random numbers : 0.000142592 seconds
	//bst.containsTreeWithRandomNumbers(10000);
	//Time taken to contains the tree with 10000 random numbers: 2.696e-07 seconds
	//Time taken to contains the vec with 10000 random numbers : 0.00143512 seconds
	//bst.containsTreeWithRandomNumbers(100000);
	//Time taken to contains the tree with 100000 random numbers: 5.04e-07 seconds
	//Time taken to contains the vec with 100000 random numbers : 0.00971749 seconds
	//bst.insertTreeWithRandomNumbers(1000);
	//Time taken to insert the tree with 1000 random numbers: 3.287e-07 seconds
	//Time taken to insert the vec with 1000 random numbers : 1.508e-07 seconds
	//bst.insertTreeWithRandomNumbers(10000);
	//Time taken to insert the tree with 10000 random numbers: 8.19e-07 seconds
	//Time taken to insert the vec with 10000 random numbers : 3.84e-07 seconds
	//bst.insertTreeWithRandomNumbers(100000);
	//Time taken to insert the tree with 100000 random numbers: 8.853e-07 seconds
	//Time taken to insert the vec with 100000 random numbers : 2.313e-07 seconds
	//bst.eraseTreeWithRandomNumbers(1000);
	//Time taken to erase the tree with 1000 random numbers: 2.033e-07 seconds
	//Time taken to erase the vec with 1000 random numbers : 4.1019e-06 seconds
	//bst.eraseTreeWithRandomNumbers(10000);
	//Time taken to erase the tree with 10000 random numbers: 7.865e-07 seconds
	//Time taken to erase the vec with 10000 random numbers : 4.77749e-05 seconds
	//bst.eraseTreeWithRandomNumbers(100000);
	//Time taken to erase the tree with 100000 random numbers: 7.124e-07 seconds
	//Time taken to erase the vec with 100000 random numbers : 0.000266338 seconds
	return 0;
}