#include "Game.hpp"

int main(int argc, char* argv[])
{
    Game* gameInst = Game::Instance();
    gameInst->Load();
    gameInst->StartGameloop();
    gameInst->Exit();
    return 0;
}
