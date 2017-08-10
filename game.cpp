#include <iostream>
#include <string>
#include "game.h"

Game::Game()
{
  CurrentTry = 1;
  MaxTries = 6;
  WordLength = 5;
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
  if(guess.length() != WordLength)
  {
    return GuessMode::LENGTH_ERR;
  }
  return GuessMode::INVALID;
}

void Game::Reset()
{
  return;
}

bool Game::SubmitGuess()
{
  return false;
}