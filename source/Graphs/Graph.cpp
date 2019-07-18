#include "Graph.hpp"
<<<<<<< HEAD
#include <vector>
/** Constructor
	 * Creates a graph with n vertices but no edges.
	 * Each vertex is initialized with a value of 0.
	 */
Graph::Graph(unsigned int n){
	if(n < 1) throw "Invalid n";
	vert = n;
	edg = 0;
	for (unsigned int i = 0; i < n; ++i) //O(n)
	{
		std::vector<int> nw(n, 0); //sub-vector created,called nw, filled with zeroes
		table.push_back(nw);	   //sub-vector put in "table", vector of vectors
	}
}

/** Destructor
	 * Clear the memory used by the adjacency matrix and node value array.
	 */
Graph::~Graph(){
	table.clear();
	vert = 0;
}

/** node_count()
	 * Returns the number of nodes in the graph.
	 */
unsigned int Graph::node_count(){ //O(1) bc # of nodes is tracked
	return vert;
}

/** edge_count()
	 * Returns the number of edges in the graph.
	 * Two nodes connected to one another counts as two edges.
	 */
unsigned int Graph::edge_count(){
	return edg;
}

/** get_value(unsigned int v)
	 * Returns the value associated with node v.
	 */
int Graph::get_value(unsigned int v){
	return table[v].at(0);
}

/** set_value(unsigned int v, int val)
	 * Sets the value of node v to val.
	 */
void Graph::set_value(unsigned int v, int val){
	table[v].at(0) = val;
}

/** weight(unsigned int v, unsigned int w)
	 * Returns the weight of the edge from node v to node w.
	 * Returns 0 if the edge does not exist.
	 */
int Graph::weight(unsigned int v, unsigned int w){
	return table[v].at(w);
}

/** has_edge(unsigned int v, unsigned int w)
	 * Returns true if there is an edge from node v to node w.
	 * Note that has_edge(v, w) does not imply has_edge(w, v).
	 */
bool Graph::has_edge(unsigned int v, unsigned int w){
	return (table[v].at(w) != 0) ? true:false;
}

/** add_edge(unsigned int v, unsigned int w, int weight)
	 * Adds an edge from node v to node w to the graph, with the given weight.
	 * If no weight is specified, it defaults to 1.
	 * Self-connected nodes are not permitted, so an error is thrown when v == w.
	 * Will throw an error if weight == 0. Use remove_edge instead.
	 */
void Graph::add_edge(unsigned int v, unsigned int w, int weight){
	if(v == w) throw "Self connected not valid";
	if(!has_edge(v,w)){
		if(weight == 0){
		throw "Zero weight";
		remove_edge(v,w);
	}
	table[v][w] = weight;

	edg++;
	}

}

/** remove_edge(unsigned int v, unsigned int w)
	 * Removes the edge from node v to node w from the graph.
	 * Will throw an error if the edge does not exist.
	 */
void Graph::remove_edge(unsigned int v, unsigned int w){
	if(!has_edge(v,w)) throw "Edge does not exist";
	table[v][w]=0;
	table[w][v]=0;
	edg--;
}

/** neighbors(unsigned int v)
	 * Returns a vector containing the indices of every neighbor of the node v.
	 * A node w is defined to be a neighbor of v iff there exists an edge
	 * from v to w.
	 */
std::vector<int> Graph::neighbors(unsigned int v)
{
	std::vector<int> ngh;

	for(int i = 0; i < table[v].size(); ++i){
        ngh.push_back(i);
    }

	return ngh;
=======
#include <iostream>

Graph::Graph(unsigned int n) {
  if (!n) throw "Graph cannot contain zero vertices";
  matrix = new int*[n];
  // Note: new int[n]() initializes values to zero
  for (unsigned int i = 0; i < n; ++i) {
    matrix[i] = new int[n]();
  }
  node_values = new int[n]();
  num_nodes = n;
  num_edges = 0;
}

Graph::~Graph() {
  delete [] node_values;
  for (unsigned int i = 0; i < num_nodes; ++i) {
    delete [] matrix[i];
  }
  delete [] matrix;
}

unsigned int Graph::node_count() {
  return num_nodes;
}

unsigned int Graph::edge_count() {
  return num_edges;
}

int Graph::get_value(unsigned int v) {
  if (v >= num_nodes) throw "Vertex out of bounds";
  return node_values[v];
}

void Graph::set_value(unsigned int v, int val) {
  if (v >= num_nodes) throw "Vertex out of bounds";
  node_values[v] = val;
}

bool Graph::has_edge(unsigned int v, unsigned int w) {
  if (v >= num_nodes || w >= num_nodes) throw "Vertex out of bounds";
  return (bool) matrix[v][w];
}

int Graph::weight(unsigned int v, unsigned int w) {
  if (v >= num_nodes || w >= num_nodes) throw "Vertex out of bounds";
  return matrix[v][w];
}

void Graph::add_edge(unsigned int v, unsigned int w, int weight) {
  if (v >= num_nodes || w >= num_nodes) throw "Vertex out of bounds";
  if (!weight) throw "Weight cannot be zero";
  if (v == w) throw "Self-connected edges are not permitted";
  matrix[v][w] = weight;
  ++num_edges;
}

void Graph::remove_edge(unsigned int v, unsigned int w) {
  if (v >= num_nodes || w >= num_nodes) throw "Vertex out of bounds";
  if (!matrix[v][w]) throw "Edge does not exist";
  matrix[v][w] = 0;
  --num_edges;
}

std::vector<int> Graph::neighbors(unsigned int v) {
  if (v >= num_nodes) throw "Vertex out of bounds";
  std::vector<int> neighbor_nodes;
  for (unsigned int i = 0; i < num_nodes; ++i) {
    if (matrix[v][i]) neighbor_nodes.push_back(i);
  }
  return neighbor_nodes;
>>>>>>> upstream/master
}