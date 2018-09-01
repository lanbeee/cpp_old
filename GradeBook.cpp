#include <iostream>
#include <iomanip>
#include "GradeBook.h"
using namespace std;

GradeBook::GradeBook(string name){
	setcoursename(name);
}
void GradeBook::setcoursename(string name){
	if (name.length() <= 25){
		coursename = name;
	}
	else{
		coursename = name.substr(0,25);
		cout<< "name \""<< name <<"\" exceeds 25"<<endl;
	}
}

void GradeBook::determineavg(){
	int total = 0;
	int grade;
	int gradecounter = 0;
	double avg;

}
