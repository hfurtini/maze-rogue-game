#include <iostream>
#include <limits>
void print(std::string matriz[10][10]){
    for(int i = 0; i <= 9; i++){
        for(int j = 0; j <=9; j++){
            std::cout << matriz[i][j] << " ";
        }
        std::cout << std::endl;
    }
}
void verify(std::string matriz[10][10]){
    int x = 7, y = 2, counter = 0;
    std::string moving = matriz[x][y];
    while(true){
        char move;
        std::cout << "Where do you want to move (WASD):" << std::endl;
        std::cin >> move;
        matriz[x][y] = "-";
        if(move == 'w'){
            if(matriz[x-1][y] == "W"){
                std::cout << "Invalid moviment. Try again." << std::endl;
                continue;
            } else if((matriz[x-1][y] == "E") or (matriz[x-1][y] == "H")){
                std::cout << "You died! Game over!" << std::endl;
                break;
            }else if((matriz[x-1][y] == "O")){
                std::cout << "You won!" << std::endl;
                break;
            }else moving = matriz[x--][y];
        } else if(move == 'a'){
            if(matriz[x][y-1] == "W"){
                std::cout << "Invalid moviment. Try again." << std::endl;
                continue;                
            } else if((matriz[x][y-1] == "E") or (matriz[x][y-1] == "H")){
                std::cout << "You died! Game over!" << std::endl;
                break;
            } else if((matriz[x][y-1] == "O")){
                std::cout << "You won!" << std::endl;
                break;
            }else moving = matriz[x][y--];
        } else if(move == 's'){
            if(matriz[x+1][y] == "W"){
                std::cout << "Invalid moviment. Try again." << std::endl;
                continue;
            } else if((matriz[x+1][y] == "E") or (matriz[x+1][y] == "H")){
                std::cout << "You died! Game over!" << std::endl;
                break;
            }else if((matriz[x+1][y] == "O")){
                std::cout << "You won!" << std::endl;
                break;
            }else moving = matriz[x++][y];
        } else if(move == 'd'){
            if(matriz[x][y+1] == "W"){
                std::cout << "Invalid moviment. Try again." << std::endl;
                continue;
            } else if((matriz[x][y+1] == "E") or (matriz[x][y+1] == "H")){
                std::cout << "You died! Game over!" << std::endl;
                break;
            }else if((matriz[x][y+1] == "O")){
                std::cout << "You won!" << std::endl;
                break;
            }else moving = matriz[x][y++];
        } else{
            std::cout << "Invalid option, try again." << std::endl;
        }
        matriz[x][y] = "Y";
        counter++;
        print(matriz);
    }

}
void distance(){
    ;
}
int main(void){
    const int TAMANHOY = 10, TAMANHOX = 10;
    bool play = true;
    int control;
    std::string matriz[TAMANHOY][TAMANHOX] = {
    {{"W"},{"W"},{"W"},{"W"},{"W"},{"W"},{"W"},{"W"},{"W"},{"W"}},
    {{"W"},{"-"},{"O"},{"-"},{"-"},{"-"},{"-"},{"-"},{"-"},{"W"}},
    {{"W"},{"-"},{"W"},{"-"},{"-"},{"-"},{"-"},{"-"},{"-"},{"W"}},
    {{"W"},{"-"},{"-"},{"-"},{"H"},{"-"},{"-"},{"E"},{"-"},{"W"}},
    {{"W"},{"W"},{"W"},{"-"},{"-"},{"W"},{"-"},{"-"},{"-"},{"W"}},
    {{"W"},{"-"},{"-"},{"-"},{"-"},{"W"},{"-"},{"-"},{"-"},{"W"}},
    {{"W"},{"-"},{"W"},{"-"},{"W"},{"W"},{"-"},{"-"},{"-"},{"W"}},
    {{"W"},{"-"},{"Y"},{"-"},{"-"},{"-"},{"E"},{"-"},{"-"},{"W"}},
    {{"W"},{"-"},{"E"},{"-"},{"-"},{"-"},{"-"},{"-"},{"-"},{"W"}},
    {{"W"},{"W"},{"W"},{"W"},{"W"},{"W"},{"W"},{"W"},{"W"},{"W"}}};
    print(matriz);
    while(play){
        std::cout << "Play the game?" << std::endl;
        std::cout << "[1] - Yes" << std::endl;
        std::cout << "[2] - No" << std::endl;
        std::cin >> control;
        if(control == 1){
            verify(matriz);
        } else if(control == 2){
            std::cout << "Exiting the game..." << std::endl;
            play = false;
        }
    }
    return 0;
}