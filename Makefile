#compile and link the application
all: main

#run the application
run: main
	./main

#link main.o, student.o, stu_dent_list.o mergedStudent.o merged_list.o error_check.o to executable main
main: main.o student.o student_list.o mergedStudent.o merged_list.o
	g++ -g -o main main.o student.o student_list.o mergedStudent.o merged_list.o

#compile the main.cpp to main.o
main.o: main.cpp
	g++ -g -c main.cpp

#compile the student.cpp to student.o
student.o: student.cpp
	g++ -g -c student.cpp

#compile the student_list.cpp to student_list.o
student_list.o: student_list.cpp
	g++ -g -c student_list.cpp

#compile the mergedStudent.cpp to mergedStudent.o
mergedStudent.o: mergedStudent.cpp
	g++ -g -c mergedStudent.cpp

#compile the merged_list.cpp to merged_list.o
merged_list.o: merged_list.cpp
	g++ -g -c merged_list.cpp

#remove built files
clean:
	rm -rf main main.o student.o student_list.o mergedStudent.o merged_list.o *~

