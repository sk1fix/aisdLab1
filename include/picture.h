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
		Node* root;
		void print(Node* root) {
			if (!root) {
				print(root->left);
				cout << root->_val << " ";
				print(root->right);
			}
		}

		Node* insertTree(Node* root, int key) {
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

		template <typename T>
		void insert(<T> key) {
			if (root == nullptr) {
				return new Node(key);
			}
			if (key < root->key) {
				root->left = insertRecursive(root->left, key);
			}
			else if (key > root->key) {
				root->right = insertRecursive(root->right, key);
			}
			return root;
		}
	};
}