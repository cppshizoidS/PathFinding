cmake_minimum_required(VERSION 3.26)
project(PahtFinding LANGUAGES CXX) #change ${PROJECT_NAME} to actual projet name only in project()
# standart
set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

#lld
set(CMAKE_EXE_LINKER_FLAGS -fuse-ld=lld)
# include what you use
find_program(IWYU_PROGRAM NAMES include-what-you-use) # https://github.com/include-what-you-use/include-what-you-use
if(IWYU_PROGRAM)
  set(CMAKE_CXX_INCLUDE_WHAT_YOU_USE ${IWYU_PROGRAM})
endif()

#doxygen
if (DOCS)
  add_subdirectory(docs)
endif()

#  Functions
function(copy_after_build TARGET_NAME)
  set(DESTDIR ${CMAKE_CURRENT_LIST_DIR}/bin/)
  file(MAKE_DIRECTORY ${DESTDIR})
  # Copy binary file to <CMakeLists.txt didctory>./bin after target is compiled.
  add_custom_command(
    TARGET ${TARGET_NAME}
    POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy $<TARGET_FILE:${TARGET_NAME}> ${DESTDIR})
endfunction()

#sfml
find_package(sfml-graphics)

#Target Configurations
file(GLOB SOURCE_FILE src/*.cpp)
add_executable(${PROJECT_NAME} ${SOURCE_FILE})
# Include headers dir
target_include_directories(${PROJECT_NAME} PRIVATE include)

# sfml
target_link_libraries(${PROJECT_NAME} PRIVATE sfml-graphics)
target_link_libraries(${PROJECT_NAME} PRIVATE sfml-window)
target_link_libraries(${PROJECT_NAME} PRIVATE sfml-system)
