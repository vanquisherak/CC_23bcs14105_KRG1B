#include <bits/stdc++.h>
using namespace std;
class Trie {
private:
	struct Node {
		Node* child[26];
		bool isEnd;
		int endCount;
		int prefixCount;

		Node() : isEnd(false), endCount(0), prefixCount(0) {
			for (int i = 0; i < 26; i++) {
				child[i] = nullptr;
			}
		}
	};
	Node* root;
	void freeNode(Node* node) {
		if (node == nullptr) {
			return;
		}
		for (int i = 0; i < 26; i++) {
			freeNode(node->child[i]);
		}
		delete node;
	}
public:
	Trie() {
		root = new Node();
	}
	~Trie() {
		freeNode(root);
	}
	void insert(const string& word) {
		Node* cur = root;
		for (char ch : word) {
			int idx = ch - 'a';
			if (cur->child[idx] == nullptr) {
				cur->child[idx] = new Node();
			}
			cur = cur->child[idx];
			cur->prefixCount++;
		}
		cur->isEnd = true;
		cur->endCount++;
	}
	bool search(const string& word) const {
		Node* cur = root;
		for (char ch : word) {
			int idx = ch - 'a';
			if (cur->child[idx] == nullptr) {
				return false;
			}
			cur = cur->child[idx];
		}
		return cur->isEnd;
	}
	bool startsWith(const string& prefix) const {
		Node* cur = root;
		for (char ch : prefix) {
			int idx = ch - 'a';
			if (cur->child[idx] == nullptr) {
				return false;
			}
			cur = cur->child[idx];
		}
		return true;
	}
	int countWordsEqualTo(const string& word) const {
		Node* cur = root;
		for (char ch : word) {
			int idx = ch - 'a';
			if (cur->child[idx] == nullptr) {
				return 0;
			}
			cur = cur->child[idx];
		}
		return cur->endCount;
	}
    int countWordsStartingWith(const string& prefix) const {
		Node* cur = root;
		for (char ch : prefix) {
			int idx = ch - 'a';
			if (cur->child[idx] == nullptr) {
				return 0;
			}
			cur = cur->child[idx];
		}
		return cur->prefixCount;
	}
};
int main() {
	Trie trie;
	int q;
	cin >> q;
	while (q--) {
		int type;
		string s;
		cin >> type >> s;
		if (type == 1) {
			trie.insert(s);
		} else if (type == 2) {
			cout << (trie.search(s) ? "Found" : "Not Found") << '\n';
		} else if (type == 3) {
			cout << (trie.startsWith(s) ? "Yes" : "No") << '\n';
		} else if (type == 4) {
			cout << trie.countWordsEqualTo(s) << '\n';
		} else if (type == 5) {
			cout << trie.countWordsStartingWith(s) << '\n';
		}
	}
	return 0;
}
