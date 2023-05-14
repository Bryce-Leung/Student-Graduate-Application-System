#include <iostream>
#include <cmath>
#include <string> 
#include <iomanip>
#include "student.hpp" 
#include "student_list.hpp"
 
//constructors:
//empty init
DomStuList::DomStuList()
{
  head = NULL;
  tail = NULL;
  return;
}

//full init
DomStuList::DomStuList(std::string fName, std::string lName, std::string prov, float gpa, int rsScore, int id)
{
  ////Part 2 #5////
  DomStuPtr start = NULL;
  try 
  {
    start = new DomesticStudent(fName, lName, prov, gpa, rsScore, id);
  } 
  catch(std::bad_alloc& ex) {
    std::cout << "Error(5): Out of memory!";
    std::exit(5);
  }
  head = start;
  tail = start;
  return;
}
//copy constructors
DomStuList::DomStuList(const DomStuList& DST)
{
  this->head = NULL;
  this->tail = NULL;
  DomStuPtr cur = DST.get_head(); //get head of DST to copy from
  while(cur != NULL)
  {
    //copy each student from DST to this
    ////Part 2 #5////
    DomStuPtr insertee = NULL;
    try{
      insertee = new DomesticStudent;
    }
    catch(std::bad_alloc& ex)
    {
      std::cout << "Error(5): Out of memory!";
      std::exit(5);
    }
    insertee->set_allStuID(cur->get_fName(), cur->get_lName(), cur->get_CGPA(), cur->get_rsScore(), cur->get_appID());
    insertee->set_province(cur->get_province());
    this->insertNode(insertee);
    cur = cur->get_next();
  }
}
//destructor 
DomStuList::~DomStuList()
{
  if(head == NULL)
  {
    //empty list, can return 
    return;
  }
  if(head == tail)
  {
    //only 1 node 
    delete head;
    return;
  }
  //else we have > 1 node 
  DomStuPtr cur = head;
  DomStuPtr behind = head;
  cur = cur->get_next();
  while(cur != NULL)
  {
    delete behind;
    behind = cur;
    cur = cur->get_next();
  }
  //then once this loop ends, all the elements have been deleted bc cur = null and behind = the last element of the list at that pt 
  delete behind;
  //clean up any potential issues with the head and tail pointers just in case
  head = NULL;
  tail = NULL;
  return;
}

//required funcs
//search funcs:
//default sort: 
/*
rsScore
CGPA
prov/country
(drop int stu with bad toefl)
*/
//app id
void DomStuList::searchAppID(int ID)
{
  DomStuList returnee = DomStuList();
  DomStuPtr cur = head;
  while(cur != NULL)
  {
    if(cur->get_appID() == ID)//check if current item has correct ID
    {
      //if so, we create a copy of it and add it to a new list that holds all matches
      ////Part 2 #5////
      DomStuPtr temp = NULL;
      try{
        temp = new DomesticStudent;
      }
      catch(std::bad_alloc& ex)
      {
        std::cout << "Error(5): Out of memory!";
        std::exit(5);
      }
      temp->set_allStuID(cur->get_fName(), cur->get_lName(), cur->get_CGPA(), cur->get_rsScore(), cur->get_appID());
      temp->set_province(cur->get_province());
      returnee.insertNode(temp);
    }
    cur = cur->get_next();
  }
  //once we're here, we have our list of matches 
  //note that if nothing matches, we get a null list
  std::cout << returnee;
}

//cgpa
void DomStuList::searchCGPA(float gpa)
{
  DomStuList returnee = DomStuList();
  DomStuPtr cur = head;
  while(cur != NULL)
  {
    if(cur->get_CGPA() == gpa)//check if current item has correct gpa
    {
      //if so, we create a copy of it and add it to a new list that holds all matches
      ////Part 2 #5////
      DomStuPtr temp = NULL;
      try{
        temp = new DomesticStudent;
      }
      catch(std::bad_alloc& ex)
      {
        std::cout << "Error(5): Out of memory!";
        std::exit(5);
      }
      temp->set_allStuID(cur->get_fName(), cur->get_lName(), cur->get_CGPA(), cur->get_rsScore(), cur->get_appID());
      temp->set_province(cur->get_province());
      returnee.insertNode(temp);
    }
    cur = cur->get_next();
  }
  //once we're here, we have our list of matches
  //note that if nothing matches, we get a null list
  std::cout << returnee;
} 

//research score 
void DomStuList::searchRSScore(int score)
{
  DomStuList returnee = DomStuList();
  DomStuPtr cur = head;
  while(cur != NULL)
  {
    if(cur->get_rsScore() == score)//check if current item has correct rsScore
    {
      //if so, we create a copy of it and add it to a new list that holds all matches
      ////Part 2 #5////
      DomStuPtr temp = NULL;
      try{
        temp = new DomesticStudent;
      }
      catch(std::bad_alloc& ex)
      {
        std::cout << "Error(5): Out of memory!";
        std::exit(5);
      }
      temp->set_allStuID(cur->get_fName(), cur->get_lName(), cur->get_CGPA(), cur->get_rsScore(), cur->get_appID());
      temp->set_province(cur->get_province());
      returnee.insertNode(temp);
    }
    cur = cur->get_next();
  }
  //once we're here, we have our list of matches
  //note that if nothing matches, we get a null list
  std::cout << returnee;
}


//fname and lname 
void DomStuList::searchNames(std::string fName, std::string lName)
{
  DomStuList returnee = DomStuList();
  DomStuPtr cur = head;
  while(cur != NULL)
  {
    
    if(cur->get_fName() == fName && cur->get_lName() == lName)//check if current item has correct names
    {
      //if so, we create a copy of it and add it to a new list that holds all matches
      ////Part 2 #5////
      DomStuPtr temp = NULL;
      try{
        temp = new DomesticStudent;
      }
      catch(std::bad_alloc& ex)
      {
        std::cout << "Error(5): Out of memory!";
        std::exit(5);
      }
      temp->set_allStuID(cur->get_fName(), cur->get_lName(), cur->get_CGPA(), cur->get_rsScore(), cur->get_appID());
      temp->set_province(cur->get_province());
      returnee.insertNode(temp);
    }
    cur = cur->get_next();
  }
  //once we're here, we have our list of matches
  //note that if nothing matches, we get a null list
  std::cout << returnee;
}

//ThresholdSearch
void DomStuList::searchThreshold(float CGPA_Threshold, int Research_Threshold)
{
  DomStuList returnee = DomStuList();
  DomStuPtr cur = head;
  while(cur != NULL)
  {
    if(cur->get_CGPA() >= CGPA_Threshold && cur->get_rsScore() >= Research_Threshold)
    {
      ////Part 2 #5////
      DomStuPtr temp = NULL;
      try{
        temp = new DomesticStudent;
      }
      catch(std::bad_alloc& ex)
      {
        std::cout << "Error(5): Out of memory!";
        std::exit(5);
      }
      temp->set_allStuID(cur->get_fName(), cur->get_lName(), cur->get_CGPA(), cur->get_rsScore(), cur->get_appID());
      temp->set_province(cur->get_province());
      returnee.insertNode(temp);
    }      
    cur = cur->get_next();
  }
  std::cout << returnee;
}


//Head and Tail
void DomStuList::GetHeadandTail(int type)
{
  if(type == 1){
    DomStuList returnee = DomStuList();
    DomStuPtr cur = get_head();
    std::cout << "head:\n";
    ////Part 2 #5////
    DomStuPtr temp = NULL;
    try{
      temp = new DomesticStudent;
    }
    catch(std::bad_alloc& ex)
    {
      std::cout << "Error(5): Out of memory!";
      std::exit(5);
    }
    temp->set_allStuID(cur->get_fName(), cur->get_lName(), cur->get_CGPA(), cur->get_rsScore(), cur->get_appID());
    temp->set_province(cur->get_province());
    returnee.insertNode(temp);      
    cur = cur->get_next();
    std::cout << returnee;
  }
  else {
    DomStuList returnee = DomStuList();
    DomStuPtr cur = get_tail();
    std::cout << "tail:\n";
    ////Part 2 #5////
    DomStuPtr temp = NULL;
    try{
      temp = new DomesticStudent;
    }
    catch(std::bad_alloc& ex)
    {
      std::cout << "Error(5): Out of memory!";
      std::exit(5);
    }
    temp->set_allStuID(cur->get_fName(), cur->get_lName(), cur->get_CGPA(), cur->get_rsScore(), cur->get_appID());
    temp->set_province(cur->get_province());
    returnee.insertNode(temp);      
    cur = cur->get_next();
    std::cout << returnee;
  }
}

//MultiSearch
void DomStuList::multiSearch(bool nameEnable, std::string fName, std::string lName, bool idEnable, int ID, bool gpaEnable, float gpa, bool scoreEnable, int score)
{
  DomStuList returnee;
  DomStuPtr cur = head;
  if(!nameEnable && !idEnable && !gpaEnable && !scoreEnable)
  {
    std::cout << "No filters selected, please try again.\n";
    return;
  }
  else if(nameEnable)
  {
    if(idEnable)
    {
      if(gpaEnable)
      {
        if(scoreEnable)
        {
          while(cur != NULL)
          {
            if(cur->get_fName() == fName && cur->get_lName() == lName && cur->get_appID() == ID && cur->get_CGPA() == gpa && cur->get_rsScore() == score)
            {
              ////Part 2 #5////
              DomStuPtr temp = NULL;
              try{
                temp = new DomesticStudent;
              }
              catch(std::bad_alloc& ex)
              {
                std::cout << "Error(5): Out of memory!";
                std::exit(5);
              }
              temp->set_allStuID(cur->get_fName(), cur->get_lName(), cur->get_CGPA(), cur->get_rsScore(), cur->get_appID());
              temp->set_province(cur->get_province());
              returnee.insertNode(temp);
            }      
            cur = cur->get_next();
          }
          std::cout << returnee;
          return;
        }//name id gpa score
        else
        {
          while(cur != NULL)
          {
            if(cur->get_fName() == fName && cur->get_lName() == lName && cur->get_appID() == ID && cur->get_CGPA() == gpa)
            {
              ////Part 2 #5////
              DomStuPtr temp = NULL;
              try{
                temp = new DomesticStudent;
              }
              catch(std::bad_alloc& ex)
              {
                std::cout << "Error(5): Out of memory!";
                std::exit(5);
              }
              temp->set_allStuID(cur->get_fName(), cur->get_lName(), cur->get_CGPA(), cur->get_rsScore(), cur->get_appID());
              temp->set_province(cur->get_province());
              returnee.insertNode(temp);
            }      
            cur = cur->get_next();
          }
          std::cout << returnee;
          return;
        }//name id gpa
      }//gpa in id end 
      else if(scoreEnable)
      {
        while(cur != NULL)
        {
          if(cur->get_fName() == fName && cur->get_lName() == lName && cur->get_appID() == ID && cur->get_rsScore() == score)
          {
            ////Part 2 #5////
            DomStuPtr temp = NULL;
            try{
              temp = new DomesticStudent;
            }
            catch(std::bad_alloc& ex)
            {
              std::cout << "Error(5): Out of memory!";
              std::exit(5);
            }
            temp->set_allStuID(cur->get_fName(), cur->get_lName(), cur->get_CGPA(), cur->get_rsScore(), cur->get_appID());
            temp->set_province(cur->get_province());
            returnee.insertNode(temp);
          }      
          cur = cur->get_next();
        }
        std::cout << returnee;
        return;
      }//name id score
      else
      {
        while(cur != NULL)
        {
          if(cur->get_fName() == fName && cur->get_lName() == lName && cur->get_appID() == ID)
          {
            ////Part 2 #5////
            DomStuPtr temp = NULL;
            try{
              temp = new DomesticStudent;
            }
            catch(std::bad_alloc& ex)
            {
              std::cout << "Error(5): Out of memory!";
              std::exit(5);
            }
            temp->set_allStuID(cur->get_fName(), cur->get_lName(), cur->get_CGPA(), cur->get_rsScore(), cur->get_appID());
            temp->set_province(cur->get_province());
            returnee.insertNode(temp);
          }      
          cur = cur->get_next();
        }
        std::cout << returnee;
        return;
      }//name id
    }//id in name end 
    else if(gpaEnable)
    {
      if(scoreEnable)
      {
        while(cur != NULL)
        {
          if(cur->get_fName() == fName && cur->get_lName() == lName && cur->get_CGPA() == gpa && cur->get_rsScore() == score)
          {
            ////Part 2 #5////
            DomStuPtr temp = NULL;
            try{
              temp = new DomesticStudent;
            }
            catch(std::bad_alloc& ex)
            {
              std::cout << "Error(5): Out of memory!";
              std::exit(5);
            }
            temp->set_allStuID(cur->get_fName(), cur->get_lName(), cur->get_CGPA(), cur->get_rsScore(), cur->get_appID());
            temp->set_province(cur->get_province());
            returnee.insertNode(temp);
          }      
          cur = cur->get_next();
        }
        std::cout << returnee;
        return;
      }//name gpa score
      else
      {
        while(cur != NULL)
        {
          if(cur->get_fName() == fName && cur->get_lName() == lName && cur->get_CGPA() == gpa)
          {
            ////Part 2 #5////
            DomStuPtr temp = NULL;
            try{
              temp = new DomesticStudent;
            }
            catch(std::bad_alloc& ex)
            {
              std::cout << "Error(5): Out of memory!";
              std::exit(5);
            }
            temp->set_allStuID(cur->get_fName(), cur->get_lName(), cur->get_CGPA(), cur->get_rsScore(), cur->get_appID());
            temp->set_province(cur->get_province());
            returnee.insertNode(temp);
          }      
          cur = cur->get_next();
        }
        std::cout << returnee;
        return;
      }//name gpa
    }//end gpa in name
    else if(scoreEnable)
    {
      while(cur != NULL)
      {
        if(cur->get_fName() == fName && cur->get_lName() == lName && cur->get_rsScore() == score)
        {
            ////Part 2 #5////
            DomStuPtr temp = NULL;
            try{
              temp = new DomesticStudent;
            }
            catch(std::bad_alloc& ex)
            {
              std::cout << "Error(5): Out of memory!";
              std::exit(5);
            }
          temp->set_allStuID(cur->get_fName(), cur->get_lName(), cur->get_CGPA(), cur->get_rsScore(), cur->get_appID());
          temp->set_province(cur->get_province());
          returnee.insertNode(temp);
        }     
        cur = cur->get_next();
      }
      std::cout << returnee;
      return;
    }//name score
    else
    {
      this->searchNames(fName,lName);
      return;
    }
  }//end names 
  else if(idEnable)
  {
    if(gpaEnable)
    {
      if(scoreEnable)
      {
      while(cur != NULL)
      {
        if(cur->get_appID() == ID && cur->get_CGPA() == gpa && cur->get_rsScore() == score)
        {
          ////Part 2 #5////
          DomStuPtr temp = NULL;
          try{
            temp = new DomesticStudent;
          }
          catch(std::bad_alloc& ex)
          {
            std::cout << "Error(5): Out of memory!";
            std::exit(5);
          }
          temp->set_allStuID(cur->get_fName(), cur->get_lName(), cur->get_CGPA(), cur->get_rsScore(), cur->get_appID());
          temp->set_province(cur->get_province());
          returnee.insertNode(temp);
        }      
        cur = cur->get_next();
      }
      std::cout << returnee;
      return;
      }//id gpa score
      else
      {
        while(cur != NULL)
        {
          if(cur->get_appID() == ID && cur->get_CGPA() == gpa)
          {
            ////Part 2 #5////
            DomStuPtr temp = NULL;
            try{
              temp = new DomesticStudent;
            }
            catch(std::bad_alloc& ex)
            {
              std::cout << "Error(5): Out of memory!";
              std::exit(5);
            }
            temp->set_allStuID(cur->get_fName(), cur->get_lName(), cur->get_CGPA(), cur->get_rsScore(), cur->get_appID());
            temp->set_province(cur->get_province());
            returnee.insertNode(temp);
          }      
          cur = cur->get_next();
        }
        std::cout << returnee;
        return;
      }//id gpa
    }
    else if(scoreEnable)
    {
      while(cur != NULL)
      {
        if(cur->get_appID() == ID && cur->get_rsScore() == score)
        {
          ////Part 2 #5////
          DomStuPtr temp = NULL;
          try{
            temp = new DomesticStudent;
          }
          catch(std::bad_alloc& ex)
          {
            std::cout << "Error(5): Out of memory!";
            std::exit(5);
          }
          temp->set_allStuID(cur->get_fName(), cur->get_lName(), cur->get_CGPA(), cur->get_rsScore(), cur->get_appID());
          temp->set_province(cur->get_province());
          returnee.insertNode(temp);
        }      
        cur = cur->get_next();
      }
      std::cout << returnee;
      return;
    }//id score
    else
    {
      this->searchAppID(ID);
      return;
    }
  }//end id
  else if(gpaEnable)
  {
    if(scoreEnable)
    {
      while(cur != NULL)
      {
        if(cur->get_CGPA() == gpa && cur->get_rsScore() == score)
        {
          ////Part 2 #5////
          DomStuPtr temp = NULL;
          try{
            temp = new DomesticStudent;
            }
          catch(std::bad_alloc& ex)
          {
            std::cout << "Error(5): Out of memory!";
            std::exit(5);
          }
          temp->set_allStuID(cur->get_fName(), cur->get_lName(), cur->get_CGPA(), cur->get_rsScore(), cur->get_appID());
          temp->set_province(cur->get_province());
          returnee.insertNode(temp);
        }      
        cur = cur->get_next();
      }
      std::cout << returnee;
      return;
    }
    else
    {
      this->searchCGPA(gpa);
      return;
    }
  }//end gpa
  else if(scoreEnable)//only score selected
  {
    this->searchRSScore(score);
    return;
  }
  else
  {
    std::cout << "Critical error with multi-search function, please try again.";
    std::exit(-1);
  }
}


 //insert func
bool DomStuList::insertNode(DomStuPtr insertee)
//suyuan liu, cleaned up for this instance by thomas
{
  if (head == NULL)
  {
    head = insertee;
    tail = insertee;
    return true;
  }
  ////Part 2 #5////
  DomStuPtr dummy_head = NULL;
  try{ 
    dummy_head = new DomesticStudent;
  }
  catch(std::bad_alloc& ex)
  {
    std::cout << "Error(5): Out of memory!";
    std::exit(5);
  }
  //get a head to put before the real head
  dummy_head->set_next(head);
  DomStuPtr cur = dummy_head;
  while (cur->get_next() != NULL) {
    if (insertee->get_rsScore() > cur->get_next()->get_rsScore()) 
    //note that as the list is always sorted, we can do checks like this
    {
      insertee->set_next(cur->get_next());
      cur->set_next(insertee);
      break;
    } 
    else if(insertee->get_rsScore() == cur->get_next()->get_rsScore())
    {
      //research scores match, now we need to find what to sort on next
      if(insertee->get_CGPA() > cur->get_next()->get_CGPA())
      {
        insertee->set_next(cur->get_next());
        cur->set_next(insertee);
        break;
      }
      else if(insertee->get_CGPA() == cur->get_next()->get_CGPA())
      {
        //rs score and cgpa match, last condition is province 
        //note that these must be in ascending order
        if(insertee->get_province() < cur->get_next()->get_province() && insertee->get_CGPA() == cur->get_next()->get_CGPA())
        {
          insertee->set_next(cur->get_next());
          cur->set_next(insertee);
          break;
        }
        else if(insertee->get_province() > cur->get_next()->get_province() && insertee->get_CGPA() == cur->get_next()->get_CGPA())
        {
          cur = cur->get_next();
        }
        else
        {
          insertee->set_next(cur->get_next());
          cur->set_next(insertee);
          break;
        }
      }//end for nested loops within cgpa sorter
      else
      {
        if(cur->get_next()->get_rsScore() < insertee->get_rsScore())
        {//check if we've hit the end of the people with the same rs score
          insertee->set_next(cur->get_next());
          cur->set_next(insertee);
          break;
        }
        else
        {
          cur = cur->get_next();
        }
      }
    }//end for nested loops
    else 
    {
      cur = cur->get_next();
    }
  }
  if (cur->get_next() == NULL)
  {
    cur->set_next(insertee);
    tail = insertee;
  }
  head = dummy_head->get_next();
  delete dummy_head;
  return true;
}

//delete func
bool DomStuList::deleteNode(std::string fName, std::string lName)
{
  DomStuPtr cur = head;
  if(head == NULL) 
  {
    //empty list, nothing to delete
    return false;
  }
  bool foundDelete = false; //has anything been deleted 
  //else we have at least 1 element 
  //first check if the first element is right
  while(head->get_fName() == fName && head->get_lName() == lName)
  {
    head = cur->get_next();
    delete cur;
    cur = head;
    foundDelete = true;
    if(head == NULL)
    //we deleted every element of the list in this way 
    {
      tail = NULL;
      return foundDelete;
    }
  }
  //check if only 1 element is left after that 
  if(head == tail)
  {
    if(head->get_fName() == fName && head->get_lName() == lName)
    //one entry and its true
    {
      delete head;
      head = NULL;
      tail = NULL;
      return true;
    }
    else
    {
    	//one entry and its wrong
    	return foundDelete;
    }
  }
  //general case, theres at least 2 students left and the head is not to be deleted
  DomStuPtr behind = head;
  cur = head->get_next(); //move cur 1 up
  while(cur != NULL)
  {
    if(cur->get_fName() == fName && cur->get_lName() == lName)
    {
      //we've found a match, delete it
      behind->set_next(cur->get_next());
      DomStuPtr toDelete = cur;
      cur = cur->get_next();
      delete toDelete;
      foundDelete = true; //we've deleted at least one thing
    }
    else
    {
    	//the current element is not a match
    	cur = cur->get_next();
    	behind = behind->get_next();
    }
  }
  return foundDelete; //if false, didnt delete anything 
}

 //delete ends func
bool DomStuList::deleteEnds()//delete head and tail 
{
  if(head == NULL)
  //empty list
  {
    return false;
  }
  if(head == tail)
  //single element list
  {
    delete head;
    head = NULL;
    tail = NULL;
    return true;
  }
  if(head->get_next() == tail)
  //2 element list
  {
    delete head;
    delete tail;
    head = NULL;
    tail = NULL;
    return true;
  }
  //else at least 3 elements
  DomStuPtr first = head;
  DomStuPtr last = tail;
  DomStuPtr cur = head;
  while(cur->get_next() != tail)
  {
    cur = cur->get_next();
  }
  //now cur is the element right before tail
  head = head->get_next();
  tail = cur;
  cur->set_next(NULL);
  delete first;
  delete last;
  return true;
}

 //overloaded << op
std::ostream& operator <<(std::ostream& outs, const DomStuList &DST)
{
  DomStuPtr cur = DST.get_head();
  if(cur == NULL) //empty list
  {
    outs << "This is an empty list.\n";
    return outs;
  }
  //else we have at least 1 student, get a header 
  std::cout << "Student ID | First Name | Last Name | CGPA | Research Score | Province\n";
  while(cur != NULL)
  {
    //outs << std::left << setw(7) << cur;
    outs << *cur; //might need fixing based on overloaded << op for dom stu
    cur = cur->get_next();
  }
  return outs;
}
//overloaded assignment op 
DomStuList& DomStuList::operator =(const DomStuList& DST)
{
  head = NULL;
  tail = NULL;
  DomStuPtr cur = DST.get_head(); //get head of DST to copy from
  while(cur != NULL)
  {
    //insert each student from DST to this
    ////Part 2 #5////
    DomStuPtr insertee = NULL;
    try{
      insertee = new DomesticStudent;
    }
    catch(std::bad_alloc& ex)
    {
      std::cout << "Error(5): Out of memory!";
      std::exit(5);
    }
    insertee->set_allStuID(cur->get_fName(), cur->get_lName(), cur->get_CGPA(), cur->get_rsScore(), cur->get_appID());
    insertee->set_province(cur->get_province());
    this->insertNode(insertee);
    cur = cur->get_next();
  }
  return *this;
}

DomStuPtr DomStuList::get_head() const
{
  return head;
}
DomStuPtr DomStuList::get_tail() const
{
  return tail;
}


//END FOR DOM STU LIST 
//===================================================================================================================================

//int student list: 

//constructors:
//empty init
IntStuList::IntStuList()
{
  head = NULL;
  tail = NULL;
  return;
}
//full init
IntStuList::IntStuList(std::string fName, std::string lName, std::string nation, float gpa, int rsScore, ToeflScore toefl_score, int id)
{
  ////Part 2 #5////
  IntStuPtr start = NULL;
  try{
    start = new InternationalStudent(fName, lName, nation, gpa, rsScore, toefl_score, id);
  }
  catch(std::bad_alloc& ex)
  {
    std::cout << "Error(5): Out of memory!";
    std::exit(5);
  }
  head = start;
  tail = start;
  return;
}
//copy constructors
IntStuList::IntStuList(const IntStuList& IST)
{
  this->head = NULL;
  this->tail = NULL;
  IntStuPtr cur = IST.get_head(); //get head of DST to copy from
  while(cur != NULL)
  {
    //copy each student from DST to this
    ////Part 2 #5////
    IntStuPtr insertee = NULL;
    try{
      insertee = new InternationalStudent;
    }
    catch(std::bad_alloc& ex)
    {
      std::cout << "Error(5): Out of memory!";
      std::exit(5);
    }
    insertee->set_allStuID(cur->get_fName(), cur->get_lName(), cur->get_CGPA(), cur->get_rsScore(), cur->get_appID());
    insertee->set_country(cur->get_country());
    insertee->set_toeflScore(cur->get_toeflScore());
    this->insertNode(insertee);
    cur = cur->get_next();
  }
  return;
}
//destructor 
IntStuList::~IntStuList()
{
  if(head == NULL)
  {
    //empty list, can return 
    return;
  }
  if(head == tail)
  {
    //only 1 node 
    delete head;
    return;
  }
  //else we have > 1 node 
  IntStuPtr cur = head;
  IntStuPtr behind = head;
  cur = cur->get_next();
  while(cur != NULL)
  {
    delete behind;
    behind = cur;
    cur = cur->get_next();
  }
  //then once this loop ends, all the elements have been deleted bc cur = null and behind = the last element of the list at that pt 
  //clean up any potential issues with the head and tail pointers just in case
  head = NULL;
  tail = NULL;
  return;
}

//required funcs
//search funcs:
//app id
void IntStuList::searchAppID(int ID)
{
  IntStuList returnee = IntStuList();
  IntStuPtr cur = head;
  while(cur != NULL)
  {
    if(cur->get_appID() == ID)//check if current item has correct gpa
      {
      //if so, we create a copy of it and add it to a new list that holds all matches
      ////Part 2 #5////
      IntStuPtr temp = NULL;
      try{
        temp = new InternationalStudent;
      }
      catch(std::bad_alloc& ex)
      {
        std::cout << "Error(5): Out of memory!";
        std::exit(5);
      }
      temp->set_allStuID(cur->get_fName(), cur->get_lName(), cur->get_CGPA(), cur->get_rsScore(), cur->get_appID());
      temp->set_country(cur->get_country());
      temp->set_toeflScore(cur->get_toeflScore());
      returnee.insertNode(temp);
      
      }      
      cur = cur->get_next();
    }
   //once we're here, we have our list of matches
  //note that if nothing matches, we get a null list
  std::cout << returnee;
}

//cgpa
void IntStuList::searchCGPA(float gpa)
{
  IntStuList returnee = IntStuList();
  IntStuPtr cur = head;
  while(cur != NULL)
  {
    if(cur->get_CGPA() == gpa)//check if current item has correct gpa
      {
      //if so, we create a copy of it and add it to a new list that holds all matches
      ////Part 2 #5////
      IntStuPtr temp = NULL;
      try{
        temp = new InternationalStudent;
      }
      catch(std::bad_alloc& ex)
      {
        std::cout << "Error(5): Out of memory!";
        std::exit(5);
      }
      ToeflScore toeflTemp;
      toeflTemp = cur->get_toeflScore();
      temp->set_allStuID(cur->get_fName(), cur->get_lName(), cur->get_CGPA(), cur->get_rsScore(), cur->get_appID());
      temp->set_country(cur->get_country());
      temp->set_toeflScore(toeflTemp);
      returnee.insertNode(temp);
      
      }      
      cur = cur->get_next();
    }
   //once we're here, we have our list of matches
  //note that if nothing matches, we get a null list
  std::cout << returnee;
}
//research score 
void IntStuList::searchRSScore(int score)
{
  IntStuList returnee = IntStuList();
  IntStuPtr cur = head;
  while(cur != NULL)
  {
    if(cur->get_rsScore() == score)//check if current item has correct gpa
      {
      //if so, we create a copy of it and add it to a new list that holds all matches
      ////Part 2 #5////
      IntStuPtr temp = NULL;
      try{
        temp = new InternationalStudent;
      }
      catch(std::bad_alloc& ex)
      {
        std::cout << "Error(5): Out of memory!";
        std::exit(5);
      }
      ToeflScore toeflTemp;
      toeflTemp = cur->get_toeflScore();
      temp->set_allStuID(cur->get_fName(), cur->get_lName(), cur->get_CGPA(), cur->get_rsScore(), cur->get_appID());
      temp->set_country(cur->get_country());
      temp->set_toeflScore(toeflTemp);
      returnee.insertNode(temp);
      
      }      
      cur = cur->get_next();
    }
   //once we're here, we have our list of matches
  //note that if nothing matches, we get a null list
  std::cout << returnee;
}
//fname and lname 
void IntStuList::searchNames(std::string fName, std::string lName)
{
  IntStuList returnee = IntStuList();
  IntStuPtr cur = head;
  while(cur != NULL)
  {
    if(cur->get_fName() == fName && cur->get_lName() == lName)//check if current item has correct gpa
      {
      //if so, we create a copy of it and add it to a new list that holds all matches
      ////Part 2 #5////
      IntStuPtr temp = NULL;
      try{
        temp = new InternationalStudent;
      }
      catch(std::bad_alloc& ex)
      {
        std::cout << "Error(5): Out of memory!";
        std::exit(5);
      }
      ToeflScore toeflTemp;
      toeflTemp = cur->get_toeflScore();
      temp->set_allStuID(cur->get_fName(), cur->get_lName(), cur->get_CGPA(), cur->get_rsScore(), cur->get_appID());
      temp->set_country(cur->get_country());
      temp->set_toeflScore(toeflTemp);
      returnee.insertNode(temp);
      }      
      cur = cur->get_next();
    }
   //once we're here, we have our list of matches
  //note that if nothing matches, we get a null list
  std::cout << returnee;
}

//Threholdsearch
void IntStuList::searchThreshold(float CGPA_Threshold, int Research_Threshold)
{
  IntStuList returnee = IntStuList();
  IntStuPtr cur = head;
  while(cur != NULL)
  {
    if(cur->get_CGPA() >= CGPA_Threshold && cur->get_rsScore() >= Research_Threshold)
    {
      ////Part 2 #5////
      IntStuPtr temp = NULL;
      try{
        temp = new InternationalStudent;
      }
      catch(std::bad_alloc& ex)
      {
        std::cout << "Error(5): Out of memory!";
        std::exit(5);
      }
      ToeflScore toeflTemp;
      toeflTemp = cur->get_toeflScore();
      temp->set_allStuID(cur->get_fName(), cur->get_lName(), cur->get_CGPA(), cur->get_rsScore(), cur->get_appID());
      temp->set_country(cur->get_country());
      temp->set_toeflScore(toeflTemp);
      returnee.insertNode(temp);
    }      
    cur = cur->get_next();
  }
  std::cout << returnee;
}

//Head and Tail
void IntStuList::GetHeadandTail(int type)
{
  if(type == 1) {
    IntStuList returnee = IntStuList();
    IntStuPtr cur = get_head();
  
    std::cout << "Head:\n";
    ////Part 2 #5////
    IntStuPtr temp = NULL;
    try{
      temp = new InternationalStudent;
    }
    catch(std::bad_alloc& ex) {
      std::cout << "Error(5): Out of memory!";
      std::exit(5);
    }
    
    ToeflScore toeflTemp;
    toeflTemp = cur->get_toeflScore();
    temp->set_allStuID(cur->get_fName(), cur->get_lName(), cur->get_CGPA(), cur->get_rsScore(), cur->get_appID());
    temp->set_country(cur->get_country());
    temp->set_toeflScore(toeflTemp);
    returnee.insertNode(temp);     
    cur = cur->get_next();
    std::cout << returnee;
  }
  else {
    IntStuList returnee = IntStuList();
    IntStuPtr cur = get_tail();
  
    std::cout << "Tail:\n";
    ////Part 2 #5////
    IntStuPtr temp = NULL;
    try{
      temp = new InternationalStudent;
    }
    catch(std::bad_alloc& ex) {
      std::cout << "Error(5): Out of memory!";
      std::exit(5);
    }
    
    ToeflScore toeflTemp;
    toeflTemp = cur->get_toeflScore();
    temp->set_allStuID(cur->get_fName(), cur->get_lName(), cur->get_CGPA(), cur->get_rsScore(), cur->get_appID());
    temp->set_country(cur->get_country());
    temp->set_toeflScore(toeflTemp);
    returnee.insertNode(temp);     
    cur = cur->get_next();
    std::cout << returnee;
  }

}


//MultiSearch
void IntStuList::multiSearch(bool nameEnable, std::string fName, std::string lName, bool idEnable, int ID, bool gpaEnable, float gpa, bool scoreEnable, int score)
{
  IntStuList returnee;
  IntStuPtr cur = head;
  if(!nameEnable && !idEnable && !gpaEnable && !scoreEnable)
  {
    std::cout << "No filters selected, please try again.";
    return;
  }
  else if(nameEnable)
  {
    if(idEnable)
    {
      if(gpaEnable)
      {
        if(scoreEnable)
        {
          while(cur != NULL)
          {
            if(cur->get_fName() == fName && cur->get_lName() == lName && cur->get_appID() == ID && cur->get_CGPA() == gpa && cur->get_rsScore() == score)
            {
              ////Part 2 #5////
              IntStuPtr temp = NULL;
              try{
                temp = new InternationalStudent;
              }
              catch(std::bad_alloc& ex)
              {
                std::cout << "Error(5): Out of memory!";
                std::exit(5);
              }
              ToeflScore toeflTemp;
              toeflTemp = cur->get_toeflScore();
              temp->set_allStuID(cur->get_fName(), cur->get_lName(), cur->get_CGPA(), cur->get_rsScore(), cur->get_appID());
              temp->set_country(cur->get_country());
              temp->set_toeflScore(toeflTemp);
              returnee.insertNode(temp);
            }      
            cur = cur->get_next();
          }
          std::cout << returnee;
          return;
        }//name id gpa score
        else
        {
          while(cur != NULL)
          {
            if(cur->get_fName() == fName && cur->get_lName() == lName && cur->get_appID() == ID && cur->get_CGPA() == gpa)
            {
              ////Part 2 #5////
              IntStuPtr temp = NULL;
              try{
                temp = new InternationalStudent;
              }
              catch(std::bad_alloc& ex)
              {
                std::cout << "Error(5): Out of memory!";
                std::exit(5);
              }
              ToeflScore toeflTemp;
              toeflTemp = cur->get_toeflScore();
              temp->set_allStuID(cur->get_fName(), cur->get_lName(), cur->get_CGPA(), cur->get_rsScore(), cur->get_appID());
              temp->set_country(cur->get_country());
              temp->set_toeflScore(toeflTemp);
              returnee.insertNode(temp);
            }      
            cur = cur->get_next();
          }
          std::cout << returnee;
          return;
        }//name id gpa
      }//gpa in id end 
      else if(scoreEnable)
      {
        while(cur != NULL)
        {
          if(cur->get_fName() == fName && cur->get_lName() == lName && cur->get_appID() == ID && cur->get_rsScore() == score)
          {
            ////Part 2 #5////
            IntStuPtr temp = NULL;
            try{
              temp = new InternationalStudent;
            }
            catch(std::bad_alloc& ex)
            {
              std::cout << "Error(5): Out of memory!";
              std::exit(5);
            }
            ToeflScore toeflTemp;
            toeflTemp = cur->get_toeflScore();
            temp->set_allStuID(cur->get_fName(), cur->get_lName(), cur->get_CGPA(), cur->get_rsScore(), cur->get_appID());
            temp->set_country(cur->get_country());
            temp->set_toeflScore(toeflTemp);
            returnee.insertNode(temp);
          }      
          cur = cur->get_next();
        }
        std::cout << returnee;
        return;
      }//name id score
      else
      {
        while(cur != NULL)
        {
          if(cur->get_fName() == fName && cur->get_lName() == lName && cur->get_appID() == ID)
          {
            ////Part 2 #5////
            IntStuPtr temp = NULL;
            try{
              temp = new InternationalStudent;
            }
            catch(std::bad_alloc& ex)
            {
              std::cout << "Error(5): Out of memory!";
              std::exit(5);
            }
            ToeflScore toeflTemp;
            toeflTemp = cur->get_toeflScore();
            temp->set_allStuID(cur->get_fName(), cur->get_lName(), cur->get_CGPA(), cur->get_rsScore(), cur->get_appID());
            temp->set_country(cur->get_country());
            temp->set_toeflScore(toeflTemp);
            returnee.insertNode(temp);
          }      
          cur = cur->get_next();
        }
        std::cout << returnee;
        return;
      }//name id
    }//id in name end 
    else if(gpaEnable)
    {
      if(scoreEnable)
      {
        while(cur != NULL)
        {
          if(cur->get_fName() == fName && cur->get_lName() == lName && cur->get_CGPA() == gpa && cur->get_rsScore() == score)
          {
            ////Part 2 #5////
            IntStuPtr temp = NULL;
            try{
              temp = new InternationalStudent;
            }
            catch(std::bad_alloc& ex)
            {
              std::cout << "Error(5): Out of memory!";
              std::exit(5);
            }
            ToeflScore toeflTemp;
            toeflTemp = cur->get_toeflScore();
            temp->set_allStuID(cur->get_fName(), cur->get_lName(), cur->get_CGPA(), cur->get_rsScore(), cur->get_appID());
            temp->set_country(cur->get_country());
            temp->set_toeflScore(toeflTemp);
            returnee.insertNode(temp);
          }      
          cur = cur->get_next();
        }
        std::cout << returnee;
        return;
      }//name gpa score
      else
      {
        while(cur != NULL)
        {
          if(cur->get_fName() == fName && cur->get_lName() == lName && cur->get_CGPA() == gpa)
          {
            ////Part 2 #5////
            IntStuPtr temp = NULL;
            try{
              temp = new InternationalStudent;
            }
            catch(std::bad_alloc& ex)
            {
              std::cout << "Error(5): Out of memory!";
              std::exit(5);
            }
            ToeflScore toeflTemp;
            toeflTemp = cur->get_toeflScore();
            temp->set_allStuID(cur->get_fName(), cur->get_lName(), cur->get_CGPA(), cur->get_rsScore(), cur->get_appID());
            temp->set_country(cur->get_country());
            temp->set_toeflScore(toeflTemp);
            returnee.insertNode(temp);
          }      
          cur = cur->get_next();
        }
        std::cout << returnee;
        return;
      }//name gpa
    }//end gpa in name
    else if(scoreEnable)
    {
      while(cur != NULL)
      {
        if(cur->get_fName() == fName && cur->get_lName() == lName && cur->get_rsScore() == score)
        {
          ////Part 2 #5////
          IntStuPtr temp = NULL;
          try{
            temp = new InternationalStudent;
          }
            catch(std::bad_alloc& ex)
          {
            std::cout << "Error(5): Out of memory!";
            std::exit(5);
          }
          ToeflScore toeflTemp;
          toeflTemp = cur->get_toeflScore();
          temp->set_allStuID(cur->get_fName(), cur->get_lName(), cur->get_CGPA(), cur->get_rsScore(), cur->get_appID());
          temp->set_country(cur->get_country());
          temp->set_toeflScore(toeflTemp);
          returnee.insertNode(temp);
        }     
        cur = cur->get_next();
      }
      std::cout << returnee;
      return;
    }//name score
    else
    {
      this->searchNames(fName,lName);
      return;
    }
  }//end names 
  else if(idEnable)
  {
    if(gpaEnable)
    {
      if(scoreEnable)
      {
      while(cur != NULL)
      {
        if(cur->get_appID() == ID && cur->get_CGPA() == gpa && cur->get_rsScore() == score)
        {
          ////Part 2 #5////
          IntStuPtr temp = NULL;
          try{
            temp = new InternationalStudent;
          }
          catch(std::bad_alloc& ex)
          {
            std::cout << "Error(5): Out of memory!";
            std::exit(5);
          }
          ToeflScore toeflTemp;
          toeflTemp = cur->get_toeflScore();
          temp->set_allStuID(cur->get_fName(), cur->get_lName(), cur->get_CGPA(), cur->get_rsScore(), cur->get_appID());
          temp->set_country(cur->get_country());
          temp->set_toeflScore(toeflTemp);
          returnee.insertNode(temp);
        }      
        cur = cur->get_next();
      }
      std::cout << returnee;
      return;
      }//id gpa score
      else
      {
        while(cur != NULL)
        {
          if(cur->get_appID() == ID && cur->get_CGPA() == gpa)
          {
            ////Part 2 #5////
            IntStuPtr temp = NULL;
            try{
              temp = new InternationalStudent;
            }     
            catch(std::bad_alloc& ex)
            {
              std::cout << "Error(5): Out of memory!";
              std::exit(5);
            }
            ToeflScore toeflTemp;
            toeflTemp = cur->get_toeflScore();
            temp->set_allStuID(cur->get_fName(), cur->get_lName(), cur->get_CGPA(), cur->get_rsScore(), cur->get_appID());
            temp->set_country(cur->get_country());
            temp->set_toeflScore(toeflTemp);
            returnee.insertNode(temp);
          }      
          cur = cur->get_next();
        }
        std::cout << returnee;
        return;
      }//id gpa
    }
    else if(scoreEnable)
    {
      while(cur != NULL)
      {
        if(cur->get_appID() == ID && cur->get_rsScore() == score)
        {
          ////Part 2 #5////
          IntStuPtr temp = NULL;
          try{ 
            temp = new InternationalStudent;
          }
          catch(std::bad_alloc& ex)
          {
            std::cout << "Error(5): Out of memory!";
            std::exit(5);
          }
          ToeflScore toeflTemp;
          toeflTemp = cur->get_toeflScore();
          temp->set_allStuID(cur->get_fName(), cur->get_lName(), cur->get_CGPA(), cur->get_rsScore(), cur->get_appID());
          temp->set_country(cur->get_country());
          temp->set_toeflScore(toeflTemp);
          returnee.insertNode(temp);
        }      
        cur = cur->get_next();
      }
      std::cout << returnee;
      return;
    }//id score
    else
    {
      this->searchAppID(ID);
      return;
    }
  }//end id
  else if(gpaEnable)
  {
    if(scoreEnable)
    {
      while(cur != NULL)
      {
        if(cur->get_CGPA() == gpa && cur->get_rsScore() == score)
        {
          ////Part 2 #5////
          IntStuPtr temp = NULL;
          try{
            temp = new InternationalStudent;
          }
          catch(std::bad_alloc& ex)
          {
            std::cout << "Error(5): Out of memory!";
            std::exit(5);
          }
          ToeflScore toeflTemp;
          toeflTemp = cur->get_toeflScore();
          temp->set_allStuID(cur->get_fName(), cur->get_lName(), cur->get_CGPA(), cur->get_rsScore(), cur->get_appID());
          temp->set_country(cur->get_country());
          temp->set_toeflScore(toeflTemp);
          returnee.insertNode(temp);
        }      
        cur = cur->get_next();
      }
      std::cout << returnee;
      return;
    }
    else
    {
      this->searchCGPA(gpa);
      return;
    }
  }//end gpa
  else if(scoreEnable)//only score selected
  {
    this->searchRSScore(score);
    return;
  }
  else
  {
    std::cout << "Critical error with multi-search function, please try again.";
    std::exit(-1);
  }
}


  //multi search func
  void multiSearch(bool nameEnable, std::string fName, std::string lName, bool idEnable, int ID, bool gpaEnable, float gpa, bool scoreEnable, int score);


    //O(N)
  void multiSearch(bool nameEnable, std::string fName, std::string lName, bool idEnable, int ID, bool gpaEnable, float gpa, bool scoreEnable, int score);

//insert func
bool IntStuList::insertNode(IntStuPtr insertee)
{
  if (head == NULL)
  {
    head = insertee;
    tail = insertee;
    return true;
  }
  if(!insertee->validToefl())
  {
    this->insertBack(insertee);
    return true;
  }
  ////Part 2 #5////
  IntStuPtr dummy_head = NULL;
  try{
    dummy_head = new InternationalStudent;
  }
  catch(std::bad_alloc& ex)
  {
    std::cout << "Error(5): Out of memory!";
    std::exit(5);
  }
  //get a head to put before the real head
  dummy_head->set_next(head);
  IntStuPtr cur = dummy_head;
  while (cur->get_next() != NULL) 
  {
    if (insertee->get_rsScore() > cur->get_next()->get_rsScore()) 
    //note that as the list is always sorted, we can do checks like this
    {
      insertee->set_next(cur->get_next());
      cur->set_next(insertee);
      break;
    } 
    else if(insertee->get_rsScore() == cur->get_next()->get_rsScore())
    {
      //research scores match, now we need to find what to sort on next
      if(insertee->get_CGPA() > cur->get_next()->get_CGPA())
      {
        insertee->set_next(cur->get_next());
        cur->set_next(insertee);
        break;
      }
      else if(insertee->get_CGPA() == cur->get_next()->get_CGPA())
      {
        //rs score and cgpa match, last condition is province 
        //note that these must be in ascending order
        if(insertee->get_country() < cur->get_next()->get_country() && insertee->get_CGPA() == cur->get_next()->get_CGPA())
        {
          insertee->set_next(cur->get_next());
          cur->set_next(insertee);
          break;
        }
        else if(insertee->get_country() > cur->get_next()->get_country() && insertee->get_CGPA() == cur->get_next()->get_CGPA())
        {
          cur = cur->get_next();
        }
        else
        {
          insertee->set_next(cur->get_next());
          cur->set_next(insertee);
          break;
        }
      }//end for nested loops within cgpa sorter
      else
      {
        if(cur->get_next()->get_rsScore() < insertee->get_rsScore())
        {//check if we've hit the end of the people with the same rs score
          insertee->set_next(cur->get_next());
          cur->set_next(insertee);
          break;
        }
        else
        {
          cur = cur->get_next();
        }
      }
    }//end for nested loops
    else 
    {
      cur = cur->get_next();
    }
  }
  if (cur->get_next() == NULL)
  {
    cur->set_next(insertee);
    tail = insertee;
  }
  head = dummy_head->get_next();
  delete dummy_head;
  return true;
}
//delete func
bool IntStuList::deleteNode(std::string fName, std::string lName)
{
  IntStuPtr cur = head;
  if(head == NULL) 
  {
    //empty list, nothing to delete
    return false;
  }
  bool foundDelete = false; //has anything been deleted 
  //else we have at least 1 element 
  //first check if the first element is right
  while(head->get_fName() == fName && head->get_lName() == lName)
  {
    head = cur->get_next();
    delete cur;
    cur = head;
    foundDelete = true;
    if(head == NULL)
    //we deleted every element of the list in this way 
    {
      tail = NULL;
      return foundDelete;
    }
  }
  //check if only 1 element is in list now
  //note that this works both if we've already deleted some number of heads, and if we havent
  if(head == tail)
  {
    if(head->get_fName() == fName && head->get_lName() == lName)
    //one entry and its true
    {
      delete head;
      head = NULL;
      tail = NULL;
      return true;
    }
    else
    {
      //one entry and its wrong
      return foundDelete;
    }
  }
  //general case, theres at least 2 students left and the head is not to be deleted
  IntStuPtr behind = head;
  cur = head->get_next(); //move cur 1 up
  while(cur != NULL)
  {
    if(cur->get_fName() == fName && cur->get_lName() == lName)
    {
      //we've found a match, delete it
      behind->set_next(cur->get_next());
      IntStuPtr toDelete = cur;
      cur = cur->get_next();
      delete toDelete;
      foundDelete = true; //we've deleted at least one thing
    }
    else
    {
    	//the current element is not a match
    	cur = cur->get_next();
    	behind = behind->get_next();
    }
  }
  return foundDelete; //if false, didnt delete anything 
}
//delete ends func
bool IntStuList::deleteEnds()//delete head and tail 
{
  if(head == NULL)
  //empty list
  {
    return false;
  }
  if(head == tail)
  //single element list
  {
    delete head;
    head = NULL;
    tail = NULL;
    return true;
  }
  if(head->get_next() == tail)
  //2 element list
  {
    delete head;
    delete tail;
    head = NULL;
    tail = NULL;
    return true;
  }
  //else at least 3 elements
  IntStuPtr first = head;
  IntStuPtr last = tail;
  IntStuPtr cur = head;
  while(cur->get_next() != tail)
  {
    cur = cur->get_next();
  }
  //now cur is the element right before tail
  head = head->get_next();
  tail = cur;
  cur->set_next(NULL);
  delete first;
  delete last;
  return true;
}

//overloaded << op
std::ostream& operator <<(std::ostream& outs, const IntStuList &IST)
{
  IntStuPtr cur = IST.get_head();
  if(cur == NULL) //empty list
  {
    outs << "This is an empty list.\n";
    return outs;
  }
  //check head toefl validity 
  if(!cur->validToefl())
  {
    outs << "This list has a student with an invalid TOEFL score\n";
    return outs;
  }
  //else we have at least 1 student, get a header 
  std::cout << "Student ID |  First Name  |  Last Name  |  CGPA  |  Research Score  |  Country  |   TOEFL / R / L / S / W \n";
  while(cur != NULL)
  {
    if(!cur->validToefl())
    {
      break;
    }
    outs << *cur; //might need fixing based on overloaded << op for int stu
    cur = cur->get_next();
  }
  return outs;
}
//overloaded assignment op 
IntStuList& IntStuList::operator =(const IntStuList& IST)
{
  head = NULL;
  tail = NULL;
  IntStuPtr cur = IST.get_head(); //get head of DST to copy from
  while(cur != NULL)
  {
    //copy each student from DST to this
    ////Part 2 #5////
    IntStuPtr insertee = NULL;
    try{
      insertee = new InternationalStudent;     
    }
    catch(std::bad_alloc& ex)
    {
      std::cout << "Error(5): Out of memory!";
      std::exit(5);
    }
    insertee->set_allStuID(cur->get_fName(), cur->get_lName(), cur->get_CGPA(), cur->get_rsScore(), cur->get_appID());
    insertee->set_country(cur->get_country());
    insertee->set_toeflScore(cur->get_toeflScore());
    this->insertNode(insertee);
    cur = cur->get_next();
  }
  return *this;
}

//get ends func
IntStuPtr IntStuList::get_head() const
{
  return head;
}
IntStuPtr IntStuList::get_tail() const
{
  return tail;
}

void IntStuList::insertBack(IntStuPtr insertee)
{
  IntStuPtr lead = tail;
  if(tail == NULL)//empty list
  {
    head = insertee;
    tail = insertee;
    return;
  }
  else//non-empty list 
  {
    tail->set_next(insertee);
    tail = insertee;
    return;
  }
}
