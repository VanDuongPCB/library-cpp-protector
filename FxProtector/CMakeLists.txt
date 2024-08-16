cmake_minimum_required(VERSION 3.5)


project(FxProtector)


set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)


file(GLOB HEADER_FILES *.h)
file(GLOB SOURCE_FILES *.cpp)
file(GLOB UI_FILES *.ui)
file(GLOB RESOURCE_FILES *.qrc)


add_library(${PROJECT_NAME} SHARED ${HEADER_FILES} ${SOURCE_FILES} ${UI_FILES} ${RESOURCE_FILES} )

find_package(Qt${QT_VERSION_NUMBER} COMPONENTS Widgets)

target_link_libraries(${PROJECT_NAME}
Qt${QT_VERSION_NUMBER}::Core
Qt${QT_VERSION_NUMBER}::Widgets
${LIBRARY_OUTPUT_DIRECTORY}/FxCommonUI.lib
)

if(MSVC)
    # Set the "VC++ Directories > Include Directories" setting
    set(CMAKE_VS_SDK_INCLUDE_DIRECTORIES 
    "$(VC_IncludePath);$(WindowsSDK_IncludePath)" 
    "${CMAKE_SOURCE_DIR}/CommonUI/FxCommonUI"
    )
endif()

target_include_directories(${PROJECT_NAME} PUBLIC 
${CMAKE_SOURCE_DIR}/CommonUI/FxCommonUI
)

set_target_properties( ${PROJECT_NAME} PROPERTIES
    FOLDER "Protector"
    RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/${PRODUCT_NAME}
)