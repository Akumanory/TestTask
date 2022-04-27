#include "Catalog.h"
#include "Person.h"
#include "InputHandler.h"
// #include "headers/Car.h"
#include <string>

int main()
{
    Person person;
    Catalog catalog(10);
    catalog.AddToCatalogByArgs(280,   9090.40);
    catalog.AddToCatalogByArgs(120,   8080.50);
    catalog.AddToCatalogByArgs(56,    1260.50);
    catalog.AddToCatalogByArgs(1,     60.30);
    catalog.AddToCatalogByArgs(1200,  100860.10);
    catalog.AddToCatalogByArgs(70,    1860.55);
    catalog.AddToCatalogByArgs(500,   20050.12);
    catalog.AddToCatalogByArgs(88,    1000.15);
    catalog.AddToCatalogByArgs(34,    2560.06);
    catalog.AddToCatalogByArgs(28,    887.32);

    InputHandler ih(catalog, person);
    ih.Initialize();

    return 0;
}