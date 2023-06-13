void Heap::heapSort(int* array,int numberOfElementsInArray)
{
    //Each element of the array will be placed into the heap, which we will assume to be empty, during the for loop.
    for( int i=0; i<numberOfElementsInArray; i++)
    {
        this->insertNode(array[i]); //call of member function to insert each element into max heap
    }

    //After sorting the heap such that it always provides us the maximum element,
    //we will use the method deleteRoot to return the root of the heap.
    //We will then place those elements in our array so that it has a non-decreasing order.

    int i =0;
    while( ! this->isEmpty() )
    {
        array[i] = this->deleteRoot();
        i++;
    }
    //Now that the array is sorted in non-decreasing order, the elements in it are arranged from maximum to least.
}

//implementation of deleteRoot() function

int Heap::deleteRoot()
{
    //remember that this heap is implemented as an array, which is a static structure rather than a dynamic one.

    if( this->numberOfElements == 0)            //numberOfElements of a given heap
        throw new Exception("The heap is empty");
    int result = this->heap[1];                            //heap is an array that holds elements of our heap, and
    //heap[1] is the root of our heap, so we save it
    //because with this algorithm we will overwrite it
    int last = this->heap[numberOfElements];
    numberOfElements--;
    int i = 1;
    while (2* i <numberOfElements+1) //sorting the heap
    {
        int child = 2*i;      //read up on binary static heaps in order to understand this part
        if ( child + 1 < nuberOfElements + 1 && heap[child + 1] < heap[child])
            child = child +1;
        if (last <= heap[child])
            break;
        heap[i] = heap[child];
        i = child;
    }
    heap [i] = last;
    return result; //root
}

int main{

};