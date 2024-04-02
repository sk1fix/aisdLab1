#pragma once
#include <cstdio>
#include <iostream>
#include <cstdlib>
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
		void print(Node<T>* root) {
			if (!root) {
				print(root->left);
				cout << root->_val << " ";
				print(root->right);
			}
		}

		template <typename T>
		Node<T>* insertTree(Node<T>* root, int key) {
			if (root == nullptr) {
				return new Node<T>(key);
			}
			if (key < root->key) {
				root->left = insertTree(root->left, key);
			}
			else if (key > root->key) {
				root->right = insertTree(root->right, key);
			}
			return root;
		}

		template <typename T>
		void clear(Node<T>* head) {
			if (!head) {
				return;
			}
			clear(head->_left);
			clear(head->_right);
			delete head;
		}

		template <typename T>
		Node<T>* deleteNode(Node<T>* root, int key) {
			if (root == nullptr) {
				return root;
			}
			if (key < root->key) {
				root->left = deleteNode(root->left, key);
			}
			else if (key > root->key) {
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
				root->key = temp->key;
				root->right = deleteNode(root->right, temp->key);
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

		bool contains(int key) {
			if (root == nullptr) {
				return false;
			}
			if (key == root->key) {
				return true;
			}
			else if (key < root->key) {
				return contains(root->left, key);
			}
			else {
				return contains(root->right, key);
			}
		}

		bool erase(int key) {
			return deleteNode(root, key);
		}

		BinarySearchTree operator=(BinarySearchTree other) {
			std::swap(root, other.root);
			return *this;
		}
	};
std::vector<int> findDuplicates(const std::vector<int>& vec) {
	std::vector<int> duplicates;
	for (size_t i = 0; i < vec.size(); ++i) {
		bool isDuplicate = false;
		for (size_t j = 0; j < i; ++j) {
			if (vec[i] == vec[j]) {
				isDuplicate = true;
				break;
			}
		}
		if (isDuplicate) {
			bool isAlreadyAdded = false;
			for (int dup : duplicates) {
				if (vec[i] == dup) {
					isAlreadyAdded = true;
					break;
				}
			}
			if (!isAlreadyAdded) {
				duplicates.push_back(vec[i]);
			}
		}
	}
	return duplicates;
}
std::vector<int> random(int a, int b, size_t n, size_t i) {
	std::vector<int> res;
	std::mt19937 gen(i);
	std::uniform_int_distribution<> distribution(a, b);
	for (size_t j = 0; j < n; j++) {
		size_t x = distribution(gen);
		res.push_back(x);
	}
	return res;
}

int random(int a, int b, size_t i) {
	std::mt19937 gen(i);
	std::uniform_int_distribution<> distribution(a, b);
	return distribution(gen);
}
}