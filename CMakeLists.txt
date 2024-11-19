cmake_minimum_required(VERSION 3.10)

project(CPDLC)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/build)

set(TOWER_SOURCES
    Tower.cpp
    TowerSender.cpp
    TowerReceiver.cpp
    DataLinkMessage.cpp
)

set(AIRCRAFT_SOURCES
    Aircraft.cpp
    MockDownlinkSender.cpp
    MockUplinkReceiver.cpp
    ConnectionResponse.cpp
    AircraftReceiver.cpp
    DataLinkMessage.cpp
    DownLinkMessages/RequestLevel.cpp
    DownLinkMessages/RequestBlockLevel.cpp
    DownLinkMessages/RequestCruiseLevel.cpp
    DownLinkMessages/RequestClimbLevel.cpp
    DownLinkMessages/RequestDescentLevel.cpp
    DownLinkMessages/RequestLevelAtPosition.cpp
    DownLinkMessages/PermittedResponseGroup.cpp
    DownLinkMessages/Wilco.cpp
    DownLinkMessages/Response.cpp
    DownLinkMessages/Negative.cpp
    DownLinkMessages/Roger.cpp 
    DownLinkMessages/Affirm.cpp
    DownLinkMessages/Standby.cpp
    DownLinkMessages/Unable.cpp 
)

add_executable(Tower.exe ${TOWER_SOURCES})
add_executable(Aircraft.exe ${AIRCRAFT_SOURCES})

include_directories(/usr/include)
link_directories(/usr/lib/x86_64-linux-gnu)

# Link ZeroMQ library
target_link_libraries(Tower.exe PRIVATE zmq)
target_link_libraries(Aircraft.exe PRIVATE zmq)

# Add cppzmq as a header-only 
find_path(CPPZMQ_INCLUDE_DIR zmq.hpp REQUIRED)
if (CPPZMQ_INCLUDE_DIR)
    target_include_directories(Tower.exe PRIVATE ${CPPZMQ_INCLUDE_DIR})
    target_include_directories(Aircraft.exe PRIVATE ${CPPZMQ_INCLUDE_DIR})
else()
    message(FATAL_ERROR "cppzmq headers not found. Install cppzmq.")
endif()
