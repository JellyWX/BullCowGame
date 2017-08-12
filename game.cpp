#include <iostream>
#include <string>
#include <map>

#include "game.h"

Game::Game()
{
  Reset("plant");
}

int Game::getMaxTries() const
{
  std::map<int,int> Tries {{3,5},{4,10},{5,15},{6,20},{7,30}};
  return Tries[WordLength];
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
  return Won;
}

bool Game::getIsogram(std::string word) const
{
  std::map<char,bool> letter_map;
  
  for (char letter : word)
  {
    if(not letter_map[letter])
    {
      letter_map[letter] = true;
    }else{
      return true;
    }
  }
  return false;
}

GuessMode Game::ValidateGuess(std::string guess)
{
  int GuessLen = guess.length();
  if(GuessLen != WordLength)
  {
    return GuessMode::LENGTH_ERR;
  }
  else if(getIsogram(guess))
  {
    return GuessMode::NOT_ISO;
  }
  else
  {
    return GuessMode::OK;
  }
}

void Game::Reset(std::string word)
{
  Word = word;
  CurrentTry = 1;
  WordLength = Word.length();
  MaxTries = getMaxTries();
  Won = false;
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
  
  if(Score.Bulls == WordLength)
  {
    Won = true;
  }
  
  return Score;
}