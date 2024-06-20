//// 201-phase2.cpp : This file contains the 'main' function. Program execution begins and ends there.
////
//
#include <iostream>
#include <fstream>


using namespace std;

class TrieNode {
public:
	char data;
	TrieNode* arr[26];
	bool flag; //represent the end of word

	TrieNode() { // constructor to set flag as false (set true at the end of every word) and arr to null (if i > 26 characters of alphapet)
		flag = false;
		for (int i = 0; i < 26; i++) {
			arr[i] = nullptr;
		}
	}
};
class Trie {
private:
	TrieNode* root;

public:
	Trie() {
		root = new TrieNode(); //wo '\0' it throws an error that no instance of constructor "TrieNode::TrieNode" matches the argument list so I had to set it to null character
	}
	//getter to get root member variable to use it in the printAll function
	TrieNode* getRoot() {
		return root;
	}
	//insert function
	void insert(string word) {
		TrieNode* curr = root;
		for (int i = 0; i < word.length(); i++) {// a loop to iterate over each char c in word
			char c = word[i];
			int index = c - 'a'; //calculates the index using ascii table
			if (curr->arr[index] == nullptr) {
				curr->arr[index] = new TrieNode();
				curr->arr[index]->data = c;
			}
			curr = curr->arr[index];
		}
		curr->flag = true; //to access the flag member variable of the TrieNode pointed to by curr and updating its value to true indicating end of word.
	}
	//	
	//	// search function
	bool searchfun(string word) {
		TrieNode* curr = root;
		for (int i = 0; i < word.length(); i++) {
			char c = word[i];
			int index = c - 'a';
			if (curr->arr[index] == nullptr) {
				return false;
			}
			curr = curr->arr[index];
		}
		return curr->flag;
	}
	//
	//	// multiple word search function
	bool helpermultiplesearch(string word, TrieNode* root) {
		TrieNode* curr = root;
		for (int i = 0; i < word.length(); i++) {
			char c = word[i];
			int index = c - 'a';
			if (curr->arr[index] == nullptr) {
				return false;
			}
			curr = curr->arr[index];
		}
		return curr->flag;
	}
	//
	//	
	void multipleWordSearch(string* words, int size, TrieNode* root, bool* results) {
		for (int i = 0; i < size; i++) {
			string word = words[i];
			bool found = helpermultiplesearch(word, root);
			results[i] = found;
		}
	}

	//
	//	////printAll function
	//	//void printAll(TrieNode* ptr, string w) { //ptr-> pointer to the current node / w-> var to store the word formed from root to the current node
	//	//	if (ptr == nullptr) { //base case
	//	//		return;
	//	//	}
	//	//	if (ptr->flag == true) {
	//	//		cout << w << endl;
	//	//	}
	//	//	for (int i = 0; i < 26; i++) {
	//	//		if (ptr->arr[i] != nullptr) {
	//	//			char c = 'a' + i;
	//	//			printAll(ptr->arr[i], w + c); //recursive call to move to next node
	//	//		}
	//	//	}
	//	//}
	//
	//	//helper function for partial word (prefix)
	///*	void printAllandPrefix(TrieNode* ptr, string prefix, string current) {
	//		if (ptr == nullptr) {
	//			return;
	//		}
	//
	//		if (ptr->flag == true) {
	//			cout << prefix + current << endl;
	//		}
	//
	//		for (int i = 0; i < 26; i++) {
	//			if (ptr->arr[i] != nullptr) {
	//				char c = 'a' + i;
	//				printAllandPrefix(ptr->arr[i], prefix, current + c);
	//			}
	//		}
	//	}*/
	//
	//	//void partialWordSearchpre(TrieNode* root, string prefix) {
	//		/*TrieNode* ptr = root;
	//
	//		// Traverse to the node representing the prefix
	//		for (int i = 0; i < prefix.length(); i++) {
	//			char c = prefix[i];
	//			int index = c - 'a';
	//			if (ptr->arr[index] == nullptr) {// Prefix not found in the trie
	//				return;
	//			}
	//			ptr = ptr->arr[index];
	//		}
	//		printAllandPrefix(ptr, prefix, "");
	//	}*/
	//
	//	//helper function for partial word (suffix)
	//	//void printAllandSuffix(TrieNode* ptr, string suffix, string current) {
	//	//	if (ptr == nullptr) {
	//	//		return;
	//	//	}
	//
	//	//	for (int i = 0; i < 26; i++) {
	//	//		if (ptr->arr[i] != nullptr) {
	//	//			char c = 'a' + i;
	//	//			printAllandSuffix(ptr->arr[i], suffix, current + c);
	//	//		}
	//	//	}
	//	//	bool matches = true;
	//	//	if (current.length() >= suffix.length()) {
	//	//		int index = current.length() - suffix.length();
	//	//		for (int i = 0; i < suffix.length(); i++) {
	//	//			if (current[index + i] != suffix[i]) {
	//	//				matches = false;
	//	//				break;
	//	//			}
	//	//		}
	//	//	}
	//	//	if (matches) {
	//	//		cout << current << endl;
	//	//	}
	//	//}
	//	//void partialWordSearchsuf(TrieNode* root, string suffix) {
	//	//	printAllandSuffix(root, suffix, "");
	//	//}
	//
	//	//fuzzy search functions
	//	//void helperfuzzySearch(TrieNode* ptr, const string& search, string& current, int searchIndex) {
	//	//	if (ptr == nullptr) {
	//	//		return;
	//	//	}
	//
	//	//	if (searchIndex == search.length()) { //we reached the end 
	//	//		//print the current word 
	//	//		if (ptr->flag) { //indicating the end of the word
	//	//			cout << current << endl;
	//	//		}
	//	//		return;
	//	//	}
	//	//	
	//	//	char character = search[searchIndex];
	//	//	if (character == '?') {
	//	//		// Wildcard case: Recursively search all children of the current node
	//	//		for (int i = 0; i < 26; i++) {
	//	//			if (ptr->arr[i] != nullptr) {
	//	//				current[searchIndex] = 'a' + i;
	//	//				helperfuzzySearch(ptr->arr[i], search, current, searchIndex + 1);
	//	//			}
	//	//		}
	//	//	}
	//	//	else {
	//	//		// Non-wildcard case: Move to the next character in the pattern
	//	//		int index = character - 'a';
	//	//		if (ptr->arr[index] != nullptr) {
	//	//			current[searchIndex] = character;
	//	//			helperfuzzySearch(ptr->arr[index], search, current, searchIndex + 1);
	//	//		}
	//	//	}
	//	//}
	//
	//	//void fuzzySearch(TrieNode* root, const string& pattern) {
	//	//	string currentWord(pattern.length(), ' ');
	//	//	helperfuzzySearch(root, pattern, currentWord, 0);
	//	//}
	//	
	};
	
int main() {
	Trie T;

	//Read words from txt file
	ifstream inputFile("words.txt");
	if (!inputFile) {
		cout << "Failed to open file." << endl;
		return 1;
	}

	string word;
	while (inputFile >> word) { // '>>' performs formatted input extracting words from the input file
		T.insert(word);
	}
	//
	//	// test multiple word search
	string words[] = { "how", "application", "apply" };
	bool searchResults[3];
	T.multipleWordSearch(words, 3, T.getRoot(), searchResults);
	// Print the search results
	for (int i = 0; i < 3; i++) {
		cout << words[i] << ": " << searchResults[i] << endl;
	}
	//
	//
	//	//print words in trie
	//	/*cout << "The words in the Trie:" << endl;
	//	T.printAll(T.getRoot(), "", "");*/
	//
	//
	//	//search word in trie
	//	//string searchword;
	//	//cout << "Enter the word you want to search for:" << endl;
	//	//cin >> searchword;
	//
	//	//if (T.searchfun(searchword)) {
	//	//	cout << "The word (" << searchword << ") is found in the trie." << endl;
	//	//}
	//	//else {
	//	//	cout << "The word (" << searchword << ") is not found in the trie!" << endl;
	//	//}
	//
	//
	//	// test partial word search prefix
	//	/*T.partialWordSearchpre(T.getRoot(), "in");*/
	//	
	//
	//	// test partial word search suffix
	//	/*T.partialWordSearchsuf(T.getRoot(), "ing");*/
	//
	//	
	//	// test fuzzy word search 
	//	/*T.fuzzySearch(T.getRoot(), "fina?");*/
	//
	//	/*T.matchPattern(T.getRoot(), "c*t");*/
	//
	return 0;
}