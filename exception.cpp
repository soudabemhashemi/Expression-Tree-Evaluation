#include"exception.hpp"
const char* Duplication_node_id::what() const throw(){
      return "Duplicate node ID.\n"; 
 }

const char* No_parent::what() const throw(){
      return "Parent node not found.\n";
 }

const char* Validation_parent :: what() const throw(){
        return "Invalid parent.\n";
    }

const char* Validation_tree :: what() const throw(){
        return "Invalid tree structure.\n";
    }
