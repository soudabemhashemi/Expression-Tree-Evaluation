#include<iostream>
#include <string>
#include "node.hpp"
#include"tree.hpp"
#include <cstddef>
using namespace std;

Node::Node(size_t _id , size_t _parent_id , Tree* t){
   if(!t-> is_duplicate_id(_id)){
      id=_id;
   }
   else {throw Duplication_node_id ();}
   if( t-> is_duplicate_id(_parent_id) || _parent_id==DUMMY_ROOT){
     if( t-> is_valid_parent(_parent_id))
        parent_id=_parent_id;
     else throw Validation_parent();
   }
   else throw No_parent();
  
}

Operand::Operand(size_t id, size_t parent_id, int _value,Tree* tree):Node(id, parent_id,tree){  value=_value;}

Operator::Operator(size_t id, size_t parent_id,Tree* tree):Node(id,parent_id,tree){}

Add_operator::Add_operator(size_t id, size_t parent_id,Tree* tree):Operator(id,parent_id,tree){}

Multiply_operator::Multiply_operator(size_t id, size_t parent_id,Tree* tree):Operator(id,parent_id,tree){}

Not_operator::Not_operator(size_t id, size_t parent_id,Tree* tree):Operator(id,parent_id,tree){}

Median_operator::Median_operator(size_t id, size_t parent_id,Tree* tree) :Operator(id,parent_id,tree){}

int Add_operator::act_operator(vector<int> values){
   if(values.size()==2)
      return values[0]+values[1];
   else throw Validation_tree();
}

int Multiply_operator::act_operator(vector<int> values){
   if(values.size()==2)
      return values[0]*values[1];
   else throw Validation_tree();                       
}

int Not_operator::act_operator(vector<int> values){
   if(values.size()==1)
      return -values[0];
   else throw Validation_tree();
}

int Median_operator::act_operator(vector<int> values){
   if(values.size()>2)
      return values[(values.size()-1)/2];
   else throw Validation_tree();
}
