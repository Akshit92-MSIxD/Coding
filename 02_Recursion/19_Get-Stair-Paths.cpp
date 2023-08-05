// https://nados.io/question/get-stair-paths?zen=true

// T = O(3^n) , since each call , 3 recursive calls are made.

//  S = O(1) As no extra space is required, therefore space complexity is constant.
//  However, if we include the space used in the recursive stack then the space complexity is O(n).

// Draw Euler Tree for better dryrun and visualisation.


#include<iostream>
#include<vector>
#include<string>
using namespace std;

vector<string> get_stair_paths(int n){

    // 0 stair se 0 stair jnea ek hi rasta hai (chalo hi mat)
    if(n==0)
    {
        vector<string> base_case;
        base_case.push_back("");
        return base_case;
    }

   // -1 stair se ek bhi rasta ni hai , chalo ya na chalo rasta hi nahi hai
    if(n<0)
    {
        vector<string> nothing;
        return nothing;
    }

    // mujhe path1 , path2 , path3 laake dedo mai unke mu pe 1,2,3 resp lagage apne se 0 tak ka rast bana lunga
    vector<string> path1 = get_stair_paths(n-1);
    vector<string> path2 = get_stair_paths(n-2);
    vector<string> path3 = get_stair_paths(n-3);

    vector<string> path;

    for(string str : path1)
    {
        path.push_back('1'+str);
    }

    for(string str : path2)
    {
        path.push_back('2'+str);
    }

    for(string str : path3)
    {
        path.push_back('3'+str);
    }

    return path;  
}

int main(){
    int n;
    cin >> n;
    vector<string> ans = get_stair_paths(n);
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