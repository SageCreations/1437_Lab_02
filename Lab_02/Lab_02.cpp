/*
* Edward Cruz, Lab_02
*/

#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
#include "FootballPlayerType.h"

std::ifstream inFile;
std::ofstream outFile;

void show_menu();
void input_data();
void output_data();
void search_data();
void update_data(int option);
void write_data_out();

Player players[10];

int main() 
{
    inFile.open("C:\\Users\\realq\\Documents\\1437_Projects\\Lab_02\\FootballPlayersIn.txt");
    outFile.open("C:\\Users\\realq\\Documents\\1437_Projects\\Lab_02\\FootballPlayersOut.txt");
    if (!inFile)
    {
        std::cout << "\n\t\tCan't open data file: footballPlayersIn.txt";
        exit(1);
    }

    if (!outFile)
    {
        std::cout << "\n\t\tCan't open data file: footballPlayersOut.txt";
        exit(1);
    }

    input_data();
    show_menu();

    return 0;
}

void show_menu()
{
    char save; 
    int input;
    
    std::cout << "\nWelcome to Football Info";
    
    do {
        std::cout << "\nSelect one of the following options.";
        std::cout << "\n1: To print a player's data";
        std::cout << "\n2: To print the entire data";
        std::cout << "\n3: To update a player's touch downs";
        std::cout << "\n4: To update a Player's number of catches";
        std::cout << "\n5: To update a player's passing yards";
        std::cout << "\n6: To update a player's receiving yards";
        std::cout << "\n7: To update a player's rushing yards";
        std::cout << "\n99: To quit the program";
        std::cout << "\nOption: ";
        std::cin  >> input;

        switch (input)
        {
            case 1:
                //1: To print a player's data
                search_data();
                break;
            case 2:
                //2: To print the entire data
                output_data();
                break;
            case 3:
                //3: To update a player's touch downs
                update_data(3);
                break;
            case 4:
                //4: To update a Player's number of catches
                update_data(4);
                break;
            case 5:
                //5: To update a player's passing yards
                update_data(5);
                break;
            case 6:
                //6: To update a player's receiving yards
                update_data(6);
                break;
            case 7:
                //7: To update a player's rushing yards
                update_data(7);
                break;
            case 99:
                std::cout << "\n\n\t\tBefore we terminate would you like to rewrite existing data with the data from this session? (Y/N)";
                std::cin  >> save;
                if (save == 'y' || save == 'Y') 
                {
                    write_data_out();
                    exit(1);
                }
                else
                    exit(1);
                break;
            default:
                std::cout << "\n\nPlease input an option from the menu!";
                break;
        }

    } while (input != 99);
}

void input_data()
{
    std::string name, position;
    int td, cat, py, rey, ruy;
    //inFile reading and storing data from file.
    int counter = 0;
    while (inFile >> name >> position >> td >> cat >> py >> rey >> ruy)
    {
        players[counter].name = name;
        players[counter].position = position;
        players[counter].touch_downs = td;
        players[counter].catches = cat;
        players[counter].passing_yards = py;
        players[counter].recieving_yards = rey;
        players[counter].rushing_yards = ruy;
        counter++;
    }
}

void output_data()
{
    //use this when user wants to rewrite data.
    for (int i = 0; i < (sizeof(players)/sizeof(*players)); i++)
    {
        std::cout << std::left << std::endl;
        std::cout << std::setw(20) << "Name: " << players[i].name << std::endl;
        std::cout << std::setw(20) << "Position: " << players[i].position << std::endl;
        std::cout << std::setw(20) << "Touch Downs: " << players[i].touch_downs << std::endl;
        std::cout << std::setw(20) << "Catches: " << players[i].catches << std::endl;
        std::cout << std::setw(20) << "Passing Yards: " << players[i].passing_yards << std::endl;
        std::cout << std::setw(20) << "Recieving Yards: " << players[i].recieving_yards << std::endl;
        std::cout << std::setw(20) << "Rushing Yards: " << players[i].rushing_yards << std::endl;
        std::cout << std::endl;
    }
}

void search_data()
{
    bool check = false;
    do{
        int input;
        std::cout << "\n\nPick a number between 1-10 to get a specific player's data.";
        std::cout << "\n(If you showed the current data before, that is the order of the player's data)";
        std::cout << "\n(1 - 10):  ";
        std::cin  >> input;
        if ((input < 1) || (input > 10)) 
        {
            std::cout << "\nPlease pick a number between 1 and 10 next time.";
        }
        else {
            std::cout << std::left << std::endl;
            std::cout << std::setw(20) << "Name: " << players[input-1].name << std::endl;
            std::cout << std::setw(20) << "Position: " << players[input-1].position << std::endl;
            std::cout << std::setw(20) << "Touch Downs: " << players[input-1].touch_downs << std::endl;
            std::cout << std::setw(20) << "Catches: " << players[input-1].catches << std::endl;
            std::cout << std::setw(20) << "Passing Yards: " << players[input-1].passing_yards << std::endl;
            std::cout << std::setw(20) << "Recieving Yards: " << players[input-1].recieving_yards << std::endl;
            std::cout << std::setw(20) << "Rushing Yards: " << players[input-1].rushing_yards << std::endl;
            std::cout << std::endl;
            check = true;
        }
    } while (check == false);
}

void update_data(int option)
{
    bool check = false;
    do {
        int input;
        std::cout << "\n\nPick a number between 1-10 to pick the player you whish to update.";
        std::cout << "\n(If you did option #2, that is the order of the player's data)";
        std::cout << "\n(1 - 10):  ";
        std::cin  >> input;
        if ((input < 1) || (input > 10)) 
        {
            std::cout << "\nPlease pick a number between 1 and 10 next time.";
        }
        else {
            switch(option)
            {
                case 3:
                    //3: To update a player's touch downs
                    std::cout << "\n\nThe current touch downs stats are " << players[input-1].touch_downs << ".";
                    std::cout << "\nWhat would you like to change it to : ";
                    std::cin  >> players[input-1].touch_downs;
                    std::cout << "The new touch down stats are " << players[input-1].touch_downs << ".\n\n";
                    break;
                case 4:
                    //4: To update a Player's number of catches
                    std::cout << "\n\nThe current catches stats are " << players[input-1].catches << ".";
                    std::cout << "\nWhat would you like to change it to : ";
                    std::cin  >> players[input-1].catches;
                    std::cout << "The new catches stats are " << players[input-1].catches << ".\n\n";
                    break;
                case 5:
                    //5: To update a player's passing yards
                    std::cout << "\n\nThe current passing yards stats are " << players[input-1].passing_yards << ".";
                    std::cout << "\nWhat would you like to change it to : ";
                    std::cin  >> players[input-1].passing_yards;
                    std::cout << "The new passing yards stats are " << players[input-1].passing_yards << ".\n\n";
                    break;
                case 6:
                    //6: To update a player's receiving yards
                    std::cout << "\n\nThe current receiving yards stats are " << players[input-1].recieving_yards << ".";
                    std::cout << "\nWhat would you like to change it to : ";
                    std::cin  >> players[input-1].recieving_yards;
                    std::cout << "The new receiving yards stats are " << players[input-1].recieving_yards << ".\n\n";
                    break;
                case 7:
                    //7: To update a player's rushing yards
                    std::cout << "\n\nThe current rushing yards stats are " << players[input-1].rushing_yards << ".";
                    std::cout << "\nWhat would you like to change it to : ";
                    std::cin  >> players[input-1].rushing_yards;
                    std::cout << "The new rushing yards stats are " << players[input-1].rushing_yards << ".\n\n";
                    break;
            }
            check = true;
        }
    } while (check != true);
}

void write_data_out()
{
    for (int i = 0; i < sizeof(players)/sizeof(*players); i++)
    {
        outFile << players[i].name << " " 
                << players[i].position << " "
                << players[i].touch_downs << " "
                << players[i].catches << " "
                << players[i].passing_yards << " "
                << players[i].recieving_yards << " "
                << players[i].rushing_yards << std::endl;
    }
}