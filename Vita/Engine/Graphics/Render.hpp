//
//  Render.hpp
//  Vita
//
//  Created by Dan Waller on 15/08/2020.
//  Copyright © 2020 Dan Waller. All rights reserved.
//

#ifndef Render_hpp
#define Render_hpp

#include <stdio.h>
#include <SDL.h>
#include <SDL_image.h>
#include <iostream>
#include <vector>
namespace Graphics{

    struct Sprite{
        SDL_Texture* texture;
        SDL_Rect rect;
    };

    class Render{
    private:
        SDL_Window *window;
        SDL_Renderer *renderer;
        const int WINDOW_WIDTH = 1280;
        const int WINDOW_HEIGHT = 720;
        std::vector<Sprite> spriteList;
    private:
        void CreateTestScene();
    public:
        Render();
        ~Render();
        void Draw(); 
        SDL_Texture* LoadTexture(const char* filePath, SDL_Renderer *renderer);
        void DrawImage(SDL_Texture *texture, int xPos, int yPos);

    };
};
#endif /* Render_hpp */
