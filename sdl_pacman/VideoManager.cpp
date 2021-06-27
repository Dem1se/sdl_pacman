#include "VideoManager.hpp"
#include "Level.hpp"

VideoManager::VideoManager(GameMode* GameModeInst)
{
    _GameMode = GameModeInst;
    _TileSheetHelper = new TileSheetHelper();

    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "Couldn't initialize SDL: %s", SDL_GetError());
    }
    
    if (SDL_CreateWindowAndRenderer(Width * scaleX, Height * scaleY, SDL_WINDOW_SHOWN, &_Window, &_Renderer)) {
        SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "Couldn't create window and renderer: %s", SDL_GetError());
    }

    SDL_Surface* pac = SDL_LoadBMP("C:/Users/Dem1se/Source/Repos/sdl_pacman/sdl_pacman/Assets/pacman.bmp");

    _Pacman = SDL_CreateTextureFromSurface(_Renderer, pac);

    SDL_FreeSurface(pac);
    SDL_RenderSetScale(_Renderer, scaleX, scaleY);
}

VideoManager::~VideoManager()
{
    SDL_DestroyTexture(_Pacman);
    SDL_DestroyRenderer(_Renderer);
    SDL_DestroyWindow(_Window);

    _TileSheetHelper->~TileSheetHelper();
    _GameMode->~GameMode();
}

void VideoManager::Load()
{
    SDL_Surface* tileSurface,* levelSurface;
    //SDL_Texture* tileTexture;
    SDL_Rect destRect;
    
    SDL_RenderClear(_Renderer);
    levelSurface = SDL_CreateRGBSurface(0, Width, Height, 32, 0, 0, 0, 1);

    for (int i = 0; i < 36; i++)
    {
        for (int j = 0; j < 28; j++)
        {
            destRect = SDL_Rect{ i * 8, j * 8, 8, 8 };
            tileSurface = _TileSheetHelper->GetSurfaceFromTileSheet(_GameMode->LevelGetTile(i, j));
            SDL_BlitSurface(tileSurface, NULL, levelSurface, &destRect);
        }
    }
    _Level = SDL_CreateTextureFromSurface(_Renderer, levelSurface);
    
    SDL_FreeSurface(tileSurface);
    SDL_FreeSurface(levelSurface);
}

void VideoManager::Render()
{
    int pacPosX = _GameMode->GetPlayerPosition().x;
    int pacPosY = _GameMode->GetPlayerPosition().y;
    SDL_Rect pacPosRect = { pacPosX, pacPosY, 16, 16 };
    SDL_Rect levelPosRect = { 0, 0, Width, Height };
    
    SDL_SetRenderDrawColor(_Renderer, 0x00, 0x00, 0x00, 0xff);
    SDL_RenderClear(_Renderer);

    SDL_RenderCopy(_Renderer, _Level, NULL, &levelPosRect);
    SDL_RenderCopy(_Renderer, _Pacman, NULL, &pacPosRect);
    SDL_RenderPresent(_Renderer);
}
