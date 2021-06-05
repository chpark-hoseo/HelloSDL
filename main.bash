clang++  -g -std=c++17  -o main  -I/home/runner/.apt/usr/include/SDL2 *.cpp -lX11 -lSDL2 -lSDL2main -lSDL2_image -lpng -ljpeg -ltiff -lwebp
chmod 744 ./main
./main