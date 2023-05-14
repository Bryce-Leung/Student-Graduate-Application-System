#include <iostream>
#include <string>
#include <iomanip>
#include <cmath>
#include <set>

#include "mergedStudent.hpp"

  ////Constructors////
  MergedStudent::MergedStudent()
  {
    CGPA = 999;
	  ResearchScore = 999;
	  AppID = 999;
    ToeflScore = 999;
    RScore = 999;
    LScore = 999;
    SScore = 999;
    WScore = 999;
    Province = "n/a";
    Country = "n/a";
	  FirstName = "n/a";
	  LastName = "n/a";
    next = NULL;
  }

  MergedStudent::MergedStudent(std::string FName, std::string LName, int ID, int RS, float CGPAscore)
  {
    CGPA = CGPAscore;
	  ResearchScore = RS;
	  AppID = ID;
	  FirstName = FName;
	  LastName = LName;
    ToeflScore = 999;
    RScore = 999;
    LScore = 999;
    SScore = 999;
    WScore = 999;
    Province = "n/a";
    Country = "n/a";
    next = NULL;
  }


  /////Getter Functions/////
  std::string MergedStudent::get_Province() const
  {
    return Province;
  }

  std::string MergedStudent::get_Country() const
  {
    return Country;
  }

  std::string MergedStudent::get_FirstName() const
  {
    return FirstName;
  }
  
  std::string MergedStudent::get_LastName() const
  {
    return LastName;
  }

  float MergedStudent::get_CGPA() const
  {
    return CGPA;
  }

  int MergedStudent::get_ResearchScore() const
  {
    return ResearchScore;
  }

  int MergedStudent::get_AppID() const
  {
    return AppID;
  }

  int MergedStudent::get_ToeflScore() const
  {
    return ToeflScore;
  }
  
  int MergedStudent::get_RScore() const
  {
    return RScore;
  }

  int MergedStudent::get_LScore() const
  {
    return LScore;
  }

  int MergedStudent::get_SScore() const
  {
    return SScore;
  }

  int MergedStudent::get_WScore() const
  {
    return WScore;
  }

  MergePtr MergedStudent::get_next() const
  {
	  return next;
  }


  /////Setter Functions/////
  void MergedStudent::set_Province(std::string insertProvince)
  {
    Province = insertProvince;
  }

  void MergedStudent::set_Country(std::string insertCountry)
  {
    Country = insertCountry;
  }

  void MergedStudent::set_FirstName(std::string insertFirstName)
  {
    FirstName = insertFirstName;
  }

  void MergedStudent::set_LastName(std::string insertLastName)
  {
    LastName = insertLastName;
  }

  void MergedStudent::set_CGPA(float insertedCGPA)
  {
    CGPA = insertedCGPA;
  }

  void MergedStudent::set_ResearchScore(int insertedScore)
  {
    ResearchScore = insertedScore;
  }

  void MergedStudent::set_AppID(int insertedID)
  {
    AppID = insertedID;
  }

  void MergedStudent::set_ToeflScore(int insertedScore)
  {
    ToeflScore = insertedScore;
  }
  
  void MergedStudent::set_RScore(int inRScore)
  {
    RScore = inRScore;
  }

  void MergedStudent::set_LScore(int inLScore)
  {
    LScore = inLScore;
  }

  void MergedStudent::set_SScore(int inSScore)
  {
    SScore = inSScore;
  }

  void MergedStudent::set_WScore(int inWScore)
  {
    WScore = inWScore;
  }

  void MergedStudent::set_next(MergedStudent* _next)
  {
	  next = _next;
  }

  ////Virtual print function base////
  void MergedStudent::printer()
  {
    std::cout << "-------------------------------------------------------n/a-------------------------------------------------------" << std::endl;
  }


//////////Domestic Child Class/////////
////Constructor functions////
Domestic::Domestic()
{
  
}

Domestic::Domestic(std::string FName, std::string LName, std::string Prov, int ID, int RS, float CGPAscore)
{
  set_CGPA(CGPAscore) ;
  set_ResearchScore(RS);
  set_AppID(ID);
  set_Province(Prov);
  set_FirstName(FName);
  set_LastName(LName);
  set_next(NULL);
  set_Country("empty");
}

////Virtual print function Domesitc child class////
void Domestic::printer()
{
  std::cout << std::setw(10) << std::left << "DOM" << std::setw(13) << std::left << get_AppID() << std::setw(17) << std::left << get_FirstName() << std::setw(16) << std::left << get_LastName() << std::setw(12) << std::fixed << std::showpoint << std::setprecision(1) << std::left << get_CGPA() << std::setw(15)<< std::left << get_ResearchScore() << std::setw(10) << std::left << MergedStudent::get_Province() << std::setw(9) << std::left << "n/a"<< std::left << "---------n/a---------" << std::endl;
}


/////////International Child Class//////////
////Constructor functions////
International::International()
{

}

International::International(std::string FName, std::string LName, std::string Count, int ID, int RS, float CGPAscore, int ToeflScore, int R, int L, int S, int W)
{
    set_CGPA(CGPAscore);
	  set_ResearchScore(RS);
	  set_AppID(ID);
    set_ToeflScore(ToeflScore);
    set_RScore(R);
    set_LScore(L);
    set_SScore(S);
    set_WScore(W) ;
    set_Country(Count);
	  set_FirstName(FName);
	  set_LastName(LName);
    set_next(NULL);
    set_Province("empty");
}

////Virtual print function Internation child class//// 
void International::printer()
{
  std::cout << std::setw(10) << std::left << "INT"  << std::setw(13) << std::left << get_AppID() << std::setw(17) << std::left << get_FirstName() << std::setw(16) << std::left << get_LastName() << std::setw(12) << std::fixed << std::showpoint << std::setprecision(1) << std::left << get_CGPA() << std::setw(15)<< std::left << get_ResearchScore() << std::setw(10) << std::left << "n/a" << std::setw(9) << std::left << get_Country()<< std::setw(6) << std::left << get_ToeflScore() << std::setw(4) << std::left << get_RScore() << std::setw(4) << std::left << get_LScore() << std::setw(4) << std::left << get_SScore() << std::setw(4) << std::left << get_WScore() << std::endl;
}
