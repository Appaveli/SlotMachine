/*
Program: Slot Machine
Programmer: Dominque Terry
Description: Slot Machine game allowing users to pull, pay, and display total.
When a user pull the handle, all numbers must be the same in order to win. i.e([3] [3] 
[3].
The cost to pull the handle is one dollar. 
*/

#include "stdafx.h"
#include <iostream>
#include <ctime> 

using namespace std; 

class slotMachine {
      private:
            int wheelA;
            int wheelB;
            int wheelC;
            double payOut;         //amount of $ won during the current turn
            double moneyInMachine; //total amount of $ in the machine
            double gameCost;       //the cost of one pull
            double moneyPaid;      //the money put in by user
      public:
             //prototypes
             slotMachine();
             bool displayMenu(void);
             bool pullHandle(void);
             void spinWheel(int &);
             double calculatePayout();
             void insertCoin(double );
             void displaySpinResults();
             int Random(int, int);
             void displayTotals();
};

int main(void) {
      //create a slot machine object
           slotMachine mySlot;

     //Start the slot machine game
     //Keep running until the user
     //decides to quit

      bool ok = true;
      while (ok){
          ok = mySlot.displayMenu();
      }

      return 0;
}

slotMachine::slotMachine () {
      //constructor, set the initial state
      //of all the properties

      srand((int) time(0));
      moneyInMachine = 100;
      moneyPaid = 0;
      payOut = 0;
      wheelA = 0;
      wheelB = 0;
      wheelC = 0;
      gameCost = 1;
}

bool slotMachine::displayMenu(void){
      //main menu, executes the command selected by the
      //user or returns a value to terminate game execution

      char choice = 'Z';

      bool continueGame = true;   

      cout << "\n\n(E)nd, (P)ull, P(A)Y, (T)otals :"; 
      cin >> choice;

      switch (choice) {
            case 'e':
            case 'E':  //stop game
                  continueGame = false;
                  break;
            case 'a':
            case 'A': //pay
                  double money;
                  cout << "\nIt's a dollar a pull!\n"
                       << "Put money into the machine $";
                  cin >> money;
                  insertCoin(money);
                  break;
            case 'p':
            case 'P': //pull
                  if (pullHandle()){
                    cout << endl << endl << endl;
                    displaySpinResults();
                    cout << "Payout $" << calculatePayout();
                  }
                  break;
           case 't':
           case 'T': //display totals
                  displayTotals();
                  break;
      }
      return continueGame;
}

bool slotMachine::pullHandle(void){
      //checks to see if there is enough user money 
      //for a spin. If so, assigns a random value
     //to each wheel. Deducts the cost of one
     //pull from the users money.
     //returns true if the handle was pulled.
     //returns false if the handle could not be pulled

	if(moneyPaid - gameCost >= 0)
	{ 
		spinWheel(wheelA);
		spinWheel(wheelB);
		spinWheel(wheelC);
		moneyPaid -= gameCost;

		return true;
	} else
	{
		return false;
	}

}

void slotMachine::spinWheel(int &theWheel){
      //assign a random value to a wheel  
     theWheel = Random(1,3);
}

double slotMachine::calculatePayout()
{
      //decides if the current wheel values merit a 
      //payout and how much that payout should be.
      //deducts the total payout from the total
      //amount of money in the machine
	if (wheelA == wheelB && wheelB == wheelC)
	{
		switch (wheelA) {
		case 1:
			moneyInMachine -= .10 * moneyInMachine;
			return .10 * moneyInMachine;
			break;        
		case 2:
			moneyInMachine -= .20 * moneyInMachine;
			return .20 * moneyInMachine;
			break;
		case 3:
			moneyInMachine -= .30 * moneyInMachine;
			return .30 * moneyInMachine;
			break;
		default:
			return 0;
			break;
		}
	}else
	{
		return 0;
	}
}

void slotMachine::insertCoin(double amount)
{
      //adds to the amount of money paid by the user
      //adds to the total money in the machine

		moneyPaid += moneyInMachine;

}

void slotMachine::displaySpinResults()
{
      //displays the value of the three wheels
            cout << "[" << wheelA << "] " 
           << "[" << wheelB << "] " 
           << "[" << wheelC << "] \n\n" ;
}

void slotMachine::displayTotals()
{
     //displays the amount of money and number
        // of pulls the player has left
         cout << "\nMoney in Machine $" << slotMachine::moneyInMachine << endl;
     cout << "Pulls Left: " <<   slotMachine::moneyPaid / slotMachine::gameCost  << endl << endl;
}           

int slotMachine::Random(int lowerLimit, int upperLimit) 
{
    //returns a random number within the given boundary
    return 1 + rand() % (upperLimit - lowerLimit + 1);
}