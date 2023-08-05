/* https://leetcode.com/problems/largest-rectangle-in-histogram/description/ (Optimal approach)  */



// Brute force by striver (Hint : find next smaller on left and right)
// TC : O(n^2) , SC : O(1)

    #include <iostream>
    #include <vector>
    using namespace std;


// use name rb(rightbound) instead of next_smaller_right_index for each ith histogram :)
// use name lb(leftbound) instead of  next_smaller_left_index  for each ith histogram :)

    int get_max_area(vector<int> &histograms)
    {
            int n = histograms.size() , max_area = -1;

            for(int i=0;i<=n-1;i++) 
            {
                int height = histograms[i];
                int next_small_left_index = i-1 , next_small_right_index = i+1;   // lets assume that width of each histogram is 1 (dont confuse see the width calculation below you will get it why i did this :) )

            // find next smaller element on the leftside

            for(int j=i-1;j>=0;j--)
            {
                    if(histograms[j]<histograms[i])
                    {
                    next_small_left_index = j;
                    break;
                    }
            }

            // find next smaller element on the rightside

            for(int j=i+1;j<=n;j++)
            {
                if(histograms[j]<histograms[i])
                    {
                    next_small_right_index = j;
                    break;
                    }
            }
                
            int width = next_small_right_index - next_small_left_index - 1;

            int area = width  * height;

                if(area>max_area)
                max_area = area;
                
            }

            return max_area;
    }

    int main()
    {

    int n;
    cout<<"Enter the size of the array : ";
    cin>>n;

    vector<int> histograms(n,0);

    cout<<"Enter the numbers inside the array : ";

    for(int i=0;i<n;i++)
    {
        cin>>histograms[i];
    }

    int max_area = get_max_area(histograms);

    cout<<"Area of largest rectangle formed in histogram : "<<max_area<<endl;

    }


/*-----------------------------------------------------------------------------------------------------------------------------------------*/



// // Brute force by me (Please draw histogram test cases to understand the brute force better!!!)
// // TC : O(n^2) , SC : O(1)

//     #include <iostream>
//     #include <vector>
//     using namespace std;


//     int get_max_area(vector<int> &histograms)
//     {
//             int n = histograms.size() , max_area = -1;

//             for(int i=0;i<=n-1;i++)  // select ith histogram of array 
//             {
//                 int height = histograms[i]; // consider it as base
//                 int width = 1;     // width is 1 for each  ith histogram in array (given)

//                 for(int j=0;j<=n-1;j++) // select those jth histograms which are greater or equal to ith histogram
//                 {
//                     if(i==j)     // dont select the same histogram 
//                     continue;

//                     if(histograms[j] > histograms[i])
//                     {
//                     width+=1; // width will get increased by one for every jth histogram greater or equal to ith histogram || include the jth histogram for the rectangle making process!!!
//                     }
//                     else
//                     {
//                         if(j<i)   // if any jth histogram on the left side found to be less than ith histogram exclude all the histograms collected till that moment (why?? think easy:) )
//                         width = 1;
//                         else
//                         break;   // if jth smaller histogram is found on right side of ith histogram then dont exclude all the histograms collected till this moment and just break
//                     }
//                 }
                
//                 int area = width * height;    // Calculate area of that rectangle which is formed by those included histograms including ith histogram

//                 if(area>max_area)
//                 max_area = area;
                
//             }

//             return max_area;
//     }

//     int main()
//     {

//     int n;
//     cout<<"Enter the size of the array : ";
//     cin>>n;

//     vector<int> histograms(n,0);

//     cout<<"Enter the numbers inside the array : ";

//     for(int i=0;i<n;i++)
//     {
//         cin>>histograms[i];
//     }

//     int max_area = get_max_area(histograms);

//     cout<<"Area of largest rectangle formed in histogram : "<<max_area<<endl;




//     }