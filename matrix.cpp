#include <iostream>
#include <stdio.h>      // For size_t
//#include <stddef.h>     // For size_t
//#include <stdint.h>     // Unsure
#include <array>        //Arrays

//size_t = long unsigned int



template <class TYPE>
class Matris {
public:
    //friend void reset();
    // constructors
    //It should be possible to construct the matrix with a single number. The matrix created should be a square matrix with initial elements set to the default element of the type.
    //It should be possible to default-construct the container, which should be semantically equivalent to matrix(0).
    Matris (){  //If we call with no arguments
    std::cout << "default-constructor with no agruments" << std::endl;
    m_rows=0;
    m_cols=0;
    m_vec[0]={};
    //reset();

    }
    Matris (int single){  //If we call with one argument
    std::cout << "default-constructor with one argument" << std::endl;
    m_rows=single;
    m_cols=single;
    m_capacity=single*single;
    m_vec[m_capacity]={};
    //reset();

    }
    Matris (int rows,int cols){
    std::cout << "default-constructor with two arguments" << std::endl;
    m_rows=rows;
    m_cols=cols;
    m_capacity=rows*cols;
    m_vec[m_capacity]={};
    //reset();


    }



//You should implement a copy-constructor and a destructor.
//Note modifying a copied matrix should not changed the
//contents of the copied-from matrix.

    Matris (Matris const& input) {   //copy-constructor
    std::cout << "copy-constructor" << std::endl;
    //return this;
   }

    int operator()(const int row, const int col) {   //() operator
    std::cout << "() Operator" << std::endl;
    int temp_rows=m_rows,temp_cols=m_cols;
    std::cout << row << " " << col << " " << m_rows << " " << m_cols << " " << m_capacity << std::endl;

    if ((row<0) or (col<0)){
        throw std::out_of_range("Index can't be less than 0");
    }
    if ((row>temp_rows) or (col>temp_cols)){
        throw std::out_of_range("Index can't be less than 0");
    }
    int index=(row*m_cols)+col; //For each column, add "row" to index, then add col
    return * m_vec[index];
   }

    void operator=(const Matris * input) {   //() operator
    std::cout << "assigning?" << std::endl;
    m_rows=input.m_rows;
    m_cols=input.m_cols;
    m_capacity=input.m_capacity;
   }

//It should not be possible to instantiate the class template
//unless the specified element type is both moveConstructible
//and moveAssignable. Use static_assert with an appropriate
//error message, to make sure that this is the case.

//Appropriate constructors should be explicit

//You should implement a copy-assignment operator, and although
//assigning a matrix to itself might seem silly, make sure it
//is handled correctly.

//Implement a move-constructor and a move-assignment operator
//taking another matrix potentially of a different size

//Implement a constructor taking std::initializer_list. This
//constructor can only construct square matrices. If the number
//of elements is not an even square root std::out_of_range
//should be thrown. The first elements defines the first row
//and then the next rows in sequence





    // operators

    //Implement * + - which should be chainable

    //Implement *= += -= as non chainable.



    // methods

    //begin()
    //end()

    int rows(){
        const int rows=m_rows;
        return rows;
    }
    int cols(){
        const int cols=m_cols;
        return cols;
    }

    void reset(){
        int max=m_capacity;
        for (int i=0;i<max;i++){
            m_vec[i]=0;
        }
    }


    //identity(unsigned int)

    //Implement insert_row which inserts a row of zeroes before a given row number.

    //Implement append_row which inserts a row of zeroes after a given row number.

    //Implement remove_row which erases the entire row at a given row number

    //Implement insert_column which inserts a column of zeroes before a given column number.

    //Implement append_column which inserts a column of zeroes after a given column number.

    //Implement remove_column which erases the entire column at a given column number

private:
   size_t m_rows;
   size_t m_cols;
   size_t m_capacity;
   TYPE * m_vec[];

};





int main(){
    Matris<int> m(3);
    Matris<int> n(3,4);
    Matris<int> p;
    int a =m(1,1);
    std::cout << "Test value: " << a  << "\n";
    std::cout << "Rows: " << m.rows() << " Cols: "<< m.cols() <<"\n";
    //std::cout << &m << "\n";
    p=m;
    std::cout << "Rows: " << p.rows() << " Cols: "<< p.cols() <<"\n";
    //std::cout << &p;
    //std::cout << "m(0,0): " << m(0,0) << " m(1,1): " << m(1,1) << " m(2,2) "<< m(2,2) <<"\n";
    //^^^THIS LINE
}
