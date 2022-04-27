#include "Car.h"

int Car::m_car_total = 0;

Car::Car(int speed, double cost) :
    m_car_id(++m_car_total),
    m_speed(speed),
    m_cost(cost)
    {}

Car::~Car()
{
    --m_car_total;
}

const int& Car::GetSpeed() const
{
    return m_speed;
}

const double& Car::GetCost() const
{
    return m_cost;
}

const int& Car::GetID() const
{
    return m_car_id;
}

void Car::PrintInfo()
{
    std::cout << "ID: " << m_car_id << " Speed: " << m_speed << " Cost: " << m_cost << std::endl;
}
// Car::Car(Car&& car) :
//     m_car_id(std::move(car.m_car_id)),
//     m_speed(std::move(car.m_speed)),
//     m_cost(std::move(car.m_cost))
// {
//     std::cout << "Car data moved" << std::endl;
// }

// const int& Car::GetID() const
// {
//     return m_car_id;
// }
