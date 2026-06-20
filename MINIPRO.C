

#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<conio.h>

int main()
{
    int a[4][4]={0};
    int i,j,k,r,c;
    int score=0;
    int moved;
    int canMove;
    char ch;

    srand(time(0));

    // initial tiles
    for(k=0;k<2;k++)
    {
	while(1)
	{
	    r=rand()%4;
	    c=rand()%4;

	    if(a[r][c]==0)
	    {
		a[r][c]=2;
		break;
	    }
	}
    }

    while(1)
    {
	clrscr();

	printf("\nScore : %d\n\n",score);
	printf("==== 2048 GAME ====\n");

	for(i=0;i<4;i++)
	{
	    for(j=0;j<4;j++)
	    {
		if(a[i][j]==0)
		    printf("   _");
		else
		    printf("%4d",a[i][j]);
	    }
	    printf("\n");
	}
	printf("\nMove: L=Left R=Right U=Up D=Down Q=Quit : ");
	scanf(" %c",&ch);

	if(ch!='l'&& ch!='r'&& ch!='u' && ch!='d' && ch!='q'
	 && ch!='L' && ch!='R' && ch!='U' && ch!='D' && ch!='Q')
	{
	  printf("Sorry...!\nYou have given wrong input\n");
	  printf("please enter correct input form above given choices");
	  getch();
	  continue;
	}

	if(ch=='q' || ch=='Q')
	    break;

	moved=0;

	// LEFT
	if(ch=='l' || ch=='L')
	{
	    for(i=0;i<4;i++)
	    {
		for(j=1;j<4;j++)
		{
		    if(a[i][j]!=0)
		    {
			k=j;
			while(k>0 && a[i][k-1]==0)
			{
			    a[i][k-1]=a[i][k];
			    a[i][k]=0;
                            k--;
                            moved=1;
                        }

                        if(k>0 && a[i][k-1]==a[i][k])
                        {
                            a[i][k-1]*=2;
                            score+=a[i][k-1];
                            a[i][k]=0;
                            moved=1;
                        }
                    }
                }
            }
        }

        // RIGHT
        if(ch=='r' || ch=='R')
        {
            for(i=0;i<4;i++)
            {
                for(j=2;j>=0;j--)
                {
                    if(a[i][j]!=0)
                    {
                        k=j;
                        while(k<3 && a[i][k+1]==0)
                        {
                            a[i][k+1]=a[i][k];
                            a[i][k]=0;
                            k++;
                            moved=1;
                        }

                        if(k<3 && a[i][k+1]==a[i][k])
                        {
                            a[i][k+1]*=2;
                            score+=a[i][k+1];
                            a[i][k]=0;
                            moved=1;
                        }
                    }
                }
            }
        }

        // UP
        if(ch=='u' || ch=='U')
        {
            for(j=0;j<4;j++)
            {
                for(i=1;i<4;i++)
                {
                    if(a[i][j]!=0)
                    {
                        k=i;
                        while(k>0 && a[k-1][j]==0)
                        {
                            a[k-1][j]=a[k][j];
                            a[k][j]=0;
                            k--;
                            moved=1;
                        }

                        if(k>0 && a[k-1][j]==a[k][j])
                        {
                            a[k-1][j]*=2;
                            score+=a[k-1][j];
                            a[k][j]=0;
                            moved=1;
                        }
                    }
                }
            }
        }

        // DOWN
        if(ch=='d' || ch=='D')
        {
            for(j=0;j<4;j++)
            {
                for(i=2;i>=0;i--)
                {
                    if(a[i][j]!=0)
                    {
                        k=i;
                        while(k<3 && a[k+1][j]==0)
                        {
                            a[k+1][j]=a[k][j];
                            a[k][j]=0;
                            k++;
                            moved=1;
                        }

                        if(k<3 && a[k+1][j]==a[k][j])
                        {
                            a[k+1][j]*=2;
                            score+=a[k+1][j];
                            a[k][j]=0;
                            moved=1;
                        }
                    }
                }
            }
        }

        // add tile only if moved
        if(moved)
        {
            while(1)
            {
                r=rand()%4;
                c=rand()%4;

                if(a[r][c]==0)
                {
                    if(rand()%10==0)
                        a[r][c]=4;
                    else
                        a[r][c]=2;
                    break;
                }
            }
        }

        // win check
        for(i=0;i<4;i++)
        for(j=0;j<4;j++)
        if(a[i][j]==2048)
        {
            clrscr();
	    printf("\nYOU WIN!\n");
            getch();
	    return 0;
        }

        // game over check
	canMove=0;

        for(i=0;i<4;i++)
        {
            for(j=0;j<4;j++)
            {
                if(a[i][j]==0)
                    canMove=1;

                if(j<3 && a[i][j]==a[i][j+1])
                    canMove=1;

                if(i<3 && a[i][j]==a[i+1][j])
                    canMove=1;
            }
        }

        if(!canMove)
        {
	    clrscr();
	    printf("\nScore : %d\n\n",score);

	    for(i=0;i<4;i++)
	    {
	      for(j=0;j<4;j++)
	      {
		if(a[i][j]==0)
		{
		   printf("    _");
		}
		else
		{
		printf("%4d",a[i][j]);
		}
	      }
	      printf("\n");
	    }
	    printf("\nGAME OVER!\n");
	    getch();
	    break;
	}
    }

    return 0;
}