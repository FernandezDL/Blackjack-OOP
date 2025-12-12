// @Copyright Julian & Diana - VFS 2025-2026

#pragma once

#include <iostream>
#include <limits>
#include <random>
#include <vector>
#include <algorithm>
#include <memory>

// Log definitions
#define LOG(X) std::cout << X
#define LOG_LN(X) std::cout << X << std::endl
#define LOG_EMPTY_LN std::cout << std::endl

// String definition
#define STRING std::string

// Cout definition
#define COUT std::cout

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
    INPUT("Do you wish to draw another card? (y/n)", CONTINUE)\
}

#define PLAYAGAIN_INPUT(CONTINUE)\
while (CONTINUE != "n" && CONTINUE != "y")\
{\
    INPUT("Do you wish to keep playing? (y/n)", CONTINUE)\
}