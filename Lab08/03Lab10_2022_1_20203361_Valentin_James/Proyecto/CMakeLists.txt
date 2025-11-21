cmake_minimum_required(VERSION 4.0)
project(Proyecto)

set(CMAKE_CXX_STANDARD 20)

add_executable(Proyecto main.cpp
        src/Pedido.cpp
        src/Pedido.h
        src/Comunes.cpp
        src/Comunes.h
        src/PedidoEspecial.cpp
        src/PedidoEspecial.h
        src/PedidoUsual.cpp
        src/PedidoUsual.h
        src/PedidoEventual.cpp
        src/PedidoEventual.h
        tad/Nodo.cpp
        tad/Nodo.h
        tad/Lista.cpp
        tad/Lista.h
        src/Promociones.cpp
        src/Promociones.h
)
