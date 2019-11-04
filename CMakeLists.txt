cmake_minimum_required(VERSION 3.15)
project(pract_1)


set(CMAKE_CXX_STANDARD 11)
add_executable(pract_1 RegularResolant/RegularResolant.h main.cpp RegularResolant/RegularResolant.cpp Solver/solver.cpp Solver/solver.h WrongNotationException/WrongNotationException.cpp WrongNotationException/WrongNotationException.h)

if(MINGW)
    set(GTEST_DISABLE_PTHREADS ON)
endif()

if(WIN32)
    set(WINDOWS_CMAKE_ARGS
            -DCMAKE_ARCHIVE_OUTPUT_DIRECTORY_DEBUG:PATH=DebugLibs
            -DCMAKE_ARCHIVE_OUTPUT_DIRECTORY_RELEASE:PATH=ReleaseLibs
            )
else(WIN32)
    set(WINDOWS_CMAKE_ARGS )
endif(WIN32)


include_directories(
        RegularResolant
        Solver
        WrongNotationException
)
include_directories(testing)

add_subdirectory(RegularResolant)
add_subdirectory(Solver)
add_subdirectory(WrongNotationException)



enable_testing()
add_subdirectory(testing)