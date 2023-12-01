#pragma once

#include <string>

namespace star_map {
    enum System {
        AlphaCentauri,
        BetaHydri,
        DeltaEridani,
        EpsilonEridani,
        Omicron2Eridani,
        Sol
    };
}

namespace heaven {

    class Vessel {
        private:

            
        public:
            Vessel(std::string name_in,int generation, star_map::System star=star_map::System::Sol) { this->name=name_in; this->generation=generation; this->current_system=star; }

            Vessel replicate(std::string name);
            void make_buster();
            bool shoot_buster();

            std::string name;
            int generation;
            int busters = 0;
            star_map::System current_system;
    };

    std::string get_older_bob(Vessel a, Vessel b);

    bool in_the_same_system(Vessel a, Vessel b);

}