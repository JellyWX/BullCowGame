#include <iostream>
#include <string>
#include "game.h"

Game BCG;


void intro()
{
  std::cout << "Welcome to Bulls and Cows.\n";
  std::cout << "Can you guess the " << BCG.getWordLength() << " letter isogram I'm thinking of?\n\n";
  return;
}

std::string GetGuess()
{
  std::string Guess = "";
  std::cout << "Try " << BCG.getCurrentTry() << ": Enter your guess: ";
  std::getline(std::cin,Guess);
  return Guess;
}

void PlayGame()
{
  for(int i=0;i<BCG.getMaxTries();i++)
  {
    std::string Guess = GetGuess();
    std::cout << "Your guess was " << Guess << std::endl << std::endl;
  }
}

bool PlayAgain()
{
  std::string ui = "";
  std::cout << "Do you want to play again? [y/N] > ";
  std::getline(std::cin,ui);
  if(ui[0] == 'y' or ui[0] == 'Y')
    return true;
  return false;
}

int main()
{
  do
  {
    intro();
    PlayGame();
  }
  while(PlayAgain());
  
  return 0;
}