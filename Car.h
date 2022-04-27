#pragma once

#include <iostream>

class Car
{
friend class Catalog;
public:
    Car(int speed = 0, double cost = 0.0);
    ~Car();

    Car(Car&& car) = default;
    Car(const Car& car) = default;

    const int&    GetID() const;
    const int&    GetSpeed() const;
    const double& GetCost() const;


    void PrintInfo();

private:
    static int    m_car_total;
    const  int    m_car_id = 0;

    const  int    m_speed = 0;
    const  double m_cost = 0.0;
};