#include "io_service_timer.h"
#include "io_service_timer_thread.h"

int main([[maybe_unused]] int argc, [[maybe_unused]] char **argv)
{
    rapchat::wait_timer();
    rapchat::wait_timer_thread();

    return 0;
}
