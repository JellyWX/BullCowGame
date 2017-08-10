#include <iostream>
#include <string>
#include "game.h"


int Game::getMaxTries()
{
  return MaxTries;
}

int Game::getCurrentTry()
{
  return CurrentTry;
}

bool Game::getGameWon()
{
  return false;
}

void Game::Reset()
{
  return;
}