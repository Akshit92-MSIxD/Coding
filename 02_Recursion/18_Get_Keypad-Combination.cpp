// https://nados.io/article/get-kpc?zen=true
// T = O(n) , n recursive calls

#include<iostream>
#include<string>
#include<vector>
using namespace std;

string ccs(char s)
{
    switch(s)
    {
        case '0' : return ".;";

        case '1' : return "abc";

        case '2' : return "def";

        case '3' : return "ghi";

        case '4' : return "jkl";

        case '5' : return "mno";
        
        case '6' : return "pqrs";

        case '7' : return "tu";

        case '8' : return "vwx";

        case '9' : return "yz";
    }
}

// ex : "789"
vector<string> getKPC(string s){

  // base case
    if(s=="")
    {
        vector<string> base_case;
        base_case.push_back("");
        return base_case;
    }

   // self work

    char ch = s[0]; // '7'

    string cchs = ccs(ch); // '7'==>"tu"

    string ros = s.substr(1); // "89"

    // Recursive case (faith)
    vector<string> subresult = getKPC(ros); // subresult = [vy, vz, wy, wz, xy, xz]
  
    vector<string> result; 

    for(char c : cchs)
    {
        for(string str : subresult)
        {
            result.push_back(c+str);
        }
    }
  
   return result; // result = [tvy, tvz, twy, twz, txy, txz, uvy, uvz, uwy, uwz, uxy, uxz]

   
}


int main(){
    string s;
    cin >> s;
    vector<string> ans = getKPC(s);
    int cnt = 0;

    cout << '[';
    for (string str : ans){
        if (cnt != ans.size() - 1)
            cout << str << ", ";
        else
            cout << str;
        cnt++;
    }
    cout << ']';
}