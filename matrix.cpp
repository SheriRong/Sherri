

#include <iostream>
#include <fstream>
const int iSize = 10;
void readMatrix (int matrix1[iSize][iSize], int matrix2[iSize][iSize],int& size, const std::string& filename)
{
    std::ifstream infile(filename);
    if(infile.is_open()){
        infile >> size;
        for (int i=0; i<size; ++i){
            for (int j=0; j<size; ++j){
                infile >> matrix1[i][j];
            }
        }
        for (int i=0; i<size; ++i){
            for (int j=0; j<size; ++j){
                infile >> matrix2[i][j];
            }
        }
    } else{
        std::cout<< "Unable to open the file";
        exit(1);
    }
}
void printMatrix (const int matrix1[iSize][iSize], const int matrix2[iSize][iSize],int size){
    for (int i=0; i<size; ++i){
        for (int j=0; j<size; ++j){
            std::cout << matrix1[i][j]<<" ";
        }
        std::cout << std:: endl;
    }
    std:: cout <<"\n";
    for (int i=0; i<size; ++i){
        for (int j=0; j<size; ++j){
            std::cout << matrix2[i][j]<<" ";
        }
        std::cout << std::endl;
    }
}
void addMatrix (const int matrix1[iSize][iSize], const int matrix2[iSize][iSize],int result[iSize][iSize],int size){
    for (int i=0; i<size; ++i){
        for(int j=0; j<size; ++j){
           result[i][j] = matrix1[i][j]+ matrix2[i][j];
        }}
    for (int i=0; i<size; ++i){
        for (int j=0; j<size; ++j){
            std::cout << result[i][j]<<" ";
        }
        std::cout << std:: endl;
    }
    std:: cout <<"\n";
    
}
void multiplyMatrix (const int matrix1[iSize][iSize], const int matrix2[iSize][iSize],int result[iSize][iSize],int size){
    for (int i=0; i<size; ++i){
        for(int j=0; j<size; ++j){
            result[i][j]=0;
            for (int k=0; k<size;++k){
            result[i][j] += matrix1[i][k]* matrix2[k][j];
        }}}
    for (int i=0; i<size; ++i){
        for (int j=0; j<size; ++j){
            std::cout << result[i][j]<<" ";
        }
        std::cout << std:: endl;
    }
    std:: cout <<"\n";
}
void subtractMatrix (const int matrix1[iSize][iSize], const int matrix2[iSize][iSize],int result[iSize][iSize],int size){
    for (int i=0; i<size; ++i){
        for(int j=0;i<size;++i){
            result[i][j]= matrix1[i][j]- matrix2[i][j];
        }
    }
    for (int i=0; i<size; ++i){
        for (int j=0; j<size; ++j){
            std::cout << result[i][j]<<" ";
        }
        std::cout << std:: endl;
    }
    std:: cout <<"\n";}
void updateMatrix (int matrix1[iSize][iSize],int size, int row, int col, int data){
    if (row >0 && row < size+1 && col > 0 && col < size+1) {
        matrix1[row-1][col-1] = data;
    } else {
        std::cout << "Invalid row or column index." << std::endl;
    }
    for (int i=0; i<size; ++i){
        for (int j=0; j<size; ++j){

            std::cout << matrix1[i][j]<<" ";
        }
        std::cout << std:: endl;
    }
    std:: cout <<"\n";
}
void maxMatrix (int matrix1 [iSize][iSize],int size){
    int max = matrix1[0][0];
    for (int i=0; i<size; ++i){
        for (int j=0; j<size; ++j){
            if (matrix1[i][j]> max){
                max = matrix1[i][j];
            }
        }
    }
    std::cout << max<<"\n";
}

void transposeMatrix(int matrix1[iSize][iSize], int result[iSize][iSize], int size) {
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            result[j][i] = matrix1[i][j];
        }
    }
    for (int i=0; i<size; ++i){
        for (int j=0; j<size; ++j){
            std::cout << result[i][j]<<" ";
        }
        std::cout << std:: endl;
    }
    std:: cout <<"\n";
}

int main() {
    int matrix1[iSize][iSize], matrix2[iSize][iSize], result[iSize][iSize];
    int size;
    int row,col, data;
    std::cout <<"Enter the row that you want to update:";
    std::cin>>row;
    std::cout <<"Enter the column that you want to update:";
    std::cin>>col;
    std::cout <<"Enter the new data:";
    std::cin>>data;
    readMatrix(matrix1,matrix2,size,"matrix_input.txt");
    std::cout<< "Print the Matrix:\n";
    printMatrix(matrix1, matrix2,size);
    std::cout<<"\nMatrix Addtion:\n";
    addMatrix(matrix1,matrix2,result,size);
    std::cout<<"Matrix Multiplication:\n";
    multiplyMatrix(matrix1,matrix2,result,size);
    std::cout<<"Matrix Subtraction\n";
    subtractMatrix(matrix1,matrix2,result,size);
    std::cout<<"Update an element of the Matrix1:\n";
    updateMatrix(matrix1,size,row,col,data);
    std::cout<<"Maximum of Matrix1:\n";
    maxMatrix(matrix1,size);
    std::cout <<"Transpose of matrix1\n";
    transposeMatrix(matrix1,result,size);
    return 0;
}
