#include <iostream>
#include <string>
#include <algorithm>

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
  GuessMode Status = GuessMode::INVALID;
  std::string Guess = "";
  
  do
  {
    std::cout << "Try " << BCG.getCurrentTry() << ": Enter your guess: ";
    std::getline(std::cin,Guess);
    
    Status = BCG.ValidateGuess(Guess);
    
    std::transform(Guess.begin(),Guess.end(),Guess.begin(),::tolower);

    
    switch(Status)
    {
    case GuessMode::LENGTH_ERR:
      std::cout << "Make sure your guess is " << BCG.getWordLength() << " characters long!\n";
      break;
    
    case GuessMode::NOT_ISO:
      std::cout << "Your input should be an isogram (all different letters!)\n";
      break;
      
    case GuessMode::INVALID:
      std::cout << "Unknown error occured\n";
      break;
    
    default:
      break;
    }
  } while(Status != GuessMode::OK);
  return Guess;
}

void PlayGame()
{
  do
  {
    std::string Guess = GetGuess();
    
    ScoreCount Score = BCG.SubmitGuess(Guess);
    std::cout << "Your guess was " << Guess << std::endl << std::endl;
    std::cout << "Bulls: " << Score.Bulls << std::endl << "Cows: " << Score.Cows << std::endl;
  }
  while(BCG.getCurrentTry()<=BCG.getMaxTries() and not BCG.getGameWon());
  
  if(BCG.getGameWon())
  {
    std::cout << "You win! Good job.\n";
  }
  else
  {
    std::cout << "You lost :( Better luck next time!\n";
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