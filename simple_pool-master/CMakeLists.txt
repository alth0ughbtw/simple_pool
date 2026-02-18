cmake_minimum_required(VERSION 3.16)
project(simple_pool)

set(CMAKE_CXX_STANDARD 17)

# Если вы используете vcpkg, эту строку можно закомментировать/удалить, 
# так как vcpkg сам находит пути. 
# Если ставите вручную — оставьте.
# set(CMAKE_PREFIX_PATH "C:/libs/SDL2") 

find_package(SDL2 REQUIRED)
find_package(SDL2_image REQUIRED)
find_package(SDL2_ttf REQUIRED)
find_package(SDL2_mixer REQUIRED)

# Собираем список исходных файлов
set(SOURCES
    src/main.cpp
    src/exception.cpp
    src/mainwindow.cpp
    src/texture.cpp
    src/font.cpp
    src/music.cpp
    src/gamestate.cpp
    src/intro.cpp
    src/level.cpp
    src/table.cpp
    src/subject.cpp
    src/observer.cpp
    src/rect.cpp
    src/ball.cpp
    src/collisionobserver.cpp
    src/audioobserver.cpp
    src/cue.cpp
)

# ВАЖНО 1: Добавляем WIN32. Это говорит компилятору, что это графическое приложение Windows.
add_executable(simple_pool WIN32 ${SOURCES})

target_include_directories(simple_pool PRIVATE
    include
    ${SDL2_INCLUDE_DIRS}
)

# ВАЖНО 2: Используем современные таргеты вместо переменных.
# SDL2::SDL2main — это то, чего вам не хватало для устранения ошибки LNK2019.
target_link_libraries(simple_pool PRIVATE
    SDL2::SDL2main     # <--- Исправляет ошибку с SDL_main
    SDL2::SDL2         # <--- Основная библиотека
    SDL2_image::SDL2_image
    SDL2_ttf::SDL2_ttf
    SDL2_mixer::SDL2_mixer
)