//
//  main.swift
//  Census
//
//  Created by David O'Neill on 1/13/19.
//  Copyright © 2019 Cwift Census. All rights reserved.
//

import Foundation



let people = [Person.create(age: 10, region: .east),
              Person.create(age: 20, region: .north),
              Person.create(age: 30, region: .south),
              Person.create(age: 40, region: .west),
              Person.create(age: 50, region: .west),
              Person.create(age: 60, region: .west),
              Person.create(age: 70, region: .south),
              Person.create(age: 80, region: .south),
              Person.create(age: 90, region: .north),
              Person.create(age: 100, region: .west)]

guard let census = CensusCreate() else { fatalError() }

for person in people {
    census.record(person: person)
}

if let hodor = Person.create(age: 5, region: .north) {
    // In C it would be PersonSetAge(hodor, PersonGetAge(hodor) * 10);
    hodor.age *= 10
    census.record(person: hodor)
}

print("The average age in TownVille in \(census.averageAge())")

for region in [StateRegion.north, .east, .south, .west] {
    print("The population in \(region) TownVille is \(census.population(region: region))")
}

// Still need to manage the C/C++ objects' lifetime....
CensusDestroy(census)
for person in people {
    PersonDestroy(person)
}

// State Region is a C enum that can be imported into C++ C and Swift.
// Extending with CustomStringConvertible.
extension StateRegion : CustomStringConvertible {
    public var description: String {
        switch self {
        case .north: return "North"
        case .east: return "East"
        case .south: return "South"
        case .west: return "West"
        }
    }
}
