#include "VideoManager.hpp"

VideoManager::VideoManager(GameMode* GameModeInst)
{
    scaleX = 2.0f;
    scaleY = 2.0f;
    width = 224;
    height = 288;
    _GameMode = GameModeInst;

    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "Couldn't initialize SDL: %s", SDL_GetError());
    }
    
    if (SDL_CreateWindowAndRenderer(width * scaleX, height * scaleY, SDL_WINDOW_OPENGL, &window, &renderer)) {
        SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "Couldn't create window and renderer: %s", SDL_GetError());
    }

    SDL_Surface* surface = SDL_LoadBMP("C:/Users/Dem1se/Source/Repos/sdl_pacman/sdl_pacman/Assets/tilesheet.bmp");
    SDL_Surface* pac = SDL_LoadBMP("C:/Users/Dem1se/Source/Repos/sdl_pacman/sdl_pacman/Assets/pacman.bmp");

    if (!surface) {
        SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "Couldn't create surface from image: %s", SDL_GetError());
    }

    tilesheet = SDL_CreateTextureFromSurface(renderer, surface);
    if (!tilesheet) {
        SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "Couldn't create texture from surface: %s", SDL_GetError());
    }
    pacman = SDL_CreateTextureFromSurface(renderer, pac);

    SDL_FreeSurface(surface);
    SDL_FreeSurface(pac);
    SDL_RenderSetScale(renderer, scaleX, scaleY);
}

void VideoManager::Exit()
{
    SDL_DestroyTexture(tilesheet);
    SDL_DestroyTexture(pacman);
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
}

void VideoManager::Render()
{
    // get the dest_rect details through the internal api here
    // TEMP static pacman position
    int pacPosX = _GameMode->PlayerInst->GetPosition().x;
    int pacPosY = _GameMode->PlayerInst->GetPosition().y;
    SDL_Rect pacPosRect = { pacPosX, pacPosY, 16, 16 };


    SDL_SetRenderDrawColor(renderer, 0x00, 0x00, 0x00, 0xff);
    SDL_RenderClear(renderer);
    SDL_RenderCopy(renderer, pacman, NULL, &pacPosRect);
    SDL_RenderPresent(renderer);
}
