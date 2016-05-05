

struct Node {
  int key;      //neighboring vertex index
  int wt;       //weight of edge
  Node *next;
};

class Vertex {
public:
  int key;      //vertex index
  Node *nv;     //neighboring vertex

  Vertex() {
    key = 0;
    nv = 0;
  }

  Vertex(int _key) {
    key = _key;
    nv = 0;
  }

  void AddVertex(int _nv, int weight) { //add neighboring vertex
    nv = new Node;
    nv->key = _nv;
    nv->wt = weight;
    nv->next = 0;
  }

  ~Vertex() {
    Node * tmp1 = nv, *tmp2;
    while (tmp1 != 0) {
      tmp2 = tmp1;
      tmp1 = tmp1->next;
      delete tmp2;
    }
  }

};

class Graph {
public:
  int size;
  Vertex *v;

  Graph(int _size) {
    size = _size;
    v = new Vertex [size + 1];
    for (int i = 1; i < size + 1; i++)
      v[i].key = i;
  }

  ~Graph() {
    delete v;
  }

  void AddEdge(int v1, int v2, int weight) {
    v[v1].AddVertex(v2, weight);
    v[v2].AddVertex(v1, weight);
  }

  int IsConnect(int v1, int v2) {
    Node *tmp = v[v1].nv;
    while (tmp) {
      if (tmp->key == v2)
        return tmp->wt;
      tmp = tmp->next;
    }
    return 0;
  }

};
