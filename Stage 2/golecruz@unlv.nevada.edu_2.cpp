//Bernard J. Gole Cruz, CS 202-2002, Assignment 4 stage 2
//This program updated version of stage 1 with implementation of class template
#include <iostream>  //for input and output stream
#include <stdlib.h>  //dynamic memory, exit and more
#include <iomanip>   //formatting manipulation

using namespace std;

//class definition and members
template <class T>
class smartArray{
 //public members
 public:
     //default constructor
     smartArray();
     //parameterize constructor
     smartArray(int);
     //copy constructor
     smartArray(const smartArray &);
     //destructor
     ~smartArray();

     //pointer to array element
     T *elements = nullptr;
     //return size;
     int length();
     //resize function
     void resize(int);


     //overloaded =
     smartArray operator = (const smartArray<T> &);
     //overloaded subscript []
     T &operator [] (const int&);


     //friend functions with definitions

     //overloaded << stream extraction
     //has direct access in pointer class member element
     friend ostream &operator << (ostream &out, const smartArray<T> &object)
     {
     //display array contents using overloaded <<
     out <<"elements are: " ;
     out <<"[" ;
     for(int i=0; i<object.size; i++){
     //display one decimal point for non int type variables
     cout << fixed << showpoint << setprecision(1);
     out << object.elements[i];
       //display contents with comma except the last iteration
        if(i != (object.size - 1)){
            out << ",";
            }
        }
     out<< "]" << endl;
     return out;
     };

     //overloaded >> stream insertion
     //has direct access in pointer class member element
     friend istream &operator >> (istream &in, smartArray<T> &object)
     {
     //initialize array index using overload >>
     for(int i=0; i<object.size; i++){
            cout <<"enter element " << i << ": ";
            in >> object.elements[i];
            }
     return in;
     };


      //overloaded addition
     friend smartArray<T> operator + (const smartArray<T> &object1, const smartArray<T> &object2)
     {
     //store size of two objects in a new variable
     int tempnum = (object1.size + object2.size)/2;
     //smartArray object that store value of sum
     smartArray<T> temp(tempnum);

     for(int i=0; i<tempnum; i++){
            temp.elements[i] = object1.elements[i] + object2.elements[i];
            }
     return temp;
     };


     //overloaded subtraction
     friend smartArray<T> operator - (const smartArray<T> &object1, const smartArray<T> &object2)
     {

     //store size of two objects in a new variable
     int tempnum = (object1.size + object2.size)/2;
     //smartArray object that store value of difference
     smartArray<T> temp(tempnum);

     for(int i=0; i<tempnum; i++){
            temp.elements[i] = object1.elements[i] - object2.elements[i];
            }
     return temp;
     };


     //overloaded multiplication
     friend smartArray<T> operator * (const smartArray<T> &object1, const smartArray<T> &object2)
     {

     //store size of two objects in a new variable
     int tempnum = (object1.size + object2.size)/2;
     //smartArray object that store value of product
     smartArray<T> temp(tempnum);

     for(int i=0; i<tempnum; i++){
           temp.elements[i] = object1.elements[i] * object2.elements[i];
             }
     return temp;
     };


     //overloaded division
     friend smartArray<T> operator / (const smartArray<T> &object1, const smartArray<T> &object2)
     {
     //store size of two objects in a new variable
     int tempnum = (object1.size + object2.size)/2;
     //smartArray object that store value of quotient
     smartArray<T> temp(tempnum);

     for(int i=0; i<tempnum; i++){
            temp.elements[i] = object1.elements[i] / object2.elements[i];
            }
     return temp;
     };


     //overloaded &, concatenate two object
     friend smartArray<T> operator & (const smartArray<T> &object1, const smartArray<T> &object2)
     {
     //smartArray object that store value of concatenate objects
     smartArray<T> temp(object1.size + object2.size);

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


     //overloaded == rational operator
     friend bool operator == (const smartArray<T> &object1, const smartArray<T> &object2)
     {
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


     //overloaded != rational operator
     friend bool operator != (const smartArray<T> &object1, const smartArray<T> &object2)
     {
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
     //return the false to display an opposite value;
     return (!(object1 == object2));

     };

 //private members
 private:
     //number of elements in the array
     int size;
     //resize number of elements in the array
     int newsize;

};


//function prototype, function definitions
//default constructor
template <class T>
smartArray<T>::smartArray()
{
    //set to 0
    this->size = 0;
};

//parameterize constructor
template <class T>
smartArray<T>::smartArray(int size){
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
       elements = new T[size];

         for(int i=0; i<size; i++){
           elements[i] = 0;
            }
       }
  };

//copy constructor
template <class T>
smartArray<T>::smartArray(const smartArray &object){
   //allocate size for element pointer
   size = object.size;
   elements = new T[size];

   //initialize a created object with data from another object
   for(int i=0; i<size; i++){
     elements[i] = object.elements[i];
     }
  };


//destructor
template <class T>
smartArray<T>::~smartArray(){
    //deallocate element
    delete []elements;
  };


//length of array
template <class T>
int smartArray<T>::length(){
    return size;
  };


//resize array
template <class T>
void smartArray<T>::resize(int newsize){

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
T *newelements = nullptr;
//allocate size for new array
newelements = new T[updatesize];
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
    //display one decimal point for non int type variables
    cout << fixed << showpoint << setprecision(1);
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
    //display two decimal point for non int type variables
    cout << fixed << showpoint << setprecision(1);
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
template <class T>
smartArray<T> smartArray<T>::operator = (const smartArray &right){
    //copy the data of objects to new object
    this->size = right.size;
    elements = new T[size];
    for(int i=0;i<size; i++){
       elements[i] = right.elements[i];
      }
    return *this;
  };


//overloaded subscript []
template <class T>
T &smartArray<T>::operator [] (const int &subscript)
{
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


int main ()
{


 //***updated version smartArray class now can handle any type of variables***
 //test for Stage II
 //smartArray objects of double type
 smartArray<double> s8(5);
 smartArray<double> s9(6);


//overload insertion >>
 cin >> s8;
 cin >> s9;

//overload extraction <<
 cout << endl;
 cout << s8;
 cout << s9;

 cout << endl;


/*
 cout <<"***TEST FOR STAGE III***" << endl;
 cout <<"overloaded operators work on class template" << endl;

//test for Stage III, ***overloaded operators works on class template***
//smartArray objects for overloaded operator test
 smartArray<double> s10;
 smartArray<double> s11;
 smartArray<double> s12;
 smartArray<double> s13;
 smartArray<double> s14;

//overload math operators
     s10 = s8 + s9;
     s11 = s8 - s9;
     s12 = s8 * s9;
     s13 = s8 / s9;

//overload &
     s14 =  s8 & s9;

//overload extraction <<
     cout << endl;
     cout << "***Overloaded math operators***" << endl;
     cout << "Sum = " << s10;
     cout << "Difference = " << s11;
     cout << "Product = " << s12;
     cout << "Quotient = " << s13;

     cout << endl;
     cout << "***Overloaded & concatenate two objects***" << endl;
     cout << "Concatenate contents of two objects = " << s14;

//overload subscript test
    cout << endl;
    cout << "***Overloaded [] operator***" << endl;
    cout << "Accessing the index of smartArray object s9[0] = " << s9[0] << endl;
    cout << "Accessing the index of smartArray object s9[1] = " << s9[1] << endl;

//overload rational operator ==

    cout << endl;
    cout << "***Overloaded rational operator == ***" << endl;
    if (s8 == s9)
    {
        cout << "objects are equal" << endl;
    }
    else
        cout << "objects are not equal" << endl;


//overload rational operator !=
    cout << endl;
    cout << "***Overloaded rational operator != ***" << endl;
    if (s8 != s9)
    {
        cout << "objects are not equal" << endl;
    }
    else
        cout << "objects are equal" << endl;


//resize object function
cout << endl;
s9.resize(s9.length());
cout << endl;
*/





    return 0;
}
