cmake_minimum_required(VERSION 3.20)
project(AirlineDatabaseManagement)

set(CMAKE_CXX_STANDARD 14)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/dataset")

add_executable(AirlineDatabaseManagement src/main.cpp src/Aviao.h src/Aviao.cpp src/Voo.h src/Voo.cpp
        src/Servico.h src/Servico.cpp src/Passageiro.h src/Passageiro.cpp src/Bilhete.h src/Bilhete.cpp
        src/Aeroporto.h src/Aeroporto.cpp src/Funcionario.cpp src/Funcionario.h src/Bagagem.cpp src/Bagagem.h
        src/CompanhiaAerea.cpp src/CompanhiaAerea.h src/TransportadorDeBagagem.cpp src/TransportadorDeBagagem.h
        src/Data.h src/Data.cpp src/Horario.cpp src/Horario.h src/LocalDeTransporte.cpp src/LocalDeTransporte.h
        src/bst.h src/ExcessoPeso.cpp src/ExcessoPeso.h src/menu.cpp src/menu.h src/LoadData.cpp src/LoadData.h)

# Doxygen Build
find_package(Doxygen)
if(DOXYGEN_FOUND)
    set(BUILD_DOC_DIR "${CMAKE_SOURCE_DIR}/docs/output")
    if(NOT EXISTS "${BUILD_DOC_DIR}")
        file(MAKE_DIRECTORY "${BUILD_DOC_DIR}")
    endif()
    set(DOXYGEN_IN "${CMAKE_CURRENT_SOURCE_DIR}/docs/Doxyfile.txt")
    set(DOXYGEN_OUT "${CMAKE_CURRENT_BINARY_DIR}/Doxyfile")
    configure_file("${DOXYGEN_IN}" "${DOXYGEN_OUT}" @ONLY)
    message("Doxygen build started")
    add_custom_target(Doxygen ALL
            COMMAND "${DOXYGEN_EXECUTABLE}" "${DOXYGEN_OUT}"
            WORKING_DIRECTORY "${CMAKE_CURRENT_BINARY_DIR}"
            COMMENT "Generating API documentation with Doxygen"
            VERBATIM)
else(DOXYGEN_FOUND)
    message("Doxygen needs to be installed to generate the documentation.")
endif(DOXYGEN_FOUND)