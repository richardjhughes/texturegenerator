set(Catch2_DIR "${LIBRARIES_ROOT_DIR}/catch2/lib/cmake/Catch2" CACHE INTERNAL "Catch2_DIR")
message(INFO Catch2_Dir)
find_package(Catch2 REQUIRED)

enable_testing()

include(CTest)
include(Catch)
