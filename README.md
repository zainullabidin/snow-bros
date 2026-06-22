# Snow Bros  
By Zain ul Abidin  & Minahil Ashraf 

---

## About
A 10-level arcade game replica of the classic Snow Bros (1990), built in C++ using SFML 2.6.x. Two snowmen brothers Nick and Tom battle through enemies by throwing snowballs to encase and roll them into chain reactions.

---

## How to Build

### Mac
brew install sfml@2
cmake -B build -S .
cmake --build build
./build/SnowBros

### Windows
Make sure SFML 2.6.1 is installed at C:\SFML\
cmake -B build -S .
cmake --build build
.\build\Debug\SnowBros.exe

---

## Controls

Action          | Player 1  | Player 2
----------------|-----------|----------
Move            | A / D     | Left / Right arrows
Jump            | W         | Up arrow
Throw Snowball  | Space     | Down arrow
Pause           | P         | P

---

## Features
- 10 levels with different enemy types and speeds
- Multiplayer (2 players on same machine)
- Login and registration system with hashed passwords
- Character selection screen (3 characters)
- In-game shop with coin-based powerups
- 4 powerups: Speed Boost, Balloon Mode, Snowball Boost, Distance Increase
- Bonus levels on levels 4 and 9 with coin rewards
- Leaderboard with real-time updates
- Progress save and load on login
- Pause menu with resume and main menu options
- FlyingFoogaFoog enemy with flight AI

---

## Dependencies
- C++17
- SFML 2.6.x (graphics, window, audio, system)
- CMake 3.x

---

## Project Structure
snow-bros/
├── src/           Source files
├── include/       Header files
├── assets/        Images, fonts, sounds
├── data/          User data, leaderboard, progress
└── CMakeLists.txt
