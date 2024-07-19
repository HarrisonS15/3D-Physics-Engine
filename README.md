# 3D-Physics-Engine
My journey learning to create a 3D physics engine from scratch in C++

## Phase 1 (Research)
### Resources
- [Short but sweet phys engine video](https://www.youtube.com/watch?v=lS_qeBy3aQI)
  - [corresponding github](https://github.com/johnBuffer/VerletSFML/)
- [Learn OpenGL](https://learnopengl.com/)
  - [The book](https://learnopengl.com/book/book_pdf.pdf)
  - [The repo](https://github.com/JoeyDeVries/learnopengl)
  - [Install guide](https://www.youtube.com/watch?v=Y4F0tI7WlDs)
- [3D Rigid Body physics](https://www.youtube.com/watch?v=4r_EvmPKOvY)
- [Math of a physics engine book](https://www.r-5.org/files/books/computers/algo-list/realtime-3d/Ian_Millington-Game_Physics_Engine_Development-EN.pdf)
- [Installing CMake/Catch2 Unit testing help](https://www.youtube.com/watch?v=eBByZNtnpFM)
  - [The video that actually worked (I ignored the azure stuff)](https://www.youtube.com/watch?v=6Uq0h_wX8_o)
  - [Catch2 repo](https://github.com/catchorg/Catch2/tree/devel)
  

### Notes
- coordinates that we specify in OpenGL are in 3D (x, y and z coordinate).
- Commands to remember
  - cmake -S . -B build
    - recompiles cmake
  - cmake --build build
    - builds cmake
  - ctest (from build dir)
    - runs all tests
  - .\Debug\src_main.exe (from build dir)
    - debugs and runs the program
