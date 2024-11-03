#
# Monitor
#
#set(LIBMonitor_SOURCE_EXTRA )
#set(LIBMonitor_HEADER_EXTRA )
set(LIBMonitor_LIB_EXTRA -lncurses)
set(LIBMonitor_INCLUDES_EXTRA
    ${CMAKE_SOURCE_DIR}/generated/src/crossroad
    ${CMAKE_SOURCE_DIR}/generated/src/execution-director
    ${CMAKE_SOURCE_DIR}/generated/src/lane
    ${CMAKE_SOURCE_DIR}/generated/src/pedestrian-light
    ${CMAKE_SOURCE_DIR}/generated/src/trafficlight
)
set(TESTMonitor_LIB_EXTRA -lncurses)
