// https://nados.io/question/print-maze-paths-with-jumps
// TC = O(3^(n+m)) , Isko dekhliyo kese Time Complexity nikalni hai!!!
// SC = O(1)

#include<iostream>
using namespace std;


    void printMazePaths(int sr, int sc, int dr, int dc, string psf) {
        

        if(sr==dr && sc==dc)
        {
            cout<<psf<<endl;
            return;
        }

        if(sr>dr || sc>dc)
        {
            return;
        }


        for(int cjump = 1 ; cjump<=dc-sc;cjump++)
        {
             printMazePaths(sr,sc+cjump,dr,dc,psf+"h"+to_string(cjump));
        }

        for(int rjump = 1 ; rjump<=dr-sr;rjump++)
        {
             printMazePaths(sr+rjump,sc,dr,dc,psf+"v"+to_string(rjump));
        }

        for(int djump = 1 ; djump<=dr-sr && djump<=dc-sc;djump++)
        {
             printMazePaths(sr+djump,sc+djump,dr,dc,psf+"d"+to_string(djump));
        }
        
        
    }

int main() {
        int n ;
        int m ;cin>>n>>m;
        printMazePaths(0, 0, n - 1, m - 1, "");
    }