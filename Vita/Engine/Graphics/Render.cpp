//
//  Render.cpp
//  Vita
//
//  Created by Dan Waller on 15/08/2020.
//  Copyright © 2020 Dan Waller. All rights reserved.
//

#include "Render.hpp"

using namespace Graphics;

Render::Render() {
    window = SDL_CreateWindow("Vita", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, WINDOW_WIDTH, WINDOW_HEIGHT, SDL_WINDOW_SHOWN);
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC | SDL_RENDERER_TARGETTEXTURE);
    CreateTestScene();
}

Render::~Render() {
    SDL_DestroyWindow(window);
    SDL_Quit();
}

void Render::CreateTestScene(){
        std::string path = "Sprites/IsoCube.png";
        SDL_Texture* texture = LoadTexture(path.c_str(), renderer);
        DrawImage(texture, WINDOW_WIDTH / 2, WINDOW_HEIGHT / 2);
        DrawImage(texture, 0, 0);
}

void Render::Draw(){
    SDL_RenderClear(renderer);
    for(int i = 0; i < spriteList.size(); i++){
        SDL_RenderCopy(renderer, spriteList.at(i).texture, NULL, &spriteList.at(i).rect);
    }
    SDL_RenderPresent(renderer);
    SDL_UpdateWindowSurface(window);
}

SDL_Texture* Render::LoadTexture(const char* filePath, SDL_Renderer *renderer){
    SDL_Texture *texture = nullptr;
    SDL_Surface *image = IMG_Load(filePath);
    if(image == nullptr){
        return nullptr;
    }
    texture = SDL_CreateTextureFromSurface(renderer, image);
    SDL_FreeSurface(image);
    return texture;
}

void Render::DrawImage(SDL_Texture *texture, int xPos, int yPos){
    int w = 0, h = 0;
    SDL_QueryTexture(texture, NULL, NULL, &w, &h);
    
    SDL_Rect rect;
    rect.h = h;
    rect.w = w;
    rect.x = xPos;
    rect.y = yPos;
    Sprite newSprite;
    
    newSprite.texture = texture;
    newSprite.rect = rect;
    spriteList.push_back(newSprite);
    
}
