#  ==============================================================================
#  Created by Fehmi Demiralp(Fedem) on 2025-05-29 GMT
#  Copyright (C) 2023-2025 Fedem (Fehmi Demiralp) <f.demiralp@gmail.com>
#
#  Released under the MIT License
#  ============================================================================

#
# Crossroad
#
#set(LIBCrossroad_SOURCE_EXTRA )
#set(LIBCrossroad_HEADER_EXTRA )
#set(LIBCrossroad_LIB_EXTRA )
set(LIBCrossroad_INCLUDES_EXTRA
    ${CMAKE_SOURCE_DIR}/generated/src/dashboard
    ${CMAKE_SOURCE_DIR}/generated/src/execution-director
    ${CMAKE_SOURCE_DIR}/generated/src/lane
    ${CMAKE_SOURCE_DIR}/generated/src/pedestrian-light
    ${CMAKE_SOURCE_DIR}/generated/src/trafficlight
)
set(TESTCrossroad_LIB_EXTRA
    LIBRDashboard_Static
    LIBRLane_Static
    LIBRTrafficLight_Static
    LIBRPedestrianLights_Static
    LIBRMonitor_Static
    LIBRExecutionDirector_Static
    -lncurses
)
