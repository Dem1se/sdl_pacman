#include "TileSheetHelper.hpp"

TileSheetHelper::TileSheetHelper(SDL_Renderer* renderer)
{
    _RenderingContext = renderer;
}

TilePos TileSheetHelper::GetTile(int PosX, int PosY)
{
    int x = PosX / 8;
    int y = PosY / 8;

    return TilePos{ x, y };
}

SDL_Texture* TileSheetHelper::GetTextureFromTileSheet(TileSetFull tile)
{
    SDL_Surface* tileSurface = new SDL_Surface();
    SDL_Texture* tileTexture, * tileTextureRotated;
    SDL_Rect srcRect, destRect = SDL_Rect {0 ,0};
    SDL_RendererFlip flip =  SDL_RendererFlip();
    // https://stackoverflow.com/questions/1183900/best-way-to-rotate-an-image-using-sdl#1183914

    switch (tile)
    {
    case TileSetFull::Top:
        flip = SDL_FLIP_VERTICAL;
        srcRect = SDL_Rect{ 8 * 0, 0, 8, 8 };
        break;
    case TileSetFull::Bottom:
        flip = SDL_FLIP_NONE;
        srcRect = SDL_Rect {8 * 0, 0, 8, 8};
        break;
    case TileSetFull::Left:
        flip = SDL_FLIP_NONE;
        srcRect = SDL_Rect{ 8 * 1, 0, 8, 8 };
        break;
    case TileSetFull::Right:
        flip = SDL_FLIP_HORIZONTAL;
        srcRect = SDL_Rect{ 8 * 1, 0, 8, 8 };
        break;
    case TileSetFull::BottomLeft:
        flip = SDL_FLIP_NONE;
        srcRect = SDL_Rect{ 8 * 2, 0, 8, 8 };
        break;
    case TileSetFull::TopLeft:
        flip = SDL_FLIP_VERTICAL;
        srcRect = SDL_Rect{ 8 * 2, 0, 8, 8 };
        break;
    case TileSetFull::TopRight:
        flip = (SDL_RendererFlip)(SDL_FLIP_VERTICAL | SDL_FLIP_HORIZONTAL);
        srcRect = SDL_Rect{ 8 * 2, 0, 8, 8 };
        break;
    case TileSetFull::BottomRight:
        flip = SDL_FLIP_HORIZONTAL;
        srcRect = SDL_Rect{ 8 * 2, 0, 8, 8 };
        break;
    case TileSetFull::BottomBorder:
        flip = SDL_FLIP_NONE;
        srcRect = SDL_Rect{ 8 * 3, 0, 8, 8 };
        break;
    case TileSetFull::TopBorder:
        flip = SDL_FLIP_HORIZONTAL;
        srcRect = SDL_Rect{ 8 * 3, 0, 8, 8 };
        break;
    case TileSetFull::LeftBorder:
        flip = SDL_FLIP_NONE;
        srcRect = SDL_Rect{ 8 * 4, 0, 8, 8 };
        break;
    case TileSetFull::RightBorder:
        flip = SDL_FLIP_VERTICAL;
        srcRect = SDL_Rect{ 8 * 4, 0, 8, 8 };
        break;
    case TileSetFull::BottomLeftBorder:
        flip = SDL_FLIP_NONE;
        srcRect = SDL_Rect{ 8 * 5, 0, 8, 8 };
        break;
    case TileSetFull::TopLeftBorder:
        flip = SDL_FLIP_VERTICAL;
        srcRect = SDL_Rect{ 8 * 5, 0, 8, 8 };
        break;
    case TileSetFull::TopRightBorder:
        flip = (SDL_RendererFlip)(SDL_FLIP_VERTICAL | SDL_FLIP_HORIZONTAL);
        srcRect = SDL_Rect{ 8 * 5, 0, 8, 8 };
        break;
    case TileSetFull::BottomRightBorder:
        flip = SDL_FLIP_HORIZONTAL;
        srcRect = SDL_Rect{ 8 * 5, 0, 8, 8 };
        break;
    case TileSetFull::BottomLeftTee:
        flip = SDL_FLIP_NONE;
        srcRect = SDL_Rect{ 8 * 6, 0, 8, 8 };
        break;
    case TileSetFull::TopLeftTee:
        flip = SDL_FLIP_VERTICAL;
        srcRect = SDL_Rect{ 8 * 6, 0, 8, 8 };
        break;
    case TileSetFull::TopRightTee:
        flip = (SDL_RendererFlip)(SDL_FLIP_VERTICAL | SDL_FLIP_HORIZONTAL);
        srcRect = SDL_Rect{ 8 * 6, 0, 8, 8 };
        break;
    case TileSetFull::BottomRightTee:
        flip = SDL_FLIP_HORIZONTAL;
        srcRect = SDL_Rect{ 8 * 6, 0, 8, 8 };
        break;
    case TileSetFull::Dot:
        flip = SDL_FLIP_NONE;
        srcRect = SDL_Rect{ 8 * 7, 0, 8, 8 };
        break;
    case TileSetFull::Energizer:
        flip = SDL_FLIP_NONE;
        srcRect = SDL_Rect{ 8 * 8, 0, 8, 8 };
        break;
    case TileSetFull::Blank:
        flip = SDL_FLIP_NONE;
        srcRect = SDL_Rect{ 8 * 8, 0, 8, 8 };
        break;
    }
    
    SDL_BlitSurface(_TileSheet, &srcRect, tileSurface, &destRect); // copy the right tile from tileset
    tileTexture = SDL_CreateTextureFromSurface(_RenderingContext, tileSurface); // create texture from surface
    SDL_RenderCopyEx(_RenderingContext, tileTexture, &srcRect, &destRect, 0, NULL, flip );
    return tileTexture;
}


