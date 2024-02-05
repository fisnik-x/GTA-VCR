#ifndef H_VICE_CITY_RADIO
#define H_VICE_CITY_RADIO

#include <memory>
//#include "RadioManager.h"
#include "../third-party/SDL/include/SDL3/SDL.h"
#include "../third-party/SDL/include/SDL3/SDL_opengl.h"
#include "../third-party/glfw/include/GLFW/glfw3.h"

class ViceCityRadio {
public:
    ViceCityRadio();
    ~ViceCityRadio() = default;
    void Run();
private:
    std::shared_ptr<SDL_Window> m_window;
};

#endif