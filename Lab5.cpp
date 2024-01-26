/********************************************************************************
 * � � � � � � � � � � � �   � � � � � �  �5  � �   5   � � � � � � �   �  +  + *
 *------------------------------------------------------------------------------*
 * Project Type  : Win64 Console Application                                    *
 * Project Name  : Teor_Grph_Lab5                                               *
 * File Name     : Lab5. CPP                                                    *
 * Programmer(s) : ������� �.�.                                                 *
 * Modifyed By   :                                                              *
 * Created       : 24/09/23                                                     *
 * Last Revision : 29/09/23                                                     *
 * Comment(s)    : ���������, ��������� ������������� ���� ����� ����� ���������*
 *                 � �����. ����� ������������ ���������� ��������. ����������� *
 *				   ������ �������� ������� ����� ���������, �������� �������    *
 *				   ����, � ����� ��������                                      *
 ********************************************************************************/


#include <iostream>              // ����������� ������ �����/������
#include <vector>                // ������ � ��������� ��� �������� �������� ���������� � �������� ���������
#include <fstream>               // ������ � �������� �����/������ ��� �����
#include <iomanip>               // ���������� � ������������� setw
#include <graphviz/gvc.h>        // ���������� Graphviz ��� ������������ ����������� ����� �� ������� ���������
#include <opencv2/opencv.hpp>    // ���������, ������������� ��� ������� OpenCv

using namespace std;             // ���������� ������������ ��� std




/*******************************************************************/
/*            � � � � � � � � � �    � � � � � � � � �             */
/*******************************************************************/

// ���� � ����� ����� ����������� ���������
// ������� �����
// ����� ��� ������� ���������
const char* FNAMEIN = "matrix_t5_001.txt";                // ���� � �������� ���������
//const char* FNAMEIN = "matrix_t5_002.txt";                // ���� � �������� ���������
//const char* FNAMEIN = "matrix_t5_003.txt";                // ���� � �������� ���������
//const char* FNAMEIN = "matrix_t5_004.txt";                // ���� � �������� ���������
//const char* FNAMEIN = "matrix_t5_005.txt";                // ���� � �������� ���������
//const char* FNAMEIN = "matrix_t5_006.txt";                // ���� � �������� ���������
//const char* FNAMEIN = "matrix_t5_007.txt";                // ���� � �������� ���������
//const char* FNAMEIN = "matrix_t5_008.txt";                // ���� � �������� ���������
//const char* FNAMEIN = "matrix_t5_009.txt";                // ���� � �������� ���������
//const char* FNAMEIN = "matrix_t5_010.txt";                // ���� � �������� ���������
//const char* FNAMEIN = "matrix_t5_011.txt";                // ���� � �������� ���������
//const char* FNAMEIN = "matrix_t5_012.txt";                // ���� � �������� ���������
//const char* FNAMEIN = "matrix_t5_013.txt";                // ���� � �������� ���������
//const char* FNAMEIN = "matrix_t5_014.txt";                // ���� � �������� ���������

// ����� ��� ������ �����
//const char* FNAMEIN = "list_of_edges_t5_001.txt";         // ���� �� ������� ����
//const char* FNAMEIN = "list_of_edges_t5_002.txt";         // ���� �� ������� ����
//const char* FNAMEIN = "list_of_edges_t5_003.txt";         // ���� �� ������� ����
//const char* FNAMEIN = "list_of_edges_t5_004.txt";         // ���� �� ������� ����
//const char* FNAMEIN = "list_of_edges_t5_005.txt";         // ���� �� ������� ����
//const char* FNAMEIN = "list_of_edges_t5_006.txt";         // ���� �� ������� ����
//const char* FNAMEIN = "list_of_edges_t5_007.txt";         // ���� �� ������� ����
//const char* FNAMEIN = "list_of_edges_t5_008.txt";         // ���� �� ������� ����
//const char* FNAMEIN = "list_of_edges_t5_009.txt";         // ���� �� ������� ����
//const char* FNAMEIN = "list_of_edges_t5_010.txt";         // ���� �� ������� ����
//const char* FNAMEIN = "list_of_edges_t5_011.txt";         // ���� �� ������� ����
//const char* FNAMEIN = "list_of_edges_t5_012.txt";         // ���� �� ������� ����
//const char* FNAMEIN = "list_of_edges_t5_013.txt";         // ���� �� ������� ����
//const char* FNAMEIN = "list_of_edges_t5_014.txt";         // ���� �� ������� ����

// ����� ��� ������ ���������
//const char* FNAMEIN = "list_of_adjacency_t5_004.txt";     // ���� �� ������� ���������
//const char* FNAMEIN = "list_of_adjacency_t5_005.txt";     // ���� �� ������� ���������
//const char* FNAMEIN = "list_of_adjacency_t5_013.txt";     // ���� �� ������� ���������
//const char* FNAMEIN = "list_of_adjacency_t5_014.txt";     // ���� �� ������� ���������

// �������� �����
const char* FNAMEOUT1 = "Output_File.txt";
const char* FNAMEOUT2 = "Vertex_beg.txt";
const char* FNAMEOUT3 = "Vertex_end.txt";
// ������������� ��� ������� ����������
const int INF = 10000;




/*******************************************************************/
/*      � � � � � � � � � �    � � � � � � � �    � � � � � �      */
/*******************************************************************/

 // ���������� ������� ��� ���������� ����� ������ �� �����
ifstream fin;
// ���������� ������� ��� ���������� ������ ������ � ����
ofstream fout;




/*******************************************************************/
/*                 � � � � � � � �   � � � � � � �                 */
/*******************************************************************/

/*------------------------------------------------------------------------*/
/*                 Graph                  */
/*----------------------------------------*/

class Graph
{
private:
	vector<vector<int>> m_matrix;                             // ���� � ��������� ����������� �������� ���������
	int m_size;                                               // ������ ������� ��������� (���������� ������ � �����)

public:
	// �����������
	Graph();
	// ����������
	~Graph();
	// ����������� ������ ��� ��������� �������� �������
	const int GetSize();
	// ������� ������������ True, ���� ���� ���������������, False, ���� ���� �������;
	bool is_directed();
	// �������, ������������ ������� ���������
	vector<vector<int>> adjacency_matrix();
	// ������� �������, ��������� ������ ������, ���������� ��� �����, ������������ ��;
	int Weight(int Vi, int Vj);
	// �������, ����������� ������ ������ � ���������� True, ���� � ����� ���� ��������������� ����� / ����, False, ���� ����� ���;
	bool is_edge(int Vi, int Vj);
	// �������, ������������ ������ ������, ������� ������� v;
	vector<int> adjacency_list(int v);
	// �������, ������������ ������ ���� ���� �����;
	vector<pair<int, int>> list_of_edges_pairs();
	// � �������, ������������ ������ ���� ���� �����, ����������� ������� v / ��������� �� ������� v
	vector<pair<int, int>> list_of_edges(int v);
};




/*******************************************************************/
/*              � � � � � � � � �    � � � � � � �                 */
/*******************************************************************/

// ���������� ����� ��� ����������
string drawGraph(const vector<vector<int>>& adjacencyMatrix);     // ���������� ����������� ������ �� ��������� ������ adjacencyMatrix, ���������� ������������� �������� 

// ����� ����� �� ����� � ���� ��������
void OpenImage(const vector<vector<int>>& adjacencyMatrix);       // ���������� ����������� ������ �� ��������� ������ adjacencyMatrix, ���������� ������������� �������� 

// ����� ������� ��������� �� �����
void PrintMatrix(vector<vector<int>> matrix);                     // �������, ������� ���������� ������� �� �����. �������� �� ��������

// ������ ������� � ������� ������
void Usloviya();

// ��������������� ������� ��� ���������� ������� ������� � ����������� �����������
int findMinDistance(vector<int> distance,                         // ������ ���������� �� ��������� ������� �� ���� ���������
	                vector<bool> visited);                        // ������������ ������

// ����� ������������� ����
vector<int> printPath(vector<vector<int>> graph,                  // ������� ��������� �����
	                  vector<int> previous,                       // ������ ���������� ������ ��� ������
	                  vector<int> distance,                       // ���������� �� �������� �� ��������� ������ �����
	                  int start,                                  // ��������� ������� ������������� ����
	                  int end);                                   // �������� ������� ������������� ����

// �������� �������� ��� ���������� ����������� ���� � ������ ������ ������������� ����
vector<int> Dijkstra(vector<vector<int>> graph,                          // ������� ��������� �����
	          int start,                                          // ��������� ������� ����
	          int end);                                           // �������� ������� ����




// ����������� - ���������� ������� �� �����
Graph::Graph()
{
	fin.open(FNAMEIN);            // ��������� ������ � ������
	if (!fin.is_open())           // ���� �� ������
	{
		cout << "����� � ����� ������ ���. ���������� ����������� ������";
		fin.close();              // ������� ���� ��� ������
		system("pause");
		exit(0);                  // ���������� ��������, ��������������� ���� � caller
	}// if (!fin.is_open())

	int value;                    // ��������� ����������� ������
	char key;                     // ���� ��� �������� ������������� �������� ������� ����� � �����
	bool spravka = true;          // ���� ��� ������ ������� �� �����
	vector<int> row;              // ������ ��� ���������� ������������� �������� �� ����� ���������
	vector<vector<int>> matrix;   // ��������������� ������� ���������

	// ������ ����� ������� �����, ����� ������������ ������� ������� �� ����� �������
	while (spravka)
	{
		cout << "\x1b[30m � � � � � � �   � � � �   � � �   <h>   � � �   � � � � � �   � � � � � � � � � : \x1b[30m";
		// ������������ ��� ���� ��� ����, ����� ���� �������, ����� �������� �� ����� ����
		cin >> key;
		cout << "\n �� �����: " << key << endl;

		// � ����������� �� �������� �����
		switch (key)
		{
			// ������ � �������� ���������
		case('m'):
		case('M'):
		{
			cout << "\n\t\t\t\t\x1b[32m � �   � � � � � � �   � � �   � � � � � � �   -   � � � � � � �   � � � � � � � � �\n\n\x1b[30m\n";
			// ��������� ��������� ����� �� �����
			while (fin >> value)
			{
				// ����� ���������� ������ ������ ������� ������ ������
				row.clear();
				// �������� � ������ ������ ��������� ������� �� ������� while (fin >> value)
				row.push_back(value);
				// ��������� ��� ��������� �������� ������, ���� �� ����� ������ � ��������� - \n
				while (fin.peek() != '\n' && fin >> value)
				{
					row.push_back(value);
				}// while (fin.peek() != '\n' && fin >> value)

				// ������ � ������� ��������� ������. ��� ������ ����� ���������� ������, ��� ��� �������� � �������� ���������
				m_matrix.push_back(row);

			}// while (fin >> value)

			// ��������� ���� �� ����. ������� ���������
			spravka = false;
			break;
		}

		// ������ �� ������� ����
		case('e'):
		case('E'):
		{
			cout << "\n\t\t\t\t\x1b[32m � �   � � � � � � �   � � �   � � � � � � �   -   � � � � � �   � � � � �\n\n\x1b[30m\n";

			// ��������� �������� �� ����� � ������
			// � ������� ����� ���������� � ������������ ����� ��� ��������: ��������� �������, �������� ������� � ��� �����
			while (fin >> value)
			{
				// ����� ���������� ������ ������ ������� ������ ������
				row.clear();
				// �������� � ������ ������ ��������� ������� �� ������� while (fin >> value)
				row.push_back(value);
				// ��������� ��� ��������� �������� ������, ���� �� ����� ������ � ��������� - \n
				while (fin.peek() != '\n' && fin >> value)
				{
					row.push_back(value);
				}// while (fin.peek() != '\n' && fin >> value)

				// ������ � ������� ��������� ������. ��� ������ ����� ���������� ������, ��� ��� �������� � �������� ���������
				m_matrix.push_back(row);
			}// while (fin >> value)

			// ������� ���� ������
			fin.close();
			int size_m = m_matrix[m_matrix.size() - 1][0];    // ������ ������� ���������
			vector<vector<int>> vec_1(size_m);                // ������� ���������

			for (int i = 0; i < size_m; i++)                  // ����� ������ ������ ������ vec_1
			{
				vec_1[i].resize(size_m, 0);
			}// for i

			// ��������� ������� ���������
			for (int i = 0; i < m_matrix.size(); i++)
			{
				if (m_matrix[0].size() == 3)                  // 3 ������� - ��� ��� �����, ���� �� �� ������, �� ������ �� = 1
				{
					vec_1[m_matrix[i][0] - 1][m_matrix[i][1] - 1] = m_matrix[i][2];
				}
				else
				{
					vec_1[m_matrix[i][0] - 1][m_matrix[i][1] - 1] = 1;
				}// if (m_matrix[0].size() == 3)
			}// for i

			// ���������� ������� ���������
			m_matrix = vec_1;
			// ��������� ���� �� ����. ������� ���������
			spravka = false;
			break;
		}

		// �������� �� �������� ���������
		case('l'):
		case('L'):
		{
			cout << "\n\t\t\t\t\x1b[32m � �   � � � � � � �   � � �   � � � � � � �   -   � � � � � �   � � � � � � � � �\n\n\x1b[30m\n";

			// ������ �� ����� ���������
			string line;
			int rowNumber = 0;            // ����� ������� ������

			// ������ ����������
			while (getline(fin, line))
			{
				// ���� ������ ������, ��������� ������� ������ ������
				if (line.empty())
				{
					matrix.push_back(std::vector<int>(m_size, 0));
				}
				// ������ �� ������
				else
				{
					// ������ ������
					vector<int> row;
					// ������� ����� ��� ������ �������� �� ������ line. ����� �� ����� ������������ iss ������ � ���������� >> ��� ���������� �������� �� ������.
					istringstream iss(line);
					// ��������� �������� ��� ������
					int value;

					// ������ �������� �� ����� � �������� ��� � ������ ������
					while (iss >> value)
					{
						row.push_back(value);
					}// while

					// �������� ������ � �������
					matrix.push_back(row);
				}// if (line.empty()) 

				// ����������� ����� ������
				rowNumber++;
			}// while (getline(fin, line)) 

			// ���� �������� - ��������� ���
			fin.close();

			m_size = matrix.size();                         // ������ ������� ���������

			std::vector<std::vector<int>> vec_1(m_size);    // ��� ������� ��������� �������� m_size

			for (int i = 0; i < m_size; i++)                // ����� ������ ������ ������ ��� ������� ���������
			{
				// ��������� ��������������� ������� ������ �� ����� �������
				vec_1[i].resize(m_size, 0);
			}// for i

			for (int i = 0; i < m_size; i++)                 // ��������� ��� ������� ��������� 
			{
				for (int j = 0; j < matrix[i].size(); j++)
				{
					// ������� � ��� ��������, ������� ����������� ��� ������ � �����
					vec_1[i][matrix[i][j] - 1] = 1;
				}// for j
			}// for i

			// �������� �������� � �������� ������� ���������
			for (int i = 0; i < m_size; i++)
			{
				row.clear();
				for (int j = 0; j < m_size; ++j)
				{
					row.push_back(vec_1[i][j]);
				}// fot j

				m_matrix.push_back(row);
			}// for i

			// ��������� ���� �� ����. ������� ���������
			spravka = false;
			break;
		}

		// ������������ ������ �������
		case('h'):
		case('H'):
		{
			// ��������� ���� ����� ��������� ������� �� ������
			spravka = true;
			// ������� �������
			Usloviya();
			break;
		}

		// ���� ��������� ������� ����
		case('n'):
		case('N'):
		{
			// ����� ��������� �������, �������� ������������� � ����������
			int beg;
			// ��������� ���� ����� ��������� ������� �� ������
			spravka = true;
			cout << " ������� ��������� �������: ";
			cin >> beg;
			cout << endl;
			// ���������� ������� � ����
			fout.open(FNAMEOUT2);          // ��������� ������ � ������
			if (!fout.is_open())           // ���� �� ������
			{
				cout << " ����� � ����� ������ ���. ���������� ����������� ������";
				system("pause");
				exit(0);     // ���������� ��������, ��������������� ���� � caller
			}// if (!fout.is_open())
			// ������� ��������� ������� � ����
			fout << beg;
			// ��������� ���� ������
			fout.close();
			break;
		}

		case('d'):
		case('D'):
		{
			// ����� �������� �������, �������� ������������� � ����������
			int end;
			// ��������� ���� ����� ��������� ������� �� ������
			spravka = true;
			cout << " ������� �������� �������: ";
			cin >> end;
			cout << endl;
			fout.open(FNAMEOUT3);          // ��������� ������ � ������
			// ���������� ������� � ����
			if (!fout.is_open())           // ���� �� ������
			{
				cout << " ����� � ����� ������ ���. ���������� ����������� ������";
				system("pause");
				exit(0);     // ���������� ��������, ��������������� ���� � caller
			}// if (!fout.is_open())
			// ������� �������� ������� � ����
			fout << end;
			// ��������� ���� ������
			fout.close();
			break;
		}

		// ����� - ������������ ��� �� ��� ����. ����������� ��������� � �������
		default:
			cout << "\n\x1b[31m ������������� ��������� � ������� �������� �� ������ ������!!!\n\x1b[30m";
			// ��������� ���� ����������
			fin.close();
			exit(0);
		}
	}
	// ��������� ���� ����������
	fin.close();
	// ���������� ������ ���������/ ��������������� ������� ���������
	m_size = m_matrix.size();
}

// ����������
Graph::~Graph()
{
	// ������ ���� - ������� ������������ �������������
}

// ������ ��� ��������� �������� �������
const int Graph::GetSize()
{
	return(m_size);
}


// ������� ������������ True, ���� ���� ���������������, False, ���� ���� �������;
bool Graph::is_directed()
{
	// ��� �� �������
	for (int i = 0; i < m_size; i++)
	{
		// ��� �� ��������
		for (int j = 0; j < m_size; j++)
		{
			// ���� ���� �����������������, �� ������� �����������, ��� ��� �� ����� ����� ������ ������ ������������
			if (m_matrix[i][j] != m_matrix[j][i])
			{
				return true; // ������� ������������ ����� - ���� ���������������
			}// if (m_matrix[i][j] != m_matrix[j][i])

		}// for j

	}// for i

	return false; // �� ������� ������������ ����� - ���� �����������������
}


// �������, ������������ ������� ���������
vector<vector<int>> Graph::adjacency_matrix()
{
	return(m_matrix);
}


// ������� �������, ��������� ������ ������, ���������� ��� �����, ������������ ��;
int Graph::Weight(int Vi, int Vj)

{
	// ������ ������ ����� �� ��������� ���������� ��������
	if ((Vi >= m_size || Vi < 0) || (Vj >= m_size || Vj < 0))
	{
		cout << "������! ����� ������� �� ����������\n";
		// ������� ������
		return(-1);
	}

	// ���� ���� ����������(� ������� ��������� �� 0)
	if (m_matrix[Vi][Vj] != 0)
	{
		cout << "��� ����� ����� ��������� " << Vi << " � " << Vj << " �����" << m_matrix[Vi][Vj] << endl;
		cout << m_matrix[Vi][Vj] << endl;
		// ���������� ��� ����� ����� ���������
		return(m_matrix[Vi][Vj]);
	}

	// ���� ���������������. ������� ��� ����
	else if ((m_matrix[Vi][Vj] != m_matrix[Vj][Vi]) && (m_matrix[Vi][Vj] != 0 || m_matrix[Vj][Vi] != 0))
	{
		cout << "���� ���������������. ���� ����. ����������� �����������. ��� ���� ����� ��������� " << Vi << " � " << Vj << " �����" << m_matrix[Vi][Vj] << endl;
		// ���������� ��� ����
		return(m_matrix[Vi][Vj]);
	}

	// ����� ����� ��������� ��� - ������� ������� ��������� ����� 0
	else if (m_matrix[Vi][Vj] == 0)
	{
		cout << "����� ����� ��������� " << Vi << " � " << Vj << "���\n";
		// ������� ������� ��������
		return(m_matrix[Vi][Vj]);
	}

	return(0);
}


// �������, ����������� ������ ������ � ���������� True, ���� � ����� ���� ��������������� ����� / ����, False, ���� ����� ���;
bool Graph::is_edge(int Vi, int Vj)
{
	// ������ ������ ����� �� ��������� ���������� �������� - ���� ���
	if ((Vi >= m_size || Vi < 0) || (Vj >= m_size || Vj < 0))
	{
		// �������, ��� ���� ���
		return(false);
	}

	// ������� ������� ��������� �� ����� 0 - ����� ����
	if (m_matrix[Vi][Vj] != 0)
	{
		// ������������, ��� ����� ����
		return(true);
	}

	// ������� ������� ��������� ������� - ����� ���
	if (m_matrix[Vi][Vj] == 0)
	{
		// ������������, ��� ����� ���
		return(false);
	}

}


// �������, ������������ ������ ������, ������� ������� v;
vector<int> Graph::adjacency_list(int v)
{
	// ������ ������
	vector<int> adjList;

	// �������� �� ���� �������� � ���������, ���� �� ����� ����� �������� v � ������� ��������
	for (int i = 0; i < m_size; i++)
	{
		// ���� ���� - ������� ������� �� �������
		if (m_matrix[v][i] != 0)
		{
			// �������� ������� � ������
			adjList.push_back(i);
		}// if (m_matrix[v][i] != 0)

	}// for i

	// ���������� ������ ������� ������
	return adjList;
}


// �������, ������������ ������ ���� ���� �����;
vector<pair<int, int>> Graph::list_of_edges_pairs()
{
	// ������ ���, ���������� ����� � ���� ���� ����������� ��� ������
	vector<pair<int, int>> edges_pairs;
	// ��� �� ���� ��������� ������
	for (int i = 0; i < m_size; i++)
	{
		// ��� �� ���� ��������� �������
		for (int j = 0; j < m_size; j++)
		{
			// ���� ������� �� �������
			if (m_matrix[i][j] != 0)
			{
				// ��������� ���� ������
				edges_pairs.push_back(make_pair(i, j));
			}// if (m_matrix[i][j] != 0)
		}// for j
	}// for i

	// ������� ������ ���� (��� ������)
	return(edges_pairs);
}


// �������, ������������ ������ ���� ���� �����, ����������� ������� v / ��������� �� ������� v
vector<pair<int, int>> Graph::list_of_edges(int v)
{
	int count = 0;
	vector<pair<int, int>> edges;         // ������ ��� ������(������ ����)
	vector<pair<int, int>> edges_inc;     // ������ ���� ����������� ������� v / ��������� �� ������� v
	edges = list_of_edges_pairs();        // �������� ��� ���� ������ �����

	// ������� ��� ����. ���� ���� �����������������, �� ��� ����� ���� (v,n) � (n, v) - ���������� ����������� ��� ������������� ������ �������. � ������� - ��������� ������� ������ ������
	for (int i = 0; i < edges.size(); i++)
	{
		// ������������� ������ ������� ����
		if (edges[i].first == v)
		{
			// �������� � ����� �����, ����������� ������� ������ �����
			edges_inc.push_back(edges[i]);
			// ����������� �������
			count = count + 1;
		}//if (edges[i].first == v)
	}//for i

	// ����������  ������ ���� ���� �����, ����������� ������� v / ��������� �� ������� v
	return(edges_inc);
}





/*------------------------------------------------------------------------*/
/*                �������               */
/*--------------------------------------*/

// ���������� ����� ��� ����������
string drawGraph(const vector<vector<int>>& adjacencyMatrix)
{
	// ��������� ������ ������� ���������. ���� ������ 19, �� ������� �� ������� �������
	if (adjacencyMatrix.size() <= 19)
	{
		bool key = false;
		// ��������� ������� ����� �� ������, ����� ������, ����� �� ��������� �� ��� ������
		for (int i = 0; i < adjacencyMatrix.size(); i++)
		{
			for (int j = 0; j < adjacencyMatrix.size(); j++)
			{
				// ���� ��� ����� ������ 1 ��� �������������, ������, ����� ��������� ��� � ������
				if (adjacencyMatrix[i][j] > 1 || adjacencyMatrix[i][j] < 0)
					key = true;
			}
		}

		// ��������� ���� ��� ������ ����� � ������� DOT
		std::ofstream file;
		file.open("graph.dot");
		file << "digraph G {" << endl;

		if (key)
		{
			// ������� ���� � ��������� ����� �����
			for (int i = 0; i < adjacencyMatrix.size(); i++)
			{
				for (int j = 0; j < adjacencyMatrix[i].size(); j++)
				{
					// ���������, ��� ��� ����� �� ����� 0, ����� �� �������� �������� �����
					if (adjacencyMatrix[i][j] != 0)
					{
						// ������� ����� � ��������� ���� � ������� DOT
						file << i << " -> " << j << " [label=\"" << adjacencyMatrix[i][j] << "\"];" << endl;
					}// if (adjacencyMatrix[i][j] != 0) 
				}// for j
			}// for i
		}

		else
		{
			// ������� ���� ��� �������� ����� �����
			for (int i = 0; i < adjacencyMatrix.size(); i++)
			{
				for (int j = 0; j < adjacencyMatrix[i].size(); j++)
				{
					// ���������, ��� ��� ����� ����� 1, ����� �� �������� �������� �����
					if (adjacencyMatrix[i][j] == 1)
					{
						// ������� ����� ��� �������� ���� � ������� DOT
						file << i << " -> " << j << ";" << endl;
					}//if (adjacencyMatrix[i][j] == 1) 
				}// for j
			}// for i
		}// if key

		// ��������� ���� � ��������� ����������
		file << "}" << std::endl;
		file.close();

		// ���������� ����������� ����� � ������� PNG � ������� ������� DOT
		system("dot -Tpng graph.dot -o graph.png");
		cout << "\n\nGraph image saved as graph.png" << endl;
	}

	// �������, ��� ���� ������� ��� ���������
	else
	{
		cout << "\n\nGraph image is not saved as graph.png. It is too big" << endl;
	}

	// ���������� �������� ��� �������� ������ OpenCV
	return "graph.png";
}


// ����� ����� �� �����
void OpenImage(const std::vector<std::vector<int>>& adjacencyMatrix)
{
	// ��������� ����������� ������� ���������
	if (adjacencyMatrix.size() <= 19)
	{
		// �������� ���� � �����������, ���������� � ������� ������� drawGraph
		std::string imagePath = drawGraph(adjacencyMatrix);
		// ��������� ����������� � ������� OpenCV
		cv::Mat img = cv::imread(imagePath, -1);

		// ���������, ������� �� ��������� �����������
		if (img.empty()) {
			cout << "Could not open or find the image" << endl;
			return;
		}

		// ������� ���� � ��������� "Graph"
		cv::namedWindow("Graph", cv::WINDOW_NORMAL);
		// ���������� ����������� � ����
		cv::imshow("Graph", img);
		// ����, ���� ������������ ������ ����� �������
		cv::waitKey(0);
		// ��������� ����
		cv::destroyWindow("Graph");
		return;
	}// if (adjacencyMatrix.size() <= 19)
}


// ����� ������� ��������� �� �����
void PrintMatrix(vector<vector<int>> matrix)
{
	// ��������� ������� ����
	setlocale(0, "C");            // ������� ������ � �������� �������
	cout << setw(2) << setfill(' ') << (char)218 << (char)196 << (char)196 << setw(matrix.size() * 2 + 7) << setfill(' ') << (char)196 << (char)196 << (char)191 << endl;          // ����� ������� ���������� ������

	// ��� �� �������
	for (int i = 0; i < matrix.size(); i++)
	{
		cout << setw(5) << setfill(' ');
		// ��� �� ��������
		for (int j = 0; j < matrix.size(); j++)
		{
			// ������� ������� �������
			cout << matrix[i][j] << " ";
		}// for j

		cout << endl;
	}// for i
	cout << setw(2) << setfill(' ') << (char)192 << (char)196 << (char)196 << setw(matrix.size() * 2 + 7) << setfill(' ') << (char)196 << (char)196 << (char)217 << endl;          // ����� ������� �������
	// ���������� ������� ����
	setlocale(LC_ALL, "Russian");

	// ���������� ��������� ��������
	return;
}


// ������ ������� � ������� ������
void Usloviya()
{
	cout << "\n\t\t\t\t/********************************************************************************\n";
	cout << "\t\t\t\t* � � � � � � � � � � � �   � � � � � �  �5  � �   5   � � � � � � �   �  +  +  *\n";
	cout << "\t\t\t\t*-------------------------------------------------------------------------------*\n";
	cout << "\t\t\t\t* Project Type  : Win64 Console Application                                     *\n";
	cout << "\t\t\t\t* Project Name  : Teor_Grph_Lab5                                                *\n";
	cout << "\t\t\t\t* File Name     : Lab5. CPP                                                     *\n";
	cout << "\t\t\t\t* Programmer(s) : ������� �.�.                                                  *\n";
	cout << "\t\t\t\t* Modifyed By   :                                                               *\n";
	cout << "\t\t\t\t* Created       : 24/09/23                                                      *\n";
	cout << "\t\t\t\t* Last Revision : 29/09/23                                                      *\n";
	cout << "\t\t\t\t********************************************************************************/\n";

	cout << "\n\t\t\t\t\t\t\t\x1b[31m   � � � � � � � : \n\n\x1b[30m";
	// ������� ������� � �������
	setlocale(0, "C");                       // ��������� ������� ����
	cout << char(218) << setw(40) << setfill((char)196) << (char)191 << endl << (char)179;  // ������� ������� ������ �����
	setlocale(LC_ALL, "Rus");                // ���������� ������� ����
	cout << " �������� ���� ������� �� ������:      ";
	setlocale(0, "C");                       // ��������� ������� ����
	cout << (char)179 << endl << (char)195 << setw(5) << setfill((char)196) << (char)194 << setw(35) << setfill((char)196) << (char)180 << setfill(' ') << endl << (char)179;    // ������� ������ ������ ����� � ������������ ����� ������� � ��������� ���������
	cout << "  e " << (char)179 << "  Edges_list_file_path            ";                                                                                                         // ������� ������� ������ � ������ � �������� ��������� �������
	cout << (char)179 << endl << (char)195 << setw(5) << setfill((char)196) << (char)197 << setw(35) << setfill((char)196) << (char)180 << endl << (char)179;
	cout << "  m " << (char)179 << "  Adjacency_matrix_file_path      ";
	cout << (char)179 << endl << (char)195 << setw(5) << setfill((char)196) << (char)197 << setw(35) << setfill((char)196) << (char)180 << endl << (char)179;
	cout << "  l " << (char)179 << "  Adjacency_list_file_path        ";
	cout << (char)179 << endl << (char)195 << setw(5) << setfill((char)196) << (char)197 << setw(35) << setfill((char)196) << (char)180 << endl << (char)179;
	cout << "  n " << (char)179 << "  Begin_vertex_number             ";
	cout << (char)179 << endl << (char)195 << setw(5) << setfill((char)196) << (char)197 << setw(35) << setfill((char)196) << (char)180 << endl << (char)179;
	cout << "  d " << (char)179 << "  End_vertex_number               ";
	cout << (char)179 << endl << (char)195 << setw(5) << setfill((char)196) << (char)197 << setw(35) << setfill((char)196) << (char)180 << endl << (char)179;
	cout << "  o " << (char)179 << "  Output_file_path                ";
	cout << (char)179 << endl << (char)192 << setw(5) << setfill((char)196) << (char)193 << setw(35) << setfill((char)196) << (char)217 << endl;
	cout << endl;
	setlocale(LC_ALL, "Rus");               // ���������� ������� ����
	
	// ������� ��������� ��������
	return;                                 // ���������� ��������� ��������
}



// ��������������� ������� ��� ���������� ������� ������� � ����������� �����������
int findMinDistance(vector<int> distance,                         // ������ ���������� �� ��������� ������� �� ���� ���������
	                vector<bool> visited)                         // ������������ ������
{
	int minDistance = INF;                                        // ����������� ���������� - �������������
	int Dindex = -1;                                              // ���������� ����� �������� ������� �� ������� �������

	// ��� �� ���� ��������������� �������� � �������� ��, �� ������� ���������� ����������
	for (int i = 0; i < distance.size(); i++)
	{
		if (visited[i] == false && distance[i] < minDistance) 
		{
			minDistance = distance[i];                            // ���������� ����������
			Dindex = i;                                           // ���������� � �����
		}// if (visited[i] == false && distance[i] < minDistance) 
	}// for i

	// ������� ��������� ��������
	return Dindex;
}


// ����� ������������� ����
vector<int> printPath(vector<vector<int>> graph,                  // ������� ��������� �����
	                  vector<int> previous,                       // ������ ���������� ������ ��� ������
	                  vector<int> distance,                       // ���������� �� �������� �� ��������� ������ �����
	                  int start,                                  // ��������� ������� ������������� ����
	                  int end)                                    // �������� ������� ������������� ����
{
	vector<int> path;                                             // ������ ����
	int Weight = distance[end];                                   // ����� ���� �� ��������� ������� ���� �� �������� - ��� ��� �������, ���������� ��� �������� �������� ������� ����
	int current = end;                                            // ��������� � ������ ���� �������� ������, ������� � ��������

	// ���� �� ����� �� ���������
	while (current != start)
	{
		// � ����� ������� ��������� ��������� ������� ���� � �������� �������
		path.push_back(current);

		// ��� ������ ��������� �������, ���� � ������
		current = previous[current];
	}// while

	// ��������� ��������� ������� ���� ��� ��������� � �������
	path.push_back(start);

	// ������������� ������ ������, ��� �� ��������� ����� - ���������, ������� ����� ������������� ��� � �����
	// ������� ����� ����
	cout << "\n\u001b[31m � � � � �   � � � � � � � �   � � � � �   � � � � � � � � � :\x1b[30m";
	cout << "\n Shortest path length between " << start + 1 << " and " << end + 1 << " vertices: " << Weight << endl;

	cout << "\n\u001b[36m � � � � � � �   � � � � �   � � � � � � � � � :\x1b[30m\n";
	// ������� ������������� ���� � ���� ���� ������, ������������ ����� � ��� ���, ���� ���� �� ���������
	cout << " Vertices of a geodesic chain from the vertex " << start + 1 << " to " << end + 1 << ": " << endl;
	cout << " [";
	// �������� �������� ���� ������ � �����
	for (int i = path.size() - 1; i > 0; i--)
	{

		cout << "(";
		// ������� ������� �������
		cout << path[i] + 1 << " ";
		// � ��������� - ���������� �����
		cout << path[i - 1] + 1 << " ";
		// ���� ���� ������� �� �� ��������� ���� ������� ��� ��������������� �����
		if (graph[path[i]][path[i - 1]] != 1)
		{
			cout << graph[path[i]][path[i - 1]];
		}// if (graph[path[i]][path[i - 1]] != 1)

		if (i != 1)
		{
			cout << ") ";
		}
		else 
		{
			cout << ")";
		}// if (i != 1)
	}// for i

	cout << "]\n";
	cout << endl;

	// ������� ��������� ��������
	return path;
}


// �������� �������� ��� ���������� ����������� ���� � ������ ������ ������������� ����
vector<int> Dijkstra(vector<vector<int>> graph,                   // ������� ��������� �����
	          int start,                                          // ��������� ������� ����
	          int end)                                            // �������� ������� ����
{
	// ������ ������
	vector<int> error(1, -INF);

	// ���������� ������ � �����
	int Vertices = graph.size();

	// ������ ���������� �� ������ �������. ���������� ��� ��������, � �� Vertices ���� �������� ���������������
	vector<int> distance(Vertices, INF);

	// �� ���� ������� ����� �� ��������
	vector<bool> visited(Vertices, false);

	// ���������� ������� ��� ������, �� ������� �� � �� ������
	vector<int> previous(Vertices, INF);

	// ��������� ������� ���� � ���� ������ �� ����� -> ��������� ����� ����
	distance[start] = 0;

	// ������ � ����� �� ������������� �� 1 ����� ������, ��� ��� ��������� ��� ���������
	for (int i = 0; i < Vertices - 1; i++) 
	{
		// ������� ��������������� ������� ������ �� �������������, ��� ������� ���������� �� �������� ����������
		int current = findMinDistance(distance, visited);

		// ���� ��� ������������ ������ � ���� �� ������ - ����������� ���������
		if (current == -1)
		{
			// ���� �� ������
			cout << " There is no path between the vertices " << start+1 << " and " << end+1 << ".\n";
			// ���������� ��������� ��������
			return (error);
		}// if (current == -1)

		// ��� ������� ���������� � ������� ��� ����������
		visited[current] = true;
		
		// ���� ����� �������, ���� �������� ������� ��������� - �� ����� �����, ��� ���������� �� �� �����������
		if (visited[end] == true)
		{
			break;
		}// if (visited[end] == true)

		for (int j = 0; j < Vertices; j++) 
		{	// ���������� ��� ��� ������� ������� � ������(� ���������� �����) �� ������� ��������� �� ��������� ��������:
			// ���� ������� �� �������� � ���������� ���� �� ������ �������, ������ ����� ����� �� ������ ������� �� ����� ������ ���� ������, ��� ����, ������� ��� ������ �� ����� ��� ����� �������
			if (graph[current][j] != 0 && visited[j] == false && distance[current] + graph[current][j] < distance[j])
			{
				// ������������� ��� ����� ������� ����� �������� ����
				distance[j] = distance[current] + graph[current][j];

				// ��������� ��� ��� ���������� �������, �� ������� ������
				previous[j] = current;
			}// if
		}// for j
	}// for i

	// ������� ���� �� �����
	return(printPath(graph, previous, distance, start, end));
}




/*------------------------------------------------------------------------*/
/*            ������� �������           */
/*--------------------------------------*/
int main()
{
	// ���������� ������� ����
	setlocale(LC_ALL, "Russian");
	// ���� ������� - �����
	system("color F0");
	// ���� ������ � ����. ���������� - ������ ���
	bool print = false;
	// ����, �������� ������������� ��� ������
	char letter;

	cout << "\t\t\t\t\t\t\x1b[34m    � � � � � �   �   � � � � � � �\x1b[30m\n\n\n";
	// ������� ������ �����. ����������� ���������� ��-���������
	Graph NewGraph;

	// �����, ����� �� ������������ �������� � ���� ����������� ����������
	cout << " ������ �� �� �������� ������ � ����? ������� <o>, ���� ������, ��� ����� ������ ������ - ���� ���. �������: ";
	cin >> letter;                             // ���� �������������
	cout << " �� �����: " << letter;         // ���-������

	// ���� ������������ ����� ��������. ������������� ����
	if (letter == 'o' || letter == 'O')
	{
		print = true;
	}// if (letter == 'o' || letter == 'O')

	// ������� �� ����� ������� ���������
	cout << "\n\n\x1b[35m � � � � � � �   � � � � � � � � �   � �   � � � � � � � �   � � � � � � :\x1b[30m\n\n";
	PrintMatrix(NewGraph.adjacency_matrix());

	// ���������� ��������� ������� ���� �� �����
	int startVertex = -1;         // ��������� �������
	// ��������� ���� ������
	fin.open(FNAMEOUT2);
	if (!fin.is_open())           // ���� �� ������
	{
		cout << "\u001b[31m ����� � ����� ������ ���. ���������� ����������� ������ ��������� �������\x1b[30m";
		fin.close();              // ������� ���� ��� ������
		system("pause");

		return -1;                // ������� � �������
	}// if (!fout.is_open())

	// ���� ������ - ������
	if (fin.peek() == ifstream::traits_type::eof())
	{
		cout << "\u001b[31m ���� ��������� ������� ������.\n";
		cout << " ������� ��������� ������� � ������������� ���������!!\x1b[30m\n";
		// ������� � �������
		return -2;
	}// if
	
	// ��������� ��������� �������
	fin >> startVertex;
	// ��������� ���� ������
	fin.close();
	// ������� ���� ����� ��� ���������� �������
	ofstream fout (FNAMEOUT2,fstream::trunc);
	fout.close();  // ��������� ����
	// ���-������ ��������� �������
	cout << "\u001b[33m ��������� �������:\x1b[30m " << startVertex << endl;

	// ������ �� ����� ��������� ������� �� ������� ��������� ������ �����
	if (startVertex < 0 || startVertex - 1 > NewGraph.GetSize() - 1)
	{
		cout << "\u001b[31m ��������� ������� ������� �� ������� ������ �����!!!\x1b[30m\n";
		// ������� � �������
		return -3;
	}// if


	// ���������� �������� ������� ���� �� �����
	int endVertex = -1; // �������� �������
	// ��������� ���� ������
	fin.open(FNAMEOUT3);
	if (!fin.is_open())           // ���� �� ������
	{
		cout << "\u001b[31m ����� � ����� ������ ���. ���������� ����������� ������ �������� �������\x1b[30m";
		fin.close();              // ������� ���� ��� ������
		system("pause");
		return -4;                // ������� � �������
	}// if (!fin.is_open())

	// ���� ������ - ������
	if (fin.peek() == ifstream::traits_type::eof())
	{
		cout << "\u001b[31m ���� �������� ������� ������.\n";
		cout << " ������� �������� ������� � ������������� ���������!!\x1b[30m\n";
		// ������� � �������
		return -5;
	}// if

	// ��������� �������� �������
	fin >> endVertex;
	// ��������� ���� ������
	fin.close();

	// ������� ���� ����� ��� ���������� �������
	ofstream file(FNAMEOUT3, fstream::trunc);
	file.close();  // ��������� ����
	// ���-������ ��������� �������
	cout << "\u001b[33m �������� �������: \x1b[30m" << endVertex << endl;

	// ������ �� ����� �������� ������� �� ������� ��������� ������ �����
	if (endVertex < 0 || endVertex - 1 > NewGraph.GetSize() - 1)
	{
		cout << "\u001b[31m �������� ������� ������� �� ������� ������ �����!!!\n\x1b[30m";
		return -6;
	}

	// ������ ����������
	vector<int> rez;
	// ��������� ����� ������������� ���� ����� �������� ��������
	rez = Dijkstra(NewGraph.adjacency_matrix(), startVertex-1, endVertex-1);


	if (print)
	{
		fout.open(FNAMEOUT1);           // ��������� ������ � ������
		if (!fout.is_open())           // ���� �� ������
		{
			cout << "����� � ����� ������ ���. ���������� ����������� ������";
			fin.close();               // ������� ���� ��� ������
			system("pause");
			exit(0);                   // ���������� ��������, ��������������� ���� � caller
		}// if (!fout.is_open())

		fout << "\t\t\t\t\t\t    � � � � � �   �   � � � � � � �\n\n\n";
		fout << "\n � � � � � � �   � � � � � � � � �   � �   � � � � � � � �   � � � � � � :\n\n";
		// ������� ������� ��������� � ����
			// ��� �� ������� �������
		for (int i = 0; i < NewGraph.GetSize(); i++)
		{
			// ��� �� �������� �������
			for (int j = 0; j < NewGraph.GetSize(); j++)
			{
				// ������� ��������� ������� ������� � ����
				fout << NewGraph.adjacency_matrix()[i][j] << " ";
			}// for j
			fout << endl;
		}// for i
		// �������� �������� ���� ������ � �����

		fout << "\n ��������� �������: " << startVertex << endl;
		fout << " �������� �������: " << endVertex << endl;

		if (rez[0] == -INF)
		{
			fout << "\n There is no path between the vertices " << startVertex << " and " << endVertex << ".\n";
		}
		else
		{
			int Weight = 0;

			fout << "\n � � � � � � �   � � � � �   � � � � � � � � � : \n";
			// ������� ������������� ���� � ���� ���� ������, ������������ ����� � ��� ���, ���� ���� �� ���������
			fout << " Vertices of a geodesic chain from the vertex " << startVertex << " to " << endVertex  << ": " << endl;
			fout << " [";

			for (int i = rez.size() - 1; i > 0; i--)
			{
				Weight = Weight + NewGraph.adjacency_matrix()[rez[i]][rez[i - 1]];
				fout << "(";
				// ������� ������� �������
				fout << rez[i] + 1 << " ";
				// � ��������� - ���������� �����
				fout << rez[i - 1] + 1 << " ";
				// ���� ���� ������� �� �� ��������� ���� ������� ��� ��������������� �����
				if (NewGraph.adjacency_matrix()[rez[i]][rez[i - 1]] != 1)
				{
					fout << NewGraph.adjacency_matrix()[rez[i]][rez[i - 1]];
				}// if (graph[path[i]][path[i - 1]] != 1)

				if (i != 1)
				{
					fout << ") ";
				}
				else
				{
					fout << ")";
				}// if (i != 1)
			}// for i

			fout << "]\n";
			cout << endl;

			fout << "\n � � � � �   � � � � � � � �   � � � � �   � � � � � � � � � :";
			fout << "\n Shortest path length between " << startVertex << " and " << endVertex << " vertices: " << Weight << endl;
		}
		
		fout.close();
	}// if (print)

	// ������� �������� � ������ �� �����
	OpenImage(NewGraph.adjacency_matrix());

	// ���������� ��������� ��������
	return 0;
}