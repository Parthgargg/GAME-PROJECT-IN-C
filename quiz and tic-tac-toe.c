#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include<string.h>

int main()
{   system("color F3");
     start();


    return 0;
}
void start()
{
    system("cls");
    printf("\n");
    printf("\t\t\t\t\t");printf("HELLO THERE MATE");printf("\n\t\t\t\t       ");printf("******************");printf("\n");
    printf("\t\t\t\t");printf("WELCOME TO OUR MINI GAMES WORLD\n");printf("\n");
    printf("\t\t\t\t");printf("1 PLAYER GAME\n");printf("");

    printf("\t\t\t\t");printf("2 PLAYER GAME\n");

    printf("\n\n");
    int play;
    printf("\t\t\t\t");printf("Enter your response: ");scanf("%d",&play);
    switch(play)
    {
    case 1:play1();
    break;
    case 2:tic2();
      break;
    default: printf("\t\t\t\t");printf("Invalid input.");getch( );start(); break;
    }
}
void play1()
{

    system("cls");
    char cho;
    printf("\n\n\t\t\t\t");printf("1 PLAYER GAMES\n\n");
    printf("\t\t\t\t");printf("A. QUIZ\n");
    printf("\t\t\t\t");printf("B. PUZZLE\n");
    printf("\t\t\t\t");printf("C. TIC TAC TOE(Vs Computer)\n\n");
    printf("\t\t\t\t");printf("Enter your Game: "); fflush(stdin); scanf("%c",&cho);

    cho=toupper(cho);


    switch(cho)
    {
    case 'A': quiz();     break;
    case 'B': puz();    break;
    case 'C': tic1();    break;
    default: printf("\t\t\t\t");printf("Invalid input.");getch( );start(); break;
    }

}
void quiz()
{
    system("cls");
    char question[][100] = {"1.The Lucknow session of Indian National Congress that took place 1916 was presided by?: ",
                            "2.Madhuri Dixit's name in N Chandra's movie 'Tezaab' was?: ",
                            "3.Which county did Ravi Sashtri play for?:  ",
                            "4.'OS' computer abberivative usaually means?: ",
                            "5.Who rote the famous book-'We the people?: "};

    char options[][100]  = {"A. Rashbihari Gosh","B. Ambika Charan Majumdar","C. Bhupendra Nath Bose","D. None of these",
                            "A. Nisha","B. Mohini","C. Pooja","D. Chandramukh",
                            "A. Glamorgan","B. Leicestershire","C. Gloucestershire","D. Lancashire",
                            "A. Order of Significance","B. Open Software","C. Operating System","D. Optical Sensor",
                           " A. T.N.kaul","B. J.R.D.Tata","C. Khushwant Singh","D. Nani Palkhivala"};
    char answers[5] = {'B','B','A','C','D'};
    int numberofquestions = sizeof(question)/sizeof(question[0]);

    char guess;
    int score;

    printf("\t\t\t\t");printf("WELCOME TO QUIZ GAME\n");
    int i,j;

    for( int i=0;i<numberofquestions;i++)
    {
        printf("\n***");
        printf("\n%s",question[i]);
        printf("\n***\n");


    for(int j=(i*4);j<(i*4)+4;j++)
        {printf("\t\t\t\t");printf("%s\n",options[j]);}

        printf("\t\t\t\t");printf("guess: ");
        fflush(stdin);
        scanf("%c",&guess);



    guess = toupper(guess);


    if(guess==answers[i])
    {
        printf("\t\t\t\t");printf("CORRECT!\n");
        score++;
    }
    else
    {
       printf("\t\t\t\t"); printf("WRONG!\n");
       printf("\t\t\t\t");printf("Correct Option is %c\n",answers[i]);
    }

    }

    printf("\t\t\t\t");printf("\n***\n");
    printf("\t\t\t\t");printf("FINAL SCORE: %d/%d\n",score,numberofquestions);
    printf("\t\t\t\t");printf("\n***\n");
    getch();start();

}
/**PUZZLE GAME**/
void puz()
{
    system("cls");
    char question[][100] = {"1.Some months have 30 days, some months have 31 days. How many have 28? ",
                            "2.If you drop me, I'm sure to crack. Give me a smile, and I'll always smile back. What am I? ",
                            "3.Every night I'm told what to do, and each morning I do what I'm told. But I still don't escape your scold. What am I?  ",
                            "4.Voiceless it cries ,Wingless flutters,Toothless bites,Mouthless mutters.",
                            "5.What has 13 hearts but no other organs? "};

    char answers[5][100]={"ALL","MIRROR","ALARM","WIND","CARDS"};

    int numberofquestions = sizeof(question)/sizeof(question[0]);

    char guess[50];
    int score;

    printf("\t\t\t\t");printf("QUIZ GAME\n");
    int i,j;

    for( int i=0;i<numberofquestions;i++)
    {
        printf("\n***");
        printf("\n%s",question[i]);
        printf("\n***\n");




        printf("GUESS: ");
        fflush(stdin);
        scanf("%s",guess);
            int k = 0;
    char ch;

    while (guess[k]!='\0') {
        ch = guess[k];
        guess[k]=toupper(ch);
        k++;
    }


    if(strcmp(guess,answers[i])==0)
    {
        printf("CORRECT!\n\n");
        score++;
    }
    else
    {
        printf("WRONG!\n");
        printf("Correct answer is %s\n\n",answers[i]);
    }

    }




    printf("\n***\n");
    printf("FINAL SCORE: %d/%d\n",score,numberofquestions);
    printf("\n***\n");
    getch(); start();

}
/**TIC TAC TOE 1 PLAYER*/
char matrix[3][3]; /** the tic tac toe matrix*/
char check(void);
void init_matrix(void);
void get_player_move (void);
void get_computer_move (void);
void disp_matrix(void);
void tic1(void)
{
    char done;

done='*';
init_matrix();
do {
disp_matrix();
get_player_move();
done = check(); /** see if winner */
if (done!= '*')
    break; /** winner!*/
get_computer_move();
done = check(); /** see if winner */
} while (done=='*');

if (done=='X')
   {disp_matrix();printf("\t\t\t\t\t    "); printf("You won!\n");}
else
   {
    disp_matrix();
    printf("\t\t\t\t\t    "); printf("I won!!!!\n");}
getch();start();
 /** show final positions */
}
/** Initialize the matrix. */
void init_matrix (void){
int i, j;
for(i=0; i<3; i++)
for(j=0; j<3; j++) matrix[i][j] = '*';
}
/** Get a player's move. */
void get_player_move (void)
{
int x, y;
printf("\t\t\t\t");printf("Enter X,Y coordinates for your move\n");
printf("\t\t\t\t\t");printf("X-Co-ordinate: ");
scanf("%d", &x);
printf("\t\t\t\t\t");printf("Y-Co-ordinate: ");
scanf("%d", &y);
x--; y--;
if (matrix[x][y]!= '*'){
printf("Invalid move, try again. \n");
get_player_move();
}
else matrix[x][y] = 'X';
}
/** Get a move from the computer. */
void get_computer_move (void)
{
int i, j;
for(i=0; i<3; i++) {
for(j=0; j<3; j++)
if (matrix[i][j] =='*') break;
if (matrix[i][j] =='*') break;
}
if(i*j==9) {
printf("draw\n");
exit(0);
}
else
matrix[i][j] = '0';
}
/** Display the matrix on the screen. */
void disp_matrix(void)
{
    system("cls");

    printf("\t\t\t\t\t"); printf("\n\n\t\t\t\t\t    Tic Tac Toe\n\n");

    printf("\t\t\t\t");printf("You will be playing against the computer.\n");

    printf("\t\t\t\t   ");printf("  Player 1 (X)  -  Computer (0)\n\n\n");


    printf("\t\t\t\t\t");printf("     |     |     \n");
    printf("\t\t\t\t\t");printf("  %c  |  %c  |  %c \n", matrix[0][0], matrix[0][1], matrix[0][2]);

    printf("\t\t\t\t\t"); printf("_____|_____|_____\n");
   printf("\t\t\t\t\t"); printf("     |     |     \n");

   printf("\t\t\t\t\t"); printf("  %c  |  %c  |  %c \n", matrix[1][0], matrix[1][1], matrix[1][2]);

   printf("\t\t\t\t\t"); printf("_____|_____|_____\n");
   printf("\t\t\t\t\t"); printf("     |     |     \n");

   printf("\t\t\t\t\t"); printf("  %c  |  %c  |  %c \n", matrix[2][0], matrix[2][1], matrix[2][2]);

   printf("\t\t\t\t\t"); printf("     |     |     \n\n");
}
/** See if there is a winner. */
char check(void)
{
int i;
for(i=0; i<3; i++)
/** check rows */
if (matrix[i][0] ==matrix[i][1] && matrix[i][0] ==matrix[i] [2])
 return matrix[i][0];

for (i=0; i<3; i++) /** check columns */
if (matrix[0][i] ==matrix[1][i] && matrix[0][i] ==matrix [2][i])
 return matrix[0][i];
/** test diagonals **/
if (matrix[0][0] ==matrix[1][1] && matrix [1] [1] ==matrix [2] [2])
 return matrix[0][0];

if (matrix[0] [2] ==matrix[1][1] && matrix[1][1] ==matrix [2][0])
 return matrix[0] [2];

return ('*');
}

/** TIC TAC TOE 2 PLAYER **/
char square[10] = { 'o', '1', '2', '3', '4', '5', '6', '7', '8', '9' };

void tic2()
{
    system("cls");
    int player = 1, i, choice;

    char mark;
    do
    {
        board();
        player = (player % 2) ? 1 : 2;

       printf("\t\t\t\t   "); printf("Player %d, enter your move:  ", player);
        scanf("%d", &choice);

        mark = (player == 1) ? 'X' : 'O';

        if (choice == 1 && square[1] == '1')
            square[1] = mark;

        else if (choice == 2 && square[2] == '2')
            square[2] = mark;

        else if (choice == 3 && square[3] == '3')
            square[3] = mark;

        else if (choice == 4 && square[4] == '4')
            square[4] = mark;

        else if (choice == 5 && square[5] == '5')
            square[5] = mark;

        else if (choice == 6 && square[6] == '6')
            square[6] = mark;

        else if (choice == 7 && square[7] == '7')
            square[7] = mark;

        else if (choice == 8 && square[8] == '8')
            square[8] = mark;

        else if (choice == 9 && square[9] == '9')
            square[9] = mark;

        else
        {
           printf("\t\t\t\t\t"); printf("Invalid move ");

            player--;
            getch();
        }
        i = checkwin();

        player++;
    }while (i ==  - 1);

    board();

    if (i == 1)
       {
           printf("\t\t\t\t\t");printf("==>\aPlayer %d win ", --player);printf("\t\t\t\t\t");
       }
    else
       {

        printf("\t\t\t\t\t");printf("==>\aGame draw");}


    getch();start();


}

/**CHECKING WINNING CONDITION FOR TIC TAC TOE (2 PLAYER)**/
int checkwin()
{
    if (square[1] == square[2] && square[2] == square[3])
        return 1;

    else if (square[4] == square[5] && square[5] == square[6])
        return 1;

    else if (square[7] == square[8] && square[8] == square[9])
        return 1;

    else if (square[1] == square[4] && square[4] == square[7])
        return 1;

    else if (square[2] == square[5] && square[5] == square[8])
        return 1;

    else if (square[3] == square[6] && square[6] == square[9])
        return 1;

    else if (square[1] == square[5] && square[5] == square[9])
        return 1;

    else if (square[3] == square[5] && square[5] == square[7])
        return 1;

    else if (square[1] != '1' && square[2] != '2' && square[3] != '3' &&
        square[4] != '4' && square[5] != '5' && square[6] != '6' && square[7]
        != '7' && square[8] != '8' && square[9] != '9')

        return 0;
    else
        return  - 1;
}
/**TO DISPLAY BOARD OF TIC TAC TOE(2 PLAYER)**/

void board()
{
    system("cls");
    printf("\t\t\t\t\t"); printf("\n\n\t\t\t\t\t    Tic Tac Toe\n\n");

    printf("\t\t\t\t   ");printf("Player 1 (X)  -  Player 2 (O)\n\n\n");


    printf("\t\t\t\t\t");printf("     |     |     \n");
    printf("\t\t\t\t\t");printf("  %c  |  %c  |  %c \n", square[1], square[2], square[3]);

    printf("\t\t\t\t\t"); printf("_____|_____|_____\n");
   printf("\t\t\t\t\t"); printf("     |     |     \n");

   printf("\t\t\t\t\t"); printf("  %c  |  %c  |  %c \n", square[4], square[5], square[6]);

   printf("\t\t\t\t\t"); printf("_____|_____|_____\n");
   printf("\t\t\t\t\t"); printf("     |     |     \n");

   printf("\t\t\t\t\t"); printf("  %c  |  %c  |  %c \n", square[7], square[8], square[9]);

   printf("\t\t\t\t\t"); printf("     |     |     \n\n");
}
