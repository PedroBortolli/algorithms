#include <bits/stdc++.h>
using namespace std;

const int N = 2e5+5;
char s[N];
int sze = 0, root = 1;

struct node {
	int to[26];
	int freq;
	int end;
};

node trie[N];

int size() {
	return trie[1].freq;
}

//insert a string s to the trie (usage: root = insert(str);)
int insert(char s[], int p = 0, int &nd = root) {
	if (sze == 0) nd = 0;
	if (nd == 0) nd = ++sze;
	trie[nd].freq++;
	if (s[p] == 0) {
		trie[nd].end++;
		return 1;
	}
	insert(s, p+1, trie[nd].to[s[p]-'a']);
}

//use find to check if string is in the trie or not
int erase(char s[], int p = 0, int &nd = root) {
	trie[nd].freq--;
	if (s[p] == 0) return 0;
	int k = erase(s, p+1, trie[nd].to[s[p]-'a']);
	if (k == 0) trie[nd].to[s[p]-'a'] = k;
	return trie[nd].freq;
}

//returns the amount of strings equal to s in the trie
int find(char s[], int p = 0, int nd = 1) {
	if (nd == 0) return 0;
	if (s[p] == 0) return trie[nd].end;
	find(s, p+1, trie[nd].to[s[p]-'a']);
}

//number of strings that share the same prefix as prefix s
int countpref(char s[], int p = 0, int nd = 1) {
	if (nd == 0) return 0;
	if (s[p] == 0) return trie[nd].freq;
	countpref(s, p+1, trie[nd].to[s[p]-'a']);
}

int main() {
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf(" %s", s);
		root = insert(s);
	}
	for (int i = 0; i < n; i++) {
		scanf(" %s", s);
		if (find(s)) printf("	%d\n", countpref(s));
	}

	return 0;
}