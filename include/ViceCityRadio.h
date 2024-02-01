#ifndef H_VICE_CITY_RADIO
#define H_VICE_CITY_RADIO

#include <memory>
#include "RadioManager.h"

class ViceCityRadio {
private:
    std::shared_ptr<RadioManager> m_radiomgr; 
};

#endif