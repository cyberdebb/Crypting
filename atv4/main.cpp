#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main()
{
  string line;
  ifstream myfile("encrypted.txt");
  if(myfile.is_open())
  {
    while(getline(myfile,line))
    {
      cout<<line<<endl;
    }
    myfile.close();
  }

  else cout << "the file could not be opened";

  
}