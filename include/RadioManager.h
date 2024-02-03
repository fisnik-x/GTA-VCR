// Copyright (C) Fisnik. All rights reserved.
#ifndef RADIO_MANAGER
#define RADIO_MANAGER

#include <string>
#include <vector>
#include <filesystem>
#include <memory>
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
public:
    FMOD::Sound *m_sound;
    FMOD::Channel *m_channel;
public:
    RadioStation(std::string name, 
                 std::string filename, 
                 FMOD::Channel channel, 
                 FMOD::Sound sound) : m_name{name}, 
                                      m_filename{filename}
    {};

    std::string GetName() const { return m_name; }
    std::string GetFilename() const { return m_filename; }
};

class RadioManager {
    int current = 0;
    float m_volume = 1.0f;
    bool RadioStation_On = false;    
public:
    RadioManager();
    RadioManager(std::vector<RadioStation> stations);
    ~RadioManager();
    
    void Play();
    void Pause();
    void Stop();
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
