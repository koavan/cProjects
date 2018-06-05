/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>
#include <string.h>
#include <conio.h>
#include <stdlib.h>

#define ROW 40
#define COL 20
#define LEN 200
#define FLOOR 2

//inventory items
int havelamp=0;
int havekey=0;

int rpos;
int cpos;
int fpos;
int movecount = 0;

int lamprpos=0;
int lampcpos=0;
int lampfpos=0;
int keyrpos=0;
int keycpos=0;
int keyfpos=0;
int trpos=0;
int tcpos=0;
int tfpos=0;
int teamflag1=0;
int teamflag2=0;
int sendnote=0;
int giftpoints=0;
int conf_flag=0;

char a[ROW][COL][FLOOR][LEN];
int board[ROW][COL][FLOOR];

void displayhelp(void);
void giftpos();
void initboard1(void);
void update1(int,int,int,char *);

#define INITROW 7
#define INITCOL 10
#define INITFLOOR 0

#define LAMPROW 29
#define LAMPCOL 8
#define LAMPFLOOR 0

#define KEYROW  9
#define KEYCOL  15
#define KEYFLOOR 0

#define TREASUREROW 29
#define TREASURECOL 6
#define TREASUREFLOOR 0

void initboard(void)
{
    int i,j,k;
    
    rpos = INITROW; /* initial position */
    cpos = INITCOL;
    fpos = INITFLOOR;
    teamflag1=1;
    teamflag2=1;
    giftpoints = 1;
    sendnote = 1;
    conf_flag = 1;
    
    puts("\nWelcome to SSIET Treasure Hunt by CDC Team!!!");
    puts("\nThe objective of this game is to explore the place identify as many items and find the treasure");
    puts("You will be accumulating many items along the way");
    puts("You have to find the lamp and the key and then get to the Treasure Room!");
    puts("\nCollect points along the way!!!");
    puts("\n******Helpful hint - take a paper and pen and note down your position and move directions..*******");
    puts("Moving left is moving West, moving right is moving East, moving up is moving North and moving down is moving South");
    puts("\nHappy Hunting...TreasureHunting!!\n***********************************************\n");
    
    displayhelp();
    giftpos();
    
    for(i=0;i<ROW;++i)
        for(j=0;j<COL;++j)
        for(k=0;k<FLOOR;++k)
            strcpy(a[i][j][k],"WALL/FENCE!");
    
    for(i=0;i<ROW;++i)
        for(j=0;j<COL;++j)
            for(k=0;k<FLOOR;++k)
                board[i][j][k] = 0;
                
    initboard1();
}

void display()
{
    
    if(rpos < ROW && cpos < COL && fpos < FLOOR)
    {
        //printf("\nYou are now at ");
        puts(a[rpos][cpos][fpos]);
    }
    else
    {
        puts("out of place!! going back to initial position");
    rpos = INITROW; /* initial position */
    cpos = INITCOL;
    fpos = INITFLOOR;
    
        display();
    }
}

void displayinventory()
{
    puts("You have ");
    if(havelamp > 0)
        printf("a Lamp!");
    else if(havekey > 0)
        printf("and a key!");
    else
        printf("nothing as of now! Happy exploring..");
}

void displayhelp()
{
    printf("\nExplore the place and find the treasure!");
    printf("\nTo explore use: \n");
    puts("A to move West ");
    puts("S to move South ");
    puts("W to move North");
    puts("D to move East");
    //puts("U to move floor up");
    puts("H for help");
    puts("I for inventory");
}

void checkpos(void)
{
   int flag = 0;
   if(cpos == lampcpos && rpos == lamprpos && fpos == lampfpos)
   {
       if(havelamp == 0)
       {
           puts("\n\n*************************************\nGreat!!! You have found the lamp. Continue hunting...\n*****************");
           havelamp = 1;
           flag = 1;
       }
   }
   if(flag == 0 && sendnote == 1 && ((movecount % 300) == 0) && movecount > 0)
   {
       printf("\nWell you have spent quite sometime. Let me help");
       if(havekey == 1)
       {
           puts("You have found the key");
       }
       else
       {
           puts("\nSearch for the key in the PLACE OF BOOKS in the college");
       }
       if(havelamp == 1)
       {
           puts("\nYou have found the lamp");
       }
       else
       {
           puts("\nSearch for the lamp near the only WINGS OF FIRE - Trinidad within college");
       }
       if(havelamp == 1 && havekey == 1)
       {
           puts("\nHead to this place - EMSIRAN HLAH II");
       }
   }
   else if(flag == 0 && sendnote == 1 && ((movecount % 801) == 0) && movecount > 0)
   {
       printf("\nWell you have spent quite sometime. Let me help");
       if(havekey == 1)
       {
           puts("You have found the key");
       }
       else
       {
           puts("\nSearch for the key in the LIBRARY in the college");
       }
       if(havelamp == 1)
       {
           puts("You have found the lamp");
       }
       else
       {
           puts("\nSearch for the lamp near the Acadmic block entrance within college");
       }
       if(havelamp == 1 && havekey == 1)
       {
           puts("Head to this place - Seminar Hall II");
       }
   }
   
  if(cpos == keycpos && rpos == keyrpos && fpos == keyfpos)
   {
       if(havekey == 0)
       {
           puts("\n*****************************************\nGreat!!! You have found the key. Continue hunting...\n");
           havekey = 1;
           flag = 1;
       }
   }
   if(teamflag1 == 1 && cpos == 9 && rpos == 12)
   {
       teamflag1 = 0;
       puts("\nHey Team-3 is also in the same place searching for the treasure ...Hurry!\n");
   }
   
   if(teamflag2 == 1 && cpos == 10 && rpos == 34)
   {
       teamflag2 = 0;
       puts("\nHey Team-blazers is also in the same place searching for the treasure....\n");
   }
   
   if(cpos == 8 && rpos == 1 && fpos == 0)
   {
       giftpoints += 50;
       printf("\nYou have come to the clue corner\n");
      if(havekey == 1)
       {
           puts("You have already found the key");
       }
       else
       {
           puts("\nSearch for the key in the PLACE OF BOOKS in the college");
       }
       if(havelamp == 1)
       {
           puts("You have already found the lamp");
       }
       else
       {
           puts("\nSearch for the lamp near the only WINGS OF FIRE - Trinidad within college");
       }
       if(havelamp == 1 && havekey == 1)
       {
           puts("Head to this place - EMSIRAN HLAH II");
       }
   }
   
      
   if(cpos == 4 && rpos == 17 && fpos == 0)
   {
       //puts("You are collecting gift points");
       puts("You have come to the clue corner!!!");
       giftpoints += 51;
     
        if(havekey == 1)
       {
           puts("You have already found the key");
       }
       else
       {
           puts("\nSearch for the key in the PLACE OF BOOKS in the college");
       }
       if(havelamp == 1)
       {
           puts("You have already found the lamp");
       }
       else
       {
           puts("\nSearch for the lamp near the only WINGS OF FIRE - Trinidad within college");
       }
       if(havelamp == 1 && havekey == 1)
       {
           puts("Head to this place - EMSIRAN HLAH II");
       }
       
   }
   
   if( havelamp == 1 && havekey == 1)
   {
       if(flag == 1)
       {
        puts("\n****************************************\nFantastic! You have found a lamp and a key!! The treasure room is now open\n************************\n");
        trpos = TREASUREROW;
        tcpos = TREASURECOL;
	    tfpos = TREASUREFLOOR;
		update1(TREASUREROW,TREASURECOL,TREASUREFLOOR,"You have arrived at Seminar hall II and found the treasure!!!!");
		
       }
       else
       {
           if(rpos == trpos && tcpos == cpos && fpos == tfpos)
           {
               printf("\nYou have won the game!! Report to the CDC Coding Team coordinator");
               printf("\nYou took %d moves %d points! Congratulations\n", movecount,giftpoints);
               exit(0);
           }
       }
   }
   
}
void giftpos()
{
    //lamp
    lamprpos = LAMPROW;
    lampcpos = LAMPCOL;
    lampfpos = LAMPFLOOR;
    havelamp = 0;
    
    //key
    keyrpos = KEYROW;
    keycpos = KEYCOL;
    keyfpos = KEYFLOOR;
    havekey = 0;
    
    
    if(lampcpos < 0 || lampcpos > COL) printf("error in position");
    if(lamprpos < 0 || lamprpos > ROW) printf("error in position");
    if(keycpos < 0 || keycpos > COL) printf("error in position");
    if(keyrpos < 0 || keyrpos > ROW) printf("error in position");
}

int main()
{
    char input;
    char ch;
    
    initboard();
    puts("\nTo start with - There is a hut with thatched roof. You hear bird sounds. You hear a music and sounds of leaves rustling..");
    while(1)
    {
        fflush(stdin);
        
        ch = getch();
        switch(ch)
        {
            case 'A':
            case 'a':
            case 27:
                if(cpos == 0 || board[rpos][cpos-1][fpos] == 0)
                    printf("cannot move further West\n");
                else 
                {
        	    movecount++;
                    cpos--;
                    display();
                }
                break;
           case 'W':
           case 'w':
           case 91:
                if(rpos == 0 || board[rpos-1][cpos][fpos] == 0)
                    printf("\nCannot move further North\n");
                else
                {
        	    movecount++;
                    rpos--;
                    display();
                }
                break;
           case 'S':
           case 's':
           case 66:
                if(rpos == ROW-1 || board[rpos+1][cpos][fpos] == 0)
                    printf("\nCannot move further South\n");
                else
                {
        	    movecount++;
                    rpos++;
                    display();
                }
                break;
           case 'D':
           case 'd':
           case 67:
                if(cpos == COL-1 || board[rpos][cpos+1][fpos] == 0)
                    printf("\nCannot move further East\n");
                else
                {
        	    movecount++;
                    cpos++;
                    display();
                }
                break;
           case 'U':
           case 'u':
                if(fpos == FLOOR-1 || board[rpos][cpos][fpos+1] == 0)
                    printf("\nCannot move further up - You are in top floor\n");
                else
                {
        	    movecount++;
		    fpos++;
                    display();
                }
                break;
           case 'J':
           case 'j':
                if(fpos == 0 || board[rpos][cpos][fpos-1] == 0)
                    printf("\nCannot move further down. You are already on ground floor\n");
                else
                {
        	    movecount++;
		    fpos--;
                    display();
                }
                break;
            case 'h':
            case 'H':
                displayhelp();
                break;
            case 'i':
            case 'I':
                displayinventory();
                break;
            case '\n':
            case '\r':
            //case 10:
            break;
            default:
                printf("\nunknown key pressed %c %d\n",ch,ch);
                puts("press h if you need help");
                //displayhelp();
                break;
            }
            //printf("\n%d %d\n", rpos,cpos);
            checkpos();
    }
    return 0;
}

void update1(int row, int col, int fl,char *s)
{
    
    if(row >= ROW || col >= COL || fl >= FLOOR )
      printf("__update__ %d %d %d",row,col,fl);
      
    strcpy(a[row][col][fl],s);
    board[row][col][fl]=1;
}


void initboard1(void)
{
    
    int i;
	strcpy(a[1][8][0],"College Entrance Gate - West. Security is not allowing to proceed in this direction");
	board[1][8][0] = 1;
	strcpy(a[1][9][0],"College Entrance Gate - CENTER. Security is not allowing to proceed in this direction");
	board[1][9][0] = 1;
	strcpy(a[1][10][0],"Col ege Entrance Gate - East. Security is not allowing to proceed in this direction");
	board[1][10][0] = 1;
	strcpy(a[2][10][0],"You are on East side of a road with gardens on either ride");
	board[2][10][0] = 1;
	strcpy(a[2][9][0],"You are on a road with gardens on either ride");
	board[2][9][0] = 1;
	strcpy(a[2][8][0],"You are on a West side of a road with gardens on either ride");
	board[2][8][0] = 1;
	strcpy(a[3][10][0],"You are on East side of the road. The road is blocked here with an entrance on the West side and a road continuing on North side.\n There is a barricade on South...");
	board[3][10][0] = 1;
	strcpy(a[3][9][0],"You are on center of the road. The road is blocked here with one entrance on the West side and a road continuing on North side. \nThere is a barricade on South...");
	board[3][9][0] = 1;
	strcpy(a[3][8][0],"You are on West side of the road. The road is blocked here with one entrance to the parking lot on the West side. \nThere is a barricade on South side and the road continues on the North side");
	board[3][8][0] = 1;
	strcpy(a[3][7][0],"You are on a mud road that continues in East West direction. You see a ball badminton court on the South. \nYou cannot enter there");
	board[3][7][0] = 1;
	strcpy(a[3][6][0],"You are on a mud road that continues in East West direction. You see a ball badminton court on the South.\nYou cannot enter there. A bus parking lot is on the West");
	board[3][6][0] = 1;
	strcpy(a[3][5][0],"You are on the North West end of the bus parking lot. You see a few yellow buses here."); 
	board[3][5][0] = 1;
	strcpy(a[4][5][0],"You are in a bus parking lot..You see 2 wheeler parking on your East");
	board[4][5][0] = 1;
	strcpy(a[5][5][0],"You are in a bus parking lot..You see bus number 10 parked here");
	board[5][5][0] = 1;
	strcpy(a[6][5][0],"You are in a bus parking lot..You see bus number 9 parked here");
	board[6][5][0] = 1;
	
	strcpy(a[7][10][0],"You are at the initial position. There is a hut with thatched roof. You hear bird sounds");
	board[7][10][0] = 1;
	strcpy(a[6][10][0],"You are on a pavement running East West. You are in the West end of the pavement");
	board[6][10][0] = 1;
	strcpy(a[6][11][0],"You are on a pavement running East West. You see gardens on the South and a compound wall on your North");
	board[6][11][0] = 1;
	strcpy(a[6][12][0],"You are on a pavement running East West. You see gardens on the South with ducks and a compound wall on your North");
	board[6][12][0] = 1;
	strcpy(a[6][13][0],"You are on a pavement running East West. You are near an intersection");
	board[6][13][0] = 1;
	strcpy(a[6][14][0],"You are on a pavement running East West. You are at the intersection. There is a road running South. There is no road towards North");
	board[6][14][0] = 1;
	strcpy(a[6][15][0],"You are on a pavement running East West. You are behind the academic block");
	board[6][15][0] = 1;
	strcpy(a[6][16][0],"You are at the East end. Actually the East North corner of the plot. You see a cricket ground in front of you. You cannot go there");
	board[6][16][0] = 1;
	
	
	
	strcpy(a[7][16][0],"You are on a pavement pathway running North South. You see academic block on the west and a cricket ground on the east");
	board[7][16][0] = 1;
	
	strcpy(a[8][16][0],"You are on a pavement pathway running North South. You see academic block on the West and cricket ground on the East");
	board[8][16][0] = 1;
	
	strcpy(a[9][16][0],"You are at an intersection. The road runs North South and also West towards academic block");
	board[9][16][0] = 1;
	
	strcpy(a[10][16][0],"You are on a pavement pathway running North South. You see an airplane on the West and cricket ground on the East");
	board[10][16][0] = 1;
	
	strcpy(a[11][16][0],"You are on a pavement pathway running North South. You see an airplane on the West and cricket ground on the East. \nApproaching intersection");
	board[11][16][0] = 1;
	
	for(i=13;i<35;++i)
	{
	   sprintf(a[i][16][0],"You are on a long pavement running North South. It is headed towards mess building on South and cricket ground on North. You are on step %d",i);
	   board[i][16][0] = 1;
	}
	 
	for(i=6;i<16;++i)
	{
	   sprintf(a[34][i][0],"You are on a pavement running East West. On North you see the main building and on South you see the mess building. Step %d",i);
	   board[34][i][0] = 1;
	}
	
	strcpy(a[34][10][0],"You are at an intersection. path continues East West and there is an entrance #1 to the main building on the North");
	board[34][10][0] = 1;
	
	strcpy(a[34][12][0],"You are at an intersection. path continues East West and there is an entrance #2 to the main building on the North");
	board[34][12][0] = 1;
	
	strcpy(a[8][14][0],"You are on a pavement pathway running North South near an intersection.\n You see academic block on the East in a distance after a lawn and 2 white ducks on the West in a garden");
	board[8][14][0] = 1;
	
	strcpy(a[9][14][0],"You are at an intersection.  The pavement pathway is running North South. You see a road to your East which leads to academic block");
	board[9][14][0] = 1;
	
	strcpy(a[9][15][0],"You are in front of the academic block. It is locked. You see an airplane to your South, academic block door locked towards your North\n");
	board[9][15][0] = 1;
	
	strcpy(a[10][14][0],"You are on a pavement pathway running North South. You see academic block on the East and a garden with a pond on the West. \nYou see a group of students walking towards academic block");
	board[10][14][0] = 1;
	
	strcpy(a[11][14][0],"You see gardens on your West, a pavement road running North South, a gentle breeze hits you from the West");
	board[11][14][0] = 1;
	
	strcpy(a[7][5][0],"You are in a bus parking lot..You see bus number 8 parked here");
	board[7][5][0] = 1;
	strcpy(a[8][5][0],"You are in a bus parking lot..You see bus number 7 parked here");
	board[8][5][0] = 1;
	strcpy(a[9][5][0],"You are in a bus parking lot..You see bus number 6 parked here");
	board[9][5][0] = 1;
	strcpy(a[10][5][0],"You are in a bus parking lot..You see bus number 5 parked here");
	board[10][5][0] = 1;
	strcpy(a[11][5][0],"You are in a bus parking lot..You also see a basket ball court on your East");
	board[11][5][0] = 1;
	strcpy(a[12][5][0],"You are in a bus parking lot..You see a muddy bus parking lot with buses here on your North and a pathway leading to buildings on your East");
	board[12][5][0] = 1;
	strcpy(a[12][6][0],"You are on a road with pavement. You see a ground with boys hostels on South and basket ball court on your North. \nThe pavement road continues East West");
	board[12][6][0] = 1;
	strcpy(a[12][7][0],"You are on a road with pavement. You see a sign board showing directions to college building, hostel, cricket ground");
	board[12][7][0] = 1;
	strcpy(a[12][8][0],"You are on a road with pavement. You see a canteen on the North and boys hostel on the South");
	board[12][8][0] = 1;
	strcpy(a[12][9][0],"You are on a road with pavement. You see a lawn on the North and a building on the South");
	board[12][9][0] = 1;
	strcpy(a[12][10][0],"You are on a road with pavement. You see a lawn with flowers on the North and a building on the South");
	board[12][10][0] = 1;
	strcpy(a[12][13][0],"You are on a road running East West with pavement. You see an Indian flag to your west!");
	board[12][13][0] = 1;
	strcpy(a[12][12][0],"You are on a road with pavement. You see a stair case leading to the mainbuilding on your South and a pavement path way running East West");
	board[12][12][0] = 1;
	strcpy(a[12][11][0],"You are on a road with pavement. You see a stair case leading to the mainbuilding on your North and a path way on \nyour South and a pavement path way running East West");
	board[12][11][0] = 1;
	strcpy(a[12][14][0],"You are on a road with pavement. The road runs North South and there is another road that runs East West which meets here");
	board[12][14][0] = 1;
	strcpy(a[12][15][0],"You are on a road with pavement. You see a building wall on your South and a glider aeroplane landed on your North and a \npavement running East West");
	board[12][15][0] = 1;
	strcpy(a[12][16][0],"You are at an intersection. You are on the East end of the pavement. The pavement also runs north-south from a cricket ground to hostel far away\n");
	board[12][16][0] = 1;
	update1(13,12,0,"You are at the front entrance of the main buding");
	update1(13,11,0,"You are at the front entrance of the main buding - near a glass door");
	update1(14,12,0,"You are inside main building and see a design on the floor");
	update1(14,11,0,"You are inside main building and see a flower pot");
	update1(15,12,0,"You are in main builing corridor");
	update1(15,11,0,"You are in main building corridor and see flex board with placed students names");
	
	strcpy(a[22][10][0],"The path on the North is blocked. You have a stair case on the West CLOSED and pathway on the East. The path continues South");
	board[22][10][0] = 1;
	
	strcpy(a[23][10][0],"You have a stair case on the West and pathway on the East. The path continues South");
	board[23][10][0] = 1;
	
	strcpy(a[24][10][0],"The path runs North South. There is an open area on the East. On the West you have Civil department - entrance closed");
	board[24][10][0] = 1;
	
	strcpy(a[25][10][0],"The path runs North South. There is an open area on the East.On the West you have Civil department - entrance closed");
	board[25][10][0] = 1;
	
	strcpy(a[26][10][0],"The path runs North South. There is an open area on the East");
	board[26][10][0] = 1;
	
	strcpy(a[27][10][0],"The path runs North South. There is an open area on the East");
	board[27][10][0] = 1;
	
	strcpy(a[28][10][0],"The path runs North South. This is an intersection. On the West you see a path way to seminar hall II. On East you see another path");
	board[28][10][0] = 1;
	
	strcpy(a[28][6][0],"You are at the West end of the pathway. You see a seminar hall CLOSED on the South and a corridor running East.");
	board[28][6][0] = 1;
	
	strcpy(a[28][7][0],"This path runs East West. You see a seminar hall window on the South");
	board[28][7][0] = 1;
	
	strcpy(a[28][8][0],"This path runs East West. You see a library window on the South");
	board[28][8][0] = 1;
	
	strcpy(a[28][9][0],"The path runs East West. You see the library wall on your South");
	board[28][9][0] = 1;
	
	strcpy(a[29][10][0],"The path runs North South. You see library entrance on the West OPEN and a shuttle court on the East");
	board[29][10][0] = 1;
	
	update1(30,10,0,"You see library window on your West and shuttle court on your East");
	update1(31,10,0,"You see library wall on your West and shuttle court on your East");
	update1(32,10,0,"You see library wall on your West and shuttle court on your East");
    update1(33,10,0,"You have come to the end of the North West end of the building");
    strcpy(a[29][11][0],"The path runs East West. It connects two pathways");
	board[29][11][0] = 1;
	
	strcpy(a[29][9][0],"You are at the library entrance. The library is on your West!");
	board[29][9][0] = 1;
	
	strcpy(a[29][8][0],"You are inside the library!");
	board[29][8][0] = 1;
	
	strcpy(a[33][12][0],"You are inside the building. You are on a pathway. On your East you see Mech Engineering Window and on the West you see a shuttle court");
	board[33][12][0] = 1;
	
	strcpy(a[32][12][0],"You are inside the building. You are on a pathway running North South. \nOn your East you see Mech department entrance closed and on the West you see a shuttle court");
	board[32][12][0] = 1;
	
	strcpy(a[31][12][0],"You are on a pathway running North South. On your East you see a wall and on the West you see a shuttle court");
	board[31][12][0] = 1;
	
    strcpy(a[30][12][0],"You are on a pathway running North South. On your East you see a wall and on the West you see a pillar");
	board[30][12][0] = 1;

   strcpy(a[29][12][0],"You have approached an intersection. It runs North South as well as to the West");
	board[29][12][0] = 1;
	
	strcpy(a[28][12][0],"You are inside the building. You are on a pathway. On your East you see EEE Engineering Window and on the West you see a open area");
	board[28][12][0] = 1;
	
	strcpy(a[27][12][0],"You are inside the building. You are on a pathway running North South. \nOn your East you see Mech department entrance closed and on the West you see a shuttle court");
	board[27][12][0] = 1;
	
	strcpy(a[26][12][0],"You are on a pathway running North South. On your East you see a wall and on the West you see an open area");
	board[26][12][0] = 1;
	
    strcpy(a[25][12][0],"You are on a pathway running North South. On your East you see a wall and on the West you see a pillar");
	board[25][12][0] = 1;

   
     update1(24,12,0,"You are in a pathway that runs North South");
   	 update1(23,11,0,"You are in a passageway that connects two North South pathways"); 
   	 update1(23,12,0,"You are on a pathway that runs North South. You see stairway on the East");
   	 update1(22,12,0,"You are on a pathway that runs North South");
   	 update1(21,12,0,"You are on a pathway that runs North South. On your West you see an open area with some some shrubs");
   	 update1(20,12,0,"You are on a pathway that runs North South. You see agri department entrance closed on your East");
   	 update1(19,12,0,"You are on a pathway that runs North South. You see an open area on the West and agri department window on the East");
   	 update1(18,12,0,"You are on a pathway that runs North South. You see agri department wall on the East");
   	 update1(17,12,0,"You are on a pathway that runs North South. You see exam cell on the East");
   	 update1(16,12,0,"You are inside the main building. You have approached an intersection. It runs North South as well as to the West");
   	 update1(16,9,0,"You are on a corridor that runs East West and you see waiting hall on your North, the office window is on the South");
   	 update1(16,10,0,"You are inside the main building. You see flower decorations on the floor");
   	 update1(16,11,0,"You are inside the main building. You are on a pathway that runs North South");
   	 update1(16,8,0,"You see an entrance to main office building - front reception on your South");
   	 update1(17,8,0,"You are inside the main office are in the front reception");
   	 update1(18,8,0,"You are near in front of Principal's office. The entry to Chairman's office is blocked.\n You see a pathway leading to board room on the West and another path leading to front corridor on the North");
   	 update1(18,7,0,"You see front of CDC entrance on your South - It is closed");
   	 update1(18,6,0,"You are in front of conference room 1 on your North - It is closed");
   	 update1(18,5,0,"You are in front of conference room 2 on your North - It is closed");
   	 update1(18,4,0,"You are in front of conference room 3 on your North - It is OPEN");
   	 update1(17,4,0,"You are inside conference room 1"); /* 17,4,0 - Conference room 1 */
   	 update1(7,14,0,"You see a garden on your east and walls of academic block on your west. The pavement runs north south"); 
 }







