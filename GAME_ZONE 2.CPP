#include <iostream.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <stdlib.h>
#include <time.h>


/*************------------|FOR GUESS THE COUNTRY|------------***************/
const int MAXLENGTH=80;
const int MAX_TRIES=5;
const int MAXROW=50;
char ch='y';
int letterFill (char, char[], char[]);
void initUnknown (char[], char[]);

/*************---------------|FOR TIC TAC TOE|--------------****************/
char square[10]={'o','1','2','3','4','5','6','7','8','9'};
int checkwin();
void board();

/**************---------------|FOR CASINO ROYAL|-------------****************/
void drawLine(int n, char symbol);
void rules();

/***************----------------|MAIN FUNCTION|-------------*****************/
void main()
	 {
	     clrscr();
	     int d;
	     textcolor(RED);
	     drawLine(80,'=');
	     cprintf("\n\n\n||||||||||-------------*******WELCOME TO GAME ZONE*******--------------|||||||||\n\n\n");
	     drawLine(80,'=');
	  D: textcolor(GREEN);
	     cprintf("\n                       ::::-----||GAMES MENU||-----::::\n");
	     cout<<"\n\n\t\t\t     1).";
	     textcolor(YELLOW);
	     cprintf("  GUESS THE COUNTRY");
	     cout<<"\n\n\t\t\t     2).";
	     textcolor(YELLOW);
	     cprintf("  TIC TAC TOE");
	     cout<<"\n\n\t\t\t     3).";
	     textcolor(YELLOW);
	     cprintf("  CASINO ROYAL");
	     cout<<"\n\n\t\t\t     4).";
	     textcolor(YELLOW);
	     cprintf("  EXIT");
	     textcolor(WHITE);
	     cprintf("\n\n                                                                         ENTER YOUR CHOICE:");

	     cin>>d;
	     switch(d)
	      {
		     case 1:  char unknown [MAXLENGTH];
			      char letter;
			      int num_of_wrong_guesses=0;
			      char word[MAXLENGTH];
			      char words[][MAXLENGTH] =
				       {
						"india",
						"pakistan",
						"nepal",
						"malaysia",
						"philippines",
						"australia",
						"iran",
						"ethiopia",
						"oman",
						"indonesia",
						"america",
						"spain",
						"argentina",
						"srilanka",
						"england",
						"portugals",
						"italy",
						"milan",
						"russia",
						"dubai",
						"bangladesh",
						"bhutan",
						"china",
						"afghanistan",
						"iraq",
						"qatar"
				       };
			      cout << "\n\nWelcome to GUESS THE COUNTRY Game";
			      cout << "\n\nEach letter is represented by a star.";
			      cout << "\n\nYou have to type only one letter in one try";
			      cout << "\n\nYou have " << MAX_TRIES << " tries to try and guess the word.";
			      cout << "\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~";
			    while(ch=='y'||ch=='Y')
			     {randomize();
			      int n=random(26);
			      strcpy(word,words[n]);
			      initUnknown(word, unknown);

				 num_of_wrong_guesses=0;
				  while (num_of_wrong_guesses < MAX_TRIES)
				    {
				      cout<< "\n\n" << unknown;
				      cout<< "\n\nGuess a letter: ";
				      cin>> letter;
				      if (letterFill(letter, word, unknown)==0)
					  {
						cout << endl << "Whoops! That letter isn't in there!" << endl;
						num_of_wrong_guesses++;
					  }
				      else
					  {
						cout << endl << "You found a letter! Isn't that exciting!" << endl;
					  }

				      cout<<"You Have "<< MAX_TRIES - num_of_wrong_guesses;
				      cout<<" Guesses Left."<< endl;

				      if (strcmp(word, unknown) == 0)
					 {
						cout<<"\n\n"<<word<<endl;
						cout<<"\n\nYeah! You Got It!";
						textcolor(RED);
						cprintf("\n:::---|YOU WON|---:::");
						break;
					 }
				    }
				   if(num_of_wrong_guesses == MAX_TRIES)
					 {
						textcolor(GREEN);
						cprintf("\n Sorry, You LOSE...You've Been HANGED.");
						cout << endl;
						cout << "The word was : ";
						textcolor(BLUE);
						cprintf(word);
						cout<< endl;
					 }
				   cout<<"\n\n Do You Want To Play This Game Again (y/n):";
				   cin>>ch;
				 }
			      if(ch=='n'||ch=='N')
				 {
				   cout<<"\n\n Do You Want To Play Any Other Game (y/n):";
				   cin>>ch;
				   if(ch=='y'||ch=='Y')
				      goto D;
				   else
				      textcolor(GREEN);
				      cprintf("\n\n                          :::Press Any Key To Exit:::");
				      break;
				 }
			     break;

		     case 2:    int i,choice;
				char mark;
				int player=1;
			      M:do
				  {
					board();
					player=(player%2)?1:2;
					cout << "Player  " << player << ", Enter A Number:  ";
					cin >> choice;
					mark=(player == 1) ? 'X' : 'O';
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
						   cout<<"!!!!---|Invalid move|---!!!! ";
						   player--;
						   getch();
						}
					i=checkwin();
					player++;
				  }while(i==-1);
				  board();
				  if(i==1)
				    cout<<"==>\a PLAYER  "<<--player<<"  WINS ";
				  else
				    cout<<"==>\a GAME DRAW";
				  cout<<"\n\n Do You Want To Play This Game Again (y/n):";
				  cin>>ch;
				  if(ch=='y'||ch=='Y')
				    {
				       square[1] = '1';
				       square[2] = '2';
				       square[3] = '3';
				       square[4] = '4';
				       square[5] = '5';
				       square[6] = '6';
				       square[7] = '7';
				       square[8] = '8';
				       square[9] = '9';
				       player=1;
				       board();
				       goto M;
				    }
				  if(ch=='n'||ch=='N')
				    { cout<<"\n\n Do You Want To Play Any Other Game (y/n):";
				      cin>>ch;
				      if(ch=='y'||ch=='Y')
					  goto D;
				      if(ch=='n'||ch=='N')
					 { textcolor(GREEN);
					   cprintf("\n\n                           :::Press Any Key To Exit:::");}
				    }

			     break;

		     case 3:      char playerName[25];
				  int guess,dice;
				  float amount,bettingAmount;
				  char c;
				  srand(time(0));
				  drawLine(60,'_');
				  cout << "\n\n\n\t\tCASINO ROYAL\n\n\n\n";
				  drawLine(60,'_');
				  cout << "\n\nEnter Your Name : ";
				  cin >>playerName;
				  cout << "\n\nEnter Deposit amount to play game : $";
				  cin >> amount;

				  do
				    {
				       rules();
				       cout << "\n\nYour current balance is $ " << amount << "\n";
				       do
					 {
					    cout <<playerName<<", enter money to bet : $";
					    cin >> bettingAmount;
					    if(bettingAmount > amount)
					    cout << "Your betting amount is more than your current balance\n"
						 <<"\nRe-enter data\n ";
					 }while(bettingAmount > amount);
				       do
					 {
					    cout << "Guess your number to bet between 1 to 10 :";
					    cin >> guess;
					    if(guess <= 0 || guess > 10)
					    cout << "Please check the number!! should be between 1 to 10\n"
					    <<"\nRe-enter data\n ";
					 }while(guess <= 0 || guess > 10);

				       dice = rand()%10 + 1;
				       if(dice == guess)
					 {
					     cout << "\n\nYeah!! You did it!! You won Rs." << bettingAmount * 10;
					     amount = amount + bettingAmount * 10;
					 }
				       else
					 {
					     cout << "Bad Luck this time !! You lost $ "<< bettingAmount <<"\n";
					     amount = amount - bettingAmount;
					 }

				       cout << "\nThe winning number was : " << dice <<"\n";
				       cout << "\n"<<playerName<<", You have $ " << amount << "\n";
				       if(amount == 0)
					 {
					     cout << "You have no money to play ";
					     break;
					 }
				       cout << "\n\n-->Do You Want To Play This Game Again (y/n): ";
				       cin >> c;
				    }while(c=='Y'||c=='y');

				    cout << "\n\n\n";
				    drawLine(70,'=');
				    cout << "\n\nThanks for playing game. Your balance amount is $ " << amount << "\n\n";
				    drawLine(70,'=');
				    if(c=='N'||c=='n'||amount==0)
				      {
					 cout<<"\n\n Do You Want To Play Any Other Game (y/n):";
					 cin>>ch;
					 if(ch=='y'||ch=='Y')
					    goto D;
					 else
					   {textcolor(GREEN);
					    cprintf("\n\n                          :::Press Any Key To Exit:::");
					    break;}
				      }
				   break;

		     case 4:   textcolor(GREEN);
			       cprintf("\n\n                         :::Press Any Key To Exit:::");
			       break;

		     default:  char e;
			       textcolor(RED);
			       cprintf("\n\n                         !!!---|INVALID CHOICE|---!!!");
			       cout<<"\n\nDo You Want To Play Any Game (y/n):";
			       cin>>e;
			       if(e=='y'||e=='Y')
				  goto D;
			       else
				  textcolor(GREEN);
				  cprintf("\n\n                          :::Press Any Key To Exit:::");
				  break;
	      }
	     getch();
	 }
/************---------------|FOR GUESS THE COUNTRY|-------------*************/

int letterFill (char guess, char secretword[], char guessword[])
{
	int i;
	int matches=0;
	for (i = 0; secretword[i]!='\0'; i++)
	{
		if (guess == guessword[i])
			return 0;
		if (guess == secretword[i])
		{
			guessword[i] = guess;
			matches++;
		}
	}
	return matches;
}

void initUnknown (char word[], char unknown[])
{
	int i;
	int length = strlen(word);
	for (i = 0; i < length; i++)
		unknown[i]='*';
	unknown[i]='\0';
}

/***************---------------|FOR TIC TAC TOE|-------------****************/

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
	else if (square[1] != '1' && square[2] != '2' && square[3] != '3' && square[4] != '4' && square[5] != '5' && square[6] != '6' && square[7] != '7' && square[8] != '8' && square[9] != '9')
		return 0;
	else
		return -1;
}


void board()
{
	clrscr();
	cout << "\n\n\tTic Tac Toe\n\n";
	cout << "Player 1 (X)  -  Player 2 (O)" << endl << endl;
	cout << endl;
	cout << "     |     |     " << endl;
	cout << "  " << square[1] << "  |  " << square[2] << "  |  " << square[3] << endl;
	cout << "_____|_____|_____" << endl;
	cout << "     |     |     " << endl;
	cout << "  " << square[4] << "  |  " << square[5] << "  |  " << square[6] << endl;
	cout << "_____|_____|_____" << endl;
	cout << "     |     |     " << endl;
	cout << "  " << square[7] << "  |  " << square[8] << "  |  " << square[9] << endl;
	cout << "     |     |     " << endl << endl;
}



/**************----------------|FOR CASINO ROYAL|---------------****************/

void drawLine(int n, char symbol)
{
    for(int i=0; i<n; i++)
	cout << symbol;
    cout << "\n" ;
}

void rules()
{
    system("cls");
    cout << "\n\n";
    drawLine(80,'-');
    cout << "\t\tRULES OF THE GAME\n";
    drawLine(80,'-');
    cout << "\t1. Choose any number between 1 to 10\n";
    cout << "\t2. If you win you will get 10 times of money you bet\n";
    cout << "\t3. If you bet on wrong number you will lose your betting amount\n\n";
    drawLine(80,'-');
}


/**************---------------|END OF PROJECT|---------------****************/