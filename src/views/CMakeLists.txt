project(${CMAKE_PROJECT_NAME}_views)

add_library(${PROJECT_NAME} STATIC)
target_include_directories(${PROJECT_NAME} PUBLIC .)
target_link_libraries(${PROJECT_NAME}
        ${CMAKE_PROJECT_NAME}_domain
        ${CMAKE_PROJECT_NAME}_presentation
        )
target_precompile_headers(${PROJECT_NAME} PRIVATE
        "$<$<COMPILE_LANGUAGE:CXX>:${CMAKE_CURRENT_SOURCE_DIR}/precompiled.h>"
        )

add_subdirectory(views)
