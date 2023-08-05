// https://nados.io/question/get-maze-paths?zen=true

// T = O(2^n),This time complexity is exponential because for each state, 2 recursion calls are made.

// S = O(1) , O(1) As no extra space is required, therefore space complexity is constant.
  //However,if we include the space used in the recursive stack then the space complexity is O(n).

// Draw Euler tree for better Visualization

// We'll find more such questions with some variations and different solution approaches. This question
// will build a stable base for those questions .


#include<iostream>
#include<vector>
using namespace std;


// sr - source row
// sc - source column
// dr - destination row
// dc - destination column

// Apne se aage wala ek row and ek column se sare raste maango or uske baad "h" and "v" lagado accordingly !!!!
#include<iostream>
#include<vector>

using namespace std;

// sr - source row
// sc - source column
// dr - destination row
// dc - destination column
vector <string> getMazePaths(int sr, int sc, int dr, int dc) {

   
   if(sr==dr && sc==dc)
   {
       vector<string> base;
       base.push_back("");
       return base;
   }

   if(sr>dr || sc>dc)
   {
       vector<string> nothing;
       return nothing;
   }

    vector<string> subpath1 = getMazePaths(sr,sc+1,dr,dc);
    vector<string> subpath2 = getMazePaths(sr+1,sc,dr,dc);

    vector<string> path ;

    for(string st : subpath1)
    {
        path.push_back('h'+st);
    }

    for(string st : subpath2)
    {
        path.push_back('v'+st);
    }

    return path;




}

void display(vector<string>& arr){
    cout << "[";
    for(int i = 0;i < arr.size();i++){
        cout << arr[i];
        if(i < arr.size() -1) cout << ", ";
    }
    
    cout << "]"<<endl;
}


int main() {
    int n,m; cin >> n >> m;
    vector<string> ans = getMazePaths(0,0,n-1,m-1);
    display(ans);

    return 0;
}