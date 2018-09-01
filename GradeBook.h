#include <string>
using namespace std;

class GradeBook
{
public:
	GradeBook(string);
	void setcoursename(string);
	void determineavg();
private:
	string coursename;
};