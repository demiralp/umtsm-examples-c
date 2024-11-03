#
# Dashboard
#
#set(LIBDashboard_SOURCE_EXTRA )
#set(LIBDashboard_HEADER_EXTRA )
set(LIBDashboard_LIB_EXTRA -lncurses)
set(LIBDashboard_INCLUDES_EXTRA
    ${CMAKE_SOURCE_DIR}/generated/src/crossroad
    ${CMAKE_SOURCE_DIR}/generated/src/execution-director
    ${CMAKE_SOURCE_DIR}/generated/src/lane
    ${CMAKE_SOURCE_DIR}/generated/src/monitor
    ${CMAKE_SOURCE_DIR}/generated/src/pedestrian-light
    ${CMAKE_SOURCE_DIR}/generated/src/trafficlight
)
set(TESTDashboard_LIB_EXTRA -lncurses)
