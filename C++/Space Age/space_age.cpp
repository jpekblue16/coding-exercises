#include "space_age.h"

namespace space_age {

double space_age::secondsToYears(std::string planet) const {
    double ratio = planetYearRatios.find(planet)->second;
    return ( ageInSeconds / SECS_IN_YEAR ) / ratio;
}

double space_age::seconds() const {
    return ageInSeconds;
}

double space_age::on_earth() const {
    return secondsToYears("earth");
}

double space_age::on_mercury() const {
    return secondsToYears("mercury");
}

double space_age::on_venus() const {
    return secondsToYears("venus");
}

double space_age::on_mars() const {
    return secondsToYears("mars");
}

double space_age::on_jupiter() const {
    return secondsToYears("jupiter");
}

double space_age::on_saturn() const {
    return secondsToYears("saturn");
}

double space_age::on_uranus() const {
    return secondsToYears("uranus");
}

double space_age::on_neptune() const {
    return secondsToYears("neptune");
}

}  // namespace space_age