cmake_minimum_required(VERSION 3.13...3.27)

set(PICO_BOARD pico2_w)

include(pico_sdk_import.cmake)

project(sopurano)

pico_sdk_init()

add_executable(main
    main.c
)

target_link_libraries(main
    pico_stdlib
    pico_cyw43_arch_none
)

pico_add_extra_outputs(main)
