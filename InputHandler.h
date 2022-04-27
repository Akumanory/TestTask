#pragma once

#include "Catalog.h"
#include "Person.h"

#include <iostream>
#include <sstream>
#include <unordered_map>

struct TextAndId
{
    TextAndId(int command_id, std::string command_text) :
        m_command_id(command_id),
        m_command_text(command_text)
    {}

    int m_command_id;
    std::string m_command_text;
};

class InputHandler
{
public:
    InputHandler(Catalog& catalog, Person& person);
    void Initialize();
private:
    void HandleInput();
    void HandleFilter();
    void HandleCompare(const std::string& field);
    void HandleNumber(const std::string& field, const std::string& command);
    void HandleCarBuying();
private:
    bool m_stop_input_handle = false;
    std::string m_input_buffer = std::string();
    std::unordered_map<std::string, TextAndId> m_commands;
    std::unordered_map<std::string, int> m_fields_list;
    std::unordered_map<std::string, int> m_compare_list;

    Catalog& m_catalog;
    Person& m_person;
};