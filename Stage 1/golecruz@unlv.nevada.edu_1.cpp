//Bernard J. Gole Cruz, CS 202-2002, Assignment 4 stage 1
//This program implement the use overloading

#include <iostream>
#include <stdlib.h>
using namespace std;

//class definition and members
class smartArray{
 public:
     //default constructor
     smartArray();
     //parameterize constructor
     smartArray(int);
     //copy constructor
     smartArray(const smartArray &object);
     //destructor
     ~smartArray();

     //pointer to array element
     int *elements = nullptr;
     //return size;
     int length();
     //resize function
     void resize(int);


     //overloaded =
     smartArray operator = (const smartArray &);
     //overloaded subscript
     int &operator [] (const int&); //overloaded []

     //friend functions
     //overloaded stream extraction
     friend ostream &operator << (ostream &, const smartArray&);
      //overloaded stream insertion
     friend istream &operator >> (istream &, smartArray&);
     //overloaded addition
     friend smartArray operator + (const smartArray &, const smartArray &);
     //overloaded subtraction
     friend smartArray operator - (const smartArray &, const smartArray &);
     //overloaded multiplication
     friend smartArray operator * (const smartArray &, const smartArray &);
     //overloaded division
     friend smartArray operator / (const smartArray &, const smartArray &);
     //overloaded &, concatenate two object
     friend smartArray operator & (const smartArray &, const smartArray &);
     //overloaded == rational operator
     friend bool operator == (const smartArray &, const smartArray &);
     //overloaded != rational operator
     friend bool operator != (const smartArray &, const smartArray &);


 private:
     //number of elements in the array
     int size;
     //resize number of elements in the array
     int newsize;

};

//constructor
smartArray::smartArray(){
    //set to 0
    this->size = 0;
};

//parameterize constructor
smartArray::smartArray(int size){
      //program exit if size is equal to 0
      if (size <= -1){
        cout <<"invalid size" << endl;
        exit(EXIT_FAILURE);
       }
      //if size is zero, private class member size is initialize to 0
      else if (size == 0){
        this->size = size;
        }
      //if size is equal or greater than 1, memory allocation is done
      //and private class member size is initialize to 0
      else{
        this->size = size;
        elements = new int[size];

          for(int i=0; i<size; i++){
            elements[i] = 0;
            }
        }
  };

//copy constructor
smartArray::smartArray(const smartArray &object){
   //allocate size for element pointer
   size = object.size;
   elements = new int[size];

   //initialize a created object with data from another object
   for(int i=0; i<size; i++){
     elements[i] = object.elements[i];
     }
  };

//destructor
smartArray::~smartArray(){
    //deallocate element
    delete []elements;
  };

//function prototype
//length of array
int smartArray::length(){
    return size;
  };

//resize array
void smartArray::resize(int newsize){

//store resize value
int newnum;

//prompt user for resizing
cout <<"Enter new size for smartArray object s2: ";
cin >> newnum;

//store current size value
int currentsize = newsize;
//store total size for new array
int updatesize = currentsize + newnum;

//pointer to integer
int *newelements = nullptr;
//allocate size for new array
newelements = new int[updatesize];
//initialize contents to zero
for(int i= 0; i<updatesize; i++){
    newelements[i] = 0;
    }

//fill additional elements with zero if resize value is greater than current size
if (newnum > currentsize)
{
    //copy contents of array elements to new elements
    for(int i=0; i<currentsize ;i++){
    newelements[i] = elements[i];
    }
    //print the updated contents of new array elements
    cout <<"Resize: " ;
    cout <<"[" ;
    for(int i=0; i<updatesize; i++){
    cout << newelements[i];
      if(i  != updatesize - 1 ){
        cout << "," ;
        }
    }
     cout <<"]" ;

}
//copy contents of old array to new array if resize value is less than current size
else {
    for(int i=0; i<currentsize ;i++){
    newelements[i] = elements[i];
    }
    //print the updated contents of new array elements
    cout <<"Resize: " ;
    cout <<"[" ;
    for(int i=0; i<currentsize; i++){
    cout << newelements[i];
      if(i  != currentsize - 1 ){
        cout << "," ;
        }
    }
     cout <<"]" ;
    }

//deallocate array elements
delete []elements;
  };


//overloaded =
smartArray smartArray::operator = (const smartArray &right){
    //copy the data of objects to new object
    this->size = right.size;
    elements = new int[size];
    for(int i=0;i<size; i++){
       elements[i] = right.elements[i];
      }
    return *this;
  };

//overloaded []
int &smartArray::operator [] (const int &subscript){
    //access and index of array using []
    //program terminate if subscript out of range
    if (subscript < 0 || subscript >= size){
        cout <<"Subscript out of range"  <<endl;
        exit(EXIT_FAILURE);
        }
    //return element stored in array index
    else
        return elements[subscript];
  };


//friend functions with definitions

//overloaded stream << extraction
//has direct access in pointer class member element
ostream &operator << (ostream &out, const smartArray &object){
    //display array contents using overloaded <<
    out <<"[" ;
    for(int i=0; i<object.size; i++){
    out << object.elements[i];
       //display contents with comma except the last iteration
        if(i != (object.size - 1)){
        out << ",";
        }
    }
    out<< "]" << endl;

    return out;
  };

//overloaded stream >> insertion
//has direct access in pointer class member element
istream &operator >> (istream &in, smartArray &object){
    //initialize array index using overload >>
     for(int i=0; i<object.size; i++){
       cout <<"enter element " << i << ": ";
       in>> object.elements[i];
      }
      return in;
  };

//overloaded addition
smartArray operator + (const smartArray &object1, const smartArray &object2){
//store size of two objects in a new variable
int tempnum = (object1.size + object2.size)/2;
//smartArray object that store value of sum
smartArray temp(tempnum);

    for(int i=0; i<tempnum; i++){
     temp.elements[i] = object1.elements[i] + object2.elements[i];
    }
   return temp;
};

//overloaded subtraction
smartArray operator - (const smartArray &object1, const smartArray &object2){
//store size of two objects in a new variable
int tempnum = (object1.size + object2.size)/2;
//smartArray object that store value of difference
smartArray temp(tempnum);

    for(int i=0; i<tempnum; i++){
     temp.elements[i] = object1.elements[i] - object2.elements[i];
    }
   return temp;
 };


//overloaded multiplication
smartArray operator * (const smartArray &object1, const smartArray &object2){
//store size of two objects in a new variable
int tempnum = (object1.size + object2.size)/2;
//smartArray object that store value of product
smartArray temp(tempnum);

    for(int i=0; i<tempnum; i++){
     temp.elements[i] = object1.elements[i] * object2.elements[i];
    }
    return temp;
 };

//overloaded division
smartArray operator / (const smartArray &object1, const smartArray &object2){
//store size of two objects in a new variable
int tempnum = (object1.size + object2.size)/2;
//smartArray object that store value of quotient
smartArray temp(tempnum);

    for(int i=0; i<tempnum; i++){
     temp.elements[i] = object1.elements[i] / object2.elements[i];
    }
    return temp;
  };


//overloaded & concatenate two objects
smartArray operator & (const smartArray &object1, const smartArray &object2){
//smartArray object that store value of concatenate objects
smartArray temp(object1.size + object2.size);

    //store value for object1
    for(int i=0; i<object1.size; i++){
    temp.elements[i] = object1.elements[i];
    }
    //store value for starting position
    int tempnum = object1.size;

    //store values for object2, concatenate object1 and object2
    //starting from last element of object1
    for(int i=0; i<object2.size; i++){
    temp.elements[tempnum] = object2.elements[i];
    tempnum ++;
    }

   return temp;
};


//overloaded ==
bool operator == (const smartArray &object1, const smartArray &object2){
//set bool variable to true, equal size;
bool status = true;

int i=0;

while( status && (i< object1.size) && (i < object2.size) ){
    //if two objects have same size, proceeds on checking if contents are in same position
    if( (object1.elements[i] == object2.elements[i]) && (object1.size == object2.size) ){
        status = true;
        }
    else{
        status = false;
        }
    i++;
}
    return status;
};


//overloaded !=
bool operator != (const smartArray &object1, const smartArray &object2){
//set bool variable to true equal size;
bool status = true;

int i=0;

while( status && (i< object1.size) && (i < object2.size) ){
    //if same size, proceeds on checking if contents are in same position
    if( (object1.elements[i] == object2.elements[i]) && (object1.size == object2.size) ){
        status = true;
        }
    else{
        status = false;
        }
    i++;
}
    //return the false to display an opposite value;
    return (!(object1 == object2));
};



int main(){

//test for Stage 1
//declared smartArray objects;
 smartArray s1(4);
 smartArray s2(5);

 smartArray s3;
 smartArray s4;
 smartArray s5;
 smartArray s6;
 smartArray s7;
/*

//overload insertion >>
  cin >> s1;
  cin >> s2;

//overload math operators
     s3 = s1 + s2;
     s4 = s1 - s2;
     s5 = s1 * s2;
     s6 = s1 / s2;

//overload &
     s7 =  s1 & s2;

//overload extraction <<
     cout << endl;
     cout << "***Overloaded math operators***" << endl;
     cout << "Sum = " << s3;
     cout << "Difference = " << s4;
     cout << "Product = " << s5;
     cout << "Quotient = " << s6;

     cout << endl;
     cout << "***Overloaded & concatenate two objects***" << endl;
     cout << "Concatenate contents of two objects = " << s7;


//overload subscript test
    cout << endl;
    cout << "***Overloaded [] operator***" << endl;
    cout << "Accessing the index of smartArray object s1[3] = " << s1[3] << endl;
    cout << "Accessing the index of smartArray object s2[0] = " << s2[0] << endl;


//overload rational operator ==

    cout << endl;
    cout << "***Overloaded rational operator == ***" << endl;
    if (s1 == s2)
    {
        cout << "objects are equal" << endl;
    }
    else
        cout << "objects are not equal" << endl;


//overload rational operator !=
    cout << endl;
    cout << "***Overloaded rational operator != ***" << endl;
    if (s1 != s2)
    {
        cout << "objects are not equal" << endl;
    }
    else
        cout << "objects are equal" << endl;

//resize object function
cout << endl;
s2.resize(s2.length());
*/

cout << s1;
cout << s2;
    return 0;
}
