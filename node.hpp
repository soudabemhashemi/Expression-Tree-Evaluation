#ifndef __NODE_H__
#define __NODE_H__

#define DUMMY_ROOT 0
#define FAIL 0
#include <cstddef>
#include<cstdlib>
#include<vector>

#include"exception.hpp"

using namespace std;

class Tree;
class Node {
  public:
   Node(size_t id,size_t parent_id,Tree* tree);
   size_t get_parent_id(){return parent_id;}
   size_t get_id(){return id;}
  protected:
    size_t id;
    size_t parent_id;
   Tree* tree;
};

class Operand : public Node{
public:
   Operand(size_t id, size_t parent_id, int value,Tree* tree);
   int get_value(){return value;}
   
private:
   int value;

};

class Operator : public Node{
public:
  Operator(size_t id, size_t parent_id,Tree* tree);
  virtual int act_operator(vector<int> values)=0;
};

class Add_operator : public Operator{
  public:
      Add_operator(size_t id, size_t parent_id,Tree* tree);
      int act_operator(vector<int> values);
};

class Multiply_operator : public Operator{
  public:
      Multiply_operator(size_t id, size_t parent_id,Tree* tree);
      int act_operator(vector<int> values);
};

class Not_operator : public Operator{
  public:
      Not_operator(size_t id, size_t parent_id,Tree* tree);
      int act_operator(vector<int> values);
};

class Median_operator : public Operator{
  public:
      Median_operator(size_t id, size_t parent_id,Tree* tree);
      int act_operator(vector<int> values);
};
#endif
