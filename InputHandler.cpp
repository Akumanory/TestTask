#include "InputHandler.h"

InputHandler::InputHandler(Catalog& catalog, Person& person) :
    m_catalog(catalog),
    m_person(person)
{
    m_commands.emplace("help",      TextAndId(0, " - show list of alavible commands"));
    m_commands.emplace("quit",      TextAndId(1, " - exit the programm"));
    m_commands.emplace("filter",    TextAndId(2, " - filter the catalog by passing values then shows filtered list"));
    m_commands.emplace("buy_car",   TextAndId(3, " - assign the car to person and remove this car from catalog"));
    m_commands.emplace("owned_car", TextAndId(4, " - show person's car info"));
    m_commands.emplace("list",      TextAndId(5, " - show all items in catalog"));

    m_fields_list.emplace("id",    0);
    m_fields_list.emplace("speed", 1);
    m_fields_list.emplace("cost",  2);

    m_compare_list.emplace("<",   0);
    m_compare_list.emplace(">",   1);
    m_compare_list.emplace("=",   2);
}

void InputHandler::Initialize()
{
    std::cout << "Please enter command or use help command to get list of avalible commands" << std::endl;
    while (!m_stop_input_handle)
    {
        HandleInput();
    }
    std::cout << "Exiting program" << std::endl;
}

void InputHandler::HandleInput()
{
    if (std::getline(std::cin, m_input_buffer))
    {
        auto search = m_commands.find(m_input_buffer);
        if (search != m_commands.end())
        {

            switch (search->second.m_command_id)
            {
            case 0:
                // help
                std::cout << "List of avalible commands:" << std::endl;
                for (auto& it : m_commands) {
                    std::cout << it.first << it.second.m_command_text << std::endl;
                }
                std::cout << std::endl;
                break;

            case 1:
                // exit
                m_stop_input_handle = true;
                break;

            case 2:
                HandleFilter();
                break;

            case 3:
                HandleCarBuying();
                break;

            case 4:
                if (m_person.m_owned_car != nullptr)
                {
                    std::cout << "Owned car information:" << std::endl;
                    m_person.m_owned_car.get()->PrintInfo();
                    std::cout << std::endl;
                }
                else
                {
                    std::cout << "You don't own any car" << std::endl;
                    std::cout << std::endl;
                }
                break;

            case 5:
                // list
                std::cout << "List of items in catalog:" << std::endl;
                m_catalog.PrintCatalog();
                std::cout << std::endl;
                break;

            default:
                break;
            }
        }
        else
        {
            std::cout << "No such command" << std::endl;
            std::cout << std::endl;
        }
    }
}

void InputHandler::HandleFilter()
{
    std::cout << "Please enter required param for filtering:" << std::endl;
    std::cout << "Avalible fields: " << std::endl;
    for (auto& item : m_fields_list)
    {
        std::cout << item.first << std::endl;
    }
    std::cout << std::endl;

    while(true)
    {
        // wait for field to be typed
        if (std::getline(std::cin, m_input_buffer))
        {
            auto search = m_fields_list.find(m_input_buffer);
            if (search != m_fields_list.end())
            {
                HandleCompare(search->first);
                break;
            }
            else
            {
                std::cout << "No such field" << std::endl;
                std::cout << std::endl;
            }
        }
    }
}

void InputHandler::HandleCompare(const std::string& field)
{
    std::cout << "Please enter required compare for filtering:" << std::endl;
    std::cout << "Avalible compares: " << std::endl;
    for (auto& item : m_compare_list)
    {
        std::cout << item.first << std::endl;
    }
    std::cout << std::endl;

    while(true)
    {
        // wait for compare param to be typed
        if (std::getline(std::cin, m_input_buffer))
        {
            auto search = m_compare_list.find(m_input_buffer);
            if (search != m_compare_list.end())
            {
                HandleNumber(field, search->first);
                break;
            }
            else
            {
                std::cout << "No such compare" << std::endl;
                std::cout << std::endl;
            }
        }
    }
}

void InputHandler::HandleNumber(const std::string& field, const std::string& command)
{
    std::cout << "Please enter number for filtering" << std::endl;
    std::cout << std::endl;

    while(true)
    {
        // wait for compare param to be typed
        if (std::getline(std::cin, m_input_buffer))
        {
            if (std::all_of(m_input_buffer.begin(), m_input_buffer.end(), isdigit))
            {
                int number = std::stoi(m_input_buffer);

                m_catalog.FilterCatalog(
                    [&field, &command, &number](Car& car){
                        auto temp_field = 0;

                        if (field == "id")
                        {
                            temp_field = car.GetID();
                        }
                        if (field == "cost")
                        {
                            temp_field = car.GetCost();
                        }
                        if (field == "speed")
                        {
                            temp_field = car.GetSpeed();
                        }

                        if (command == ">")
                        {
                            return temp_field > number;
                        }

                        if (command == "<")
                        {
                            return temp_field < number;
                        }

                        if (command == "=")
                        {
                            return temp_field == number;
                        }
                        return false;
                    }
                );
                break;
            }
            else
            {
                std::cout << "Invalid number" << std::endl;
                std::cout << std::endl;
            }
        }
    }
}

void InputHandler::HandleCarBuying()
{
    std::cout << "Please enter car id for buying:" << std::endl;
    std::cout << std::endl;

    while (true)
    {
        if (std::getline(std::cin, m_input_buffer))
    {
        if (std::all_of(m_input_buffer.begin(), m_input_buffer.end(), isdigit))
        {
            int id = std::stoi(m_input_buffer);

            if (m_catalog.BuyCar(m_person, id))
            {
                std::cout << "Now you own this car:" << std::endl;
                m_person.m_owned_car.get()->PrintInfo();
                std::cout << std::endl;
                break;
            }
            else
            {
                std::cout << "No such id in catalog" << std::endl;
                std::cout << std::endl;
            }

        }
        else
        {
            std::cout << "Invalid number" << std::endl;
            std::cout << std::endl;
        }
    }
    }




}