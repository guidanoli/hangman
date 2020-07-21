cmake_minimum_required(VERSION 3.13.3)

set(This cmdhangman)

set(Sources
    main.cpp
    utils.cpp
)

set(Headers
    utils.hpp
)

add_executable(${This} ${Sources} ${Headers})

target_link_libraries(${This} PUBLIC
    hangman
)