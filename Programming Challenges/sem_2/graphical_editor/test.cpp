 #include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <map>
#include <set>
#include <queue>
#include <vector>
#include <cmath>


using namespace std;

int M, N; //m is column and n is row
char **image; //image container

void fillImage(int x, int y, char oldColor, char newColor);
void fillPixel(int x, int y, char oldColor, char newColor);

int main() {
    
    char operation;
    cin>>operation;
    
    while (operation != 'X') {
        if (operation == 'S') { //save and print out the current image
            string fileName;
            cin>>fileName;
            cout<<fileName<<endl;
            for (int i = 0; i < N; i++) {
                for (int j = 0; j < M; j++) {
                    cout<<image[i][j];
                }
                cout<<endl;
            }
        }
        else if (operation == 'I'){
            cin>>M>>N;
            image = new char *[N];
            for (int i = 0; i < N; i++) {
                image[i] = new char[M];
                for (int j = 0; j < M; j++) {
                    image[i][j] = 'O';
                }
            }
        }
        else if (operation == 'C'){ //clear the image

            for (int i = 0; i < N; i++) {
                image[i] = new char[M];
                for (int j = 0; j < M; j++) {
                    image[i][j] = 'O';
                }
            }
        }
        else if (operation == 'L'){ //color pixel x,y to c
            int X,Y; char C;
            cin>>X>>Y>>C;
            image[Y-1][X-1] = C;
        }
        else if (operation == 'V'){ //draw vertical line
            int X,Y1, Y2; char C;
            cin>>X>>Y1>>Y2>>C;
            if (Y1 > Y2) {
                int temp = Y1;
                Y1 = Y2;
                Y2 = temp;
            }
            for (int j = Y1-1; j < Y2; j++) {
                image[j][X-1] = C;
            }
        }
        else if (operation == 'H'){ //draw horizontal line
            int X1, X2, Y; char C;
            cin>>X1>>X2>>Y>>C;
            if (X1 > X2) {
                int temp = X1;
                X1 = X2;
                X2 = temp;
            }
            for (int j = X1-1; j < X2; j++) {
                image[Y-1][j] = C;
            }
        }
        else if (operation == 'K'){ //draw a filled rectangle
            int X1, X2, Y1, Y2; char C;
            cin>>X1>>Y1>>X2>>Y2>>C;
            for (int i = Y1-1; i < Y2; i++) {
                for (int j = X1-1; j < X2; j++) {
                    image[i][j] = C;
                }
            }
        }
        else if (operation == 'F'){ //bucket fill
            int X,Y; char C;
            cin>>X>>Y>>C;
            char oldColor = image[Y-1][X-1];
            image[Y-1][X-1] = C;
            fillImage(X, Y, oldColor, C);
            
        }
        else{ //invalid operation, ignore the line
            string line;
            getline (cin, line);
        }
        
        cin>>operation;
    }
  
  return 0;
}



void fillPixel(int x, int y, char oldColor, char newColor){
    if (x > 0 && y > 0 && x <= M && y <= N && image[y-1][x-1] == oldColor) {
        image[y-1][x-1] = newColor; //set to new color
        fillImage(x, y, oldColor, newColor);
    }
}

void fillImage(int x, int y, char oldColor, char newColor){
    if (oldColor == newColor) {
        return;
    }
    
    fillPixel(x, y-1, oldColor, newColor);
    fillPixel(x-1, y, oldColor, newColor);
    fillPixel(x, y+1, oldColor, newColor);
    fillPixel(x+1, y, oldColor, newColor);
}