#include "tree.hpp"
#include "tree.cpp"
#include "node.hpp"
#include <stdexcept>

#define CATCH_CONFIG_MAIN
#include "catch.hpp"

class Tree;
class Node;
TEST_CASE("Show total value"){
   Tree tree;
   tree.add_operator_node(1,DUMMY_ROOT, Add);
   tree.add_operator_node(2, 1, Multiply);
   tree.add_operator_node(3, 1, Not);
   tree.add_operator_node(4, 2, Median);
   tree.add_operand_node(5, 2, 5);
   tree.add_operand_node(6, 4 ,2);
   tree.add_operand_node(7, 4, 3);
   tree.add_operand_node(8, 4, 4);
   tree.add_operand_node(9, 3, 1);
   REQUIRE(tree.evaluate_tree() == 14);
}


TEST_CASE("Calculate median gate"){
   Tree t;
   vector<int> values{10, 20 , 30 };
   REQUIRE(Median_operator(1,2,&t).act_operator(values) == 20);
}

TEST_CASE("Check validation of parent id"){
   Tree tree;
   tree.add_operator_node(1,DUMMY_ROOT, Add);
   tree.add_operator_node(2, 1, Multiply);
   tree.add_operator_node(3, 1, Not);
   tree.add_operator_node(4, 2, Median);
   tree.add_operand_node(5, 2, 5);
   tree.add_operand_node(6, 4 ,2);
   tree.add_operand_node(7, 4, 3);
   tree.add_operand_node(8, 4, 4);
   tree.add_operand_node(9, 3, 1);
   REQUIRE(tree.is_valid_parent(4) == true );
}



