#ifndef STUDENT_HPP_
#define STUDENT_HPP_

#include <iostream>
#include <string>

class Student {
public:
	//constructor functions
	Student(); //assume name is blank and all other values are default values
	Student(std::string fName, std::string lName, float gpa, int rsScore, int id); //full init
	//POSTCONDITION: the name fields are the inputted fields, GPA and ResearchScore = inputted fields
	Student(std::string fName, std::string lName, int id); //assume gp and rsscore are 0
	//POSTCONDITION: the name fields are the inputted fields, GPA and ResearchScore = 0

	//getter functions
	std::string get_fName() const;
	std::string get_lName() const;
	float get_CGPA() const;
	int get_rsScore() const;
	int get_appID() const;

	//setter functions
	void set_fName(std::string newName);
	void set_lName(std::string newName);
  bool set_CGPA(float gpa);
	bool set_rsScore(int score);
	bool set_allStuID(std::string newFName, std::string newLName, float gpa, int rsScore, int id);

	//isValid function
	bool isValid(float GPA, int rsScore, int appID) const;

  //Compare functions
  friend char compareCGPA(const Student &stu1, const Student &stu2);
  friend char compareResearchScore(const Student &stu1, const Student &stu2);
  friend char compareFirstName(const Student &stu1, const Student &stu2);
  friend char compareLastName(const Student &stu1, const Student &stu2);

  std::string nameFormater(std::string,  int mode);

private:
  //Private member variables
	std::string FirstName;
	std::string LastName;
	float CGPA; //0 to 4.3, round off to 1 decimal place
	int ResearchScore; //0 to 100
	int AppID; //starts with 20210000, less than 10,000 applicants total
};
typedef class Student* StudentPtr;


class ToeflScore {
public:
	//constructors
	ToeflScore();
	//initializes all values to 0
	ToeflScore(int rScore, int lScore, int sScore, int wScore);
	//initializes all values to inputted values if valid, else defaults all to 0

	//overloaded << operator function;
	friend std::ostream& operator <<(std::ostream& outs, const ToeflScore& toefl);

	//getter funcs
	int get_rScore() const;
	int get_lScore() const;
	int get_sScore() const;
	int get_wScore() const;
  int get_totalScore() const;

	//setter funcs
	void set_rScore(int argumentScore);
	void set_lScore(int argumentScore);
	void set_sScore(int argumentScore);
	void set_wScore(int argumentScore);

  //overload assignment op
  ToeflScore& operator =(const ToeflScore& TScore);

private:
  //Private members
	bool Toefl_isValid(int argument) const; //checks range from 0 to 30 inclusive
	int readingScore;
	int listeningScore;
	int speakingScore;
	int writingScore;
	int totalScore;
  //link

};


class DomesticStudent : public Student {
public:
	//constructors
	DomesticStudent(); //assume name is blank and all other values are default values
	DomesticStudent(std::string fName, std::string lName, std::string prov, float gpa, int rsScore, int id); //full init
	//POSTCONDITION: the name fields are the inputted fields, GPA and ResearchScore = inputted fields
	DomesticStudent(std::string fName, std::string lName, std::string prov, int id); //assume gp and rsscore are 0
	//POSTCONDITION: the name fields are the inputted fields, GPA and ResearchScore = 0

  //setter function
	void set_province(std::string prov);
  void set_next(DomesticStudent* _next);

  //getter function
	std::string get_province() const;
  DomesticStudent* get_next() const;

  //validProvince function
	bool validProvince(std::string prov) const;

  //Overload function
  friend std::ostream& operator <<(std::ostream& outs, const DomesticStudent& ar);

  //Compare function
  friend char compareProvince(const DomesticStudent &stu1, const DomesticStudent &stu2);

private:
  //Private member
	std::string Province;
  class DomesticStudent* next;

};
typedef class DomesticStudent* DomStuPtr;

class InternationalStudent : public Student {
public:
	//constructors
	InternationalStudent(); //assume name is blank and all other values are default values
	InternationalStudent(std::string fName, std::string lName, std::string nation, float gpa, int rsScore, ToeflScore toefl_score, int id); //full init
	//POSTCONDITION: the name fields are the inputted fields, GPA and ResearchScore = inputted fields
	InternationalStudent(std::string fName, std::string lName, std::string nation, ToeflScore toefl_score, int id); //assume gpa and rsscore are 0
	//POSTCONDITION: the name fields are the inputted fields, GPA and ResearchScore = 0

	//setter functions
	void set_country(std::string nation);
	void set_toeflScore(ToeflScore toefl);
  void set_next(InternationalStudent* _next);

	//getter functions
	std::string get_country() const;
	ToeflScore get_toeflScore() const;
  ToeflScore get_totalScore() const;
  InternationalStudent* get_next() const;

	//validProvince function
	bool validCountry(std::string country) const;
  bool validToefl() const;

  //Overload function
  friend std::ostream& operator <<(std::ostream& outs, const InternationalStudent& a);

  //Compare function
  friend char compareCountry(const InternationalStudent &stu1, const InternationalStudent &stu2);

private:
  //Private members
	std::string Country;
	ToeflScore Toefl;
  //ptr to next
  class InternationalStudent* next;
};
typedef class InternationalStudent* IntStuPtr;

#endif /* STUDENT_HPP_ */
