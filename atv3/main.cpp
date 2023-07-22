#include <iostream>
#include <string>
#include <cstdlib>
#include <cstring>
#include <bitset>
#include <sstream>
#include <cstring>

using namespace std;

string Xor(string input, char ch)
{
    int h=0;
    int a, b;
    string result="";
    string s = "";
    int ascii = int(ch);

    while(s.length() < input.length()){
    ostringstream os;
    os<<ascii;
    string str = os.str();
    s.append(str);     
    }

    while (h != input.length()){
    string s1 = input.substr(h,2);
    string s2 = s.substr(h,2);

    a = stoi(s1,0,16); //convert to decimal
    b=stoi(s2);

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
    string input="1b37373331363f78151b7f2b783431333d78397828372d363c78373e783a393b3736";

    char alfa[] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};
    
    for (int i=0; i<26; i++){
    cout<<"letter "<<alfa[i]<<": ";
    cout<<Xor(input, alfa[i])<<endl;
    }

cout<<"\nby decoding each one of the answers, the 'X' key is the that gives us a full sentence:"<<endl;
cout<<"Cooking MC's like a pound of bacon";
}

