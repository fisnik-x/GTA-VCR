#include "../include/ViceCityRadio.h"

ViceCityRadio::ViceCityRadio(){}

void ViceCityRadio::Run(){
    
    SDL_bool keep_running = true;
    
    if(SDL_Init(SDL_INIT_VIDEO) < 0){}

    m_window = std::shared_ptr<SDL_Window>(
        SDL_CreateWindow(
        "GTA VCR",
        640,                               
        480,                               
        SDL_WINDOW_OPENGL | SDL_WINDOW_FULLSCREEN                  
    ), SDL_DestroyWindow);

    SDL_Event e;
    while (keep_running) {
        while (SDL_PollEvent(&e) > 0) {
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