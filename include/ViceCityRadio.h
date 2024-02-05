#ifndef H_VICE_CITY_RADIO
#define H_VICE_CITY_RADIO

#include <Windows.h>
#include <memory>
//#include "RadioManager.h"
//#include "../third-party/SDL/include/SDL3/SDL.h"
//#include "../third-party/SDL/include/SDL3/SDL_opengl.h"
#include "../third-party/glfw/include/GLFW/glfw3.h"

class ViceCityRadio {
    #define rgb2f(x) ((int)x/255.0f)
public:
    ViceCityRadio();
    ~ViceCityRadio();
    void Run();
private:
    GLFWwindow* m_window = nullptr;
    const GLFWvidmode* m_video = nullptr;
};

#endif