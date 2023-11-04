
// Difference between String and Char array :

// 1) String : No need to define size ==> size can be changed dynamically(at runtime)
// 1) Char array : Need to define size while declaration. ==> size cannot be changed

// 2) String : always ends with special character i.e '\0'
// 2) Char array : does not end with '\0'


// //Sample code : 

#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main()
{
    // string str1;
    // cin>>str1 ; // cin takes input until whitespace is encountered!!! (cin is an object!!)
    // cout<<str1<<endl;

    // string str2;
    // getline(cin,str2); // getline(cin,str) takes input until newline is encountered!!! ( getline() is a function !!!)
    // cout<<str2<<endl;

    // cout<<str2.length()<<endl; // OR str2.size() used to print the length of string !!!

    // cout<<str2[5]<<endl; // str[index] is used to print particular char of a string , Note : printing null charactacter will show nothing!!!

    // cout<<str2.substr(3,2)<<endl; // str.substr(start_index,no_of_chars) used to print substring



    // // String concatenation example

    // string s1 = "Akshit" , s2 ="Rawat"; // we can also take input through cin

    // string s3 = s1 + s2;

    // cout<<s3<<endl;
    
    // s1.append(s2); // append s2 to s1
    // cout<<s1<<endl<<endl;



    // Insert a string after a specific position or from specific index

    string S1 = "Ayush";
    S1.insert(5,"R"); // Inserting/placing "YOOO" after position 4 or starting from index 4 in S1 using insert(after_pos/index,"string") function!!!
    cout<<S1<<endl;



//     // Finding a starting index of a particular string in a string!!!

//     cout<< S1.find("Rawat")<<endl; // find the starting index of "Rawat" in S1 !!!



//     // Erase a string from particular index

//      S1.erase(4,4); // erasing "YOOO" starting from index = 4
//      cout<<S1<<endl;


// //  Concatenate a char to a string!!!

//     vector<string> vec = {"Akshit"};

//     cout<<vec[0]<<endl;

//     char c = '-';

//     vec[0] = vec[0] + c;

//     cout<<vec[0];




 }

