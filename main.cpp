#include <iostream> //cin and cout
#include <fstream> //file processing
#include <sstream> //formatted string processing
#include <cstdlib> //atof and atoi
#include <iomanip>
#include <limits>
#include <cmath>
#include <ctype.h> 
#include <stdio.h> 
#include "mergedStudent.hpp"
#include "merged_list.hpp"
#include "student_list.hpp"
using namespace std;


//////////Error Checking Functions//////////
//(Part2 #1)Checking that all the fields are present based on standard format
bool hasNumField(string line, int expected_field) {
  if (line.size() == 0) {
    return expected_field == 0;
  }
  if (line[line.size() - 1] == ',') {
    return false;
  }
  int num_field = 1;
  for (int i=0; i<line.size(); i++) {
    if (line[i] == ',') num_field++;
  }
  return num_field == expected_field;
}


//(Part 2 #2) Fomats the inputted names to the correct style captial first lowercase after
string NamestringFormater(string str, int mode = 0 ) {
  // nameFormater is added for first_name, last_name, province and country already
  // we add this stringFormater for user input strings to match the stored values.
  string formatted_str = str;
  for (int i=0; i<formatted_str.size(); i++) {
    if (mode == 0) {
      if (i==0) {
       formatted_str[i] = ::toupper(formatted_str[i]);
      } else {
       formatted_str[i] = ::tolower(formatted_str[i]);
      }
    } else {
      formatted_str[i] = ::toupper(formatted_str[i]);
    }
  }
  return formatted_str;
}


//(Part 2 #2) Fomats the inputted provinces to all caps
string ProvincestringFormater(string str, int mode = 0 ) {
  string formatted_str = str;
  for (int i=0; i<formatted_str.size(); i++) {
    if (mode == 0) {
       formatted_str[i] = ::toupper(formatted_str[i]);
    } else {
      formatted_str[i] = ::toupper(formatted_str[i]);
    }
  }
  return formatted_str;
}


//Checks user input for names, province, and country
bool nameCheck(std::string Fname, std::string Lname, std::string Province, std::string Country , int type)
{
  int i=0;
  int j=0;
  int k=0;
  int l=0;
  int print = 0;
  int notfound = 0;
  std::string issue;
  if(type == 1) {
    while(Fname[i]) {
      if(!(isalpha(Fname[i]))) {
        print = 1;
        issue = "name";
      }
      i++;
    }
    while(Lname[j]) {
      if(!(isalpha(Lname[j]))) {
        print = 1;
        issue = "name";
      }
      j++;
    }
  }
  else if(type == 2) {
    while(Province[k]) {
      if(!(isalpha(Province[k]))) {
        print = 1;
        issue = "province";
      }
      k++;
    }
    Province = ProvincestringFormater(Province); // FIX THIS
    if(Province != "NL" && Province != "PE" && Province != "NS" && Province != "NB" 
    && Province != "QC" && Province != "ON" && Province != "MB" && Province != "SK" 
    && Province != "AB" && Province != "BC" && Province != "YT" && Province != "NT" 
    && Province != "NU") {
      print = 1;
      issue = "province";
      notfound = 1;
    }
  }
  else if(type == 3) {
    while(Country[l]) {
      if(!(isalpha(Country[l]))) {
        print = 1;
        issue = "country";
      }
      l++;
    }
    Country = NamestringFormater(Country);
    if(Country != "Canada" && Country != "China" && Country != "India" && Country != "Iran" && Country != "Korea") {
      print = 1;
      issue = "country";
      notfound = 1;
    }
  }

  if(print == 1){ //Prints error
    std::cout << "\nWarning: You have inputted a ";
    std::cout << issue;
    if(notfound == 1) {
      std::cout <<" that is non-valid\n";
    }
    else {
      std::cout <<" that is non-alphabetical\n";
    }
    std::cout << "Please try another ";
    std::cout << issue << std::endl;
    std::cout << "\nX============================================X\n";
    return false;
  }
  else {
    return true;
  }
}


//Checks user input for CGPA, Research Score, and Toefl fields
bool valueCheck(float inCGPA, int inResearch, int ID, int inRead, int inListen, int inSpeak, int inWrite, int type)
{
  int print = 0;
  std::string issue;
  if(type == 1 || type == 5){ //CGPA
    if(inCGPA >= 0.0 && inCGPA <= 4.3001) {
    }
    else {
      print = 1;
      if(type == 1) {
        issue = "CGPA";
      }
      else {
        issue = "CGPA threshold";
      }
    }
  }
  else if(type == 2 || type == 6){ //Research Score
    if(inResearch >= 0 && inResearch <= 100) {
    }
    else {
      print = 1;
      if(type == 2) {
        issue = "research score";
      }
      else {
        issue = "research threshold";
      }
    }
  }
  else if(type == 3){ //Student ID
    if(ID >= 20210000 && ID < 20220000) {
    }
    else {
      print = 1;
      issue = "student ID";
    }
  }
  else if(type == 4) {
    if(inRead >= 0 && inRead <= 30 && inListen >= 0 && inListen <= 30 
    && inSpeak >= 0 && inSpeak <= 30 && inWrite >= 0 && inWrite <= 30) {
    }
    else {
      print = 1;
      issue = "TEOFL field";
    }
  }
  
  if(print == 1) { //Prints error
    std::cout << "\nWarning: You have inputted an invalid ";
    std::cout << issue << std::endl;
    std::cout << "Please try another ";
    std::cout << issue << std::endl;
    std::cout << "\nX============================================X\n";
    return false;
  }
  else {
    return true;
  }
}


/////////Main Program////////
int main()
{
//Linked list creation
  DomStuList domlst;
  IntStuList intlst;
  merged_list merglst;

  //Read the domestic-stu.txt file and exit if failed
  string lineDom;
  ifstream domesticFile("domestic-stu.txt");
  if(!domesticFile.is_open()) {
    cout << "Unable to open file domestic-stu.txt" << endl;
    return -1;
  }

  getline(domesticFile, lineDom);

  int Dom_stu_count = 0;
  int CdentNumber;

  while( getline(domesticFile, lineDom) ) {
    std::istringstream ss(lineDom);

    //(Part 2 #1) Checking for missing field error message and exit
    if (!hasNumField(lineDom, 5)) {
      cout << "Error(1): Domestic file line missing field, line: " << lineDom << endl;
      exit(1);
    }

    std::string DomfirstName, DomlastName, province, Doms_cgpa, Doms_researchScore;
    float cgpa;
    int researchScore;

    //get firstName separated by comma
    getline(ss, DomfirstName, ',');

    //get lastName separated by comma
    getline(ss, DomlastName, ',');

    //get province separated by comma
    getline(ss, province, ',');

    //get cpga separated by comma, and convert string to float
    getline(ss, Doms_cgpa, ',');
    cgpa = stof(Doms_cgpa.c_str());

    //get researchScore separated by comma, and convert it to int
    getline(ss, Doms_researchScore, ',');
    researchScore = atoi(Doms_researchScore.c_str());

    DomesticStudent* node = new DomesticStudent(DomfirstName, DomlastName, province, cgpa, researchScore, 20210000 + Dom_stu_count);
    domlst.insertNode(node);

    Dom_stu_count++;
  }

  //close your file
  domesticFile.close();


  //Read the international-stu.txt file and exit if failed
  string lineInt;
  ifstream InternationalFile("international-stu.txt");
  if(!InternationalFile.is_open()) {
    cout << "Unable to open file domestic-stu.txt" << endl;
    return -1;
  }

  getline(InternationalFile, lineInt);

  int Int_stu_count = Dom_stu_count;
  int IntStudentNumber;

  while( getline(InternationalFile, lineInt) ) {
    std::istringstream ss(lineInt);

    //(Part 2 #1) Checking for missing field error message and exit
    if (!hasNumField(lineInt, 9)) {
      cout << "Error(2): International file line missing field, line: " << lineInt << endl;
      exit(2);
    }

    std::string IntfirstName, IntlastName, Intcountry, Ints_cgpa, Ints_researchScore, ReadingScore, ListeningScore, SpeakingScore, WritingScore;
    float Intcgpa;
    int IntresearchScore;
    int IntReadingScore;
    int IntListeningScore;
    int IntSpeakingScore;
    int IntWritingScore;

    //get firstName separated by comma
    getline(ss, IntfirstName, ',');

    //get lastName separated by comma
    getline(ss, IntlastName, ',');

    //get country separated by comma
    getline(ss, Intcountry, ',');

    //get cpga separated by comma, and convert string to float
    getline(ss, Ints_cgpa, ',');
    Intcgpa = stof(Ints_cgpa.c_str());

    //get researchScore separated by comma, and convert it to int
    getline(ss, Ints_researchScore, ',');
    IntresearchScore = atoi(Ints_researchScore.c_str());

    //TOFEL score information to be inserted into the object array
    getline(ss, ReadingScore, ',');
    IntReadingScore = atof(ReadingScore.c_str());

    getline(ss, ListeningScore, ',');
    IntListeningScore = atof(ListeningScore.c_str());

    getline(ss, SpeakingScore, ',');
    IntSpeakingScore = atof(SpeakingScore.c_str());

    getline(ss, WritingScore, ',');
    IntWritingScore = atof(WritingScore.c_str());

    ToeflScore toefl = ToeflScore(IntReadingScore, IntListeningScore, IntSpeakingScore, IntWritingScore);

    InternationalStudent* node = new InternationalStudent(IntfirstName, IntlastName, Intcountry, Intcgpa, IntresearchScore, toefl, 20210000 + Int_stu_count);
    intlst.insertNode(node);

    Int_stu_count++;

  }

  //close your file
  InternationalFile.close();

int option;
int optiona;
int group;
int globalCount = Int_stu_count;
std::string ChosFname;
std::string ChosLname;
std::string UserProvince;
std::string UserCountry;


InputType:
  std::cout << "MAIN MENU";
  std::cout << "\nX===========================================X" << std::endl;
  std::cout << "Select a what you would like to do" << std::endl;
  Input:
  std::cout << "Press '1' to search, create, and delete domestic students list" << std::endl;
  std::cout << "Press '2' to search, create, and delete international students list" << std::endl;
  std::cout << "Press '3' to search and view the sorted merged list" << std::endl;
  std::cout << "Press '4' to enter unit testing mode" << std::endl;
  std::cout << "Press '0' to exit the program" << std::endl;
  std::cout << "X===========================================X" << std::endl;

  std::cout << "Choice: ";

  if(std::cin >> group && group >= 0 && group <= 4) {
  }
  else {
    std::cout << "\nWarning: You have chosen an invalid option\n";
    std::cout << "\nX===========================================X\n";
    std::cout << "Here are your options:\n\n";
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    goto Input;
  }

  if(std::cin.peek())
  {
    std::cout << "Stopped reading past any integer values:\n";
    std::cin.ignore(100000, '\n');
  }

  switch(group)
  {
    case 0: //Exit
      std::cout << "\nGoodbye" << std::endl;
    goto Done;

    case 3:
      //Inserted both linked lists into a merged list
      merglst.InsertDomNode(domlst);
      merglst.InsertIntNode(intlst);
      
      Menua:
        std::cout << "MERGED LIST MENU";
        std::cout << "\nX===========================================X\n";
        std::cout << "Select a what you would like to do\n";
        Input1:
        std::cout << "Press '1' to print out the sorted student list\n";
        std::cout << "Press '2' to search based on CGPA and research score threshold\n";
        std::cout << "Press '0' to exit the program\n";
        std::cout << "X===========================================X\n";

      std::cout << "Choice: ";

      if(std::cin >> optiona && optiona >= 0 && optiona <= 2) {
      }
      else
      {
        std::cout << "\nWarning: You have chosen an invalid option\n";
        std::cout << "\nX===========================================X\n";
        std::cout << "Here are your options:\n\n";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        goto Input1;
      }
      if(std::cin.peek())
      {
        std::cout << "Stopped reading past any integer values:\n";
        std::cin.ignore(100000, '\n');
      } 
      switch(optiona) {
//////////Printing out the sorted student list//////////
        case 1: 
          std::cout << "X-Merged list printed-X" << std::endl;
          std::cout << merglst;
          std::cout << "\nReturning to merged list menu..." << std::endl;
        goto Menua;


//////////Search for students based on CGPA and research score threshold//////////
        case 2: 
          float CGPAThresh;
          int ResearchThresh;
          std::cout << "X-Students searched by minimum CGPA and research score threshold-X\n" << std::endl;
          //Error check
          CGPAThresh:
          std::cout << "\tPlease input your desired minimum threshold for CGPA (0.0 - 4.3): ";
          if(cin >> CGPAThresh && valueCheck(CGPAThresh, 0, 0, 0, 0, 0, 0, 5)) {
              CGPAThresh = abs(CGPAThresh);
              CGPAThresh = floor(CGPAThresh*10+0.5)/10;
          }
          else {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            goto CGPAThresh;
          }

          RSThresh:
          std::cout << "\n\nPlease input your desired minimum threshold for research score (0 - 100): ";
          if(cin >> ResearchThresh && valueCheck(0, ResearchThresh, 0, 0, 0, 0, 0, 6)) {
          }
          else {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            goto RSThresh;
          }
          merglst.SearchThreshold(CGPAThresh,ResearchThresh);

          std::cout << "\nReturning to merged list menu..." << std::endl;
        goto Menua;


//////////Exit//////////
        case 0: 
          std::cout << "\nGoodbye" << std::endl;
        goto Done;
      }


//////////UnitTest//////////
      case 4:
      goto UnitTest;
  }


//////////Menu system for specific student types/////////
while(1) {
  bool Name, ID, CGPA, Rscore;
  std::string Enable;
  Menub:
    std::cout << "INDIVIDUAL LIST SUB-MENU";
    std::cout << "\nX===========================================X\n";
    std::cout << "Select what you would like to do\n";
    Input2:
    std::cout << "Press '1' to search the first and last name of a student\n";
    std::cout << "Press '2' to search by application ID\n";
    std::cout << "Press '3' to search by CGPA\n";
    std::cout << "Press '4' to search by research score\n";
    std::cout << "Press '5' to search by CGPA and research score threshold\n"; 
    std::cout << "Press '6' to search by multiple conditions\n";
    std::cout << "Press '7' to view the head and tail of the list\n";
    std::cout << "Press '8' to insert a student\n";
    std::cout << "Press '9' to delete a student\n";
    std::cout << "Press '10' to delete the head and tail\n";
    std::cout << "Press '11' to return to main menu\n";
    std::cout << "Press '0' to exit the program\n";
    std::cout << "X===========================================X\n";

    std::cout << "Choice: ";

    if(std::cin >> option && option >= 0 && option <= 11) {
    }
    else {
      std::cout << "\nWarning: You have chosen an invalid option\n";
      std::cout << "\nX===========================================X\n";
      std::cout << "Here are your options:\n\n";
      std::cin.clear();
      std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
      goto Input2;
    }
    if(std::cin.peek())
    {
      std::cout << "Stopped reading past any integer values:\n";
      std::cin.ignore(100000, '\n');
    }
    switch(option) {
//////////Search for first and last name of student//////////
      case 1: 

        std::cout << "\nX-Students searched by first name and last name-X\n" << std::endl;
        Rein0:
        ChosFname.clear();
        ChosLname.clear();
        std::cout << "Please input the name of the student you want to search: ";
        std::cin >> ChosFname >> ChosLname;
        if(std::cin.peek())
        {
          std::cout << "Stopped reading past any string values past the first 2:\n";
          std::cin.ignore(100000, '\n');
        }
        if(nameCheck(ChosFname, ChosLname, "empty", "empty", 1)) {
          ChosFname = NamestringFormater(ChosFname);//Name formattor
          ChosLname = NamestringFormater(ChosLname);//Name formattor
          if(group == 1) { //Domestic Students
            domlst.searchNames(ChosFname,ChosLname);
          }
          else { //International Students 
            intlst.searchNames(ChosFname,ChosLname);
          }
        }
        else {
          goto Rein0;
        }

        std::cout << "\nReturning to sub-menu..." << std::endl;
      goto Menub;


//////////Search for application ID//////////
      case 2: 
        int IDsearch;

        std::cout << "\nX-Students searched by application ID-X\n" << std::endl;
        Rein1:
        std::cout << "Please input the desired application ID (form 2021xxxx): ";

        if(std::cin >> IDsearch && valueCheck(0, 0, IDsearch, 0, 0, 0, 0, 3)) {
          if(group == 1) { //Domestic Students
            domlst.searchAppID(IDsearch);
          }
          else { //International Students
            intlst.searchAppID(IDsearch);
          }
        }
        else {
          std::cin.clear();
          std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
          goto Rein1;
        }
        if(std::cin.peek())
        {
        std::cout << "Stopped reading past any integer values:\n";
          std::cin.ignore(100000, '\n');
        }

        std::cout << "\nReturning to sub-menu..." << std::endl;
      goto Menub;


//////////Search for CGPA//////////
      case 3: 
        float CGPAsearch;

        std::cout << "\nX-Students searched by CGPA-X\n" << std::endl;
        Rein2:
        std::cout << "Please input the desired CGPA(0.0 - 4.3): ";
        if(std::cin >> CGPAsearch && valueCheck(CGPAsearch, 0, 0, 0, 0, 0, 0, 1)) {
          CGPAsearch = abs(CGPAsearch);
          CGPAsearch = floor(CGPAsearch*10+0.5)/10;
          if(group == 1){ //Domestic Students
            domlst.searchCGPA(CGPAsearch);
          }
          else{ //International Students
            intlst.searchCGPA(CGPAsearch);
          }
        }
        else {
          std::cin.clear();
          std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
          goto Rein2;
        }
        if(std::cin.peek())
        {
          std::cout << "Stopped reading past any valid float values:\n";
          std::cin.ignore(100000, '\n');
        }
        std::cout << "\nReturning to sub-menu..." << std::endl;
      goto Menub;


//////////Search for research score//////////
      case 4: 
        int Researchsearch;

        std::cout << "\nX-Students searched by research score-X\n" << std::endl;
        Rein3:
        std::cout << "Please input the desired research score (0 - 100): ";

        if(std::cin >> Researchsearch) {
          if(group == 1){ //Domestic Students
            domlst.searchRSScore(Researchsearch);
          }
          else{ //International Students
            intlst.searchRSScore(Researchsearch);
          }
        }
        else{
          std::cin.clear();
          std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
          goto Rein3;
        }
        if(std::cin.peek())
        {
          std::cout << "Stopped reading past any integer values:\n";
          std::cin.ignore(100000, '\n');
        }
        std::cout << "\nReturning to sub-menu..." << std::endl;
      goto Menub;


//////////Threshold search//////////
      case 5:
          float CGPAThresh2;
          int ResearchThresh2;
          if(group == 1) {
            std::cout << "X-Domestic Students searched by minimum CGPA and research score threshold-X\n\n";
          }
          else {
            std::cout << "International X-Students searched by minimum CGPA and research score threshold-X\n\n";
          }
          
          //Error check
          CGPAThresh2:
          std::cout << "\tPlease input your desired minimum threshold for CGPA (0.0 - 4.3): ";
          if(cin >> CGPAThresh2 && valueCheck(CGPAThresh2, 0, 0, 0, 0, 0, 0, 5)) {
            CGPAThresh2 = abs(CGPAThresh2);
            CGPAThresh2 = floor(CGPAThresh2*10+0.5)/10;
          }
          else{
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            goto CGPAThresh;
          }

          RSThresh2:
          std::cout << "\n\nPlease input your desired minimum threshold for research score (0 - 100): ";
          if(cin >> ResearchThresh2 && valueCheck(0, ResearchThresh2, 0, 0, 0, 0, 0, 6)) {
          }
          else {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            goto RSThresh;
          }

          if(group == 1) {
            domlst.searchThreshold(CGPAThresh2, ResearchThresh2);
          }
          else {
            intlst.searchThreshold(CGPAThresh2, ResearchThresh2);
          }
          std::cout << "\nReturning to sub-menu..." << std::endl;
      goto Menub;


//////////Multiple Search//////////
      case 6:
        ChosFname.clear();
        ChosLname.clear();
        int inID, inResearchScore;
        float inCGPA1;
        std::cout << "Would you like to search by Name(yes or no)?: \n\n";
        if(std::cin >> Enable && (Enable == "yes" || Enable == "Yes" || Enable == "YES")) {
          if(std::cin.peek())
          {
            std::cout << "Stopped reading past the first string value:\n";
            std::cin.ignore(100000, '\n');
          }
          Name = true;
          ReNamed:
          std::cout << "Please input the name of the student you want to search: ";
          std::cin >> ChosFname >> ChosLname;
          if(std::cin.peek())
          {
            std::cout << "Stopped reading past the first 2 string values:\n";
            std::cin.ignore(100000, '\n');
          }
          if(nameCheck(ChosFname, ChosLname, "empty", "empty", 1)) {
            ChosFname = NamestringFormater(ChosFname);//Name formattor
            ChosLname = NamestringFormater(ChosLname);//Name formattor
          }
          else {
          goto ReNamed;
          }
        }
        Enable.clear();

        std::cout << "Would you like to search by Student ID(yes or no)?: \n\n";
        if(std::cin >> Enable && (Enable == "yes" || Enable == "Yes" || Enable == "YES")) {
          if(std::cin.peek())
          {
            std::cout << "Stopped reading past the first string value:\n";
            std::cin.ignore(100000, '\n');
          }
          ID = true;
          reID:
          std::cout << "Please input the desired application ID (form 2021xxxx): ";
          if(std::cin >> inID && valueCheck(0, 0, inID, 0, 0, 0, 0, 3)){
          }
          else {
          std::cin.clear();
          std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
          goto reID;
          }
          if(std::cin.peek())
          {
            std::cout << "Stopped reading past any integer values:\n";
            std::cin.ignore(100000, '\n');
          }
        }
        Enable.clear();
     
        std::cout << "Would you like to search by CGPA(yes or no)?: \n\n";
        if(std::cin >> Enable && (Enable == "yes" || Enable == "Yes" || Enable == "YES")) {
          if(std::cin.peek())
          {
            std::cout << "Stopped reading past any valid float values:\n";
            std::cin.ignore(100000, '\n');
          }
          CGPA = true;
          reCG:
          std::cout << "Please input your desired minimum threshold for CGPA (0.0 - 4.3): ";
          if(std::cin >> inCGPA1 && valueCheck(inCGPA1, 0, 0, 0, 0, 0, 0, 1)){
          }
          else {
          std::cin.clear();
          std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
          goto reCG;
          }
          if(std::cin.peek())
          {
            std::cout << "Stopped reading past any valid float values:\n";
            std::cin.ignore(100000, '\n');
          }
        }
        Enable.clear();    

        std::cout << "Would you like to search by Research Score(yes or no)?: \n\n";
        if(std::cin >> Enable && (Enable == "yes" || Enable == "Yes" || Enable == "YES")) {
          if(std::cin.peek())
          {
            std::cout << "Stopped reading past the first string value:\n";
            std::cin.ignore(100000, '\n');
          }
          Rscore = true;
          reRS:
          std::cout << "Please input your desired minimum threshold for research score (0 - 100): ";
          if(std::cin >> inResearchScore && valueCheck(0, inResearchScore, 0, 0, 0, 0, 0, 2)){
          }
          else {
          std::cin.clear();
          std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
          goto reRS;
          }
          if(std::cin.peek())
          {
            std::cout << "Stopped reading past any integer values:\n";
            std::cin.ignore(100000, '\n');
          }
        }
        Enable.clear();
        
        if(group == 1){
          domlst.multiSearch(Name, ChosFname, ChosLname, ID, inID, CGPA, inCGPA1, Rscore,  inResearchScore);
        }
        else{
          intlst.multiSearch(Name, ChosFname, ChosLname, ID, inID, CGPA, inCGPA1, Rscore,  inResearchScore);
        }
      goto Menub;


//////////Display the head and tail//////////
      case 7:
        std::cout << "X-Displaying head and tail of list-X\n\n";
        if(group == 1) {
          domlst.GetHeadandTail(1);
          std::cout << std::endl;
          domlst.GetHeadandTail(2); 
        }
        else {
          intlst.GetHeadandTail(1);
          std::cout << std::endl;
          intlst.GetHeadandTail(2);          
        }
        std::cout << "\nReturning to sub-menu..." << std::endl;
      goto Menub;


//////////Insert a Student//////////
      case 8: 
        float inCGPA;
        int inResearch;
        int inRead;
        int inListen;
        int inSpeak;
        int inWrite;
        std::cout << "\nX-Inserting a student-X\n" << std::endl;
        Rein4:
        ChosFname.clear();
        ChosLname.clear();
        std::cout << "Please input the name of the student you want to insert: ";
        std::cin >> ChosFname >> ChosLname;
        if(std::cin.peek())
          {
            std::cout << "Stopped reading past the first two string values:\n";
            std::cin.ignore(100000, '\n');
          }
        if(nameCheck(ChosFname, ChosLname, "empty", "empty", 1)) {
          //Allows user to continue to the next input
        }
        else {
          goto Rein4;
        }

        if(group == 1) { //Domestic Student
          ReProvince:
          UserProvince.clear();
          cout << "Please input a province (): " ;
          std::cin >> UserProvince;
          if(std::cin.peek())
          {
            std::cout << "Stopped reading past the first string value:\n";
            std::cin.ignore(100000, '\n');
          }
          if(nameCheck("empty", "empty", UserProvince, "empty", 2)) {
            //Allows user to continue to the next input
          }
          else {
            goto ReProvince;
          }
        }
        else { //International Student
          ReCountry:
          UserCountry.clear();
          cout << "Please input a country (): ";
          std::cin >> UserCountry;
          if(std::cin.peek())
          {
            std::cout << "Stopped reading past the first string value:\n";
            std::cin.ignore(100000, '\n');
          }
          if(nameCheck("empty", "empty", "empty", UserCountry, 3)) {
            //Allows user to continue to the next input
          }
          else {
            goto ReCountry;
          }

          ReTOEFL:
          ReRead:
          cout << "Please input a reading score (0 - 30): ";  
          if(std::cin >> inRead) {
          }
          else {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            goto ReRead;
          }
          if(std::cin.peek())
          {
            std::cout << "Stopped reading past any integer values:\n";
            std::cin.ignore(100000, '\n');
          }
          ReListen:
          cout << "Please input a listening score (0 - 30): ";  
          if(std::cin >> inListen) {
          }
          else {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            goto ReListen;
          }
          if(std::cin.peek())
          {
            std::cout << "Stopped reading past any integer values:\n";
            std::cin.ignore(100000, '\n');
          }
          ReSpeak:
          cout << "Please input a speaking score (0 - 30): ";  
          if(std::cin >> inSpeak) {
          }
          else {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            goto ReSpeak;
          }
          if(std::cin.peek())
          {
            std::cout << "Stopped reading past any integer values:\n";
            std::cin.ignore(100000, '\n');
          }
          ReWrite:
          cout << "Please input a writing score (0 - 30): ";  
          if(std::cin >> inWrite) {
          }
          else {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            goto ReWrite;
          }
          if(std::cin.peek())
          {
            std::cout << "Stopped reading past any integer values:\n";
            std::cin.ignore(100000, '\n');
          }
          if(valueCheck(0, 0, 0, 0, inRead, inListen, inSpeak, inWrite)) {
          }
          else {
            goto ReTOEFL;
          }
        }

        ReCGPA:
        cout << "Please input a CGPA (0.0 - 4.3): ";
        if(std::cin >> inCGPA && valueCheck(inCGPA, 0, 0, 0, 0, 0, 0, 2)) {
            inCGPA = abs(inCGPA);
            inCGPA = floor(inCGPA*10+0.5)/10;
        }
        else {
          std::cin.clear();
          std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
          goto ReCGPA;
        }
        if(std::cin.peek())
        {
          std::cout << "Stopped reading past any valid float values:\n";
          std::cin.ignore(100000, '\n');
        }

        ReRS:
        cout << "Please input a research score (0 - 100): ";  
        if(std::cin >> inResearch && valueCheck(0, inResearch, 0, 0, 0, 0, 0, 2)) {
        }
        else {
          std::cin.clear();
          std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
          goto ReRS;
        }
        if(std::cin.peek())
        {
          std::cout << "Stopped reading past any integer values:\n";
          std::cin.ignore(100000, '\n');
        }

        if(group == 1) { //Node insertion
          DomesticStudent* node = new DomesticStudent(ChosFname, ChosLname, UserProvince, inCGPA, inResearch, 20210000 + globalCount);
          domlst.insertNode(node);
        }
        else if(group == 2) {
          ToeflScore toefl = ToeflScore(inRead, inListen, inSpeak, inWrite);
          InternationalStudent* node1 = new InternationalStudent(ChosFname, ChosLname, UserCountry, inCGPA, inResearch, toefl, 20210000 + globalCount);
          intlst.insertNode(node1);
        }

        globalCount++;
        std::cout << "\nReturning to sub-menu..." << std::endl;
      goto Menub;


//////////Delete a student//////////
      case 9: 
        std::cout << "\nX-Deleting a student-X\n" << std::endl;
        Rein5:
        ChosFname.clear();
        ChosLname.clear();
        std::cout << "Please input the name of the student you want to delete: ";
        std::cin >> ChosFname >> ChosLname;
        if(std::cin.peek())
        {
          std::cin.ignore(100000, '\n');
        }
        if(nameCheck(ChosFname, ChosLname, "empty", "empty", 1)) {
          ChosFname = NamestringFormater(ChosFname);//Name formattor
          ChosLname = NamestringFormater(ChosLname);//Name formattor
          if(group == 1) { //Domestic Students
            domlst.deleteNode(ChosFname,ChosLname);
          }
          else { //International Students
            intlst.deleteNode(ChosFname,ChosLname);
          }
        }
        else {
          goto Rein5;
        }

        std::cout << "\nReturning to sub-menu..." << std::endl;
      goto Menub;


//////////Delete head and tail of list//////////
      case 10:
      std::cout << "X-Deleting head and tail of list-X\n\n";
      if(group == 1){
      std::cout << "Pre-Deletion:\n";
      domlst.GetHeadandTail(1);
      std::cout << std::endl;
      domlst.GetHeadandTail(2);
      std::cout << std::endl;
      domlst.deleteEnds();
      std::cout << "Post-Deletion:\n";
      domlst.GetHeadandTail(1);
      std::cout << std::endl;
      domlst.GetHeadandTail(2);
      }
      else{
      std::cout << "Pre-Deletion:\n";
      intlst.GetHeadandTail(1);
      std::cout << std::endl;
      intlst.GetHeadandTail(2);
      std::cout << std::endl;
      intlst.deleteEnds();
      std::cout << "Post-Deletion:\n";
      intlst.GetHeadandTail(1);
      std::cout << std::endl;
      intlst.GetHeadandTail(2);
      }
      std::cout << "\nReturning to sub-menu..." << std::endl;
      goto Menub;

//////////Return to student list selection//////////
      case 11: 
        std::cout << "\nReturning to main menu..." << std::endl;
      goto InputType;


//////////Exit//////////
      case 0: 
        std::cout << "\nGoodbye" << std::endl;
      goto Done;

    }
  }


/////////UNIT TEST//////////
  UnitTest:
  Menuc:
    int option4;
    std::cout << "UNIT TEST MENU";
    std::cout << "\nX===========================================X" << std::endl;
    std::cout << "Select what you would like test" << std::endl;
    Input4:
    std::cout << "Press '1' to test the inserting functions in domstu and intstu" << std::endl;
    std::cout << "Press '2' to test the search function based off cgpa, application ID, and researchscore" << std::endl;
    std::cout << "Press '3' to test the search functions based off first and last name" << std::endl;
    std::cout << "Press '4' to test the delete functions based off first and last name" << std::endl;
    std::cout << "Press '5' to Delete the head and tail nodes of the list" << std::endl;
    std::cout << "Press '6' to merge the two lists into one" << std::endl;
    std::cout << "Press '7' to search existing students in their merged link list based on cgps_threshold and researchScore_threshold" << std::endl;
    std::cout << "Press '0' to return to main menu" << std::endl;
    std::cout << "X===========================================X" << std::endl;

    std::cout << "Choice: ";

    if(std::cin >> option4 && option >= 0 && option4 <= 8)
    {
      //Continues on if the input is valid
    }
    else
    {
      std::cout << "\nWarning: You have chosen an invalid option\n";
      std::cout << "\nX===========================================X\n";
      std::cout << "Here are your options:\n\n";
      std::cin.clear();
      std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
      goto Input4;
    }
    if(std::cin.peek())
    {
      std::cin.ignore(100000, '\n');
    }

  switch(option4)
  {
    case 1: 
    {
    // normal cases
    std::cout << "We will now show cases for our insert functions" << endl;
    std::cout << "This is the domlist before inserting anything" << std::endl; 
    std::cout << domlst << std::endl; 
    std::cout << "This is the intlist before inserting anything" << std::endl;
    std::cout << intlst << std::endl;
    std::cout << "Inserting Chad Thomason into domstu, with a cgpa of 4.1 researchScore of 100 and he is from NU" << std::endl;
    DomesticStudent* node = new DomesticStudent("Chad", "Thomason", "NU", 4.1, 100, 20210000 + globalCount);
    domlst.insertNode(node);
    std::cout << domlst << endl;
    std::cout << "Inserting Balbir Liu into intst, with a cgpa of 3.7, researchScore of 99, has toefl scores of 28, 26, 25, and 30 respectively and he is from China" << endl;
    ToeflScore toefl = ToeflScore(28, 26, 25, 30);
    InternationalStudent* node1 = new InternationalStudent("Balbir", "Liu", "China", 3.7, 99, toefl, 20210000 + globalCount);
    intlst.insertNode(node1);
    std::cout << intlst << endl; 
    // names messed up
    std::cout << "Inserting cHAd tHoMAson into domstu, with a cgpa of 4.1 researchScore of 100 and he is from NU" <<endl;
    DomesticStudent* node4 = new DomesticStudent("cHAd", "tHoMAson", "NU", 4.1, 100, 20210000 + globalCount);
    domlst.insertNode(node4);
    std::cout << domlst << endl;
    std::cout << "Inserting BAlbiR LIu into intst, with a cgpa of 3.7, researchScore of 99, has toefl scores of 28, 26, 25, and 30 respectively and he is from China" << endl;
    ToeflScore toefl2 = ToeflScore(28, 26, 25, 30);
    InternationalStudent* node5 = new InternationalStudent("BAlbiR", "LIu", "China", 3.7, 99, toefl2, 20210000 + globalCount);
    intlst.insertNode(node5);
    std::cout << intlst << endl; 
    // bad cgpa inserts and research score
    std::cout << "Inserting Chad Thomason into domstu, with a cgpa of 4.12 researchScore of 101 and he is from NU" <<endl;
    DomesticStudent* node6 = new DomesticStudent("Chad", "Thomason", "NU", 4.12, 101, 20210000 + globalCount);
    domlst.insertNode(node6);
    std::cout << domlst << endl;
    std::cout << "Inserting Balbir Liu into intst, with a cgpa of 3.73, researchScore of -1, has toefl scores of 28, 26, 25, and 30 respectively and he is from China" << endl;
    ToeflScore toefl3 = ToeflScore(28, 26, 25, 30);
    InternationalStudent* node7 = new InternationalStudent("Balbir", "Liu", "China", 3.73, -1, toefl3, 20210000 + globalCount);
    intlst.insertNode(node7);
    std::cout << intlst << endl; 

    goto Menuc;
    }
    
    case 2: 
    int IDsearch; 
    int CGPAsearch; 
    int RSsearch;
    std::cout << "We will now search the existing Domstu and Intstu for 'normal cases' with appID, cgpa, and research scores " << endl; 
    std::cout << "Testing normal case 1: appID 20210016 in domstu and 20210116 in intstu" << endl; 
    domlst.searchAppID(20210016);
    std::cout << std::endl; 
    intlst.searchAppID(20210116);
    std::cout << std::endl; 
    std::cout << "Testing normal case 2: cgpa of 2.9 in both domstu and intstu" << endl; 
    domlst.searchCGPA(2.9);
    std::cout << std::endl; 
    intlst.searchCGPA(2.9);
    std::cout << std::endl; 
    std::cout << "Testing normal case 3: research score of 86 in both domstu and intstu" << endl; 
    domlst.searchRSScore(86); 
    std::cout << std::endl; 
    intlst.searchRSScore(86);
    std::cout << std::endl; 

    std::cout << "We will now search the existing Domstu and Intstu for 'edge cases'" << endl; 
    std::cout << "Testing edge case 1, 2: appID 20210000 and 20210099 in domstu and 20210100 and 20210199 in instu" << endl; 
    domlst.searchAppID(20210000);
    std::cout << std::endl; 
    intlst.searchAppID(20210100);
    std::cout << std::endl; 
    domlst.searchAppID(20210099);
    std::cout << std::endl; 
    intlst.searchAppID(20210199);
    std::cout << std::endl; 
    std::cout << "Testing edge case 3, 4: cgpa of 4.33 and 0.00 in both domstu and intstu" << endl; 
    domlst.searchCGPA(4.33);
    std::cout << std::endl; 
    intlst.searchCGPA(4.33);
    std::cout << std::endl; 
    domlst.searchCGPA(0.00);
    std::cout << std::endl; 
    intlst.searchCGPA(0.00);
    std::cout << std::endl;
    std::cout << "Testing edge case 5, 6: research score of 0 and 100 in both domstu and intstu" << endl; 
    domlst.searchRSScore(0); 
    std::cout << std::endl; 
    intlst.searchRSScore(0);
    std::cout << std::endl; 
    domlst.searchRSScore(100); 
    std::cout << std::endl; 
    intlst.searchRSScore(100);
    std::cout << std::endl; 

    std::cout << "Now for user inputted values" << std::endl;
    std::cout << "Please input a appID for domstu" << std::endl;
    std::cin >> IDsearch; 
    if(std::cin.peek())
    {
      std::cin.ignore(100000, '\n');
    }
    std::cout << std::endl << "This is the student associated with the inputted ID: \n";
    domlst.searchAppID(IDsearch);
    std::cout << std::endl;
    std::cout << "Please input a appID for intstu" << std::endl;
    std::cin >> IDsearch; 
    if(std::cin.peek())
    {
      std::cin.ignore(100000, '\n');
    }
    std::cout << std::endl << "This is the student associated with the inputted ID: \n";
    intlst.searchAppID(IDsearch);
    std::cout << std::endl;

    std::cout << "Please input a cgpa for domstu" << std::endl;
    std::cin >> IDsearch; 
    if(std::cin.peek())
    {
      std::cin.ignore(100000, '\n');
    }
    std::cout << std::endl << "This is the student associated with the inputted ID: \n";
    domlst.searchAppID(IDsearch);
    std::cout << std::endl;
    std::cout << "Please input a cgpa for intstu" << std::endl;
    std::cin >> IDsearch; 
    if(std::cin.peek())
    {
      std::cin.ignore(100000, '\n');
    }
    std::cout << std::endl << "This is the student associated with the inputted ID: \n";
    intlst.searchAppID(IDsearch);
    std::cout << std::endl;

    std::cout << "Please input a research score for domstu" << std::endl;
    std::cin >> RSsearch; 
    if(std::cin.peek())
    {
      std::cin.ignore(100000, '\n');
    }
    std::cout << std::endl << "This is the student associated with the inputted ID: \n";
    domlst.searchAppID(RSsearch);
    std::cout << std::endl;
    std::cout << "Please input a research score for intstu" << std::endl;
    std::cin >> RSsearch; 
    if(std::cin.peek())
    {
      std::cin.ignore(100000, '\n');
    }
    std::cout << std::endl << "This is the student associated with the inputted ID: \n";
    intlst.searchAppID(RSsearch);
    std::cout << std::endl;
    goto Menuc;

    case 3: 
    ChosFname.clear();
    ChosLname.clear();
    int group1;
    std::cout << "We will now search the existing Domstu and Intstu with first name and last name" << endl; 
    std::cout << "First testing for Carter Watson inside domstu and Haibo Liu in intstu" << endl;
    domlst.searchNames("Carter", "Watson"); 
    std::cout << std::endl;
    intlst.searchNames("Haibo", "Liu");
    std::cout << std::endl;
    std::cout << "Now testing for cArTEr WaTSon inside domstu and HAibO lIu in intstu" << endl;
    domlst.searchNames("cArTEr", "WaTSon"); //THat is outside of the function it happens in main  even the error checking happens in main seriously you need to input check these it will not work otherwise 
    // will implement
    std::cout << std::endl;
    
    intlst.searchNames("HAibO", "lIu");
    std::cout << std::endl;
    std::cout << "Now testing for C arter Watson inside domstu and Haibo L iu in intstu" << endl;
    domlst.searchNames("C arter", "Watson"); 
    std::cout << std::endl;
    intlst.searchNames("Haibo", "L iu");
    std::cout << std::endl;
    std::cout << "Now testing for Cart3r Wat5on inside domstu and Haib0 L1u in intstu" << endl; 
    domlst.searchNames("Cart3r", "Wat5on"); 
    std::cout << std::endl;
    intlst.searchNames("Haib0", "L1u");
    std::cout << std::endl;

    std::cout << "Now for the user inputted values" << endl;
    userinput1:
    std::cout << "Now for the user inputted values" << endl;
    std::cout << "Where would you like to delete from select 1 for domstu, select 2 for intstu" << endl;
    std::cin >> group;
    if(std::cin.peek())
    {
      std::cin.ignore(100000, '\n');
    }
    std::cout << endl;
    std::cout << "Please input the name for the student you would like to search" << endl; 
    std::cin >> ChosFname >> ChosLname;
    if(std::cin.peek())
    {
      std::cin.ignore(100000, '\n');
    }
    if(nameCheck(ChosFname, ChosLname, "empty", "empty", 1)){
      ChosFname = NamestringFormater(ChosFname);//Name formattor
      ChosLname = NamestringFormater(ChosLname);//Name formattor
      if(group1 == 1){ //Domestic Students
        domlst.searchNames(ChosFname,ChosLname);
      }
      else if(group1 == 2){ //International Students 
        intlst.searchNames(ChosFname,ChosLname);
      }
      else {
        std::cout << "invalid group selected, try again" << endl; 
        goto userinput1;
      }
    }
    goto Menuc; 

    case 4: 
    int group;
    ChosFname.clear();
    ChosLname.clear();
    std::cout << "We will now delete the existing Domstu and Intstu with first name and last name" << endl; 
    std::cout << "First testing for cArTEr WaTSon inside domstu and HAibO lIu in intstu" << endl;
    domlst.deleteNode("cArTEr", "WaTSon");
    std::cout << domlst << endl;
    intlst.deleteNode("HAibO", "lIu"); 
    std::cout << intlst << endl;
    std::cout << "Now testing for C arter Watson inside domstu and Haibo L iu in intstu" << endl;
    domlst.deleteNode("C arter", "Watson"); 
    std::cout << domlst << endl;
    intlst.deleteNode("Haibo", "L iu");
    std::cout << intlst << endl;
    std::cout << "Now testing for Cart3r Wat5on inside domstu and Haib0 L1u in intstu" << endl; 
    domlst.deleteNode("Cart3r", "Wat5on"); 
    std::cout << domlst << endl;
    intlst.deleteNode("Haib0", "L1u");
    std::cout << intlst << endl;
    std::cout << "finally testing for Carter Watson inside domstu and Haibo Liu in intstu" << endl;
    domlst.deleteNode("Carter", "Watson"); 
    std::cout << domlst << endl;
    intlst.deleteNode("Haibo", "Liu");
    std::cout << intlst << endl;

    std::cout << "Reinserting both Carter Watson and Haibo Liu into their respective lists for user testing" << endl;
    userinput:
    std::cout << "Now for the user inputted values" << endl;
    std::cout << "Where would you like to delete from select 1 for domstu, select 2 for intstu" << endl;
    std::cin >> group;
    if(std::cin.peek())
    {
      std::cin.ignore(100000, '\n');
    }
    std::cout << endl;
    std::cout << "Please input the name for the student you would like to delete" << endl; 
    std::cin >> ChosFname >> ChosLname;
    if(std::cin.peek())
    {
      std::cin.ignore(100000, '\n');
    }
    if(nameCheck(ChosFname, ChosLname, "empty", "empty", 1)){
      ChosFname = NamestringFormater(ChosFname);//Name formattor
      ChosLname = NamestringFormater(ChosLname);//Name formattor
      if(group == 1){ //Domestic Students
        domlst.deleteNode(ChosFname,ChosLname);
      }
      else if(group == 2){ //International Students 
        intlst.deleteNode(ChosFname,ChosLname);
      }
      else {
        std::cout << "invalid group selected, try again" << endl; 
        goto userinput;
      }
    }
    std::cout << domlst << endl; 
    std::cout << intlst << endl;
    goto Menuc;

    case 5:
    std::cout << "This is the head and tail of the domstu" << endl;
    domlst.GetHeadandTail(1);
    domlst.GetHeadandTail(2);
    std::cout << "Deleting the head and tail of the domstu" << endl; 
    domlst.deleteEnds();
    std::cout << "The new head and tail of the domstu are" << endl;
    domlst.GetHeadandTail(1);
    domlst.GetHeadandTail(2);
    std::cout << "This is the head and tail of the intstu" << endl;
    intlst.GetHeadandTail(1);
    intlst.GetHeadandTail(2);
    std::cout << "Deleting the head and tail of the intstu" << endl; 
    intlst.deleteEnds();
    std::cout << "The new head and tail of the intstu are" << endl;
    intlst.GetHeadandTail(1);
    intlst.GetHeadandTail(2);
    goto Menuc;

    case 6: 
    std::cout << "This is the domstudent list \n" << domlst << endl; 
    std::cout << "This is the intstudent list \n" << intlst << endl; 
    merglst.InsertDomNode(domlst);
    merglst.InsertIntNode(intlst);
    std::cout << "Now we will merge the two lists \n" << endl << endl << merglst << endl; 

    goto Menuc; 

    case 7: 
    float CGPAThresh;
    int ResearchThresh;
    merglst.InsertDomNode(domlst);
    merglst.InsertIntNode(intlst);
    std::cout << "We will now search the merged list using cgpa_threshold and researchScore_treshhold" << endl;
    std::cout << "First searching with cgpa > 3.6 and researchScore > 0" << endl;
    merglst.SearchThreshold(3.6,0); 

    goto UnitTest;

    case 0:
    goto InputType;

  }

  Done:
  return 0;
}
