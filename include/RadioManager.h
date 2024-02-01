// Copyright (C) Fisnik. All rights reserved.
#ifndef RADIO_MANAGER
#define RADIO_MANAGER

#include <string>
#include <vector>
#include <filesystem>
#include "../vendors/fmod/include/fmod.hpp"
#include "../vendors/fmod/include/fmod.h"

enum RadioStations {
    WILDSTYLE,
    FLASH_FM,
    KCHAT,
    FEVER,
    V_ROCK,
    VCPR,
    RADIO_ESANTOSO,
    EMOTION,
    WAVE
};

enum RadioState {
    ON,
    OFF
};

class RadioStation {
    std::string m_name;
    std::string m_filename;
    RadioStations m_station;
    FMOD::Sound* m_sound = 0;
    FMOD::Channel* m_channel = 0;
public:
    RadioStation(std::string name, 
                 std::string filename, 
                 FMOD::Channel channel, 
                 FMOD::Sound sound) : m_name{name}, 
                                      m_filename{filename}
    {};
};

class RadioManager {
    float m_volume = 1.0f;
public:
    RadioManager();
    RadioManager(std::vector<RadioStation> stations);
    ~RadioManager();
    void Play();
    void Stop();
    void Next();
    void Prev();
    void TurnOn();
    
    void CreateRadioStation(const std::string name, const std::string filename);
    void ChangeRadioStation(int n);
    bool UpdatePosition(unsigned int position);
    unsigned int GetCurrentPosition();

private:
    FMOD::System* m_system; 
    RadioState m_state;
    std::vector<RadioStation> m_stations;
};

#endif
