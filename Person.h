#pragma once

#include <memory>

#include "Car.h"

class Person
{
friend class Catalog;
friend class InputHandler;
public:
    Person();

private:
    std::shared_ptr<Car> m_owned_car = nullptr;
};