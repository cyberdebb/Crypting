#include <iostream>
#include <string>
#include <cstdlib>
#include <cstring>
#include <bitset>

using namespace std;

    //An Array used to translate to Base64 values
    char base64_chars[64] = {'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z',
                            'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z',
                            '0','1','2','3','4','5','6','7','8','9','+','/'};

int main() {
    long a, c;
    int b;

    string totalBinary="";
    string output="";

    string input = "49276d206b696c6c696e6720796f757220627261696e206c696b65206120706f69736f6e6f7573206d757368726f6f6d";
    
    //Convert the hex string into a binary string
    int h=0;
    while (h != input.length()){
        string test = input.substr(h,2);

        b = stoi(test,0,16); //convert to decimal

        test = bitset<8>(b).to_string();

        totalBinary.append(test);

        h=h+2;
    }
    
    int e = 6-(totalBinary.length()%6);

    // cout << e << endl; //For testing values
    // cout << totalBinary << endl; //For testing values

        //6 bits are needed for each conversion
        switch (e) {
            case 1:
                totalBinary.append("0");
            break;
            case 2:
                totalBinary.append("00");
            break;
            case 3:
                totalBinary.append("000");
            break;
            case 4:
                totalBinary.append("0000");
            break;
            case 5:
                totalBinary.append("00000");
            break;
            case 6:
            break;
        }

    // cout << totalBinary << endl; // For testing values

        int h=0;
        // Convert 6 bits at a time into a string
        while (h!=totalBinary.length()) {

            output += (base64_chars[bitset<6>(totalBinary.substr(h,h+6)).to_ulong()]);

            h+=6;
        }

        //Calculate padding
        switch (output.length()%4){
            case 0:
            break;

            case 2:
                output.append("==");
            break;

            default:
                output.append("=");

        }

        //Output results
        cout << output;
}