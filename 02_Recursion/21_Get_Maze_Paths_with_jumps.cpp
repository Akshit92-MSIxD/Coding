// https://nados.io/question/get-maze-path-with-jumps?zen=true

// S = O(1) (**Imp here to read)

 /* The space complexity cannot be defined when space is increasing continuously 
 (as the Arraylist size keeps on increasing with new paths being added). In these situations, the space 
 complexity is approx the same as time complexity. Remember, the space complexity is only valid if we have
 used any extra memory or data structure. We used Arraylist because we were asked to store the paths in the
 question. So, we havenot used any extra data structure. So, the space complexity will be O(1). */

// T = O(3^(n+m)) , Isko dekhliyo kese Time Complexity nikalni hai!!!

#include<iostream>
#include<vector>
#include<string>

using namespace std;

vector<string> get_maze_paths(int sr, int sc, int dr, int dc) {

    if(sr==dr && sc==dc)
    {
        vector<string> base_case;
        base_case.push_back("");
        return base_case;
    }

    if(sr>dr || sc>dc)
    {
        vector<string> nothing;
        return nothing;
    }
        vector<string> path1;
        vector<string> path2;
        vector<string> path3;

        vector<string> finalpath;

        // All column jumps
        for(int cjump = 1 ; cjump<=dc-sc;cjump++)
        {
            path1 = get_maze_paths(sr,sc+cjump,dr,dc);

            char ch = cjump + 48; // ex : 1 to '1'
            string h = "h";
            
            for(string str : path1)
            {
                finalpath.push_back(h+ch+str);
            }

        }


        // All row jumps
        for(int rjump = 1 ; rjump<=dr-sr;rjump++)
        {
            path2 = get_maze_paths(sr+rjump,sc,dr,dc);

            for(string str : path2)
            {
                finalpath.push_back("v"+to_string(rjump)+str); // to_string() to covert 1 to "1"
            }

        }


         // All diagonal jumps
        for(int djump = 1 ; djump<=dc-sc && djump<=dr-sr;djump++)
        {
            path3 = get_maze_paths(sr+djump,sc+djump,dr,dc);

            for(string str : path3)
            {
                finalpath.push_back("d"+to_string(djump)+str);
            }

        }
  

   return finalpath;
    
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
    vector<string> ans = get_maze_paths(0,0,n-1,m-1);
    display(ans);

    return 0;
}