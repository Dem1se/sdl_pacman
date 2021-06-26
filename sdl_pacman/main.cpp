#include "Game.hpp"

int main(int argc, char* argv[])
{
    Game* GameInst = Game::Instance();
    GameInst->Initialize();
    GameInst->StartGameloop();
    
    return 0;
}
