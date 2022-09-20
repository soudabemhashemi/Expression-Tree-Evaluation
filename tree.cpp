#include<iostream>
#include <string>
#include "tree.hpp"
#include <cstddef>
using namespace std;

bool Tree::is_duplicate_id(size_t id){
   for(int i=0 ; i<operand_node.size() ; i++)
     if(id==operand_node[i]->get_id())
        return true;
   for(int i=0 ; i<operator_node.size() ; i++)
     if(id==operator_node[i]->get_id())
        return true;
   return false;
}

bool Tree::is_valid_parent(size_t parent_id){
    int count_root=0;
    for(int i=0 ; i<operand_node.size() ; i++)
        if(parent_id==operand_node[i]->get_id())
          return false;
     for(int i=0 ; i<operand_node.size() ; i++)
         if(operand_node[i]->get_parent_id() == DUMMY_ROOT)
             count_root++;
     for(int i=0 ; i<operator_node.size() ; i++)
         if(operator_node[i]->get_parent_id() == DUMMY_ROOT)
             count_root++;
     if(count_root>1) return false;
    return true;
}
 
void Tree::add_operand_node(const size_t id, const size_t parent_id, const int value){
  try{
           Operand *new_node=new Operand(id,parent_id,value,this);
           operand_node.push_back(new_node);
   }catch (exception& e){
      cout<<e.what()<<endl;
      abort();
   }
}

void Tree::add_operator_node(const size_t id, const size_t parent_id, const OperatorType type){ 
  try{
   switch(type){
      case 0:{ 
          Operator *new_node=new Add_operator(id , parent_id ,this);
          operator_node.push_back(new_node);
          break;
        }
     case 1:{ 
          Operator *new_node=new Multiply_operator(id , parent_id ,this);
          operator_node.push_back(new_node);
          break;
        }
     case 2:{ 
          Operator *new_node=new Not_operator(id , parent_id ,this);
          operator_node.push_back(new_node);
          break;
        }
     case 3:{ 
         Operator *new_node=new Median_operator(id , parent_id ,this);
          operator_node.push_back(new_node);
          break;
        }
   }
   }catch (exception *e){
      cout<<e->what()<<endl;
      abort();
   }
}


Operator* Tree::find_operator(vector<Operand*> nodes){
  for(int i=0; i<operator_node.size() ; i++)
     if(operator_node[i]->get_id()==nodes[0]->get_parent_id()){
         return operator_node[i];
    }
return 0;
}

vector<Operand*>  Tree::compare_operand_parent_id(Operand *node){
   vector<Operand*> nodes;
   nodes.push_back(node);
   for(int i=operand_node.size()-2 ; i>-1 ; i--){
         if(operand_node[i]->get_parent_id()==node->get_parent_id())
             nodes.push_back(operand_node[i]);
  }
  return nodes;
}

int calculate_value(Operator *node,vector<Operand*> nodes){
    int value;
    vector<int> values;
    for(int j=0; j<nodes.size(); j++)
             values.push_back(nodes[j]->get_value());
     value=node->act_operator(values);
     return value;
}


int Tree::evaluate_tree(){
  try{
  int value;
  while(operand_node[operand_node.size()-1]->get_parent_id()){
      vector<Operand*> nodes=compare_operand_parent_id(operand_node[operand_node.size()-1]);
      Operator *node=find_operator(nodes);
      value=calculate_value(node,nodes);
      operator_node.pop_back();
      add_operand_node(node->get_id(),node->get_parent_id(),value);
  }
  return value;
  }catch (exception& e){
       cout<<e.what()<<endl;
       abort();
      }
}
  
