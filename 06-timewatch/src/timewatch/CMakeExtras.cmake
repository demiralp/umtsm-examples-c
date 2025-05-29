#  ==============================================================================
#  Created by Fehmi Demiralp(Fedem) on 2025-05-29 GMT
#  Copyright (C) 2023-2025 Fedem (Fehmi Demiralp) <f.demiralp@gmail.com>
#
#  Released under the MIT License
#  ============================================================================

#
# Timewatch
#
#set(LIBTimewatch_SOURCE_EXTRA )
#set(LIBTimewatch_HEADER_EXTRA )
set(LIBTimewatch_LIB_EXTRA -lncurses)
set(LIBTimewatch_INCLUDES_EXTRA
    ${CMAKE_SOURCE_DIR}/generated/src/timewatch
)
set(TESTTimewatch_LIB_EXTRA -lncurses)
