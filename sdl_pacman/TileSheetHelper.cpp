#include "TileSheetHelper.hpp"

TileSheetHelper::TileSheetHelper()
{
    _TileSheet = SDL_LoadBMP("C:/Users/Dem1se/Source/Repos/sdl_pacman/sdl_pacman/Assets/tilesheet.bmp");
}

TileSheetHelper::~TileSheetHelper()
{
    SDL_FreeSurface(_TileSheet);
}

SDL_Surface* TileSheetHelper::GetSurfaceFromTileSheet(TileSetFull tile)
{
    SDL_Surface* tileSurface = SDL_CreateRGBSurface(0, 8, 8, 32, 0, 0, 0, 0);
    SDL_Rect srcRect, destRect = SDL_Rect{ 0 ,0 };

    switch (tile)
    {
    case TileSetFull::Bottom:
        srcRect = SDL_Rect{ 8 * 0, 0, 8, 8 };
    case TileSetFull::Top:
        srcRect = SDL_Rect{ 8 * 0, 8, 8, 8 };
        break;
        break;
    case TileSetFull::Left:
        srcRect = SDL_Rect{ 8 * 1, 0, 8, 8 };
        break;
    case TileSetFull::Right:
        srcRect = SDL_Rect{ 8 * 1, 8, 8, 8 };
        break;
    case TileSetFull::BottomLeft:
        srcRect = SDL_Rect{ 8 * 2, 0, 8, 8 };
        break;
    case TileSetFull::TopLeft:
        srcRect = SDL_Rect{ 8 * 2, 8, 8, 8 };
        break;
    case TileSetFull::TopRight:
        srcRect = SDL_Rect{ 8 * 2, 16, 8, 8 };
        break;
    case TileSetFull::BottomRight:
        srcRect = SDL_Rect{ 8 * 2, 24, 8, 8 };
        break;
    case TileSetFull::BottomBorder:
        srcRect = SDL_Rect{ 8 * 3, 0, 8, 8 };
        break;
    case TileSetFull::TopBorder:
        srcRect = SDL_Rect{ 8 * 3, 8, 8, 8 };
        break;
    case TileSetFull::LeftBorder:
        srcRect = SDL_Rect{ 8 * 4, 0, 8, 8 };
        break;
    case TileSetFull::RightBorder:
        srcRect = SDL_Rect{ 8 * 4, 8, 8, 8 };
        break;
    case TileSetFull::BottomLeftBorder:
        srcRect = SDL_Rect{ 8 * 5, 0, 8, 8 };
        break;
    case TileSetFull::TopLeftBorder:
        srcRect = SDL_Rect{ 8 * 5, 8, 8, 8 };
        break;
    case TileSetFull::TopRightBorder:
        srcRect = SDL_Rect{ 8 * 5, 16, 8, 8 };
        break;
    case TileSetFull::BottomRightBorder:
        srcRect = SDL_Rect{ 8 * 5, 24, 8, 8 };
        break;
    case TileSetFull::BottomLeftTee:
        srcRect = SDL_Rect{ 8 * 6, 0, 8, 8 };
        break;
    case TileSetFull::TopLeftTee:
        srcRect = SDL_Rect{ 8 * 6, 8, 8, 8 };
        break;
    case TileSetFull::TopRightTee:
        srcRect = SDL_Rect{ 8 * 6, 16, 8, 8 };
        break;
    case TileSetFull::BottomRightTee:
        srcRect = SDL_Rect{ 8 * 6, 24, 8, 8 };
        break;
    case TileSetFull::Dot:
        srcRect = SDL_Rect{ 8 * 7, 0, 8, 8 };
        break;
    case TileSetFull::Energizer:
        srcRect = SDL_Rect{ 8 * 8, 0, 8, 8 };
        break;
    case TileSetFull::Blank:
        srcRect = SDL_Rect{ 8 * 9, 0, 8, 8 };
        break;
    }

    SDL_BlitSurface(_TileSheet, &srcRect, tileSurface, &destRect);
    return tileSurface;
}


