CMAKE_MINIMUM_REQUIRED(VERSION 3.10)
SET(EXECUTABLE_NAME r-type_client)
SET(SHARED_SRC ../shared)
PROJECT(${EXECUTABLE_NAME})

INCLUDE_DIRECTORIES(${CMAKE_INCLUDE_PATH}
        graph/
        network/
        scenes/
        scenes/game
        scenes/menu/
        conf/
        ../shared/
        )

ADD_EXECUTABLE(
        ${EXECUTABLE_NAME}
        ${SHARED_SRC}/Protocol.cpp
        ${SHARED_SRC}/Protocol.hpp
        conf/Conf.hpp
        Main.cpp
        scenes/IScene.hpp
        scenes/game/Game.cpp
        scenes/game/Game.hpp
        scenes/menu/Menu.cpp
        scenes/menu/Menu.hpp
        graph/SFML.cpp
        graph/SFMLEntity.cpp
        network/Network.cpp
        network/Network.hpp)

TARGET_LINK_LIBRARIES(${EXECUTABLE_NAME} ${CONAN_LIBS})