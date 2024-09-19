cmake_minimum_required(VERSION 3.10)
project(HelloRaylib)

# Definir o padrão de C++ para C++17
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Localize a Raylib
# Se você instalou a Raylib usando um gerenciador de pacotes ou instalador, o CMake pode encontrá-la automaticamente.
# Caso contrário, defina o caminho para o diretório de instalação da Raylib.
find_package(raylib REQUIRED)

# Adicionar o diretório de cabeçalhos do projeto
include_directories(${PROJECT_SOURCE_DIR}/include)

# Adicionar os arquivos fonte
file(GLOB SOURCES "src/*.cpp")

# Criar o executável
add_executable(HelloRaylib ${SOURCES})

# Linkar a biblioteca Raylib com o projeto
target_link_libraries(HelloRaylib raylib)

# Se você estiver em um sistema que não seja Windows, pode precisar adicionar outras bibliotecas
if (NOT MSVC)
    # Adiciona bibliotecas necessárias para sistemas Unix
    target_link_libraries(HelloRaylib -lGL -lGLU -lm -lpthread)
endif()
