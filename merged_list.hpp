#ifndef MERGED_LIST_HPP
#define MERGED_LIST_HPP
#include <iostream>
#include <cmath>
#include <string> 
#include <iomanip>
#include "student_list.hpp"
#include "mergedStudent.hpp"
#include "student.hpp"

class merged_list
{
  public:
    //Constructor
    merged_list();

    //Destructor
    ~merged_list();

    //Insert Functions
    bool InsertDomNode(DomStuList& Dominput);
    bool InsertIntNode(IntStuList& Intinput);
    bool InsertNode(MergePtr insertee, int type);

    //Search Function
    void SearchThreshold(float CGPA_Threshold, int Research_Threshold);

    //Print Function calls upon the virtual print function
    friend std::ostream& operator <<(std::ostream& outs, const merged_list &MST);
    
    //Get functions
    MergePtr get_head() const;
    MergePtr get_tail() const;
    
    
  private:
  //Private members
  MergePtr head;
  MergePtr tail;

};



#endif /* MERGED_LIST_ */