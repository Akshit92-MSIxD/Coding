// https://nados.io/question/get-subsequence?zen=true
// T = O(n)


#include <iostream>
#include <vector>
using namespace std;

// ex : abc
vector<string> gss(string str){

    // if string is empty , there is only one subsequence i.e "" empty string!!!
      if(str=="")
      {
          vector<string> base_case;
          base_case.push_back("");
          return base_case;
      }


    char ch = str[0]; // a

    string ros = str.substr(1); // bc

    vector<string> subres = gss(ros); // gss(ros) will return  [--,-c,b-,bc]

    vector<string> res; // ek baar 'a' aaega or ek baar ni aaega i.e [---,--c,-b-,-bc] and [a--.a-c,ab-,abc]


    // 'a' ni aaega ==> [---,--c,-b-,-bc]

    for(string s : subres)
    {
        res.push_back(s);
    }


    // 'a' aeaega ==> [a--.a-c,ab-,abc]

    for(string s : subres)
    {
        res.push_back(ch+s);
    }

    return res; // [---,--c,-b-,-bc,a--.a-c,ab-,abc]
}

int main(){
    string s;
    cin >> s;
    vector<string> ans = gss(s);
    int cnt = 0;

    cout << "[";
    for (string str : ans){
        if (cnt != ans.size() - 1)
            cout << str << ", ";
        else
            cout << str;
        cnt++;
    }
    cout << "]";
}