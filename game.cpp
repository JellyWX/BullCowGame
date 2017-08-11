#include <iostream>
#include <string>
#include "game.h"

Game::Game()
{
  Reset(6);
}

int Game::getMaxTries() const
{
  return MaxTries;
}

int Game::getCurrentTry() const
{
  return CurrentTry;
}

int Game::getWordLength() const
{
  return WordLength;
}

bool Game::getGameWon() const
{
  return false;
}

GuessMode Game::ValidateGuess(std::string guess)
{
  int GuessLen = guess.length();
  if(GuessLen != WordLength)
  {
    return GuessMode::LENGTH_ERR;
  }
  return GuessMode::INVALID;
}

void Game::Reset(int tries)
{
  Word = "plant";
  CurrentTry = 1;
  MaxTries = tries;
  WordLength = 5;
  return;
}

ScoreCount Game::SubmitGuess(std::string guess)
{
  ScoreCount Score;
  CurrentTry++;
  
  int GuessLen = guess.length();
  for(int gc = 0;gc<GuessLen;gc++)
  {
    for(int wc = 0;wc<WordLength;wc++)
    {
      if(guess[gc] == Word[wc])
      {
        if(gc == wc)
        {
          Score.Bulls++;
        }else{
          Score.Cows++;
        }
      }
    }
  }
  
  return Score;
}