project(${CMAKE_PROJECT_NAME}_presentation)

add_library(${PROJECT_NAME} STATIC)
target_include_directories(${PROJECT_NAME} PUBLIC .)
target_link_libraries(${PROJECT_NAME}
        ${CMAKE_PROJECT_NAME}_data
        ${CMAKE_PROJECT_NAME}_domain
        )
target_precompile_headers(${PROJECT_NAME} PRIVATE
        "$<$<COMPILE_LANGUAGE:CXX>:${CMAKE_CURRENT_SOURCE_DIR}/precompiled.h>"
        )

add_subdirectory(presentation)
