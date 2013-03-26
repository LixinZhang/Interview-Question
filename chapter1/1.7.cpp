/*
 * Write an algorithm such that if an element in an M*N matrix is 0, its entire row and column is set to 0.
 * 写一个算法用于实现如果一个M*N的矩阵中某个元素为0.则将该行和该列所有元素设置为0
 */
#include<iostream>
using namespace std;

/*
 * 由于，不能在查找0的时候，进行相应行和列的更新0，因为这样会导致整个矩阵变为0矩阵了
 * 那么就需要记录每个0的位置，然后再统一进行行和列的0替换
 * 方法1：开两个数组row[i],column[j]，记录第i行与第j列是否为0
 * 方法2：建立一个struct，记录row 和 column，用链表形式记录，这样可以最小化存储空间
 * 方法3：num = row*MAXCOLUMN + column的方式进行0元素的位置存储
 */


void solution(int arr[][3], int maxcolumns, int maxrows) {
    bool * row = new bool[maxrows]; 
    bool * column = new bool[maxcolumns];
    for(int i=0;i<maxrows;i++){
        for(int j=0;j<maxcolumns;j++){
            if(arr[i][j] == 0){
                row[i] = true;
                column[i] = true;
            }
        }
    }
    for(int i=0;i<maxrows;i++){
        for(int j=0;j<maxcolumns;j++){
            if(row[i] | column[j]) arr[i][j] = 0;
        }
    }
}


int main(){
    int arr[3][3] = {{1,2,3},{4,0,6},{7,8,9}};
    solution(arr,3,3);
    int maxrows = 3;
    int maxcolumns = 3;
    for(int i=0;i<maxrows;i++){
        for(int j=0;j<maxcolumns;j++){
            cout<<arr[i][j]<<'\t';
        }
        cout<<endl;
    }
   
    return 0;
}
