#pragma once

#include <memory>

#include "Car.h"

class Person
{
friend class Catalog;
friend class InputHandler;
public:
    Person();
// private:
//     void AssignCar(std::shared_ptr<Car>& car);
private:
    std::shared_ptr<Car> m_owned_car = nullptr;
};