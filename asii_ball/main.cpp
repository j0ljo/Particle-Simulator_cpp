#include <iostream>
#include <thread>
#include <chrono>
#include <vector>
#include <cmath>
#include <conio.h> // Windows-only

const int WIDTH = 40;
const int HEIGHT = 20;

float ballX = 20.0;
float ballY = 10.0;
float velocityX = 0.5;
float velocityY = 0.3;

void clearScreen() {
    // Works in Windows CMD
    system("cls");
}

void drawFrame() {
    std::vector<std::string> screen(HEIGHT, std::string(WIDTH, ' '));

    int x = static_cast<int>(ballX);
    int y = static_cast<int>(ballY);

    if (x >= 0 && x < WIDTH && y >= 0 && y < HEIGHT) {
        screen[y][x] = 'O';
    }

    clearScreen();
    for (const auto& row : screen) {
        std::cout << row << '\n';
    }
}

int main() {
    while (true) {
        // Check for quit key
        if (_kbhit()) {
            char ch = _getch();
            if (ch == 'q' || ch == 'Q') break;
        }

        // Update ball position
        ballX += velocityX;
        ballY += velocityY;

        if (ballX <= 0 || ballX >= WIDTH - 1) velocityX *= -1;
        if (ballY <= 0 || ballY >= HEIGHT - 1) velocityY *= -1;

        drawFrame();

        std::this_thread::sleep_for(std::chrono::milliseconds(16));
    }

    std::cout << "Exited simulation.\n";
    return 0;
}
