//
//  Vita.hpp
//  Vita
//
//  Created by Dan Waller on 15/08/2020.
//  Copyright © 2020 Dan Waller. All rights reserved.
//

#ifndef Vita_hpp
#define Vita_hpp
#include <stdio.h>
#include <iostream>
#include <SDL.h>
#include <SDL_image.h>
#include <vector>
#include "Input.hpp"
#include "Render.hpp"

namespace Engine{
    class Vita{
        private:
        Graphics::Render* render;
        Input* input;
        private:
            void InitiateSDL();
            void InitiateRenderer();
            virtual void Update();
            
        public:
            Vita();
            ~Vita();


    };
};
#endif /* Vita_hpp */
