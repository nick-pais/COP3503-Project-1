//Programming Project 1
#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <fstream>
#include <cstdlib>
#include <ctime>
using namespace std;

void generatesquare(int n) {
    /* Initializing variables
     tempR is for temporary row
     tempC is for temporary column*/
    printf("\n");
    int tempR, tempC;
    int square[n][n];

    // set intial array value
    for(int i=0 ; i<n ; i++) {
        for(int j=0 ; j<n ; j++) {
                square[i][j] = 0;
        }
    }

    int row = 1;
    int col = (n+1)/2;
    int inc = 1;
    int h = inc+1;
    // Starting point number entered.
    square[row-1][col-1] = inc;

    // "The algorithm"
    for(inc=h ; inc<=((n*n)) ; inc++){
        tempR = row - 1;
        tempC = col + 1;
        if (tempR==0 && tempC==(n+1)){
            tempR = row + 1;
            tempC = n;
            row = tempR;
            col = tempC;
            square[row-1][col-1]=inc;
        } else{
            if(tempR==0){
                tempR = n;
            }
            if(tempC==(n+1)){
                tempC= 1;
            }
            if(square [tempR-1][tempC-1]==0){
                row = tempR;
                col = tempC;
                square[row-1][col-1] = inc;
            } else{
                tempR = row + 1;
                tempC = col;

                if(tempR==(n+1)){
                    tempR = 1;
                }
                    row = tempR;
                    col = tempC;
                    square[row-1][col-1]=inc;
                }
        }
    }


    // code for printing the square, and adding spaces between the numbers
    // added space to get numbers to align
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            printf("%3d ", square[i][j]);
        }
        printf("\n");
    }
    // sum of rows
    int sum = 0;
    printf("\nChecking the sums of every row:      ");
    for (int j =0; j < n; j++){
        sum = 0;
        for (int i =0; i <n; i++){
            sum  += square[i][j];

        }
        cout << sum << " " << ends;
    }
    // sum of columns
    printf("\nChecking the sums of every column:   ");
    for (int j =0; j < n; j++){
        sum = 0;
        for (int i =0; i <n; i++){
            sum  += square[j][i];

        }
        cout << sum << " " << ends;
    }
    //sum of diagonals
    printf("\nChecking the sums of every diagonal: ");
    sum = 0;
    for (int i =0; i < n; i++){
        sum += square[i][i];
    }
    cout << sum << " " << ends;
    sum = 0;
    int f = n-1;
    for (int i = 0; i < n; i++){
        sum += square[f][i];
        f--;
    }
    cout << sum << endl;

    int temp;
    for(int row = 0; row < n  ; row++) {
        for (int col = 0; col < n/2 ; col++) {
            temp = square[row][col];
            square[row][col] = square[row][n - 1 - col];
            square[row][n - 1 - col] = temp;
    }
    }
    // prints array
    printf("\n");
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            printf("%3d ", square[i][j]);
        }
        printf("\n");
    }
    //sum of rows
    sum = 0;
    printf("\nChecking the sums of every row:      ");
    for (int j =0; j < n; j++){
        sum = 0;
        for (int i =0; i <n; i++){
            sum  += square[i][j];

        }
        cout << sum << " " << ends;
    }
    //sum of columns
    printf("\nChecking the sums of every column:   ");
    for (int j =0; j < n; j++){
        sum = 0;
        for (int i =0; i <n; i++){
            sum  += square[j][i];

        }
        cout << sum <<" "<< ends;
    }
    //Print diagonal sums
    printf("\nChecking the sums of every diagonal: ");
    sum = 0;
    for (int i =0; i < n; i++){
        sum += square[i][i];
    }
    cout << sum << " " <<ends;
    sum = 0;
    f = n-1;
    for (int i = 0; i < n; i++){
        sum += square[f][i];
        f--;
    }
    cout << sum << " "<< endl;
    //Flips array vertically.
    for (int col =0; col <n; col++){
        for (int row = 0; row < n/2 ; row++) {
            temp = square[row][col];
            square[row][col] = square[n - 1 - row][col];
            square[n - 1 - row][col] = temp;
        }
    }
    //prints array.
    printf("\n");
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            printf("%3d ", square[i][j]);
        }
        printf("\n");
    }
    //Print row sums
    sum = 0;
    printf("\nChecking the sums of every row:      ");
    for (int j =0; j < n; j++){
        sum = 0;
        for (int i =0; i <n; i++){
            sum  += square[i][j];

        }
        cout << sum << " "<< ends;
    }
    //Print column sums.
    printf("\nChecking the sums of every column:   ");
    for (int j =0; j < n; j++){
        sum = 0;
        for (int i =0; i <n; i++){
            sum  += square[j][i];

        }
        cout << sum << " " << ends;
    }
    //Print diagonal sums
    printf("\nChecking the sums of every diagonal: ");
    sum = 0;
    for (int i =0; i < n; i++){
        sum += square[i][i];
    }
    cout << sum << " " << ends;
    sum = 0;
    f = n-1;
    for (int i = 0; i < n; i++){
        sum += square[f][i];
        f--;
    }
    cout << sum << " " << endl;
    return;
}




int main() {
    string SizeOfSq;
    int intSizeOfSq;
    for (int i = 0; i < 1; i--){
        // ask use for size
        cout << "Enter the size of the magic square: ";
        getline(cin, SizeOfSq);
        intSizeOfSq = atoi(SizeOfSq.c_str());
        // make sure the number given is valid
        if ((intSizeOfSq > 2)&&(intSizeOfSq < 16)&&(intSizeOfSq%2 !=0)){
            break;
        }
    }
    // Creates squares
    generatesquare(intSizeOfSq);
    return 0;
}
