#include "doctor_data.h"

heaven::Vessel heaven::Vessel::replicate(std::string newName) {
    return Vessel(newName,this->generation+1,this->current_system);
}

void heaven::Vessel::make_buster() {
    this->busters++;
}

bool heaven::Vessel::shoot_buster() {
    if (this->busters == 0) return false;

    busters--;
    return true;
}

std::string heaven::get_older_bob(Vessel a, Vessel b) {
    return (a.generation < b.generation) ? a.name : b.name;
}

bool heaven::in_the_same_system(Vessel a, Vessel b) {
    return a.current_system == b.current_system;
}