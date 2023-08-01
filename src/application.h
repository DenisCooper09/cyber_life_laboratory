/*
 *  ╔═╗╦ ╦╔╗ ╔═╗╦═╗  ╦  ╦╔═╗╔═╗  ╦  ╔═╗╔╗ ╔═╗╦═╗╔═╗╔╦╗╔═╗╦═╗╦ ╦
 *  ║  ╚╦╝╠╩╗║╣ ╠╦╝  ║  ║╠╣ ║╣   ║  ╠═╣╠╩╗║ ║╠╦╝╠═╣ ║ ║ ║╠╦╝╚╦╝
 *  ╚═╝ ╩ ╚═╝╚═╝╩╚═  ╩═╝╩╚  ╚═╝  ╩═╝╩ ╩╚═╝╚═╝╩╚═╩ ╩ ╩ ╚═╝╩╚═ ╩
 *
 *  application.h
 *  Main class that controls application. (Initializes application, performs renderer, etc.)
 */

#pragma once

#define GLEW_STATIC

#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include <iostream>
#include <chrono>

enum ERROR_CODE {
    SUCCESS = 0,
    GLFW_INIT_ERROR = -1,
    WINDOW_INIT_ERROR = -2,
    GLEW_INIT_ERROR = -3
};

class [[maybe_unused]] application {
private:
    int _window_width;
    int _window_height;
    char *_window_title;

    GLFWwindow *_window;

    uint8_t background_color_r = 255;
    uint8_t background_color_g = 255;
    uint8_t background_color_b = 255;
    uint8_t background_color_a = 255;

    static bool _initialize_glfw();

    bool _initialize_window();

    static bool _initialize_glew();

    ERROR_CODE _initialize();

    void _render() const;

public:
    [[maybe_unused]] application(
            const int &WINDOW_WIDTH,
            const int &WINDOW_HEIGHT,
            const char *WINDOW_TITLE);

    ~application();

    [[maybe_unused]] ERROR_CODE setup();

    [[maybe_unused]] void loop();

    [[maybe_unused]] bool application_should_close();

    [[maybe_unused]] void set_window_position(const int &X, const int &Y);

    [[maybe_unused]] void set_background_color(
            const uint8_t &R,
            const uint8_t &G,
            const uint8_t &B,
            const uint8_t &A);
};
