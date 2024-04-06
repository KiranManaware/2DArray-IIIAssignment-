// Given an m x n integer matrix matrix, if an element is 0, set its entire row and column to 0's.
// You must do it in place.
// Input :
// 1 1 1
// 1 0 1
// 1 1 1
// Output :
// 1 0 1
// 0 0 0
// 1 0 1
#include<iostream>
#include <vector>
using namespace std;
void setzeroes(vector<vector<int>> &arr){
    int m=arr.size();
    int n=arr[0].size();

    bool zerothRow = false;
    bool zerothCol = false;

    for(int j=0;j<n;j++){
        if(arr[0][j]==0){
            zerothRow=true;
            break;
        }
    }

    for(int i=0;i<m;i++){
        if(arr[i][0]==0){
            zerothCol=true;
            break;
        }
    }

    for(int i=0;i<m;i++){
        for(int j=1;j<n;j++){
            if(arr[i][j]==0){
                arr[i][0]=0;//row vector
                arr[0][j]=0;//col vector
            }
        }
    }

    for(int j=1;j<n;j++){
        if(arr[0][j]==0){
            for(int i=1;i<m;i++){
                arr[i][j]=0;
            }
        }
    }

    for(int i=1;i<m;i++){
        if(arr[i][0]==0){
            for(int j=1;j<n;j++){
                arr[i][j]=0;
            }
        }
    }
    //zerothRow
    if(zerothRow==true){
        for(int j=0;j<n;j++){
            arr[0][j]=0;
        }
    }
    //zerothCol
    if(zerothCol==true){
        for(int i=0;i<m;i++){
            arr[i][0]=0;
        }
    }
}
int main()
{
    int m,n;
    cout<<"Enter no of rows : ";
    cin>>m;
    cout<<"Enter no of columns : ";
    cin>>n;
    vector< vector<int> > v(m,vector<int>(n));
    //input
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            cin>>v[i][j];
        }
    }
    setzeroes(v);
    //output
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            cout<<v[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}