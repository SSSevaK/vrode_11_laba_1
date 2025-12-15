#include <iostream>
#include <vector>
#include <random>
#include <ctime>

void RandInputVec(std::vector<std::vector<int>>&,const int16_t&,const int16_t&, const int16_t& ,int16_t&, int16_t&);
void InputRange(int16_t&);
void Input_Rows_cols(int16_t&,int16_t&);
bool checkinput(int16_t&);
void CheckRange(const int16_t&);
void PtintVec(std::vector<std::vector<int>>&, const int16_t&, const int16_t&);
void Delite_rows_cols(std::vector<std::vector<int>>&, const int16_t&, const int16_t&);
void sortarr(std::vector<std::vector<int>>&, const int16_t&, const int16_t&);

int main()
{
	try
	{
		int16_t rows;
		int16_t cols;
		int16_t max;
		int16_t temp_rows = 0;
		int16_t temp_cols = 0;
		InputRange(max);
		Input_Rows_cols(rows,cols);
		std::vector<std::vector<int>> MyVec(rows,std::vector<int>(cols));
		RandInputVec(MyVec, max, rows, cols, temp_rows, temp_cols);
		PtintVec(MyVec, rows, cols);
		Delite_rows_cols(MyVec,temp_rows,temp_cols);
		std::cout << '\n';
		PtintVec(MyVec, rows-1, cols-1);
		sortarr(MyVec, rows - 1, cols - 1);
		std::cout << '\n';
		PtintVec(MyVec, rows - 1, cols - 1);
	}
	catch (const char* msq)
	{
		std::cout << msq;
	}
}
void RandInputVec(std::vector<std::vector<int>>& MyVec, const int16_t& max, const int16_t& rows, const int16_t& cols, int16_t& temp_rows, int16_t& temp_cols)
{
	srand(time(NULL));
	int16_t numb_max = INT16_MIN;
	for (auto row_it = MyVec.begin(); row_it != MyVec.end(); ++row_it)
	{
		int rows = std::distance(MyVec.begin(), row_it);

		for (auto col_it = row_it->begin(); col_it != row_it->end(); ++col_it)
		{
			int cols = std::distance(row_it->begin(), col_it);

			int32_t numb = rand() % (max + 1);
			*col_it = numb; 
			if (numb > numb_max)
			{
				temp_rows = rows;
				temp_cols = cols;
				numb_max = numb;
			}
		}
	}
}
void InputRange(int16_t& max)
{
	std::cout << "input max > 0 : ";
	if (!checkinput(max))
	{
		throw "uncorret number";
	}
	if (max < 1)
	{
		throw "number < 1";
	}
}
bool checkinput(int16_t& numb)
{
	return(std::cin >> numb) ? true : false;
}
void Input_Rows_cols(int16_t& rows, int16_t& cols)
{
	std::cout << "input rows < 100 : ";
	if (!checkinput(rows))
	{
		throw "uncorret number";
	}
	CheckRange(rows);
	std::cout << "input cols < 100 : ";
	if (!checkinput(cols))
	{
		throw "uncorret number";
	}
	CheckRange(cols);
}
void CheckRange(const int16_t& numb)
{
	if (numb < 1)
	{
		throw "number < 1";
	}
	if (numb > 100)
	{
		throw "number > 100";
	}
}
void PtintVec(std::vector<std::vector<int>>& MyVec, const int16_t& rows, const int16_t& cols)
{
	for (const auto& rows : MyVec)
	{
		for (const auto& cols : rows)
		{
			std::cout << cols;
		}
		std::cout << '\n';
	}
}
void Delite_rows_cols(std::vector<std::vector<int>>& MyVec, const int16_t& rows, const int16_t& cols)
{
	MyVec.erase(MyVec.begin() + rows);
	for (auto& row : MyVec)
	{
		row.erase(row.begin() + cols);
	}
}
void sortarr(std::vector<std::vector<int>>& MyVec, const int16_t& rows, const int16_t& cols)
{
	for (auto& row : MyVec)  
	{
		for (size_t j = 1; j < row.size(); ++j)
		{
			int16_t key = row[j];
			int k = j - 1;

			while (k >= 0 && row[k] > key)
			{
				row[k + 1] = row[k];
				--k;
			}
			row[k + 1] = key;
		}
	}
}
