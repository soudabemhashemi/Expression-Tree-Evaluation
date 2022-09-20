#ifndef __TREE_H__
#define __TREE_H__

#define DUMMY_ROOT 0
#define FAIL 0

#include<iostream>
#include <cstddef>
#include<vector>
#include "node.hpp"

using namespace std;

enum OperatorType{ Add, Multiply, Not, Median};

class Node;

class Tree{
public:
  void add_operand_node(const std::size_t id, const std::size_t parent_id, const int value);
  void add_operator_node(const std::size_t id, const std::size_t parent_id, const OperatorType type);
  int evaluate_tree();
  vector<Operand*> compare_operand_parent_id(Operand *node);
  Operator* find_operator(vector<Operand*> nodes);
  bool is_duplicate_id(std::size_t id);
  bool have_parent(std::size_t id);
  bool is_valid_parent(std::size_t parent_id);
  void add_operand_node_for_midel(const size_t id, const size_t parent_id, const int value);
private:
   std::vector<Operand*> operand_node;
   std::vector<Operator*> operator_node;
};



#endif
