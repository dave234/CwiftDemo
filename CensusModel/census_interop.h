//
//  census_interop.h
//  Census
//
//  Created by David O'Neill on 1/13/19.
//  Copyright © 2019 Cwift Census. All rights reserved.
//

#ifndef census_interop_h
#define census_interop_h

#include <stdio.h>
#include <Cwift/Cwift.h>

#ifdef __cplusplus
extern "C" {
#endif



typedef void * Person CWIFT_TYPE;
typedef void * Census CWIFT_TYPE;

typedef enum CWIFT_ENUM StateRegion {
    StateRegionNorth,
    StateRegionEast,
    StateRegionSouth,
    StateRegionWest
} StateRegion;

Person  PersonCreate(int age, StateRegion region)               CWIFT_NAME(Person.create(age:region:));
void    PersonDestroy(Person person);

int     PersonGetAge(Person person)                             CWIFT_NAME(getter:Person.age(self:));
void    PersonSetAge(Person person, int age)                    CWIFT_NAME(setter:Person.age(self:newValue:));

Census  CensusCreate(void);
void    CensusDestroy(Census);

void    CensusRecordPerson(Census census, Person person)        CWIFT_NAME(Census.record(self:person:));
int     CensusGetAverageAge (Census census)                     CWIFT_NAME(Census.averageAge(self:));
int     CensusGetPopulation (Census census, StateRegion region) CWIFT_NAME(Census.population(self:region:));

#ifdef __cplusplus
} // extern "C"
#endif

#endif /* census_interop_h */
