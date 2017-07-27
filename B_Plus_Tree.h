#pragma once
#ifndef _B_PLUS_TREE_H_
#define _B_PLUS_TREE_H_

#include <vector>
#include <string>
#include <sstream>
#include <stdexcept>
#include <utility>
#include <cassert>

class bptNode
{
private:
	int maxSize;
	bool isLeaf;
	bptNode* parent;
	std::vector<int> keys;
	std::vector<bptNode*> children;
	std::vector<int> values;

	bptNode* split();
	// ---------------------------------------
	bptNode* bm();

	bptNode* borrow_left(bptNode* &left, const size_t& parent_pos);
	bptNode* merge_left(bptNode* & left, const size_t& parent_pos);
	
	bptNode* borrow_right(bptNode* &right, const size_t& parent_pos);
	bptNode* merge_right(bptNode* & right, const size_t& parent_pos);
	// ---------------------------------------
	size_t find_pos(const int&);
	size_t find_pos(const int&)const;

	void remove(const size_t& pos);

public:
	bptNode(const bool& isleaf = true, bptNode* p = nullptr,const int& size = 3);
	bptNode(const bool& isleaf = true, const int& size = 3);
	bptNode(const bptNode&);
	bptNode& operator=(const bptNode&);
	~bptNode();

	void set_parent(bptNode* p);
	void set_max_size(const int &);

	int leftest();

	//int predecessor(const int&);
	int successor(const int&);

	bool find(const int& key) const;
	// can be modified
	// return  > value <
	int& search(const int& key);

	bptNode* insert(const int& key, const int& value);

	bptNode* del(const int& key);

	bool empty();

	bptNode* only_child();

	std::string traverse();

	friend bptNode* inherit(bptNode* &_root);
};

#endif