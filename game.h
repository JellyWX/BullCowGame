#pragma once
#include <string>

struct ScoreCount
{
  int Bulls = 0;
  int Cows = 0;
};

enum class WinLoss
{
  ONGOING,
  LOST,
  WON
};
enum class GuessMode
{
  INVALID,
  OK,
  NOT_LETTER,
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
  ScoreCount SubmitGuess(std::string);
  void Reset(int);
  
private:
  std::string Word;
  int CurrentTry;
  int MaxTries;
  int WordLength;
  WinLoss Won; 
};