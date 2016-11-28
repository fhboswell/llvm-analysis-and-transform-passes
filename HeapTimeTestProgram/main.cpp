//Assingment 13
//Franklin Boswell
//COMSC 210

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <time.h>
#include <fstream>

using namespace std;



void sort ( int x [] , int length);
void buildHeap (int x [], int length);
void buildHeap (int x [], int length);
void reheapifyUpward (int x [], int lastIndex);
void sortHeap (int x [], int length);
void reheapifyDownward (int x [], int lastIndex);
int findBigChildIndex (int  parentIndex, int x [ ] ,  int lastIndex);

int SIZE = 500000;
int* x = NULL;

int main(int argc, const char * argv[])
{
    ofstream fout;
    fout.open("HeapSort.txt", ios::app);
    
    fout << "DataSize | Time in Sec" << endl;
    cout << "DataSize | Time in Sec" << endl;
    for(int z = 1; z <=5; z++)
    {
        SIZE = z*100000;
        x = new int[SIZE];
    
    int i;
    //seed srand with different value each time you run
    //so that rand will generate different sequence each time you run
    srand((unsigned )time(NULL));
    for ( i=0;i<SIZE;i++)
    {
        x[i]=rand();
        //cout << x[i] << " ";
    }
    //Calculate the time taken by a sort routine in seconds as below:
    
    clock_t start, finish;
    start =clock( ); //time in milliseconds
    sort(x, SIZE );
    finish=clock( ); //time in milliseconds
    //the constant CLOCKS_PER_SEC below is equal to 1000
    double duration =  ((double) (finish-start)) / CLOCKS_PER_SEC ;
    cout << SIZE << "   | " << duration <<endl; //time duration in seconds
    fout << SIZE << "   | " << duration <<endl; //time duration in seconds
   // delete x;
    /*
    
    for ( i=0;i<SIZE;i +=1000)
    {
        //x[i]=rand() % 300;
        cout << x[i] << " ";
    }
    */
    delete [] x;
    }
    fout.close();
    return 0;
    
}

//heap sort method

void sort ( int x [] , int length)
{
    if (length < 2)
        return;
    
    //change unsorted array to heapified array
    buildHeap (x, length );
    
    //change heapified array to sorted array
    sortHeap (x, length);
    
}

//Method below changes unsorted array into heapified array
//Pre-condition: length > 1
void buildHeap (int x [], int length)
{
    int lastIndex;
    for (lastIndex=1; lastIndex<length; lastIndex++)
    {
        reheapifyUpward (x, lastIndex);
    }
}
//lastIndex is the index of the last working element of the array received.
void reheapifyUpward (int x [], int lastIndex)
{
    int childIndex = lastIndex;
    int parentIndex;
    int temp;
    while (childIndex > 0 )
    {
        parentIndex = (childIndex-1)/2;
        if (x [childIndex] <= x [parentIndex])
            break;
        else
        {
            //swap values at childIndex and at parentIndex.
            temp = x [childIndex];
            x [childIndex] = x [parentIndex];
            x [parentIndex] = temp;
            
            
            //Update child to parent
            childIndex = parentIndex;
        }
    }
}

//Method below changes heapified array into sorted array
//Pre-condition: length > 1
//lastIndex is the index of the last element of the array.
int findBigChildIndex (int  parentIndex, int x [ ] ,  int lastIndex)
{
    int lChildIndex = (2 * parentIndex) + 1;
    int rChildIndex = (2 * parentIndex) + 2;
    
    //case both children exist
    if (rChildIndex <= lastIndex && lChildIndex <= lastIndex)
    {
        if(x[rChildIndex] > x[lChildIndex])
        {
            return rChildIndex;
        }
        else if(x[rChildIndex] < x[lChildIndex])
        {
            return lChildIndex;
        }
        else
        {
            cout << "they are equal" << endl;
            return rChildIndex;
        }

        //compare value at rChildIndex and at lChildIndex
        //return the index where the value is larger
       
        
        
    }
    //case only left child exist
    else if (lChildIndex <= lastIndex)
    {
        return lChildIndex;
    }
    //case both children missing
    
        return -1;
    
}
void reheapifyDownward (int x [], int lastIndex)
{
    
    int parentIndex = 0;
    int temp;
    
    while (parentIndex < lastIndex)
    {
        //findBigChildIndex will return a negative value if parent has no children.
       int bigChildIndex = findBigChildIndex (parentIndex, x, lastIndex);
        
        if (bigChildIndex < 0 || x [bigChildIndex] <= x [parentIndex])
            break;
        else
        {
            //swap value at parentIndex with value at bigChildIndex
            temp = x [parentIndex];
            x [parentIndex] = x [bigChildIndex];
            x [bigChildIndex] = temp;

            
            //update parentIndex
            parentIndex = bigChildIndex;
        }
    }
}

//The function will return -1 if the parent had no children.

void sortHeap (int x [], int length)
{
    int lastIndex = length - 1;
    int temp;
    while (lastIndex > 0)
    {
        //swap the contents of index 0 with contents of lastIndex
        temp = x [0];
        x [0] = x [lastIndex];
        x [lastIndex] = temp;
        
        //decrement the array size
        lastIndex--;
        
        //call reheapifyDownward. Pass it the array and the last index number of the array.
        reheapifyDownward(x, lastIndex);
        
    }
}