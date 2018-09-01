#include <iostream>
#include <string>
using namespace std;

class gradbook
{
public:
	gradbook(string name);
	~gradbook();

	/* data */
};
class gradebook
{
public:
	void view(string a){
		cout<<"the name of subject is "<<a<<endl;
	}
	/* data */
};

int main(int argc, char const *argv[])
{
	cout << "please enter name of subject"<<endl;
	string na;
	getline(cin ,na);
	gradebook book1;
	book1.view(na);/* code */
	return 0;
}
