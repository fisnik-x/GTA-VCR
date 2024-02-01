// Copyright (C) Fisnik. All rights reserved.
#include "../include/RadioManager.h"

RadioManager::RadioManager() {
    FMOD::System_Create(&m_system);
    m_system->init(9, 1, FMOD_INIT_NORMAL);
}

RadioManager::RadioManager(std::vector<RadioStation> stations) 
: RadioManager() {
    m_stations = stations;
    for(auto radio : m_stations){
        m_system->createSound(radio.GetFilename().c_str(),
                              0x00000040, 
                              0, 
                              &radio.m_sound);
    }
}

void RadioManager::Play() {
    if(m_state == RadioState::OFF)
        m_system->playSound(
            m_stations[current].m_sound,  
            nullptr, 
            false, 
            &m_stations[current].m_channel);
    
    m_stations[current].m_channel->setPaused(false);

}

void RadioManager::TurnOn() { this->RadioStation_On = !this->RadioStation_On; }

void RadioManager::Pause() {
    m_stations[current].m_channel->setPaused(true);
}

void RadioManager::Stop() {}

void RadioManager::ChangeRadioStation(int n) {
    int now = this->current;
    bool m_paused;

    if(0b0001 && n){
        this->current--;
        this->UpdatePosition(GetCurrentPosition());
        this->m_stations[now].m_channel->getPaused(&m_paused); 
        if(!m_paused){
            this->m_stations[now].m_channel->setPaused(true);
        }

        this->m_stations[current].m_channel->setPaused(false);
        return; 
    }

    this->current++;
    this->UpdatePosition(GetCurrentPosition());
    this->m_stations[now].m_channel->setPaused(true);
    this->m_stations[current].m_channel->setPaused(false);
}

bool RadioManager::UpdatePosition(unsigned int position) {
    return true;
}

unsigned int RadioManager::GetCurrentPosition() {
    return -1;
}