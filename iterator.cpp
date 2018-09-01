#include<iostream>
#include<iterator>

using namespace std;

int main(){
    cout<<"Enter two integers"<<endl;
    istream_iterator<int> iiterator(cin);
    int fis = *iiterator;
    cout<<"No. entered = "<<(*iiterator)<<endl;
    iiterator++;
    ostream_iterator<int> oiterator(cout);
    cout<<"ostream_iterator<int> oiterator(cout);"<<endl<<"*oiterator = *iiterator + fis;"<<endl;
    *oiterator = *iiterator + fis;
}
