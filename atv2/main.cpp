#include <iostream>
#include <string>
#include <cstdlib>
#include <cstring>
#include <bitset>
#include <sstream>

using namespace std;

string Xor(string input1, string input2)
{
    int h=0;
    int a, b;
    string result="";

    while (h != input1.length()){
    string s1 = input1.substr(h,2);
    string s2 = input2.substr(h,2);

    a = stoi(s1,0,16); //convert to decimal
    b = stoi(s2,0,16); //convert to decimal

    size_t R=a^b;

    ostringstream ss;
    ss<<hex<<R;
    string str = ss.str();
       
    result.append(str); //add to the string
    h=h+2;
}
return result;
}

int main()
{
string input1="1c0111001f010100061a024b53535009181c";
string input2="686974207468652062756c6c277320657965";

cout<<Xor(input1, input2);

}