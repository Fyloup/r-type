CMAKE_MINIMUM_REQUIRED(VERSION 3.10)
SET(EXECUTABLE_NAME r-type_server)
SET(SHARED_SRC ../shared)
PROJECT(${EXECUTABLE_NAME})

INCLUDE_DIRECTORIES(${CMAKE_INCLUDE_PATH}
        ../shared/)
ADD_EXECUTABLE(
        ${EXECUTABLE_NAME}
        Main.cpp
        game/Game.cpp
        game/Game.hpp
        gameEngine/engine/Engine.cpp
        gameEngine/engine/Engine.hpp
        gameEngine/entity/Entity.cpp
        gameEngine/entity/Entity.hpp
        gameEngine/network/Server.cpp
        gameEngine/network/Server.hpp
        ${SHARED_SRC}/Protocol.cpp
        ${SHARED_SRC}/Protocol.hpp
)
TARGET_LINK_LIBRARIES(${EXECUTABLE_NAME} ${CONAN_LIBS})
