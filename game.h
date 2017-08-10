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

class Game
{
public:
  Game();

  int getMaxTries() const;
  int getCurrentTry() const;
  int getWordLength() const;
  bool getGameWon() const;
  GuessMode ValidateGuess(std::string);
  bool SubmitGuess();
  void Reset();
  
  
private:
  int CurrentTry;
  int MaxTries;
  int WordLength;
};