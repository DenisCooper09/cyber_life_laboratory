/*
 *  ╔═╗╦ ╦╔╗ ╔═╗╦═╗  ╦  ╦╔═╗╔═╗  ╦  ╔═╗╔╗ ╔═╗╦═╗╔═╗╔╦╗╔═╗╦═╗╦ ╦
 *  ║  ╚╦╝╠╩╗║╣ ╠╦╝  ║  ║╠╣ ║╣   ║  ╠═╣╠╩╗║ ║╠╦╝╠═╣ ║ ║ ║╠╦╝╚╦╝
 *  ╚═╝ ╩ ╚═╝╚═╝╩╚═  ╩═╝╩╚  ╚═╝  ╩═╝╩ ╩╚═╝╚═╝╩╚═╩ ╩ ╩ ╚═╝╩╚═ ╩
 *
 *  config.h
 *  Contains constants for application to use.
 */

#pragma once

#include "application.h"

#include <cstdint>

// ---------------- WINDOW ----------------
constexpr int WINDOW_WIDTH = 1200;
constexpr int WINDOW_HEIGHT = 800;
constexpr int WINDOW_POSITION_X = 100;
constexpr int WINDOW_POSITION_Y = 100;

constexpr const char *WINDOW_TITLE = "Cyber Life Laboratory v0.1";

constexpr uint8_t WINDOW_BACKGROUND_COLOR_R = 255;
constexpr uint8_t WINDOW_BACKGROUND_COLOR_G = 255;
constexpr uint8_t WINDOW_BACKGROUND_COLOR_B = 255;
constexpr uint8_t WINDOW_BACKGROUND_COLOR_A = 255;

constexpr GUI_STYLE WINDOW_GUI_STYLE = GUI_STYLE::DARK;
