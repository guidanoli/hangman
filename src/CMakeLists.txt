set(This hangman)

set(Sources
    state.cpp
)

set(Headers
    state.hpp
)

add_library(${This} STATIC ${Sources} ${Headers})

target_include_directories(${This} PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}")