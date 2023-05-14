#include <iostream>
#include <cmath>
#include <string> 
#include <iomanip>
#include "merged_list.hpp" 
#include "mergedStudent.hpp"
#include "student_list.hpp"


////Constructor////
merged_list::merged_list()
{
  head = NULL;
  tail = NULL;
  return;
}


////Destructor////
merged_list::~merged_list()
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
  MergePtr cur = head;
  MergePtr behind = head;
  cur = cur->get_next();
  while(cur != NULL)
  {
    delete behind;
    behind = cur;
    cur = cur->get_next();
  }

  head = NULL;
  tail = NULL;
  return;
}


////InsertDomNode function////
bool merged_list::InsertDomNode(DomStuList& Dominput)
{
  DomStuPtr cur = Dominput.get_head();
  while(cur != NULL)
  {
      ////Part 2 #5////
      MergePtr temp = NULL;
      try{
        MergedStudent* temp = new Domestic;
      }
      catch(std::bad_alloc& ex)
      {
        std::cout << "Error(5): Out of memory!";
        std::exit(5);
      }
      temp = new Domestic(cur->get_fName(), cur->get_lName(), cur->get_province(), cur->get_appID(), cur->get_rsScore(), cur->get_CGPA());
    //MergedStudent* temp = new Domestic(cur->get_fName(), cur->get_lName(), cur->get_province(), cur->get_appID(), cur->get_rsScore(), cur->get_CGPA());
  this-> InsertNode(temp, 1);//where insert is some defined other func to insert
  cur = cur->get_next();
  }
}


bool merged_list::InsertIntNode(IntStuList& Intinput)
{
  IntStuPtr cur = Intinput.get_head();
  int i = 1;
  while(cur != NULL)
  {
      ////Part 2 #5////
      MergePtr temp = NULL;
      try{
        MergedStudent* temp = new International;
      }
      catch(std::bad_alloc& ex)
      {
        std::cout << "Error(5): Out of memory!";
        std::exit(5);
      }
      temp = new International(cur->get_fName(), cur->get_lName(), cur->get_country(), cur->get_appID(), cur->get_rsScore(), cur->get_CGPA(), cur->get_toeflScore().get_totalScore(),cur->get_toeflScore().get_rScore(),cur->get_toeflScore().get_lScore(), cur->get_toeflScore().get_sScore(), cur->get_toeflScore().get_wScore()); 

  this-> InsertNode(temp, 2);
  cur = cur->get_next();
  i++;
  }
}


//insert function
bool merged_list::InsertNode(MergePtr insertee, int type)
{
  if (head == NULL)
  {
    head = insertee;
    tail = insertee;
    return true;
  }
  ////Part 2 #5////
  MergePtr dummy_head = NULL;
  try{ 
    dummy_head = new MergedStudent;
  }
  catch(std::bad_alloc& ex)
  {
    std::cout << "Error(5): Out of memory!";
    std::exit(5);
  }
  dummy_head->set_next(head);
  MergePtr cur = dummy_head;
  while (cur->get_next() != NULL) {
    if (insertee->get_ResearchScore() > cur->get_next()->get_ResearchScore()) 
    //note that as the list is always sorted, we can do checks like this
    {
      insertee->set_next(cur->get_next());
      cur->set_next(insertee);
      break;
    } 
    else if(insertee->get_ResearchScore() == cur->get_next()->get_ResearchScore())
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
        if(type == 1 || type == 3)
        {
          if(insertee->get_Province() < cur->get_next()->get_Province() && insertee->get_CGPA() == cur->get_next()->get_CGPA())
          {
            insertee->set_next(cur->get_next());
            cur->set_next(insertee);
            break;
          }
          else if(insertee->get_Province() > cur->get_next()->get_Province() && insertee->get_CGPA() == cur->get_next()->get_CGPA())
          {
            cur = cur->get_next();
            continue;
          }
          //you'll probably need an == case as well
          else
          {
            insertee->set_next(cur->get_next());
            cur->set_next(insertee);
            break;
          }
        }
        if (type == 2 || type == 3)
        {
          if(insertee->get_Province() < cur->get_next()->get_Province() && insertee->get_CGPA() == cur->get_next()->get_CGPA())
          {
            insertee->set_next(cur->get_next());
            cur->set_next(insertee);
            break;
          }
          else if(insertee->get_Province() > cur->get_next()->get_Province() && insertee->get_CGPA() == cur->get_next()->get_CGPA())
          {
            cur = cur->get_next();
            continue;
          }
          //you'll probably need an == case as well
          else
          {
            if(insertee->get_Country() < cur->get_next()->get_Country() && insertee->get_CGPA() == cur->get_next()->get_CGPA())
            {
              insertee->set_next(cur->get_next());
              cur->set_next(insertee);
              break;
            }
            else if(insertee->get_Country() > cur->get_next()->get_Country() && insertee->get_CGPA() == cur->get_next()->get_CGPA())
            {
              cur = cur->get_next();
            }
                  //you'll probably need an == case as well
            else
            {
              insertee->set_next(cur->get_next());
              cur->set_next(insertee);
              break;
            }
          }
        }
      }//end for nested loops within cgpa sorter
      else
      {
        if(cur->get_next()->get_ResearchScore() < insertee->get_ResearchScore())
        {//check if we've hit the end of the people with the same rs score
          insertee->set_next(cur->get_next());
          cur->set_next(insertee);
          break;
        }
        else
        {
          cur = cur->get_next();
          continue;
        }
      }
    }//end for nested loops
    else 
    {
      cur = cur->get_next();
      continue;
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


//Threshold search
void merged_list::SearchThreshold(float CGPA_Threshold, int Research_Threshold)
{
  merged_list returnee = merged_list();
  MergePtr cur = head;
  while(cur != NULL)
  {
    if(cur->get_CGPA() >= CGPA_Threshold && cur->get_ResearchScore() >= Research_Threshold)
    {
      
      if(cur->get_RScore() == 999)
      {
        ////Part 2 #5////
        MergePtr temp = NULL;
        try{
          MergedStudent* temp = new Domestic;
        }
        catch(std::bad_alloc& ex)
        {
          std::cout << "Error(5): Out of memory!";
          std::exit(5);
        }
        temp = new Domestic(cur->get_FirstName(), cur->get_LastName(), cur->get_Province(), cur->get_AppID(), cur->get_ResearchScore(), cur->get_CGPA());;
        returnee.InsertNode(temp, 3);
      }
      else
      {
        ////Part 2 #5////
        MergePtr temp = NULL;
        try{
          MergedStudent* temp = new International;
        }
        catch(std::bad_alloc& ex)
        {
          std::cout << "Error(5): Out of memory!";
          std::exit(5);
        }
        temp = new International(cur->get_FirstName(), cur->get_LastName(), cur->get_Country(), cur->get_AppID(), cur->get_ResearchScore(), cur->get_CGPA(), cur->get_ToeflScore(),cur->get_RScore(),cur->get_LScore(), cur->get_SScore(), cur->get_WScore());
        returnee.InsertNode(temp, 3);
      }

    }      
    cur = cur->get_next();
  }
  std::cout << returnee;
}


std::ostream& operator <<(std::ostream& outs, const merged_list &MST)
{
  MergePtr cur = MST.get_head();
  if(cur == NULL) //empty list
  {
    outs << "This is an empty list.\n";
    return outs;
  }
  //else we have at least 1 student, get a header 
  std::cout << "Status | Student ID |   First Name   |   Last Name   | CGPA | Research Score | Province | Country | TOEFL / R / L / S / W \n";
  while(cur != NULL)
  {
    if((cur->get_RScore() >= 5 || cur->get_RScore() == 999) 
    && (cur->get_LScore() >= 5 || cur->get_LScore() == 999) 
    && (cur->get_SScore() >= 5 || cur->get_SScore() == 999) 
    && (cur->get_WScore() >= 5 || cur->get_WScore() == 999) 
    && (cur->get_ToeflScore() >= 93 || cur->get_ToeflScore() == 999))
    {
      cur->printer();
    }
    cur = cur->get_next();
  }
  return outs;
}


//Get head function
MergePtr merged_list::get_head() const
{
  return head;
}

//Get tail function
MergePtr merged_list::get_tail() const
{
  return tail;
}
