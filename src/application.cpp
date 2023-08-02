/*
 *  ╔═╗╦ ╦╔╗ ╔═╗╦═╗  ╦  ╦╔═╗╔═╗  ╦  ╔═╗╔╗ ╔═╗╦═╗╔═╗╔╦╗╔═╗╦═╗╦ ╦
 *  ║  ╚╦╝╠╩╗║╣ ╠╦╝  ║  ║╠╣ ║╣   ║  ╠═╣╠╩╗║ ║╠╦╝╠═╣ ║ ║ ║╠╦╝╚╦╝
 *  ╚═╝ ╩ ╚═╝╚═╝╩╚═  ╩═╝╩╚  ╚═╝  ╩═╝╩ ╩╚═╝╚═╝╩╚═╩ ╩ ╩ ╚═╝╩╚═ ╩
 *
 *  application.cpp
 *  Implements application functions.
 *
 *  Adding new features:
 *  - Modify 'setup()' function to add new functionality that should perform once, when the application initializes.
 *  - Modify 'loop()' function to add new functionality that should be called all the time until application closes.
 *  - Modify 'render()' function to add new functionality for the application that requires rendering.
 *
 *  Note: places where to modify those function are marked by a comment '// Additional code goes here...'.
 */

#include "application.h"

bool application::_initialize_glfw() {
    std::cout << "GLFW initialization...\t";
    std::cout.flush();

    auto start = std::chrono::high_resolution_clock::now();

    if (!glfwInit()) {
        std::cerr << " [ FAILED ]" << std::endl;
        return false;
    }

    auto end = std::chrono::high_resolution_clock::now();
    long long duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start).count();

    std::cout << " [ SUCCESS ]\tTime taken: " << duration << " microseconds." << std::endl;
    std::cout.flush();

    return true;
}

bool application::_initialize_window() {
    std::cout << "Window creation...\t";
    std::cout.flush();

    auto start = std::chrono::high_resolution_clock::now();

    _window = glfwCreateWindow(
            _window_width,
            _window_height,
            _window_title,
            nullptr, nullptr
    );

    if (!_window) {
        glfwTerminate();
        std::cerr << " [ FAILED ]" << std::endl;
        return false;
    }

    glfwMakeContextCurrent(_window);

    auto end = std::chrono::high_resolution_clock::now();
    long long duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start).count();

    std::cout << " [ SUCCESS ]\tTime taken: " << duration << " microseconds." << std::endl;
    std::cout.flush();

    return true;
}

bool application::_initialize_glew() {
    std::cout << "GLEW initialization...\t";
    std::cout.flush();

    auto start = std::chrono::high_resolution_clock::now();

    if (glewInit() != GLEW_OK) {
        std::cerr << " [ FAILED ]" << std::endl;
        return false;
    }

    auto end = std::chrono::high_resolution_clock::now();
    long long duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start).count();

    std::cout << " [ SUCCESS ]\tTime taken: " << duration << " microseconds." << std::endl;
    std::cout.flush();

    return true;
}

bool application::_initialize_imgui() {
    std::cout << "ImGui initialization...\t";
    std::cout.flush();

    auto start = std::chrono::high_resolution_clock::now();

    IMGUI_CHECKVERSION();
    ImGui::CreateContext();
    ImGuiIO &io = ImGui::GetIO();
    (void) io;

    switch (_gui_style) {
        case CLASSIC: {
            ImGui::StyleColorsClassic();
            break;
        }
        case DARK: {
            ImGui::StyleColorsDark();
            break;
        }
        case LIGHT: {
            ImGui::StyleColorsLight();
            break;
        }
        default: {
            std::cerr << " [ FAILED ]" << std::endl;
            return false;
        }
    }

    ImGui_ImplGlfw_InitForOpenGL(_window, true);

    // OpenGL version is hardcoded. Will be fixed later.
    ImGui_ImplOpenGL3_Init("#version 460");

    auto end = std::chrono::high_resolution_clock::now();
    long long duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start).count();

    std::cout << " [ SUCCESS ]\tTime taken: " << duration << " microseconds." << std::endl;
    std::cout.flush();

    return true;
}

[[maybe_unused]] ERROR_CODE application::_initialize() {
    std::cout << " ######  ##    ## ########  ######## ########     ##          ###    ######## " << std::endl;
    std::cout << "##    ##  ##  ##  ##     ## ##       ##     ##    ##         ## ##   ##     ##" << std::endl;
    std::cout << "##         ####   ##     ## ##       ##     ##    ##        ##   ##  ##     ##" << std::endl;
    std::cout << "##          ##    ########  ######   ########     ##       ##     ## ######## " << std::endl;
    std::cout << "##          ##    ##     ## ##       ##   ##      ##       ######### ##     ##" << std::endl;
    std::cout << "##    ##    ##    ##     ## ##       ##    ##     ##       ##     ## ##     ##" << std::endl;
    std::cout << " ######     ##    ########  ######## ##     ##    ######## ##     ## ######## " << std::endl;
    std::cout << std::endl;
    std::cout.flush();

    if (!_initialize_glfw()) return ERROR_CODE::GLFW_INIT_ERROR;
    if (!_initialize_window()) return ERROR_CODE::WINDOW_INIT_ERROR;
    if (!_initialize_glew()) return ERROR_CODE::GLEW_INIT_ERROR;
    if (!_initialize_imgui()) return ERROR_CODE::IMGUI_INIT_ERROR;

    std::cout << std::endl;
    std::cout << "OpenGL version is " << glGetString(GL_VERSION) << std::endl;
    std::cout.flush();

    return ERROR_CODE::SUCCESS;
}

void application::_render() const {
    glClearColor(background_color_r, background_color_g, background_color_b, background_color_a);
    glClear(GL_COLOR_BUFFER_BIT);

    // Additional code goes here...
}

void application::_gui() const {
    if (ImGui::BeginMainMenuBar()) {
        if (ImGui::BeginMenu("File")) {
            if (ImGui::MenuItem("Exit", "Alt+F4")) {
                glfwSetWindowShouldClose(_window, true);
            }

            ImGui::EndMenu();
        }

        ImGui::EndMainMenuBar();
    }
}

[[maybe_unused]] application::application(
        const int &WINDOW_WIDTH,
        const int &WINDOW_HEIGHT,
        const char *WINDOW_TITLE) {
    _window_width = WINDOW_WIDTH;
    _window_height = WINDOW_HEIGHT;
    _window_title = (char *) WINDOW_TITLE;
    _window = nullptr;
}

application::~application() {
    glfwTerminate();
}

[[maybe_unused]] ERROR_CODE application::setup() {
    const ERROR_CODE ERR_CODE = _initialize();
    if (ERR_CODE != 0) {
        return ERR_CODE;
    }

    // Additional code goes here...

    return ERROR_CODE::SUCCESS;
}

[[maybe_unused]] void application::loop() {
    // Additional code goes here...

    _render();

    ImGui_ImplOpenGL3_NewFrame();
    ImGui_ImplGlfw_NewFrame();
    ImGui::NewFrame();

    _gui();

    ImGui::Render();
    ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());

    // Or here, after renderer...

    glfwSwapBuffers(_window);
    glfwPollEvents();
}

[[maybe_unused]] bool application::application_should_close() {
    return glfwWindowShouldClose(_window);
}

[[maybe_unused]] void application::set_window_position(const int &X, const int &Y) {
    glfwSetWindowPos(_window, X, Y);
}

[[maybe_unused]] void application::set_background_color(
        const uint8_t &R,
        const uint8_t &G,
        const uint8_t &B,
        const uint8_t &A) {
    background_color_r = R;
    background_color_g = G;
    background_color_b = B;
    background_color_a = A;
}

[[maybe_unused]] void application::set_gui_style(const GUI_STYLE &STYLE) {
    _gui_style = STYLE;
}
