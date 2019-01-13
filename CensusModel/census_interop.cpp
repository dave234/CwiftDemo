//
//  census_interop.c
//  Census
//
//  Created by David O'Neill on 1/13/19.
//  Copyright © 2019 Cwift Census. All rights reserved.
//

#include "census_interop.h"
#include "census_model.hpp"

//////// Person ////////////

Person PersonCreate(int age, StateRegion region) { return
    (Person) new census_model::person {
        .age = age,
        .region = region
    };
}

void PersonDestroy(Person person) {
    delete (census_model::person *)person;
}

int PersonGetAge(Person person) {
    return ((census_model::person *)person)->age;
}

void PersonSetAge(Person person, int age) {
    ((census_model::person *)person)->age = age;
}

///////// Census ///////////

Census CensusCreate() {
    return new census_model::census;
}

void CensusDestroy(Census census) {
    delete (census_model::person *)census;
}

void CensusRecordPerson(Census census, Person person) {
    ((census_model::census *)census)->recordPerson(*(census_model::person *)person);
}

int CensusGetAverageAge (Census census) {
    return ((census_model::census *)census)->averageAge();
}

int CensusGetPopulation (Census census, StateRegion region) {
    return ((census_model::census *)census)->getPopulation(region);
}
