//
//  Vita.cpp
//  Vita
//
//  Created by Dan Waller on 15/08/2020.
//  Copyright © 2020 Dan Waller. All rights reserved.
//

#include "Vita.hpp"
using namespace Engine;

void Vita::InitiateSDL(){
    SDL_Init(SDL_INIT_VIDEO);
    IMG_Init(IMG_INIT_PNG);
}

void Vita::Update(){
    SDL_Event e;
    bool quit = false;
    while (!quit){
        render->Draw();
        while (SDL_PollEvent(&e)){
            if (e.type == SDL_QUIT){
                quit = true;
            }
            if(e.type == SDL_KEYDOWN){
                input->GetInput(e.key);
            }
        }
    }
}



Vita::Vita(){
    InitiateSDL();
    render = new Graphics::Render();
    input = new Input();
    Update();
}
