clear
clang++ -std=c++17 two.cpp \
    -I/opt/homebrew/include \
    -L/opt/homebrew/lib \
    -lboost_system \
    -lpthread \
    -o main 
./main
