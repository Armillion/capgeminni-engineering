# CMakeList.txt: projekt CMake dla elementu technical-task, dołącz źródło i zdefiniuj
# tutaj logikę specyficzną dla projektu.
#

# Dodaj źródło do pliku wykonywalnego tego projektu.
add_executable (technical-task "technical-task.cpp" "technical-task.h")

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET technical-task PROPERTY CXX_STANDARD 20)
endif()

# TODO: Dodaj testy i zainstaluj elementy docelowe w razie potrzeby.
