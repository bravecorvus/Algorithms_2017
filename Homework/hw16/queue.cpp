#include <iostream>
#include <math.h>
using namespace std;

int thequeue[10000000];

class Queue {
    int startIndex;
    int endIndex;
    public:
        Queue(int inputarray[], int size) {
            int z = floor(size/2);
            startIndex = 9999999-size+1;
            cout << startIndex << endl;
            endIndex = 9999999;
            cout << endIndex << endl;
            int p = 0;
            for(int i = startIndex; i <= endIndex; ++i) {
                thequeue[i] = inputarray[p];
                ++p;
            }
        }
        Queue() {
            startIndex = 4999999;
            endIndex = 4999999;
        }
        int peek() {
            return(thequeue[endIndex]);
        }
        int getStartIndex() {
            return(startIndex);
        }
        int getEndIndex() {
            return(endIndex);
        }
        void printQueue() {
            cout << "[";
            for(int i = startIndex; i < endIndex; ++i) {
                cout << thequeue[i] << ", ";
            }
            cout << thequeue[endIndex] << "]\n\n" << endl;
        }
        int dequeue() {
            if (endIndex-startIndex == 0) {
                cout << "Queue is empty\n\n" << endl;
                return(-1);
            } else if (startIndex == 0) { //shift to the right
                int tempTemp[endIndex-startIndex+1];
                int c = 0;
                for (int i = startIndex; i <= endIndex; ++i) {
                    tempTemp[c] = thequeue[i];
                    ++c;
                }
                int tempEnd = 9999999 - endIndex;
                int tempStart = tempEnd + endIndex;
                int z = 0;
                for(int i = tempStart; i < 10000000; ++i) {
                    thequeue[i] = tempTemp[z];
                    ++z;
                }
                startIndex = tempStart;
                endIndex = 9999999;
                return(thequeue[endIndex]);
            } else {
                --endIndex;
                return(thequeue[endIndex+1]);
            }
        }
        void enqueue(int arg) {
            if (endIndex-startIndex >= 9999999) {
                cout << "Queue has already reached the maximum capacity\n\n";
            } else if (startIndex == 0) { //shift to the right
                cout << "start " << startIndex << endl;
                cout << "end " << endIndex << endl;
                int size = endIndex-startIndex+1;
                int counter = 0;
                for (int c = 9999999; c >= 9999999-size; --c) {
                    thequeue[c] = thequeue[endIndex];
                    --endIndex;
                    ++counter;
                }
                endIndex = 9999999;
                startIndex = 9999999-counter;
            } else {
                --startIndex;
                thequeue[startIndex] = arg;
            }
        }
};

int main() {
    int inputarray[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    Queue test(inputarray, 10);
    test.printQueue();
    cout << "We will now try to pop an element off the queue. Before popping, the top of the queue element is " << test.peek() << " and the top of queue index is " << test.getEndIndex() << "\n\n" << endl;
    int poppedlement = test.dequeue();
    cout << "Popping the test queue gives us " << poppedlement << ". and the new top of the queue index is " << test.getEndIndex() << "\n\n" << endl;
    cout << "Now we will try to fill up the queue just to see if we can fill the queue past the 10,000,000 variable limit.\n\n" << endl;
    for (int i = 9; i < 10000000; ++i)
    {
        test.enqueue(i);
    }
    // test.printQueue();
    cout << "Now we should be hitting the limit, so let's try to push one more element.\n\n" << endl;
    test.enqueue(10000000);
}