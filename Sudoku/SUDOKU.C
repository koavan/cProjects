#include <stdio.h>
#include <conio.h>
#include <graphics.h>
#include <dos.h>
#include <ctype.h>

struct Quadrant
{
    int cell[3][3];
};

struct Board
{
    struct Quadrant quadrant[3][3];
};

void init_Board(struct Board *b)
{
    int i=0,j;
    printf("\nInitialising Board...\n");
    for(;i<3;i++)
    {
	for(j=0;j<3;j++)
	{
	    init_Quadrant(&(b->quadrant[i][j]));
	}
    }
}

int init_Quadrant(struct Quadrant *q)
{
    int i=0,x=1,j;
    //printf("\nInitialising Quadrant\n");
    for(;i<3;i++)
    {
	for(j=0;j<3;j++)
	{
	    q->cell[i][j] = x;
	    ++x;
	}
    }
    return 0;
}

void show_Board(struct Board *b)
{
	int i,j,k,l;
	printf("Sudoku..\n");
	for(i=0;i<3;i++)	//switching rows in the board 0,1,2
	{
		for(j=0;j<3;j++) //switching rows in each quadrant
		{
			for(k=0;k<3;k++) //switching quadrants in each row
			{
				for(l=0;l<3;l++) //switching cells in a row
				{
					printf("%d\t",b->quadrant[i][k].cell[j][l]);
				}
			}
			printf("\n");
		}
	}
}

void show_BoardInColor(struct Board *b)
{
	int i,j,k,l;
	int x=10,y=10;
	//int gdriver = DETECT,gmode;
	char str[10];
	clrscr();
	//initgraph(&gdriver,&gmode,"C:\\TC\\BGI");

	setcolor(3);
	settextstyle(2,0,6);

	y=50;
	for(i=0;i<3;i++)	//switching rows in the board 0,1,2
	{
		for(j=0;j<3;j++) //switching rows in each quadrant
		{
			x=10;
			for(k=0;k<3;k++) //switching quadrants in each row
			{
				for(l=0;l<3;l++,x+=30) //switching cells in a row
				{
					sprintf(str,"%d",b->quadrant[i][k].cell[j][l]);
					outtextxy(x,y,str);
					//printf("%d\t",b->quadrant[i][k].cell[j][l]);
				}
			}
			y+=20;
			//printf("\n");
		}
	}
}


void show_Quadrant(struct Quadrant *q)
{
	int i,j;
	//printf("\nShowing a quadrant\n");
	for(i=0;i<3;i++)
	{
		for(j=0;j<3;j++)
		{
			printf("%d\t",q->cell[i][j]);
		}
		printf("\n");
	}
}

void setup_BoardUi(struct Board *b)
{
	char in1,t1[2];
	int quad=0,cell=0,value=0;
	int qrow=0,qcol=0;
	int crow=0,ccol=0;

	outtextxy(10,260,"Enter the Quadrant : ");
	in1=getch();
	quad = atoi(in1);
	sprintf(t1,"%c",in1);
	outtextxy(210,260,t1);

	outtextxy(10,290,"Enter the Cell : ");
	in1 = getch();
	cell = atoi(in1);
	sprintf(t1,"%c",in1);
	outtextxy(210,290,t1);

	outtextxy(10,320,"Enter the Value : ");
	in1 = getch();
	value = atoi(in1);
	sprintf(t1,"%c",in1);
	outtextxy(210,320,t1);

	qrow = quad / 3;
	qcol = quad % 3;
	crow = cell / 3;
	ccol = cell % 3;

	b->quadrant[qrow][qcol].cell[crow][ccol]=value;
}


void setup_BoardPrompt(struct Board *b)
{
	char in1='a',t1[2];
	int quad=0,cell=0,value=0;
	int qrow=0,qcol=0;
	int crow=0,ccol=0;

	while(in1 != 'n')
	{
		printf("\nEnter the Quadrant : ");
		scanf("%d",&quad);

		printf("Enter the Cell : ");
		scanf("%d",&cell);

		printf("Enter the Value : ");
		scanf("%d",&value);

		qrow = quad / 3;
		qcol = quad % 3;
		crow = cell / 3;
		ccol = cell % 3;

		b->quadrant[qrow][qcol].cell[crow][ccol]=value;

		printf("Do you want to continue? (y/n) : ");
		in1 = getch();
		in1 == 'N'?in1='n':0;

		clrscr();
		show_Board(b);
	}
}

void init_graphics()
{
	int gd=DETECT, gm;
	initgraph(&gd,&gm,"C:\\TC\\BGI");
	setcolor(2);
	settextstyle(2,0,6);
	outtextxy(20,20,"Sudoku..");

}

int main()
{
	struct Board myBoard;
	clrscr();
	//init_graphics();
	init_Board(&myBoard);
	show_Board(&myBoard);
	//show_Quadrant(&(myBoard.quadrant[0][0]));
	//show_BoardInColor(&myBoard);
	setup_BoardPrompt(&myBoard);
    	getch();
    	return 0;
}
