/* Main generated for Simulink Real-Time model Arizona_all_IO */
#include <ModelInfo.hpp>
#include <utilities.hpp>
#include "Arizona_all_IO.h"
#include "rte_Arizona_all_IO_parameters.h"

/* Task descriptors */
slrealtime::TaskInfo task_1( 0u, std::bind(Arizona_all_IO_step), slrealtime::TaskInfo::PERIODIC, 0.001, 0, 40);

/* Executable base address for XCP */
#ifdef __linux__
extern char __executable_start;
static uintptr_t const base_address = reinterpret_cast<uintptr_t>(&__executable_start);
#else
/* Set 0 as placeholder, to be parsed later from /proc filesystem */
static uintptr_t const base_address = 0;
#endif

/* Model descriptor */
slrealtime::ModelInfo Arizona_all_IO_Info =
{
    "Arizona_all_IO",
    Arizona_all_IO_initialize,
    Arizona_all_IO_terminate,
    []()->char const*& { return Arizona_all_IO_M->errorStatus; },
    []()->unsigned char& { return Arizona_all_IO_M->Timing.stopRequestedFlag; },
    { task_1 },
    slrealtime::getSegmentVector()
};

int main(int argc, char *argv[]) {
    slrealtime::BaseAddress::set(base_address);
    return slrealtime::runModel(argc, argv, Arizona_all_IO_Info);
}
