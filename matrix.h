#pragma once

#include <sstream>
#include "Sequence.h"

#define NUMBER_OF_ROWS_IS_NOT_EQAL "number of rows is not equal"
#define NUMBER_OF_COLUMNS_IS_NOT_EQAL "number of columns is not equal"
#define NEGATIVE_SIZE_MESSAGE "size is negative"
#define IMPOSSIBLE_TO_MULTIPLY_BECAUSE_OF_SIZE "impossible to multiply because of size"

using namespace std;

template <class T> class Matrix
{
private:

	Sequence<Sequence<T>*>* elements;
	int rows = 0;
	int columns = 0;

public:
	
	Matrix() = default;
	
	Matrix(const int rows, const int columns)
	{
		if (rows < 0 || columns < 0)
			throw out_of_range(NEGATIVE_SIZE_MESSAGE);
		if (rows == 0 || columns == 0)
		{
			this->rows = 0;
			this->columns = 0;
		} else
        {
            this->rows = rows;
            this->columns = columns;
        }
		this->elements = (Sequence<Sequence<T>*>*) new ListSequence<ListSequence<T>*>;
		for (int i = 0; i < rows; i++)
			this->elements->Append(new ListSequence<T>(this->columns));
	}
	
	~Matrix() = default;
	
	int GetRows()
	{
		return this->rows;
	}
	
	int GetColumns()
	{
		return this->columns;
	}
	
	T Get(const int i, const int j)
	{
		if (i < 0 || i >= this->rows || j < 0 || j >= this->columns) 
			throw std::out_of_range(INDEX_OUT_OF_RANGE_MESSAGE);

		return elements->Get(i)->Get(j);
	}
	
	void Set(T element, int i, int j)
	{
		if (i < 0 || i >= this->rows || j < 0 || j >= this->columns) 
			throw std::out_of_range(INDEX_OUT_OF_RANGE_MESSAGE);
		this->elements->Get(i)->Set(element, j);
	}
	
	string ToString()
    {
	    string result = "";
	    for(int i = 0; i < this->GetRows(); i++)
        {
	        for (int j = 0; j < this->GetColumns(); j++)
            {
	            stringstream ss;
	            ss << this->Get(i, j);
	            result += ss.str();
	            result += " ";
            }
	        result += "\n";
        }
        return result;
    }
};