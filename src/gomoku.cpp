#include "gomoku.hpp"

using namespace std;

int main(int argc, char *argv[])
{
    UI ui;

    if (argc > 1)
    {
        if ((string)argv[1] == "-pvia" || (string)argv[1] == "ia" || (string)argv[1] == "-vsia")
            ui.vs_ia = true;
    }
    ui.init(WINDOW_TITLE);
    while (true)
        ui.handle_event();
}
