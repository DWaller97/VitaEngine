//
//  Input.hpp
//  Vita
//
//  Created by Dan Waller on 15/08/2020.
//  Copyright © 2020 Dan Waller. All rights reserved.
//

#ifndef Input_hpp
#define Input_hpp

#include <stdio.h>
#include <SDL.h>
namespace Engine{
class Input{
public:
    Input();
    ~Input();
    void GetInput(SDL_KeyboardEvent keyEvent);
};

};

#endif /* Input_hpp */
