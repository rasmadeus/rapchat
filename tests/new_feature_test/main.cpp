#include "download_page.h"
#include "io_service_timer.h"
#include "io_service_timer_thread.h"

int main([[maybe_unused]] int argc, [[maybe_unused]] char **argv)
{
    rapchat::IoServiceTimer{}.run();
    rapchat::IoServiceTimerThread{}.run();
    rapchat::PageDownloader{}.run();

    return 0;
}
