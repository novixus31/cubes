#include <iostream>

class RubikKup {
private:
    static const int SIZE = 3;
    char cube[6][SIZE][SIZE];
    int rotationCount = 0;
    char staringColor;
public:
    RubikKup() {
        initializeCube();
    }

    void initializeCube() {
        char color = 'A';

        for (int i = 0; i < 6; i++) {
            for (int j = 0; j < SIZE; j++) {
                for (int k = 0; k < SIZE; k++) {
                    cube[i][j][k]= color;
                }
            }
            color++;
        }
    }

    void printCube() {
        for (int i = 0; i < 6; i++) {
            for (int j = 0; j < SIZE; j++) {
                for (int k = 0; k < SIZE; k++) {
                    std::cout << cube[i][j][k] << " | ";
                }
                std::cout << "-   -   -"<< std::endl;
            }
            std::cout << "-------------" << std::endl;
        }
    }

    void rotateR() {
        char temp[SIZE];

        for (int i = 0; i < SIZE; i++) {
            temp[i] = cube[0][i][SIZE - 1];
        }
        for (int i = 0; i < SIZE; i++) {
                cube[0][i][SIZE - 1] = cube[1][i][SIZE - 1];
        }
        for (int i = 0; i < SIZE; i++) {
                cube[1][i][SIZE - 1] = cube[5][i][SIZE - 1];
        }
        for (int i = 0; i < SIZE; i++) {
                cube[5][i][SIZE - 1] = cube[3][SIZE - 1 - i][0];
        }
        for (int i = 0; i < SIZE; i++) {
                cube[3][i][0] = temp[SIZE - 1 - i];
        }
        temp[0] = cube[2][0][0];
		cube[2][0][0] = cube[2][0][2];
		cube[2][0][2] = cube[2][2][2];
		cube[2][2][2] = cube[2][2][0];
		cube[2][2][0] = temp[0];
		temp[0] = cube[2][0][1];
		cube[2][0][1] = cube[2][1][2];
		cube[2][1][2] = cube[2][2][1];
		cube[2][2][1] = cube[2][1][0];
		cube[2][1][0] = temp[0];
    }
    void rotateL() {
        char temp[SIZE];

        for (int i = 0; i < SIZE; i++) {
            temp[i] = cube[0][i][0];
        }
        for (int i = 0; i < SIZE; i++) {
                cube[0][i][0] = cube[3][SIZE - 1 - i][SIZE - 1];
        }
        for (int i = 0; i < SIZE; i++) {
                cube[3][i][SIZE - 1] = cube[5][SIZE - 1 -i][0];
        }
        for (int i = 0; i < SIZE; i++) {
                cube[5][i][0] = cube[1][i][0];
        }
        for (int i = 0; i < SIZE; i++) {
                cube[1][i][0] = temp[i];
        }
        temp[0] = cube[4][0][0];
        cube[4][0][0] = cube[4][2][0];
        cube[4][2][0] = cube[4][2][2];
        cube[4][2][2] = cube[4][0][2];
        cube[4][0][2] = temp[0];
        temp[0] = cube[4][0][1];
        cube[4][0][1] = cube[4][1][0];
        cube[4][1][0] = cube[4][2][1];
        cube[4][2][1] = cube[4][1][2];
        cube[4][1][2] = temp[0];
    };
    void rotateF() {
        char temp[SIZE];

        for (int i = 0; i < SIZE; i++) {
            temp[i] = cube[0][SIZE - 1][i];
        }
        for (int i = 0; i < SIZE; i++) {
                cube[0][SIZE - 1][i] = cube[4][SIZE - 1 - i][SIZE - 1];
        }
        for (int i = 0; i < SIZE; i++) {
                cube[4][i][SIZE - 1] = cube[5][0][i];
        }
        for (int i = 0; i < SIZE; i++) {
                cube[5][0][i] = cube[2][SIZE - 1 - i][0];
        }
        for (int i = 0; i < SIZE; i++) {
                cube[2][i][0] = temp[i];
        }
        temp[0] = cube[1][0][0];
        cube[1][0][0] = cube[1][2][0];
        cube[1][2][0] = cube[1][2][2];
        cube[1][2][2] = cube[1][0][2];
        cube[1][0][2] = temp[0];
        temp[0] = cube[1][0][1];
        cube[1][0][1] = cube[1][1][0];
        cube[1][1][0] = cube[1][2][1];
        cube[1][2][1] = cube[1][1][2];
        cube[1][1][2] = temp[0];
    };
    void rotateB() {
        char temp[SIZE];

        for (int i = 0; i < SIZE; i++) {
            temp[i] = cube[0][0][i];
        }
        for (int i = 0; i < SIZE; i++) {
                cube[0][0][i] = cube[2][i][SIZE - 1];
        }
        for (int i = 0; i < SIZE; i++) {
                cube[2][i][SIZE - 1] = cube[5][SIZE - 1][SIZE - 1 - i];
        }
        for (int i = 0; i < SIZE; i++) {
                cube[5][SIZE - 1][i] = cube[4][i][0];
        }
        for (int i = 0; i < SIZE; i++) {
                cube[4][i][0] = temp[SIZE - 1 - i];
        }
        temp[0] = cube[3][0][0];
        cube[3][0][0] = cube[3][2][0];
        cube[3][2][0] = cube[3][2][2];
        cube[3][2][2] = cube[3][0][2];
        cube[3][0][2] = temp[0];
        temp[0] = cube[3][0][1];
        cube[3][0][1] = cube[3][1][0];
        cube[3][1][0] = cube[3][2][1];
        cube[3][2][1] = cube[3][1][2];
        cube[3][1][2] = temp[0];
    };
    void rotateU() {
        char temp[SIZE];

        for (int i = 0; i < SIZE; i++) {
            temp[i] = cube[1][0][i];
        }
        for (int i = 0; i < SIZE; i++) {
                cube[1][0][i] = cube[2][0][i];
        }
        for (int i = 0; i < SIZE; i++) {
                cube[2][0][i] = cube[3][0][i];
        }
        for (int i = 0; i < SIZE; i++) {
                cube[3][0][i] = cube[4][0][i];
        }
        for (int i = 0; i < SIZE; i++) {
                cube[4][0][i] = temp[i];
        }
        temp[0] = cube[0][0][0];
        cube[0][0][0] = cube[0][2][0];
        cube[0][2][0] = cube[0][2][2];
        cube[0][2][2] = cube[0][0][2];
        cube[0][0][2] = temp[0];
        temp[0] = cube[0][0][1];
        cube[0][0][1] = cube[0][1][0];
        cube[0][1][0] = cube[0][2][1];
        cube[0][2][1] = cube[0][1][2];
        cube[0][1][2] = temp[0];
    };
    void rotateD() {
        char temp[SIZE];

        for (int i = 0; i < SIZE; i++) {
            temp[i] = cube[1][SIZE - 1][i];
        }
        for (int i = 0; i < SIZE; i++) {
                cube[1][SIZE - 1][i] = cube[4][SIZE - 1][i];
        }
        for (int i = 0; i < SIZE; i++) {
                cube[4][SIZE - 1][i] = cube[3][SIZE - 1][i];
        }
        for (int i = 0; i < SIZE; i++) {
                cube[3][SIZE - 1][i] = cube[2][SIZE - 1][i];
        }
        for (int i = 0; i < SIZE; i++) {
                cube[2][SIZE - 1][i] = temp[i];
        }
        temp[0] = cube[5][0][0];
        cube[5][0][0] = cube[5][2][0];
        cube[5][2][0] = cube[5][2][2];
        cube[5][2][2] = cube[5][0][2];
        cube[5][0][2] = temp[0];
        temp[0] = cube[5][0][1];
        cube[5][0][1] = cube[5][1][0];
        cube[5][1][0] = cube[5][2][1];
        cube[5][2][1] = cube[5][1][2];
        cube[5][1][2] = temp[0];
    };
    void rotateRiverseR() {
        char temp[SIZE];

        for (int i = 0; i < SIZE; i++) {
            temp[i] = cube[0][i][SIZE - 1];
        }
        for (int i = 0; i < SIZE; i++) {
                cube[0][i][SIZE - 1] = cube[3][SIZE - 1 - i][0];
        }
        for (int i = 0; i < SIZE; i++) {
                cube[3][i][0] = cube[5][SIZE - 1 - i][SIZE - 1];
        }
        for (int i = 0; i < SIZE; i++) {
                cube[5][i][SIZE - 1] = cube[1][i][SIZE - 1];
        }
        for (int i = 0; i < SIZE; i++) {
                cube[1][i][SIZE - 1] = temp[i];
        }
        temp[0] = cube[2][0][0];
		cube[2][0][0] = cube[2][0][2];
		cube[2][0][2] = cube[2][2][2];
		cube[2][2][2] = cube[2][2][0];
		cube[2][2][0] = temp[0];
		temp[0] = cube[2][0][1];
		cube[2][0][1] = cube[2][1][2];
		cube[2][1][2] = cube[2][2][1];
		cube[2][2][1] = cube[2][1][0];
		cube[2][1][0] = temp[0];
    }
    void rotateRiverseL() {
        char temp[SIZE];

        for (int i = 0; i < SIZE; i++) {
            temp[i] = cube[0][i][0];
        }
        for (int i = 0; i < SIZE; i++) {
                cube[0][i][0] = cube[1][i][0];
        }
        for (int i = 0; i < SIZE; i++) {
                cube[1][i][0] = cube[5][i][0];
        }
        for (int i = 0; i < SIZE; i++) {
                cube[5][i][0] = cube[3][SIZE - 1 - i][SIZE - 1];
        }
        for (int i = 0; i < SIZE; i++) {
                cube[3][i][SIZE - 1] = temp[SIZE - 1 - i];
        }
        temp[0] = cube[4][0][0];
        cube[4][0][0] = cube[4][0][2];
        cube[4][0][2] = cube[4][2][2];
        cube[4][2][2] = cube[4][2][0];
        cube[4][2][0] = temp[0];
        temp[0] = cube[4][0][1];
        cube[4][0][1] = cube[4][1][2];
        cube[4][1][2] = cube[4][2][1];
        cube[4][2][1] = cube[4][1][0];
        cube[4][1][0] = temp[0];
    };
    void rotateRiverseF() {
        char temp[SIZE];

        for (int i = 0; i < SIZE; i++) {
            temp[i] = cube[0][SIZE - 1][i];
        }
        for (int i = 0; i < SIZE; i++) {
                cube[0][SIZE - 1][i] = cube[2][i][0];
        }
        for (int i = 0; i < SIZE; i++) {
                cube[2][i][0] = cube[5][0][SIZE - 1 - i];
        }
        for (int i = 0; i < SIZE; i++) {
                cube[5][0][i] = cube[4][SIZE - 1 - i][SIZE - 1];
        }
        for (int i = 0; i < SIZE; i++) {
                cube[4][i][SIZE - 1] = temp[i];
        }
        temp[0] = cube[1][0][0];
        cube[1][0][0] = cube[1][0][2];
        cube[1][0][2] = cube[1][2][2];
        cube[1][2][2] = cube[1][2][0];
        cube[1][2][0] = temp[0];
        temp[0] = cube[1][0][1];
        cube[1][0][1] = cube[1][1][2];
        cube[1][1][2] = cube[1][2][1];
        cube[1][2][1] = cube[1][1][0];
        cube[1][1][0] = temp[0];
    };
    void rotateRiverseB() {
        char temp[SIZE];

        for (int i = 0; i < SIZE; i++) {
            temp[i] = cube[0][0][i];
        }
        for (int i = 0; i < SIZE; i++) {
                cube[0][0][i] = cube[4][i][0];
        }
        for (int i = 0; i < SIZE; i++) {
                cube[4][i][0] = cube[5][SIZE - 1][SIZE - 1 - i];
        }
        for (int i = 0; i < SIZE; i++) {
                cube[5][SIZE - 1][i] = cube[2][SIZE - 1 - i][SIZE - 1];
        }
        for (int i = 0; i < SIZE; i++) {
                cube[2][i][SIZE - 1] = temp[SIZE - 1 - i];
        }
        temp[0] = cube[3][0][0];
        cube[3][0][0] = cube[3][0][2];
        cube[3][0][2] = cube[3][2][2];
        cube[3][2][2] = cube[3][2][0];
        cube[3][2][0] = temp[0];
        temp[0] = cube[3][0][1];
        cube[3][0][1] = cube[3][1][2];
        cube[3][1][2] = cube[3][2][1];
        cube[3][2][1] = cube[3][1][0];
        cube[3][1][0] = temp[0];
    };
    void rotateRiverseU() {
        char temp[SIZE];

        for (int i = 0; i < SIZE; i++) {
            temp[i] = cube[1][0][i];
        }
        for (int i = 0; i < SIZE; i++) {
                cube[1][0][i] = cube[4][0][i];
        }
        for (int i = 0; i < SIZE; i++) {
                cube[4][0][i] = cube[3][0][i];
        }
        for (int i = 0; i < SIZE; i++) {
                cube[3][0][i] = cube[2][0][i];
        }
        for (int i = 0; i < SIZE; i++) {
                cube[2][0][i] = temp[i];
        }
        temp[0] = cube[0][0][0];
        cube[0][0][0] = cube[0][0][2];
        cube[0][0][2] = cube[0][2][2];
        cube[0][2][2] = cube[0][2][0];
        cube[0][2][0] = temp[0];
        temp[0] = cube[0][0][1];
        cube[0][0][1] = cube[0][1][2];
        cube[0][1][2] = cube[0][2][1];
        cube[0][2][1] = cube[0][1][0];
        cube[0][1][0] = temp[0];
    };
    void rotateRiverseD() {
        char temp[SIZE];

        for (int i = 0; i < SIZE; i++) {
            temp[i] = cube[1][SIZE - 1][i];
        }
        for (int i = 0; i < SIZE; i++) {
                cube[1][SIZE - 1][i] = cube[2][SIZE - 1][i];
        }
        for (int i = 0; i < SIZE; i++) {
                cube[2][SIZE - 1][i] = cube[3][SIZE - 1][i];
        }
        for (int i = 0; i < SIZE; i++) {
                cube[3][SIZE - 1][i] = cube[4][SIZE - 1][i];
        }
        for (int i = 0; i < SIZE; i++) {
                cube[4][SIZE - 1][i] = temp[i];
        }
        temp[0] = cube[5][0][0];
        cube[5][0][0] = cube[5][0][2];
        cube[5][0][2] = cube[5][2][2];
        cube[5][2][2] = cube[5][2][0];
        cube[5][2][0] = temp[0];
        temp[0] = cube[5][0][1];
        cube[5][0][1] = cube[5][1][2];
        cube[5][1][2] = cube[5][2][1];
        cube[5][2][1] = cube[5][1][0];
        cube[5][1][0] = temp[0];
    };

};


int main() {
    RubikKup rubikKup;
    std::cout << "Başlangıç durumu:" << std::endl;
    rubikKup.printCube();
    rubikKup.rotateRiverseF();
    rubikKup.rotateU();
    rubikKup.rotateRiverseB();
    rubikKup.rotateRiverseD();
    rubikKup.rotateR();
    rubikKup.rotateF();
    rubikKup.rotateRiverseL();
    rubikKup.rotateU();
    rubikKup.rotateR();
    rubikKup.rotateRiverseF();
    rubikKup.rotateRiverseL();
    rubikKup.rotateU();
    rubikKup.rotateR();
    rubikKup.rotateRiverseB();
    rubikKup.rotateRiverseU();
    rubikKup.printCube();
    return 0;
}
