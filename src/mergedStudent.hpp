#ifndef MERGEDSTUDENT_HPP
#define MERGEDSTUDENT_HPP

#include <iostream>
#include <string>

class MergedStudent
{
  public:
  //Constructors
  MergedStudent();
  MergedStudent(std::string FName, std::string LName, int ID, int RS, float CGPAscore);

  //Getter Functions
  std::string get_Province() const;
  std::string get_Country() const;
  std::string get_FirstName() const;
  std::string get_LastName() const;
  float get_CGPA() const;
  int get_ResearchScore() const;
  int get_AppID() const;
  int get_ToeflScore() const;
  int get_RScore() const;
  int get_LScore() const;
  int get_SScore() const;
  int get_WScore() const;
  MergedStudent* get_next() const;
  
  //Setter Functions
  void set_Province(std::string insertProvince);
  void set_Country(std::string insertCountry);
  void set_FirstName(std::string insertFirstName);
  void set_LastName(std::string insertLastName);
  void set_CGPA(float insertedCGPA);
  void set_ResearchScore(int insertedScore);
  void set_AppID(int insertedID);
  void set_ToeflScore(int insertedScore);
  void set_RScore(int inRScore);
  void set_LScore(int inLScore);
  void set_SScore(int inSScore);
  void set_WScore(int inWScore);
  void set_next(MergedStudent* _next);

  //Print function
  virtual void printer();

  private:
  //Private member variables
	float CGPA; 
	int ResearchScore; 
	int AppID;
  int ToeflScore;
  int RScore;
  int LScore;
  int SScore;
  int WScore;
  std::string Province;
  std::string Country;
	std::string FirstName;
	std::string LastName;
  class MergedStudent* next;
};
typedef class MergedStudent* MergePtr;


class Domestic : public MergedStudent
{
  public:
  //Constructor function
  Domestic();
  Domestic(std::string FName, std::string LName, std::string Prov, int ID, int RS, float CGPAscore);
  std::string get_Province() const;
  
  //Print function
  void printer();
  
};
typedef class Domestic* MergeDomPtr;


class International : public MergedStudent
{
  public:
  //Constructor function
  International();
  International(std::string FName, std::string LName, std::string Count, int ID, int RS, float CGPAscore, int ToeflScore, int R, int L, int S, int W);
  
  //Print function
  void printer();

};
typedef class International* MergeIntPtr;
#endif /* MERGEDSTUDENT_ */
