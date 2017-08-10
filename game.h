#pragma once
#include <string>

enum class GuessMode
{
  INVALID,
  OK,
  WRONG_CASE,
  NOT_ISO,
  LENGTH_ERR
};

class Game()
{
public:
  void Reset();
  int getMaxTries();
  int getCurrentTry();
  bool getGameWon();
  GuessMode ValidateGuess(std::string);
  
  
private:
  int CurrentTry;
  int MaxTries;
  
}