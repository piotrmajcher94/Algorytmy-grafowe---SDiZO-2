#pragma once
#include "IndexOutOfBoundsException.h"
#include "FileNotFoundException.h"
#include "NotACoherentGraphException.h"
#include "QHeap.h"
#include <fstream>
#include <string>
#include <sstream>
#include <iostream>
#include <exception>


class MatrixGraph
{
private:
	struct Edge {
		int beg, end, val;
	};
	class Heap {
	public:

	Edge* root;
	volatile int size;
	bool isEmpty;

	MatrixGraph::Heap::Heap();
	MatrixGraph::Heap::~Heap();

	void MatrixGraph::Heap::push(Edge e);
	Edge MatrixGraph::Heap::pop();
	void MatrixGraph::Heap::heap_fix_up();
	void MatrixGraph::Heap::heap_fix_down();
	};
	int edgeNum; // Liczba krawędzi grafu
	int nodeNum; // Liczba wierzchołków grafu

	int* edgeValues; // Tablica wag krawędzi
	short int** matrixGraph; // Macierz grafu: wiersze - krawędzie, kolumny - wierzchołki

public:

	MatrixGraph();
	~MatrixGraph();
	void open(std::string fileName);
	void save(std::string fileName);
	void Prim(MatrixGraph &resultTree);
	void Kruskal(MatrixGraph &resultTree);
	void Dijkstra(int start, int end, bool printResult);
	bool BellmanFord(int start, int end, bool printResult);
	void addEdge(Edge e, int idx);
	friend std::ostream& operator << (std::ostream& output, MatrixGraph& graph);
	int getNodeNum() { return nodeNum; }
};