#include "Catalog.h"

Catalog::Catalog()
{}

Catalog::Catalog(const int& reserv_size)
{
    m_catalog.reserve(reserv_size);
}

void Catalog::AddToCatalog(const Car& car)
{
    m_catalog.insert(
        std::make_pair(
            car.m_car_id,
            std::make_shared<Car>(car)
            )
        );
}

const std::unordered_map<int, const std::shared_ptr<Car>>& Catalog::GetAllCarsInCatalog()
{
    return m_catalog;
}

bool Catalog::BuyCar(Person& person, const int& id)
{
    auto search = m_catalog.find(id);

    if (search != m_catalog.end())
    {
        person.m_owned_car = search->second;
        m_catalog.erase(id);
        return true;
    }
    return false;
}

void Catalog::PrintCatalog() const
{
    for (auto& it : m_catalog)
    {
        it.second.get()->PrintInfo();
    }
}