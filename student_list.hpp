#ifndef STUDENT_LIST_HPP
#define STUDENT_LIST_HPP
#include <iostream>
#include <string> 
#include "student.hpp" 

class DomStuList 
{
  public:
  //constructors:
  //empty init
  DomStuList();
  //full init
  DomStuList(std::string fName, std::string lName, std::string prov, float gpa, int rsScore, int id);
  //copy constructors
  DomStuList(const DomStuList& DST);
  //destructor 
  ~DomStuList();
  
  //required funcs
  //search funcs:
  //app id
  //O(N)
  //all search funcs, including multi search, must iterate through the entire list 1 time in worst case, giving O(N) complexity
  //i expect theyll ask us why it isnt smth like log(N) given that its sorted, but bc its a linked list, we cant access random indices without iterating through the list first, so O(N) is about as good as we can get. if it were an array, we could use smth like binary search, but given that we need to return all items with the matching value, we can't efficiently binary search a linked list 
  void searchAppID(int ID);
  //cgpa
  //O(N)
  void searchCGPA(float gpa);
  //research score 
  //O(N)
  void searchRSScore(int score);
  //fname and lname 
  //O(N)
  void searchNames(std::string fName, std::string lName);
  //Threshold
  void searchThreshold(float CGPA_Threshold, int Research_Threshold);
  //Head and Tail
  void GetHeadandTail(int type);

  
  /*
    takes all the arguments above. for each section with the corresponding "enable" set to true, it will check if the corresponding arguments are a match in the list.
    e.g. if you activate nameenable and gpaEnable, it will check for which elements in the list have the same first name (fName), last name (lName), and gpa (gpa). all other fields will be ignored.
    this methodology is repeated for the international student list multisearch function.
  */
  //insert func
  //O(N)
  //must iterate through list no more than 1 time in worst case 
  bool insertNode(DomStuPtr insertee);
  //delete func
  //O(N)
  //must iterate through list at least 1 time in worst casem giving K*N = O(N)
  bool deleteNode(std::string fName, std::string lName);
  //delete ends func
  //O(N)
  //must iterate through whole list 1 time to find pointer before tail pts in worst case, O(N) 
  bool deleteEnds();//delete head and tail 

  void multiSearch(bool nameEnable, std::string fName, std::string lName, bool idEnable, int ID, bool gpaEnable, float gpa, bool scoreEnable, int score);

  //overloaded << op
  friend std::ostream& operator <<(std::ostream& outs, const DomStuList &DST);
  //overloaded assignment op 
  DomStuList& operator =(const DomStuList& DST);

  //get ends func
  DomStuPtr get_head() const;
  DomStuPtr get_tail() const;

  private:
  DomStuPtr head;
  DomStuPtr tail;
};

//==================================================================
class IntStuList 
{
  public:
  //constructors:
  //empty init
  IntStuList();
  //full init
  IntStuList(std::string fName, std::string lName, std::string nation, float gpa, int rsScore, ToeflScore toefl_score, int id);
  //copy constructors
  IntStuList(const IntStuList& IST);
  //destructor 
  ~IntStuList();
  
  //required funcs
  //search funcs:
  //app id
  void searchAppID(int ID);
  //cgpa
  void searchCGPA(float gpa);
  //research score 
  void searchRSScore(int score);
  //fname and lname 
  void searchNames(std::string fName, std::string lName);
  //Threshold
  void searchThreshold(float CGPA_Threshold, int Research_Threshold);
  //Head and Tail
  void GetHeadandTail(int type);
 

  //insert func
  bool insertNode(IntStuPtr insertee);
  //delete func
  bool deleteNode(std::string fName, std::string lName);
  //delete ends func
  bool deleteEnds();//delete head and tail 

  void multiSearch(bool nameEnable, std::string fName, std::string lName, bool idEnable, int ID, bool gpaEnable, float gpa, bool scoreEnable, int score);

  //overloaded << op
  friend std::ostream& operator <<(std::ostream& outs, const IntStuList &IST);
  //overloaded assignment op 
  IntStuList& operator =(const IntStuList& IST);

  //get ends func
  IntStuPtr get_head() const;
  IntStuPtr get_tail() const;

  private:
  IntStuPtr head;
  IntStuPtr tail;
  void insertBack(IntStuPtr insertee);

};


#endif /* STUDENT_LIST_HPP_ */

