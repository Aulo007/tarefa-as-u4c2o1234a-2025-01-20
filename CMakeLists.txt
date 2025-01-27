cmake_minimum_required(VERSION 3.13)

set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# Define the path to the Pico SDK
set(PICO_SDK_PATH "C:/Users/Diego/.pico-sdk")

# Initialise pico_sdk from installed location
if(WIN32) 
    set(USERHOME $ENV{USERPROFILE}) 
else() 
    set(USERHOME $ENV{HOME}) 
endif()
set(sdkVersion 2.1.0)
set(toolchainVersion 13_3_Rel1)
set(picotoolVersion 2.1.0)
set(picoVscode ${USERHOME}/.pico-sdk/cmake/pico-vscode.cmake)
if (EXISTS ${picoVscode}) 
    include(${picoVscode}) 
endif()

set(PICO_BOARD pico_w CACHE STRING "Board type")

# Pull in Raspberry Pi Pico SDK (must be before project)
include(pico_sdk_import.cmake)

project(Animation5 C CXX ASM)

# Initialise the Raspberry Pi Pico SDK
pico_sdk_init()

# Add executable. Default name is the project name, version 0.1
add_executable(Animation5 Animation5.c)

# Adicionar código PIO (supondo que o arquivo se chame ws2818b.pio)
pico_generate_pio_header(Animation5 ${CMAKE_CURRENT_LIST_DIR}/ws2818b.pio)

# Incluir as bibliotecas necessárias
target_link_libraries(Animation5
    pico_stdlib
    hardware_pio   # Adiciona a biblioteca hardware_pio para usar funções PIO
)

# Definir o nome e a versão do programa
pico_set_program_name(Animation5 "Animation5")
pico_set_program_version(Animation5 "0.1")

# Modificar as linhas abaixo para habilitar/desabilitar a saída por UART/USB
pico_enable_stdio_uart(Animation5 0)
pico_enable_stdio_usb(Animation5 0)

# Adicionar os diretórios de cabeçalhos necessários ao build
target_include_directories(Animation5 PRIVATE
    ${CMAKE_CURRENT_LIST_DIR}
)

# Adicionar saídas extras
pico_add_extra_outputs(Animation5)
