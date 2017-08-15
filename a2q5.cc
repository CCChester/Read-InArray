#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <string>

using namespace std;

//intarray struct
struct IntArray {
    int size;
    int capacity;
    int *contents;
};

/*readIntArray:
    consume: NULL
    produce: IntArray
*/
IntArray readIntArray(){
    IntArray myarr;
    myarr.capacity = 0;  //initialize
    myarr.size = 0;
    int num;  //num
    string str;
    while(cin >> str){  //read from a string
        istringstream ss(str);
        if (ss >> num) {    //if it is a num
            myarr.size++;
            if(myarr.size == 1){
                myarr.capacity = 5;
                myarr.contents = new int[myarr.capacity];
            }   //allocate more
            else if(myarr.size  > myarr.capacity){
                myarr.capacity = myarr.capacity * 2;
                int *temp = new int[myarr.capacity];
                int index = 0;
                while(index < myarr.size){
                    temp[index] = myarr.contents[index]; //resize
                    index++;
                } //while
                delete [ ] myarr.contents;
                myarr.contents = temp;  //swap, copy and paste
            }
            myarr.contents[myarr.size - 1] = num;
        }//if
        else{
            ss.clear();
            ss.ignore();
            break;
        }
    }//while
    return myarr;
}

/* addToIntArray:
    consume: IntArray
    produce: NULL
*/
void addToIntArray(IntArray& ia){
    string str;
    int num;
    while(cin >> str){ //read a string
        istringstream ss(str);
        if (ss >> num){  //if it is a num
            ia.size++;
            if(ia.size == 1){
                ia.capacity = 5;
                ia.contents = new int [ia.capacity];  //allocate
            }//if
            else if(ia.size  > ia.capacity){
                ia.capacity = ia.capacity * 2; //resize
                int *temp = new int[ia.capacity];
                int index = 0;
                while(index < ia.size){
                    temp[index] = ia.contents[index];
                    index++;
                }
                delete [ ] ia.contents;
                ia.contents = temp;  //copy and paste
            }
            ia.contents[ia.size - 1] = num;
        }
        else{
            ss.clear();
            ss.ignore();
            break;
        }//if
    }//while
}

/*printIntArray: 
    consumes: IntArray
    produces: NULL
*/
void printIntArray(const IntArray& ia){
    int pos = 0;
    while(pos < ia.size){ //print it
        cout << ia.contents[pos] << " ";
        pos++;
    }
    cout <<  endl;
}

int main(){
    bool done = false;
    IntArray a[4];
    a[0].contents = a[1].contents = a[2].contents = a[3].contents = nullptr;
    while(!done){
        char c;
        char which;
        cerr << "Command?" << endl;
        cin >> c;
        if (cin.eof()) break;
        switch(c){
            case 'r':
                cin >> which;
                delete [] a[which-'a'].contents;
                a[which-'a'].contents = nullptr;
                a[which-'a'] = readIntArray();
                break;
            case '+':
                cin >> which;
                addToIntArray(a[which-'a']);
                break;
            case 'p':
                cin >> which;
                printIntArray(a[which-'a']);
                cout << "Capacity: " << a[which-'a'].capacity << endl;
                break;
            case 'q':
                done = true;
        }
    }
    for (int i = 0; i < 4; ++i) delete [] a[i].contents;
}
