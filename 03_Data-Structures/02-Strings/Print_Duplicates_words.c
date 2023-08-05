#include <stdio.h>
#include <string.h>


int return_left(int j1 , char str[])
{
    int tleft;
    for(int j=j1;str[j]!='\n';j++)
    {
         if(str[j]!=' ' && str[j-1]==' ')
         {
            tleft = j;
            return tleft;
         }

    }
    return -1;

}

int return_right(int j2 , char str[])
{
    int tright;

      for(int j=j;str[j]!='\n';j++)
    {

         if(str[j]!=' ' && (str[j+1]==' ' || str[j+1]=='\0'))
         {
            tright = j;
            return tright;
         }
    }

    return -1;

}

void make_0(int isvisted[],int tleft , int tright)
{
   for(int i=tleft ; i<=tright;i++)
   {
      isvisted[i]=0;
   }
}

int main()
{
    int n;
    scanf("%d",&n);

    fflush(stdin);

    char str[n];
    int isvisited[n];

    for(int i=0;i<n;i++)
    {
        isvisited[i]=-1;
    }

    scanf("%[^\n]s",str);
  
    int cleft=0, cright;

    for(int i=0;str[i]!='\0';i++)
    {
         if(str[i]!=' ' && str[i-1]==' ')
         {
            cleft = i;
         }

         if(str[i]!=' ' && (str[i+1]==' ' || str[i+1]=='\0'))
         {
            cright = i;
           
           if(isvisited[cleft]==0 && isvisited[cright]==0)
           {
            continue;
           }

            int cdiff = cright - cleft;

            int j = i+1;

            int count = 1;

            while(str[j]!='\0')
            {
               int tleft = return_left(j,str);
               int tright = return_right(tleft+1,str);

                int tdiff = tright - tleft;

                if(cdiff == tdiff)
                {
                    int is_word_equal = 1;
                    for(int trw1 = cleft , trw2 = tleft ; trw1<=cright && trw2<=tright ; trw1++ , trw2++)
                    {
                          if(str[trw1]!=str[trw2])
                          {
                            is_word_equal = 0;
                            break;
                          }
                    }

                    if(is_word_equal==1)
                    {
                         make_0(isvisited,tleft,tright);
                         count++;
                    }

                }

                 j=tright+1;
            }

            if(count>1)
                {
                    for(int i=cleft ; i<=cright;i++)
                    {
                        printf("%c",str[i]);
                    }
                    printf("\n");
                }
         }
    }

}