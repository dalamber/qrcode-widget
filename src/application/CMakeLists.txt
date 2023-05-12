project(${CMAKE_PROJECT_NAME}_application)
add_executable(${PROJECT_NAME})
target_link_libraries(${PROJECT_NAME}
        Qt::Core
        Qt::Gui
        Qt::Widgets
        ${CMAKE_PROJECT_NAME}_data
        ${CMAKE_PROJECT_NAME}_domain
        ${CMAKE_PROJECT_NAME}_presentation
        ${CMAKE_PROJECT_NAME}_views
        )
target_precompile_headers(${PROJECT_NAME} PRIVATE
        "$<$<COMPILE_LANGUAGE:CXX>:${CMAKE_CURRENT_SOURCE_DIR}/precompiled.h>"
        )

add_subdirectory(application)
