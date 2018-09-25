cmake_minimum_required(VERSION 2.6)

set (TARGET template_observer)

set ( INC_FILES 
        Observer.h
        Observable.h
        template_observer.h
)


install( FILES ${INC_FILES}
         DESTINATION ${CMAKE_INSTALL_PREFIX}/include/${TARGET}
)