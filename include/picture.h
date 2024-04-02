#pragma once
#include <cstdio>
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <random>
#include <limits>
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

		Node* insertTree(Node<T>* root, int key) {
			if (root == nullptr) {
				return new Node(key);
			}
			if (key < root->key) {
				root->left = insertTree(root->left, key);
			}
			else if (key > root->key) {
				root->right = insertTree(root->right, key);
			}
			return root;
		}

		void clear(Node<T>* head) {
			if (!head) {
				return;
			}
			clear(head->_left);
			clear(head->_right);
			delete head;
		}
	public:
		BinarySearchTree() : root(nulltpr) {}
		BinarySearchTree(const BinarySearchTree& other) {
			root = nullptr;
			copyTree(other.root)
		}

		void copyTree(Node* node) {
			if (!node) {
				insert(node->key);
				copyTree(node->left);
				copyTree(node->right);
			}
		}

		bool insert(int key) {
			root = insertTree(root, key);
			return true;
		}

		~BinarySearchTree() {
			clear(root)
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
					Node* temp = root->right;
					delete root;
					return temp;
				}
				else if (root->right == nullptr) {
					Node* temp = root->left;
					delete root;
					return temp;
				}
				Node* temp = findMin(root->right);
				root->key = temp->key;
				root->right = deleteNode(root->right, temp->key);
			}
			return root;
		}
	};
}