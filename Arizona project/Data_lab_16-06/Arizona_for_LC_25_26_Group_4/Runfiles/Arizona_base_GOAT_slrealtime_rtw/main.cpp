/* Main generated for Simulink Real-Time model Arizona_base_GOAT */
#include <ModelInfo.hpp>
#include <utilities.hpp>
#include "Arizona_base_GOAT.h"
#include "rte_Arizona_base_GOAT_parameters.h"

/* Task descriptors */
slrealtime::TaskInfo task_1( 0u, std::bind(Arizona_base_GOAT_step), slrealtime::TaskInfo::PERIODIC, 0.001, 0, 40);

/* Executable base address for XCP */
#ifdef __linux__
extern char __executable_start;
static uintptr_t const base_address = reinterpret_cast<uintptr_t>(&__executable_start);
#else
/* Set 0 as placeholder, to be parsed later from /proc filesystem */
static uintptr_t const base_address = 0;
#endif

/* Model descriptor */
slrealtime::ModelInfo Arizona_base_GOAT_Info =
{
    "Arizona_base_GOAT",
    Arizona_base_GOAT_initialize,
    Arizona_base_GOAT_terminate,
    []()->char const*& { return Arizona_base_GOAT_M->errorStatus; },
    []()->unsigned char& { return Arizona_base_GOAT_M->Timing.stopRequestedFlag; },
    { task_1 },
    slrealtime::getSegmentVector()
};

int main(int argc, char *argv[]) {
    slrealtime::BaseAddress::set(base_address);
    return slrealtime::runModel(argc, argv, Arizona_base_GOAT_Info);
}
