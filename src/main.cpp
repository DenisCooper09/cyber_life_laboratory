/*
 *  ╔═╗╦ ╦╔╗ ╔═╗╦═╗  ╦  ╦╔═╗╔═╗  ╦  ╔═╗╔╗ ╔═╗╦═╗╔═╗╔╦╗╔═╗╦═╗╦ ╦
 *  ║  ╚╦╝╠╩╗║╣ ╠╦╝  ║  ║╠╣ ║╣   ║  ╠═╣╠╩╗║ ║╠╦╝╠═╣ ║ ║ ║╠╦╝╚╦╝
 *  ╚═╝ ╩ ╚═╝╚═╝╩╚═  ╩═╝╩╚  ╚═╝  ╩═╝╩ ╩╚═╝╚═╝╩╚═╩ ╩ ╩ ╚═╝╩╚═ ╩
 *
 *  main.cpp
 *  Entry point of the application.
 */

#include "config.h"
#include "application.h"

int main() {
    application app(WINDOW_WIDTH, WINDOW_HEIGHT, WINDOW_TITLE);

    const ERROR_CODE ERR_CODE = app.setup();
    if (ERR_CODE != ERROR_CODE::SUCCESS) {
        std::cerr << std::endl;
        std::cerr << "Application is terminated due to an error. Error code is " << ERR_CODE << '.' << std::endl;
        return EXIT_FAILURE;
    }

    app.set_window_position(WINDOW_POSITION_X, WINDOW_POSITION_Y);

    app.set_background_color(
            WINDOW_BACKGROUND_COLOR_R,
            WINDOW_BACKGROUND_COLOR_G,
            WINDOW_BACKGROUND_COLOR_B,
            WINDOW_BACKGROUND_COLOR_A
    );

    app.set_gui_style(WINDOW_GUI_STYLE);

    while (!app.application_should_close()) {
        app.loop();
    }

    return EXIT_SUCCESS;
}
