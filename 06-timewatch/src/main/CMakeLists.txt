#  ==============================================================================
#  Created by Fehmi Demiralp(Fedem) on 2025-05-29 GMT
#  Copyright (C) 2023-2025 Fedem (Fehmi Demiralp) <f.demiralp@gmail.com>
#
#  Released under the MIT License
#  ============================================================================

cmake_minimum_required( VERSION 3.20 )

include_directories(${CMAKE_CURRENT_SOURCE_DIR})
include_directories(${CMAKE_SOURCE_DIR}/generated/src/timewatch)
include_directories(${CMAKE_SOURCE_DIR}/generated/src/command)

# The project
set(MAIN_SOURCE
    main.c
)

set(MAIN_HEADER
)

add_executable(timewatch ${MAIN_SOURCE} ${MAIN_HEADER})
target_link_libraries(timewatch PUBLIC
    LIBRTimewatch_Static
    LIBRCommand_Static
    -lncurses
)
