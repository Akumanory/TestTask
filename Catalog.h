#pragma once

#include <vector>
#include <unordered_map>
#include <memory>
#include <algorithm>
// #include <type_traits>

#include "Car.h"
#include "Person.h"

// template<typename T>
class Catalog
{
friend class InputHandler;
public:
    Catalog();
    Catalog(const int& reserv_size);

    void AddToCatalog(const Car& car);
    void PrintCatalog() const;
    bool BuyCar(Person& person, const int& id);
    const std::unordered_map<int, const std::shared_ptr<Car>>& GetAllCarsInCatalog();

    template <typename ...Args>
    void AddToCatalogByArgs(Args && ...args)
    {
        // m_catalog.emplace_back(std::forward<Args>(args)...);
        m_catalog.emplace(
            std::piecewise_construct,
            std::forward_as_tuple(Car::m_car_total),
            std::forward_as_tuple(std::make_shared<Car>(std::forward<Args>(args)...)
            )
        );
    }

    template<typename Predicate>
    void FilterCatalog(Predicate comp) const
    {
        std::cout << "Filtered result:" << std::endl;
        for (auto& item : m_catalog)
        {
            if (comp(*(item.second.get())))
            {
                item.second.get()->PrintInfo();
            }
        }
        std::cout << std::endl;
    }

private:

    bool comp(const Car& car);
    // std::vector<std::shared_ptr<Car>> m_catalog;
    std::unordered_map<int, const std::shared_ptr<Car>> m_catalog;
};

