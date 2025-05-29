#  ==============================================================================
#  Created by Fehmi Demiralp(Fedem) on 2024-11-02 GMT
#  Copyright (C) 2023-2024 Fedem (Fehmi Demiralp) <f.demiralp@gmail.com>
#
#  Released under the MIT License
#  ============================================================================

#
# Calculator
#
set(LIBCalculator_SOURCE_EXTRA Calculator_Utilities.c)
set(LIBCalculator_HEADER_EXTRA Calculator_Utilities.h)
#set(LIBCalculator_LIB_EXTRA )
#set(LIBCalculator_INCLUDES_EXTRA "${CMAKE_CURRRENT_SOURCE_DIR}")
set(TESTCalculator_LIB_EXTRA LIBRKeypad_Shared LIBRDisplay_Shared -lncurses)

#
# Display
#
set(LIBDisplay_SOURCE_EXTRA Display_Utilities.c)
set(LIBDisplay_HEADER_EXTRA Display_Utilities.h)
#set(LIBDisplay_LIB_EXTRA )
#set(LIBDisplay_INCLUDES_EXTRA "${CMAKE_CURRRENT_SOURCE_DIR}")
#set(TESTDisplay_LIB_EXTRA )

#
# Keypad
#
#set(LIBKeypad_SOURCE_EXTRA )
#set(LIBKeypad_HEADER_EXTRA )
#set(LIBKeypad_LIB_EXTRA )
#set(LIBKeypad_INCLUDES_EXTRA "${CMAKE_CURRRENT_SOURCE_DIR}")
#set(TESTKeypad_LIB_EXTRA )
