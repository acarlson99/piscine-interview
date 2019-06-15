#include <stdlib.h>
#include "header.h"

struct s_node *newNode(char c) {
	struct s_node *node = calloc(1, sizeof(struct s_node));
	node->c = c;
	node->isWord = 0;
	return (node);
}

void trieAdd(struct s_node *n, char *str) {
	if (!*str) {
		n->isWord = 1;
		return ;
	}
	if (!n->child[(int)*str])
		n->child[(int)*str] = newNode(*str);
	trieAdd(n->child[(int)*str], str + 1);
}

struct s_trie *createTrie(char **dictionary) {
	struct s_trie *t = malloc(sizeof(struct s_trie));
	if (!t)
		return (NULL);

	t->node = calloc(1, sizeof(struct s_node));
	t->node->c = '\0';
	t->node->isWord = 0;
	for (unsigned i = 0; dictionary[i]; ++i)
		trieAdd(t->node, dictionary[i]);
	return (t);
}

char *understand_(char *word, int idx, struct s_node *node) {
	if (!word[idx])
		return (word);
	if (node->c == '\0' && node->child[(int)word[idx]])
		return (understand_(word, idx, node->child[(int)word[idx]]));
	else if (!node->child[(int)word[idx]])
		return (NULL);
	if (word[idx] == '?')
		return (NULL);
	if (node->child[(int)word[idx]]) {
		word[idx] = node->c;
		return (understand_(word, idx+1, node->child[(int)word[idx]]));
	}
	return (NULL);
}

char *understand(char *word, struct s_trie *trie) {
	return (understand_(word, 0, trie->node));
}
