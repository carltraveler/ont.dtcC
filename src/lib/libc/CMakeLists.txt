cmake_minimum_required(VERSION 3.5)
project(ontology_libraries)
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wno-everything --target=wasm32 -nostdlib -fno-builtin -ffreestanding -nostdinc  -nostdlibinc -fno-threadsafe-statics  -O3")

file(GLOB CRYPT_SOURCES  "musl/src/crypt/*.c")
file(GLOB CTYPE_SOURCES  "musl/src/ctype/*.c")
file(GLOB ENV_SOURCES  "musl/src/env/*.c")
file(GLOB ERRNO_SOURCES  "musl/src/errno/*.c")
file(GLOB EXIT_SOURCES  "musl/src/exit/*.c")
file(GLOB LOCALE_SOURCES "musl/src/locale/*.c")
file(GLOB MATH_SOURCES  "musl/src/math/*.c")
file(GLOB MBYTE_SOURCES  "musl/src/multibyte/*.c")
file(GLOB MISC_SOURCES "musl/src/misc/*.c")
file(GLOB SEARCH_SOURCES "musl/src/search/*.c")
file(GLOB STDIO_SOURCES "musl/src/stdio/*.c")
file(GLOB STDLIB_SOURCES "musl/src/stdlib/*.c")
file(GLOB STRING_SOURCES "musl/src/string/*.c")
#file(GLOB TIME_SOURCES "musl/src/time/*.c")
file(GLOB THREAD_SOURCES "musl/src/thread/*.c") #only for __lock __unlock

set(INTERNAL_SOURCES musl/src/internal/floatscan.c musl/src/internal/intscan.c musl/src/internal/shgetc.c musl/src/internal/libc.c)


file(GLOB HEADERS "${CMAKE_CURRENT_SOURCE_DIR}/musl/include/*.h"
                  "${CMAKE_CURRENT_SOURCE_DIR}/musl/src/internal/*.h"
                  "${CMAKE_CURRENT_SOURCE_DIR}/musl/arch/ont/*.h"
)

add_library(c 
            ${CRYPT_SOURCES} 
            ${CTYPE_SOURCES}
            ${ENV_SOURCES}
            ${ERRNO_SOURCES}
            ${EXIT_SOURCES}
            ${INTERNAL_SOURCES}
            ${LOCALE_SOURCES}
            ${MATH_SOURCES}
            ${MBYTE_SOURCES}
            ${MISC_SOURCES}
            ${SEARCH_SOURCES}
            ${STDIO_SOURCES}
            ${STDLIB_SOURCES}
            ${STRING_SOURCES}
            ${TIME_SOURCES}
            ${THREAD_SOURCES}
            "musl/src/malloc/posix_memalign.c"
            "musl/src/malloc/memalign.c"
            ${HEADERS})

target_include_directories(c 
                           PUBLIC 
                           ${CMAKE_CURRENT_SOURCE_DIR}/musl/include
                           ${CMAKE_CURRENT_SOURCE_DIR}/musl/src/internal
                           ${CMAKE_CURRENT_SOURCE_DIR}/musl/src/crypt
                           ${CMAKE_CURRENT_SOURCE_DIR}/musl/arch/ont
			   ${CMAKE_CURRENT_SOURCE_DIR}/../ontologylib/include
                           ${CMAKE_SOURCE_DIR})

file(COPY ${CMAKE_CURRENT_SOURCE_DIR}/musl/include/ DESTINATION ${CMAKE_CURRENT_SOURCE_DIR}/../../../install/include/libc/)
file(COPY ${CMAKE_CURRENT_SOURCE_DIR}/musl/src/internal/ DESTINATION ${CMAKE_CURRENT_SOURCE_DIR}/../../../install/include/libc/)
file(COPY ${CMAKE_CURRENT_SOURCE_DIR}/musl/arch/ont/ DESTINATION ${CMAKE_CURRENT_SOURCE_DIR}/../../../install/include/libc/)
