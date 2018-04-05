#include <iostream>
#include <vector>
#include <algorithm>

class Matrix
{
	int row, col;
	int **mat;
	
public:
	Matrix(int row, int col)
	{
		this->row = row;
		this->col = col;
		mat = new int*[row];
		for (int i=0; i<row; i++)
		{
			mat[i] = new int[col];
			std::fill(mat[i], mat[i]+col, 0);
		}
	}

	~Matrix()
	{
		for (int i=0; i<row; i++)
		{
			delete [] mat[i];
		}
		delete [] mat;
		mat = nullptr;
	}
		
	int get_row() const { return row; }
	int get_col() const { return col; }
	int **get_raw_array() { return mat; }
	
	void print()
	{
		for (int r = 0; r < row; r++)
		{
			std::cout << "[";
			for (int c=0; c<col; c++)
			{
				std::cout << mat[r][c] << " ";
			}
			std::cout << "]" << std::endl;
		}
	}
};


void make_mat_row_and_col_all_zero_if_zero_exist(Matrix &mat)
{
	int row_max = mat.get_row();
	int col_max = mat.get_col();
	int **mat_raw = mat.get_raw_array();
	
	// O(raw*col)
	std::vector<std::pair<int,int> > zero_points;
	for (int row = 0; row < row_max; row++)
	{
		for (int col = 0; col < col_max; col++) 
		{
			if (mat_raw[row][col] == 0)
			{
				zero_points.push_back(std::pair<int,int>(row, col));
			}
		}
	}
	
	// O(zero_points.length) <= O(raw*col)
	for (auto zero_point : zero_points)
	{
		int raw = zero_point.first;
		int col = zero_point.second;
		
		for (int r=0; r<row_max; r++) mat_raw[r][col] = 0;
		for (int c=0; c<col_max; c++) mat_raw[raw][c] = 0;
	}
}

void main()
{
	Matrix test_mat(4,3);
	test_mat.get_raw_array()[0][0] = 1;
	test_mat.get_raw_array()[0][1] = 2;
	test_mat.get_raw_array()[0][2] = 3;
	test_mat.get_raw_array()[1][0] = 5;
	test_mat.get_raw_array()[1][1] = 0;
	test_mat.get_raw_array()[1][2] = 9;
	test_mat.get_raw_array()[2][0] = 11;
	test_mat.get_raw_array()[2][1] = 12;
	test_mat.get_raw_array()[2][2] = 0;
	test_mat.get_raw_array()[3][0] = 14;
	test_mat.get_raw_array()[3][1] = 15;
	test_mat.get_raw_array()[3][2] = 16;
	
	std::cout << "init matrix" << std::endl;
	test_mat.print();
	
	make_mat_row_and_col_all_zero_if_zero_exist(test_mat);
	
	std::cout << "after process" << std::endl;
	test_mat.print();
}
