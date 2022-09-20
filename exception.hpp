#include <exception>
using namespace std;
class Duplication_node_id : public exception {
   virtual const char* what() const throw();
};

class No_parent : public exception {
   virtual const char* what() const throw();
};

class Validation_parent : public exception {
    virtual const char* what() const throw();
};

class Validation_tree : public exception {
    virtual const char* what() const throw();
};
