// Copyright (C) Fisnik. All rights reserved.
#include "../include/RadioManager.h"

RadioManager::RadioManager() 
{
    FMOD::System_Create(&m_system);
    m_system->init(9, 1, FMOD_INIT_NORMAL);
}

RadioManager::RadioManager(std::vector<RadioStation> stations)
{

}

void RadioManager::Play() {
    //m_system->playSound();
}

void RadioManager::Stop() {

}

void RadioManager::Next() {

}

void RadioManager::Prev() {

}

void RadioManager::ChangeRadioStation(int n) {

}

bool RadioManager::UpdatePosition(unsigned int position) {
    return true;
}

unsigned int RadioManager::GetCurrentPosition() {
    return -1;
}