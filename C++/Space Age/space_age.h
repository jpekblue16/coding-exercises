#if !defined(SPACE_AGE_H)
#define SPACE_AGE_H

#include <string>
#include <unordered_map>

const std::unordered_map<std::string,double> planetYearRatios = {
    { "mercury", 0.2408467},
    { "venus", 0.61519726 },
    { "earth", 1 },
    { "mars", 1.8808158 },
    { "jupiter", 11.862615 },
    { "saturn", 29.447498 },
    { "uranus", 84.016846 },
    { "neptune", 164.79132 }
};

namespace space_age {

const double SECS_IN_YEAR = 31557600;

struct space_age {

    double ageInSeconds;

    space_age(double seconds) { ageInSeconds=seconds; }

    double seconds() const;
    double on_earth() const;
    double on_mercury() const;
    double on_venus() const;
    double on_mars() const;
    double on_jupiter() const;
    double on_saturn() const;
    double on_uranus() const;
    double on_neptune() const;

private:
    double secondsToYears(std::string planet) const;

};

}  // namespace space_age

#endif // SPACE_AGE_H