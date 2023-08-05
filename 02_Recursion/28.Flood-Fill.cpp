// https://nados.io/article/flood-fill?zen=true
// (*) Watch solution video(must)
// Time Complexity :

// O(4*(n^2)) which can simply be written as O(n^2). This is because each cell of the matrix is processed at most 4 times.
// For Example, a particular cell can be called by its top, down, left or right cell.


// SPACE COMPLEXITY :

// O(n^2) Since an extra 2D array is used for storing "visited" cells therefore the space complexity is quadratic.


#include<iostream>
#include<vector>

using namespace std;

void floodfill(vector<vector<int>> &maze , int sr , int sc , int dr , int dc , vector<vector<bool>> &visited,string ans) {

         if((sr==dr) && (sc==dc))
         {
            cout<<ans<<endl;
            return;
         }

         if(sr<0 || sr>dr|| sc<0 || sc>dc || visited[sr][sc]==true || maze[sr][sc]==1 )
         {
             return;
         }

         visited[sr][sc] = true;

         floodfill(maze,sr-1,sc,dr,dc,visited,ans+"t");
         floodfill(maze,sr,sc-1,dr,dc,visited,ans+"l");
         floodfill(maze,sr+1,sc,dr,dc,visited,ans+"d");
         floodfill(maze,sr,sc+1,dr,dc,visited,ans+"r");

         visited[sr][sc] = false;
}

int main() {
    int n, m;
    cin >> n >> m;
    vector < vector < int >> maze(n, vector<int>(m));
    vector<vector<bool>> visited(n,vector<bool>(m,false));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> maze[i][j];
        }
    }
    int dr = maze.size()-1;
    int dc = maze[0].size()-1;
    floodfill(maze,0,0,dr,dc,visited,"");
}



















































