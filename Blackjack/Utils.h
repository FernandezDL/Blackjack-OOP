// @Copyright Julian & Diana - VFS 2025-2026

#pragma once

// Libraries
#include <iostream>
#include <limits>
#include <random>
#include <vector>
#include <algorithm>
#include <memory>
#include <cstdlib>

// Log definitions
#define LOG(X) std::cout << X
#define LOG_LN(X) std::cout << X << std::endl
#define LOG_EMPTY_LN std::cout << std::endl
#define LOG_SPACER std::cout << "===========================================" << std::endl
#define LOG_SPACER_LN std::cout << "\n===========================================" << std::endl
#define LOG_SPACER2_LN std::cout << "\n*******************************************" << std::endl
#define LOG_SPACER2 std::cout << "*******************************************" << std::endl

// String definition
#define STRING std::string

// Input definitions
#define INPUT_WITH_ERROR(INPUT_TEXT, INPUT_VAR, ERROR_MESSAGE)\
do\
{\
    LOG(INPUT_TEXT << " : ");\
    std::cin >> INPUT_VAR;\
    if (!std::cin.fail())\
    {\
        break;\
    }\
    std::cin.clear();\
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');\
    std::cerr << ERROR_MESSAGE << std::endl;\
}\
while (true);

#define INPUT(INPUT_TEXT, INPUT_VAR)\
INPUT_WITH_ERROR(INPUT_TEXT, INPUT_VAR, "Invalid input. Please try again!");

#define PAUSE()\
do \
{\
    LOG("\nPress Enter to continue..."); \
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); \
}\
while(0)

#define CLEAN()\
system("cls");

// Definition for invalid argument in constructor
#define INVALID_ARGUMENT(EXCEPTION_MESSAGE) throw std::invalid_argument(EXCEPTION_MESSAGE)

// Random Number Generator definition
#define RNG std::mt19937
#define DIST std::uniform_int_distribution<int>

// Vector
#define VECTOR(X) std::vector<X>

// Smart Pointers
#define UNIQUE_PTR(X) std::unique_ptr<X>
#define SHARED_PTR(X) std::shared_ptr<X>
#define WEAK_PTR(X) std::weak_ptr<X>
#define MAKE_UNIQUE(X) std::make_unique<X>
#define MAKE_SHARED(X) std::make_shared<X>

// Project Specifics
#define CONTINUE_INPUT(CONTINUE)\
while (CONTINUE != "n" && CONTINUE != "y")\
{\
    LOG_SPACER_LN;\
    INPUT("Do you wish to draw another card? (y/n)", CONTINUE)\
    LOG_SPACER;\
}

#define PLAYAGAIN_INPUT(CONTINUE)\
while (CONTINUE != "n" && CONTINUE != "y")\
{\
    LOG_SPACER_LN;\
    INPUT("Do you wish to keep playing? (y/n)", CONTINUE)\
    LOG_SPACER;\
}

#define INSTRUCTIONS()\
LOG_LN("-------------------------------------------------------------------------------------------------------");\
LOG_LN("\t\t\t\t\tWelcome to the Royal Casino");\
LOG_EMPTY_LN;\
LOG_LN("\t\t\t\t\tThis is a Blackjack table.\n");\
LOG_LN("The goal is to get a card total total closer to 21 than the dealer's hand, without going over 21\n");\
LOG_LN("\nThe rules are:");\
LOG_LN("1.- Two cards will be drawn to you and to the dealer");\
LOG_LN("2.- If your hand is less than 21, they will ask you if you want to draw a card.");\
LOG_LN("3.- If you decide to draw a card, it will be added to the total of your hand, and if the total\n    is less than 21, you can decide to draw another card.");\
LOG_LN("4.- If you decide not to draw any more cards, it's the dealer's turn.");\
LOG_LN("5.- The dealer will try to match or beat your hand by drawing cards.");\
LOG_LN("6.- If the dealer goes over 21, the player wins, but if the dealer has a hand equal to or higher\n    than the player's, the dealer wins.");\
LOG_LN("-------------------------------------------------------------------------------------------------------\n");
