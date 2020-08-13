//
//  main.cpp
//  Vita
//
//  Created by Dan Waller on 10/08/2020.
//  Copyright © 2020 Dan Waller. All rights reserved.
//

#include <iostream>
#include <SDL.h>
#include <SDL_image.h>
#include <vector>
SDL_Window *window;
SDL_Renderer *renderer;


const int WINDOW_WIDTH = 1280;
const int WINDOW_HEIGHT = 720;

struct Sprite{
    SDL_Texture* texture;
    SDL_Rect rect;
};

std::vector<Sprite> spriteList;

SDL_Texture* LoadTexture(const char* filePath, SDL_Renderer *renderer){
    SDL_Texture *texture = nullptr;
    SDL_Surface *image = IMG_Load(filePath);
    if(image == nullptr){
        return nullptr;
    }
    texture = SDL_CreateTextureFromSurface(renderer, image);
    SDL_FreeSurface(image);
    return texture;
}

void InitiateSDL(){
    SDL_Init(SDL_INIT_VIDEO);
    IMG_Init(IMG_INIT_PNG);
    
    window = SDL_CreateWindow("Vita", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, WINDOW_WIDTH, WINDOW_HEIGHT, SDL_WINDOW_SHOWN);
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC | SDL_RENDERER_TARGETTEXTURE);
}

void DrawImage(SDL_Texture *texture, int xPos, int yPos){
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

void InitiateScene(){
    std::string path = "Sprites/IsoCube.png";
    SDL_Texture* texture = LoadTexture(path.c_str(), renderer);
    DrawImage(texture, WINDOW_WIDTH / 2, WINDOW_HEIGHT / 2);
    DrawImage(texture, 0, 0);
}



void Draw(){
    SDL_RenderClear(renderer);
    for(int i = 0; i < spriteList.size(); i++){
        SDL_RenderCopy(renderer, spriteList.at(i).texture, NULL, &spriteList.at(i).rect);
    }
    SDL_RenderPresent(renderer);
    SDL_UpdateWindowSurface(window);
}

void Update(){
    SDL_Event e;
    bool quit = false;
    while (!quit){
        Draw();
        while (SDL_PollEvent(&e)){
            if (e.type == SDL_QUIT){
                quit = true;
            }
        }
    }
}



int main(int argc, const char * argv[]) {
    InitiateSDL();
    InitiateScene();
    Update();
    SDL_DestroyWindow(window);
    SDL_Quit();
    return 0;
}

