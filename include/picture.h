#pragma once
#include <cstdio>
#include <iostream>
#include <cstdlib>
#include <chrono>
#include <random>
#include <vector>
using namespace std;
namespace tree {
	template <typename T>
	struct Node
	{
		T _val;
		Node* left;
		Node* right;
		Node(T val) : _val(val), left(nullptr), right(nullptr) {}
	};

	template <typename T>
	class BinarySearchTree
	{
	private:
		Node<T>* root;
		void printTree(Node<T>* root) {
			if (root) {
				printTree(root->left);
				cout << root->_val << " ";
				printTree(root->right);
			}
		}

		template <typename T>
		Node<T>* insertTree(Node<T>* root, int key) {
			if (root == nullptr) {
				return new Node<T>(key);
			}
			if (key < root->_val) {
				root->left = insertTree(root->left, key);
			}
			else if (key > root->_val) {
				root->right = insertTree(root->right, key);
			}
			return root;
		}

		

		template <typename T>
		void clear(Node<T>* head) {
			if (!head) {
				return;
			}
			clear(head->left);
			clear(head->right);
			delete head;
		}

		template <typename T>
		Node<T>* findMin(Node<T>* node) {
			Node<T>* current = node;
			while (current && current->left) {
				current = current->left;
			}
			return current;
		}

		template <typename T>
		Node<T>* deleteNode(Node<T>* root, int key) {
			if (root == nullptr) {
				return root;
			}
			if (key < root->_val) {
				root->left = deleteNode(root->left, key);
			}
			else if (key > root->_val) {
				root->right = deleteNode(root->right, key);
			}
			else {
				if (root->left == nullptr) {
					Node<T>* temp = root->right;
					delete root;
					return temp;
				}
				else if (root->right == nullptr) {
					Node<T>* temp = root->left;
					delete root;
					return temp;
				}
				Node<T>* temp = findMin(root->right);
				root->_val = temp->_val;
				root->right = deleteNode(root->right, temp->_val);
			}
			return root;
		}
	public:
		BinarySearchTree() : root(nullptr) {}
		BinarySearchTree(const BinarySearchTree& other) {
			root = nullptr;
			copyTree(other.root);
		}
		
		template <typename T>
		void copyTree(Node<T>* node) {
			if (!node) {
				insert(node->_val);
				copyTree(node->left);
				copyTree(node->right);
			}
		}

		bool insert(int key) {
			root = insertTree(root, key);
			return true;
		}

		~BinarySearchTree() {
			clear(root);
		}

		void print() {
			printTree(root);
		}

		template <typename T>
		bool contains(T val) {
			if (!root) {
				return false;
			}
			Node<T>* cur = root;
			while (cur) {
				if (cur->_val == val) {
					return true;
				}
				else if (cur->_val < val) {
					cur = cur->right;
				}
				else if (cur->_val > val) {
					cur = cur->left;
				}
			}
			return false;
		}

		bool erase(int key) {
			return deleteNode(root, key);
		}

		BinarySearchTree operator=(BinarySearchTree other) {
			swap(root, other.root);
			return *this;
		}

		vector<int> random(int a, int b, size_t n) {
			vector<int> res;
			random_device rd;
			mt19937 gen(rd());
			uniform_int_distribution<int> distribution(a, b);
			for (size_t j = 0; j < n; j++) {
				int x = distribution(gen);
				res.push_back(x);
			}
			return res;
		}


		void fillTreeWithRandomNumbers(int count) {
			double time_count_vec = 0;
			double time_count_tree = 0;
			for (int j = 0; j < 100; j++) {
				random_device rd;
				mt19937 gen(rd());
				uniform_int_distribution<int> dist(-100000, 100000);

				auto start_vec = chrono::high_resolution_clock::now();
				vector<int> vec = random(-100000, 100000, count);
				auto end_vec = chrono::high_resolution_clock::now();

				
				auto start = chrono::high_resolution_clock::now();
				for (int i = 0; i < count; ++i) {
					int randomNum = dist(gen);
					insert(randomNum);
				}
				auto end = chrono::high_resolution_clock::now();
				time_count_tree += chrono::duration<double>(end - start).count();
				time_count_vec += chrono::duration<double>(end_vec - start_vec).count();
			}
			cout << "Time taken to fill the tree with " << count << " random numbers: " << time_count_tree/100 << " seconds" << endl;
			cout << "Time taken to fill the vec with " << count << " random numbers: " << time_count_vec / 100 << " seconds" << endl;
		}

		void containsTreeWithRandomNumbers(int count_t) {
			double time_count_vec = 0;
			double time_count_tree = 0;

			random_device rd;
			mt19937 gen(rd());
			uniform_int_distribution<int> dist(-100000, 100000);
			for (int i = 0; i < count_t; ++i) {
				int randomNum = dist(gen);
				insert(randomNum);
			}
			auto start_tree = chrono::high_resolution_clock::now();
			for (int j = 0; j < 1000; j++) {
				int randomNum = dist(gen);
				contains(randomNum);
			}
			auto end_tree = chrono::high_resolution_clock::now();
			vector<int> vec = random(-100000, 100000, count_t);
			for (int i = 0; i < 1000; i++) {
				auto start_vec = chrono::high_resolution_clock::now();
				int cnt = count(vec.begin(), vec.end(), random(-10000, 10000, count_t)[0]);
				auto end_vec = chrono::high_resolution_clock::now();
				time_count_vec += chrono::duration<double>(end_vec - start_vec).count();
			}
			time_count_tree += chrono::duration<double>(end_tree - start_tree).count();
			
			cout << "Time taken to contains the tree with " << count_t << " random numbers: " << time_count_tree / 1000 << " seconds" << endl;
			cout << "Time taken to contains the vec with " << count_t << " random numbers: " << time_count_vec / 1000 << " seconds" << endl;
		}

		void insertTreeWithRandomNumbers(int count) {
			double time_count_vec = 0;
			double time_count_tree = 0;

			random_device rd;
			mt19937 gen(rd());
			uniform_int_distribution<int> dist(-100000, 100000);
			for (int i = 0; i < count; ++i) {
				int randomNum = dist(gen);
				insert(randomNum);
			}
			for (int j = 0; j < 1000; j++) {
				auto start_tree = chrono::high_resolution_clock::now();
				int randomNum = dist(gen);
				insert(randomNum);
				auto end_tree = chrono::high_resolution_clock::now();
				erase(randomNum);
				time_count_tree += chrono::duration<double>(end_tree - start_tree).count();
			}
			for (int i = 0; i < 1000; i++) {
				vector<int> vec = random(-100000, 100000, count);
				auto start_vec = chrono::high_resolution_clock::now();
				int randomNum = dist(gen);
				vec.push_back(randomNum);
				auto end_vec = chrono::high_resolution_clock::now();
				time_count_vec += chrono::duration<double>(end_vec - start_vec).count();
			}
			cout << "Time taken to insert the tree with " << count << " random numbers: " << time_count_tree / 1000 << " seconds" << endl;
			cout << "Time taken to insert the vec with " << count << " random numbers: " << time_count_vec / 1000 << " seconds" << endl;
		}

		void eraseTreeWithRandomNumbers(int count) {
			double time_count_vec = 0;
			double time_count_tree = 0;

			random_device rd;
			mt19937 gen(rd());
			uniform_int_distribution<int> dist(-100000, 100000);
			for (int i = 0; i < count; ++i) {
				int randomNum = dist(gen);
				insert(randomNum);
			}
			for (int j = 0; j < 1000; j++) {
				auto start_tree = chrono::high_resolution_clock::now();
				int randomNum = dist(gen);
				erase(randomNum);
				auto end_tree = chrono::high_resolution_clock::now();
				insert(randomNum);
				time_count_tree += chrono::duration<double>(end_tree - start_tree).count();
				
			}
			for (int i = 0; i < 1000; i++) {
				vector<int> vec = random(-100000, 100000, count);
				auto start_vec = chrono::high_resolution_clock::now();
				int randomNum = dist(gen);
				for (size_t j = 0; j < count; j++) {
					if (vec[j] == randomNum) {
						vec.erase(vec.begin() + j);
						break;
					}
				}
				auto end_vec = chrono::high_resolution_clock::now();
				time_count_vec += chrono::duration<double>(end_vec - start_vec).count();
			}
			cout << "Time taken to erase the tree with " << count << " random numbers: " << time_count_tree / 1000 << " seconds" << endl;
			cout << "Time taken to erase the vec with " << count << " random numbers: " << time_count_vec / 1000 << " seconds" << endl;
		}
	};

	template <typename T>
	void fillT(const vector<T>& vec, BinarySearchTree<T>& root) {
		for (int num : vec) {
			root.insert(num);
		}

	}

	template <typename T>
	vector<int> findDuplicates(const vector<int>& vec) {
		vector<int> duplicates;
		BinarySearchTree<int> temp;
		fillT(vec, temp);
		for (size_t i = 0; i < vec.size(); ++i) {
			if (temp.contains(vec[i])) {
				temp.erase(vec[i]);
			}
			if (!(count(duplicates.begin(), duplicates.end(), vec[i])))
				duplicates.push_back(vec[i]);
		}
		return duplicates;
	}
}