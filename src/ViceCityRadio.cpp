#include "../include/ViceCityRadio.h"
#include "../third-party/SDL/include/SDL3/SDL.h"
#include "../third-party/SDL/include/SDL3/SDL_opengl.h"

ViceCityRadio::ViceCityRadio(){}

void ViceCityRadio::Run(){
    
    bool keep_running = true;
    
    if(SDL_Init(SDL_INIT_VIDEO) < 0){}

    SDL_Window *wnd = SDL_CreateWindow(
        "GTA VCR",
        640,                               
        480,                               
        SDL_WINDOW_OPENGL | SDL_WINDOW_RESIZABLE                  
    );

    SDL_Event e;
    while (keep_running) {
        while (SDL_PollEvent(&e) > 0)
        {
            switch (e.type) {
            case SDL_EVENT_QUIT:
                keep_running = false;
                break;

            default:
                break;
            }
        }
    }
}