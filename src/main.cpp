// Copyright (C) Fisnik. All rights reserved.
#include "../include/ViceCityRadio.h"

int main() {
    std::unique_ptr<ViceCityRadio> m_vcr(new ViceCityRadio());
    m_vcr->Run();
    return 0;
}
