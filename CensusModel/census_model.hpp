
#pragma once

#include <string>
#include <vector>
#include <algorithm>
#include <numeric>

namespace census_model {

    struct person {
        int age;
        Region region;
    };

    class census {

        std::vector<person> _people;

    public:

        void recordPerson(person p) { _people.push_back(p); }
        int averageAge() {
            int total = 0;
            for (auto& p : _people)
                total += p.age;
            return total / _people.size();
        }

        int getPopulation(Region region) {
            int total = 0;
            for (auto& p : _people)
                total += p.region == region ? 1 : 0;
            return total;
         }
    };


}
