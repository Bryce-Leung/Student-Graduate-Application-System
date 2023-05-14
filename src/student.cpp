#include "student.hpp"
#include <iostream>
#include <iomanip>
#include <cmath>
#include <string>
#include <set>


////--------------------------------------Student Class------------------------------------------////

////nameFormater function////
//Name Formater to ensure names are in the same form to allow proper sorting
std::string Student::nameFormater(std::string name, int mode=0) {
  std::string formatted_name = name;
  for (int i=0; i<formatted_name.size(); i++) {
    if (mode == 0) {
      if (i==0) {
       formatted_name[i] = ::toupper(formatted_name[i]);
      } else {
       formatted_name[i] = ::tolower(formatted_name[i]);
      }
    } else {
      formatted_name[i] = ::toupper(formatted_name[i]);
    }
  }
  return formatted_name;
}


////Student constructors////
Student::Student()
{
	//avoid using, cannot guarantee id uniqueness without arguments
	FirstName = "A";
	LastName = "A";
	CGPA = 0;
	ResearchScore = 0;
	AppID = 20210000;
	return;
}

Student::Student(std::string fName, std::string lName, float gpa, int rsScore, int id)
{
	FirstName = nameFormater(fName);
	LastName = nameFormater(lName);//can use these before the split as they take place either way

	int dummy = 0; //calling getId will immediately update the id value so we can only call it once

	if(!isValid(gpa, rsScore, id))
	{
		std::cout << "Your values are invalid, defaulting to 0 values.\n";
		CGPA = 0;
		ResearchScore = 0;
		AppID = dummy;
		return;
	}
	//else
	CGPA = floor(gpa*10+0.5)/10; //rounds to nearest tenth
	/*
	 * credit to salisbury.edu
	 * multiply input gpa by 10, then add 0.5 (e.g. gpa = 3.795, 10*cgpa = 37.95, add 0.5 = 38.45)
	 * then floor this (for above example, gpa becoes 38)
	 * this accounts for rounding up or down bc of the addition of 0.5
	 * we then divide by 10 to arrive back at the original number but now rounded off (example result is 3.8)
	 */
	ResearchScore = rsScore;
	AppID = id;
	return;
}

Student::Student(std::string fName, std::string lName, int id)
{
	FirstName = nameFormater(fName);
	LastName = nameFormater(lName);
	CGPA = 0;
	ResearchScore = 0;//can call these before the split

	int dummy = 0;//calling getId immediately updates the next value, so can only call once

	if(!isValid(0, 0, id))
	{
		std::cout << "Your values are invalid, defaulting to 0 values.\n";
		AppID = 20210000; // if we're here and isValid fails, its bc our ID is too high so we cant use dummy
		return;
	}
	AppID = id;
	return;
}

////DomesticStudent array overloaded << operator function////
std::ostream& operator << (std::ostream& outs, const DomesticStudent& ar)
{
  int i = 0;
    outs << std::setw(13) << std::left << ar.get_appID() << std::setw(13) << std::left << ar.get_fName() << std::setw(12) << std::left << ar.get_lName() << std::setw(12) << std::fixed << std::showpoint << std::setprecision(1) << std::left << ar.get_CGPA() << std::setw(15)<< std::left << ar.get_rsScore() << std::setw(12) << std::left << ar.get_province() << std::endl;
  return outs;
}


////InternationalStudent array  overloaded << operator function////
std::ostream& operator << (std::ostream& outs, const InternationalStudent& a)
{
  int i = 0;
    outs << std::setw(14) << std::left << a.get_appID() << std::setw(15) << std::left << a.get_fName() << std::setw(14) << std::left << a.get_lName() << std::setw(15) << std::left << std::fixed << std::showpoint << std::setprecision(1) << a.get_CGPA() << std::setw(14) << std::left << a.get_rsScore() << std::setw(12) << std::left << std::setw(12) << a.get_country() << std::left << std::setw(7) << a.get_toeflScore().get_totalScore() << a.get_toeflScore() << std::endl;
  return outs;
}


////Getter functions////
std::string Student::get_fName() const
{
	return FirstName;
}

std::string Student::get_lName() const
{
	return LastName;
}

float Student::get_CGPA() const
{
	return CGPA;
}

int Student::get_rsScore() const
{
	return ResearchScore;
}

int Student::get_appID() const
{
	return AppID;
}


////Setter functions////
void Student::set_fName(std::string newName)
{
	FirstName = newName;//should never fail, names dont have limitations
}

void Student::set_lName(std::string newName)
{
	LastName = newName;//should never fail, names dont have limitations
}

bool Student::set_CGPA(float gpa)
{
	if(!isValid(gpa, ResearchScore, AppID)) //only gpa could fail, the others are there only out of necessity
	{
		return false;
	}
	CGPA = floor(gpa*10+0.5)/10;
	return true;
}

bool Student::set_rsScore(int score)
{
	if(!isValid(CGPA, score, AppID))//only research score could fail, the others are there only out of necessity
	{
		return false;
	}
	ResearchScore = score;
	return true;
}

bool Student::set_allStuID(std::string newFName, std::string newLName, float gpa, int rsScore, int id)
{
	if(!isValid(gpa, rsScore, AppID))
	{
		return false; //if not valid, return false and dont change anything
	}
	//else
	FirstName = nameFormater(newFName);
	LastName = nameFormater(newLName);
	CGPA = floor(gpa*10+0.5)/10;
	ResearchScore = rsScore;
	AppID = id;
	return true;
}


////isValid function////
//Checks that the values of the GPA, Research Score, as well as ID are within the required parameters
bool Student::isValid(float GPA, int rsScore, int appID) const
{
	if(GPA > 4.33 || GPA < 0)
	{
		return false;
	}
	if(rsScore > 100 || rsScore < 0)
	{
		return false;
	}
	if(appID > 20220000 || appID < 20210000)
	{
		return false;
	}
	return true;
}


////Student friend compare functions////
//Compares the CGPA
char compareCGPA(const Student &stu1, const Student &stu2)
{
  if (stu1.CGPA < stu2.CGPA) {
    return 'L';
  }
  else if (stu1.CGPA > stu2.CGPA ){
    return 'G';
  }
  else{
    return 'E';
  }
}

//Compares the Research Score
char compareResearchScore(const Student &stu1, const Student &stu2)
{
  if (stu1.ResearchScore < stu2.ResearchScore) {
      return 'L';
  } else if (stu1.ResearchScore > stu2.ResearchScore) {
      return 'G';
  } else {
      return 'E';
  }
}

//Compares the first name of the student
char compareFirstName(const Student &stu1, const Student &stu2) {
  if (stu1.FirstName < stu2.FirstName) {
      return 'L';
  } else if (stu1.FirstName > stu2.FirstName) {
      return 'G';
  } else {
      return 'E';
  }
}

//Compares the last name of the student
char compareLastName(const Student &stu1, const Student &stu2) {
    if (stu1.LastName < stu2.LastName) {
        return 'L';
    } else if (stu1.LastName > stu2.LastName) {
        return 'G';
    } else {
        return 'E';
    }
}


////--------------------------------------Toefl Score Class------------------------------------------////

////Constructor functions////
ToeflScore::ToeflScore()
{
	readingScore = 0;
	listeningScore = 0;
	speakingScore = 0;
	writingScore = 0;
	totalScore = 0;
}

ToeflScore::ToeflScore(int rScore, int lScore, int sScore, int wScore)
{
	if(!Toefl_isValid(rScore) || !Toefl_isValid(lScore) || !Toefl_isValid(sScore) || !Toefl_isValid(wScore))
	{
		readingScore = 0;
		listeningScore = 0;
		speakingScore = 0;
		writingScore = 0;
		totalScore = 0;
	}
	//else
	readingScore = rScore;
	listeningScore = lScore;
	speakingScore = sScore;
	writingScore = wScore;
	totalScore = readingScore + listeningScore + speakingScore + writingScore;
}


//Getter funcs
int ToeflScore::get_rScore() const
{
	return readingScore;
}

int ToeflScore::get_lScore() const
{
	return listeningScore;
}

int ToeflScore::get_sScore() const
{
	return speakingScore;
}

int ToeflScore::get_wScore() const
{
	return writingScore;
}

int ToeflScore::get_totalScore() const
{
  return totalScore;
}


//Setter funcs
void ToeflScore::set_rScore(int argumentScore)
{
	if(!Toefl_isValid(argumentScore))
	{
		return;
	}
	//else
	readingScore = argumentScore;
	totalScore = readingScore + listeningScore + speakingScore + writingScore;
}

void ToeflScore::set_lScore(int argumentScore)
{
	if(!Toefl_isValid(argumentScore))
	{
		return;
	}
	//else
	listeningScore = argumentScore;
	totalScore = readingScore + listeningScore + speakingScore + writingScore;
}

void ToeflScore::set_sScore(int argumentScore)
{
	if(!Toefl_isValid(argumentScore))
	{
		return;
	}
	//else
	speakingScore = argumentScore;
	totalScore = readingScore + listeningScore + speakingScore + writingScore;
}

void ToeflScore::set_wScore(int argumentScore)
{
	if(!Toefl_isValid(argumentScore))
	{
		return;
	}
	//else
	writingScore = argumentScore;
	totalScore = readingScore + listeningScore + speakingScore + writingScore;
}

ToeflScore& ToeflScore::operator =(const ToeflScore& TScore)
{
  this->set_rScore(TScore.get_rScore());
  this->set_lScore(TScore.get_lScore());
  this->set_wScore(TScore.get_wScore());
  this->set_sScore(TScore.get_sScore());
  return *this;
}


////Toefl_isValid function////
//Checks that the scores for the Toefl score calculation are within parameters
bool ToeflScore::Toefl_isValid(int argument) const
{
	if(argument > 30 || argument < 0)
	{
		return false;
	}
	//else
	return true;
}


////Toefl Score overloaded << operator function////
std::ostream& operator <<(std::ostream& outs, const ToeflScore& toefl)
{
	outs << std::left << std::setw(4) << toefl.get_rScore() << std::left << std::setw(4) << toefl.get_lScore() << std::left << std::setw(4) << toefl.get_sScore() << std::left << std::setw(4) << toefl.get_wScore();
	return outs;
}


////---------------------------------------Domestic Student Child Class-------------------------------------------////

////Constructor functions////
DomesticStudent::DomesticStudent() : Student() //assume name is blank and all other values are default values
{
	Province = "BC"; // change if need be for the advanced error checking part
	next = NULL;
	return;
}

DomesticStudent::DomesticStudent(std::string fName, std::string lName, std::string prov, float gpa, int rsScore, int id) : Student(fName, lName, gpa, rsScore, id)
//PRECONDTION: inthpp has been included and a global instance of it has been declared and passed in
//POSTCONDITION: the name fields are the inputted fields, GPA and ResearchScore = inputted fields
{
  //(part 2 #3) Error message and exit
  Province = nameFormater(prov, 1);
	if(!validProvince(Province)){
    std::cout << "\nError(3): Invalid province name: " << Province << " within file" << std::endl;
    std::exit(3);
	}
	next = NULL;
	return;
}

DomesticStudent::DomesticStudent(std::string fName, std::string lName, std::string prov, int id)
: Student(fName, lName, id)
//assume gp and rsscore are 0
//PRECONDTION: inthpp has been included and a global instance of it has been declared and passed in
//POSTCONDITION: the name fields are the inputted fields, GPA and ResearchScore = 0
{
	//(Part 2 #3) Error message and exit
  Province = nameFormater(prov, 1);
	if(!validProvince(Province)){
    std::cout << "\nError(3): Invalid province name: " << Province << " within file" << std::endl;
    std::exit(3);
	}

	next = NULL;
}

////Setter function////
void DomesticStudent::set_province(std::string prov){
  //(Part 2 #3) Error message for insert
  std::string fmt_prov = nameFormater(prov, 1);
	if(!validProvince(fmt_prov)){
    std::cout << "Warning: Invalid province name: " << fmt_prov << std::endl;
    return;
	}
  Province = fmt_prov;

}
void DomesticStudent::set_next(DomesticStudent* _next)
{
	next = _next;
}

std::string DomesticStudent::get_province() const
{
	return Province;
}

DomStuPtr DomesticStudent::get_next() const
{
	return next;
}


////validProvince function////
//Checks that hte province is allowed
//(Part 2 #3) Province validity check
bool DomesticStudent::validProvince(std::string prov) const
{
  std::string init[] = {"NL", "PE", "NS", "NB", "QC", "ON", "MB", "SK", "AB", "BC", "YT", "NT", "NU"};
  std::set<std::string> VALID_PROVINCE(init, init + sizeof(init)/sizeof(init[0]));
  return VALID_PROVINCE.find(prov) != VALID_PROVINCE.end();
}


////compareProvince function////
char compareProvince(const DomesticStudent &stu1, const DomesticStudent &stu2) {
    if (stu1.Province < stu2.Province) {
        return 'L';
    } else if (stu1.Province > stu2.Province) {
        return 'G';
    } else {
        return 'E';
    }
}


////----------------------------------------International Student Child Class-----------------------------------------////

//(p\Part 2 #3) Country validity check
bool InternationalStudent::validCountry(std::string country) const
{
  std::string init[] = {"Canada", "China", "India", "Iran", "Korea"};
  std::set<std::string> VALID_COUNTRY(init, init + sizeof(init)/sizeof(init[0]));
  return VALID_COUNTRY.find(country) != VALID_COUNTRY.end();
}

bool InternationalStudent::validToefl() const
{
  if(Toefl.get_rScore() < 20 || Toefl.get_lScore() < 20 || Toefl.get_sScore() < 20 || Toefl.get_wScore() < 20 || Toefl.get_totalScore() < 93)
  {
    return false;
  }
  //else
  return true;
}

////Constructor functions////
InternationalStudent::InternationalStudent() : Student()//assume name is blank and all other values are default values
{
	Country = "A";
	Toefl.set_rScore(0);
	Toefl.set_lScore(0);
	Toefl.set_sScore(0);
	Toefl.set_wScore(0);
	next = NULL;
	return;
}

InternationalStudent::InternationalStudent(std::string fName, std::string lName, std::string nation, float gpa, int rsScore, ToeflScore toefl_score, int id)
: Student(fName, lName, gpa, rsScore, id)
	//full init
	//PRECONDTION: inthpp has been included and a global instance of it has been declared and passed in
	//POSTCONDITION: the name fields are the inputted fields, GPA and ResearchScore = inputted fields
{
	Country = nameFormater(nation);

  //(Part 2 #3) Checking that india is spelled correct and fix
  if (Country == "Idian") {
    std::cout << "Attention: Misspelling 'Idian' corrected to India" << std::endl;
    Country = "India";
  }
  if (!validCountry(Country)) {
    std::cout << "\nError(4): Invalid country name: " << Country << " within file" << std::endl;
    std::exit(4);
  }

	Toefl.set_rScore(toefl_score.get_rScore());
	Toefl.set_lScore(toefl_score.get_lScore());
	Toefl.set_sScore(toefl_score.get_sScore());
	Toefl.set_wScore(toefl_score.get_wScore());
	next = NULL;
	return;
}

InternationalStudent::InternationalStudent(std::string fName, std::string lName, std::string nation, ToeflScore toefl_score, int id)
: Student(fName, lName, id)
	//assume gpa and rsscore are 0
	//PRECONDTION: inthpp has been included and a global instance of it has been declared and passed in
	//POSTCONDITION: the name fields are the inputted fields, GPA and ResearchScore = 0
{
	Country = nameFormater(nation);

  //(Part 2 #3) Checking that india is spelled correct and fix
  if (Country == "Idian") {
    std::cout << "Attention: Misspelling 'Idian' corrected to India" << std::endl;
    Country = "India";
  }
  if (!validCountry(Country)) {
    std::cout << "\nError(4)g: Invalid country name: " << Country << " within file" << std::endl;
    std::exit(4);
  }

	Toefl.set_rScore(toefl_score.get_rScore());
	Toefl.set_lScore(toefl_score.get_lScore());
	Toefl.set_sScore(toefl_score.get_sScore());
	Toefl.set_wScore(toefl_score.get_wScore());
	next = NULL;
	return;
}


////Setter functions////
void InternationalStudent::set_country(std::string nation)
{
	Country = nameFormater(nation);
}

void InternationalStudent::set_toeflScore(ToeflScore toefl)
{
	//the toeflscore class alreadyprevents illegal values, so we can just input
	Toefl.set_rScore(toefl.get_rScore());
	Toefl.set_lScore(toefl.get_lScore());
	Toefl.set_sScore(toefl.get_sScore());
	Toefl.set_wScore(toefl.get_wScore());
}
void InternationalStudent::set_next(InternationalStudent* _next)
{
	next = _next;
}


////Getter functions////
std::string InternationalStudent::get_country() const
{
	return Country;
}

ToeflScore InternationalStudent::get_toeflScore() const
{
	return Toefl;
}
InternationalStudent* InternationalStudent::get_next() const
{
	return next;
}

////compareCountry function////

char compareCountry(const InternationalStudent &stu1, const InternationalStudent &stu2){
  if (stu1.Country < stu2.Country) {
      return 'L';
  } else if (stu1.Country > stu2.Country) {
      return 'G';
  } else {
      return 'E';
  }

}

