#include <stdlib.h>
#include <limits.h>
#include "header.h"

struct s_ret {
	int maxheight;
	int minheight;
	int bst;
};

int min_(int a, int b) {
	return (a < b ? a : b);
}

int max_(int a, int b) {
	return (a > b ? a : b);
}

struct s_ret traverseTree(struct s_node *root, struct s_info *info, int min, int max) {
	if (!root)
		return ((struct s_ret){-1, -1, 1});
	int bst = 1;
	if (root->value < min || root->value > max)
		bst = 0;
	++info->elements;
	info->max = max_(info->max, root->value);
	info->min = min_(info->min, root->value);
	struct s_ret l = traverseTree(root->left, info, min, root->value - 1);
	struct s_ret r = traverseTree(root->right, info, root->value + 1, max);
	return ((struct s_ret){max_(l.maxheight, r.maxheight) + 1,
				min_(l.minheight, r.minheight) + 1,
				bst && l.bst && r.bst});
}

struct s_info getInfo(struct s_node *root) {
	struct s_info info;

	info.max = INT_MIN;
	info.min = INT_MAX;
	info.elements = 0;
	struct s_ret ret = traverseTree(root, &info, INT_MIN, INT_MAX);
	info.height = ret.minheight;
	info.isBST = ret.bst;
	info.isBalanced = abs(ret.maxheight - ret.minheight) <= 1;
	return (info);
}
