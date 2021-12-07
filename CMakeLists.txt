cmake_minimum_required(VERSION 3.10.2)
project(src)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

set(QT_VERSION 5)
SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -pthread")
set(REQUIRED_LIBS Core Gui Widgets)
set(REQUIRED_LIBS_QUALIFIED Qt5::Core Qt5::Gui Qt5::Widgets)
add_library(jsoncpp SHARED IMPORTED)
set_target_properties(jsoncpp PROPERTIES
        IMPORTED_LOCATION "/usr/local/lib/libjsoncpp.so"
        INTERFACE_INCLUDE_DIRECTORIES "/usr/local/include/json"
        )
add_executable(${PROJECT_NAME} main.cpp
        Containers/matrix/matrix/matrix_base.cpp
        Containers/matrix/errors/errors.cpp
        View/View.cpp
        View/View.h Primitives/Point.cpp Primitives/Point.h Primitives/Light/Light.cpp Primitives/Light/Light.h Primitives/Light/AmbientLight.cpp Primitives/Light/AmbientLight.h Primitives/Light/PointLight.cpp Primitives/Light/PointLight.h Primitives/Light/DirectionalLight.cpp Primitives/Light/DirectionalLight.h Loader/File/FileObjectsLoader.cpp Loader/File/FileObjectsLoader.h Primitives/Surfaces/CompositeSurface.cpp Primitives/Surfaces/CompositeSurface.h Primitives/Surfaces/Object.cpp Primitives/Surfaces/Object.h Primitives/Surfaces/Surface.cpp Primitives/Surfaces/Surface.h Scene/RayTracer/RayTracer.cpp Scene/RayTracer/RayTracer.h Primitives/Surfaces/CollectionSurface.cpp Primitives/Surfaces/CollectionSurface.h Commands/Command.h Scene/Scene.cpp Scene/Scene.h Primitives/Camera/Camera.cpp Primitives/Camera/Camera.h Loader/SceneLoader.h Loader/ObjectsLoader.h Loader/CameraLoader.h Loader/LightsLoader.h Loader/File/FileCameraLoader.cpp Loader/File/FileCameraLoader.h Loader/File/FileLightsLoader.cpp Loader/File/FileLightsLoader.h Loader/SceneLoader.cpp Scene/DrawerAlgo.h Drawer/Drawer.h Drawer/QtDrawer.cpp Drawer/QtDrawer.h Drawer/DrawerCreator/DrawerCreator.h Drawer/DrawerCreator/QtDrawerCreator.cpp Drawer/DrawerCreator/QtDrawerCreator.h Drawer/DrawerColor.cpp Drawer/DrawerColor.h Facade/Facade.cpp Facade/Facade.h Commands/MoveCommand.cpp Commands/MoveCommand.h Primitives/Primitive.h Primitives/Camera/PrimitiveCamera.cpp Primitives/Camera/PrimitiveCamera.h Primitives/Light/PrimitiveLight.cpp Primitives/Light/PrimitiveLight.h Primitives/Surfaces/PrimitiveObject.cpp Primitives/Surfaces/PrimitiveObject.h Commands/ScaleCommand.cpp Commands/ScaleCommand.h Commands/RotateCommand.cpp Commands/RotateCommand.h Commands/LoadCommand.cpp Commands/LoadCommand.h Commands/DrawCommand.cpp Commands/DrawCommand.h Primitives/Surfaces/Torus.cpp Primitives/Surfaces/Torus.h Primitives/Surfaces/qsolver.cpp Primitives/Surfaces/qsolver.h Primitives/Surfaces/Poly.cpp Loader/ConfigLoader.cpp Loader/ConfigLoader.h Loader/Configuration.cpp Loader/Configuration.h Loader/File/FileConfigLoader.cpp Loader/File/FileConfigLoader.h View/ConsoleView.cpp View/ConsoleView.h)

find_package(Qt${QT_VERSION} COMPONENTS ${REQUIRED_LIBS} REQUIRED)
target_link_libraries(${PROJECT_NAME} ${REQUIRED_LIBS_QUALIFIED} jsoncpp)

add_subdirectory("./UnitTests")
