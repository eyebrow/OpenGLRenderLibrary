
#include <vector>
#include "Program.hpp"

#ifndef MESH_H
#define MESH_H

using namespace std; 

class Mesh {
  
  //all subclasses will determine the vertices of the object and the indices for both wireframe and surface versions of the object 
  
public:
  Mesh();
  
  vector<float>& GetVertices();
  vector<float>& GetTexCoords();
  vector<float>& GetNormals();
  vector<float>& GetColors();
  vector<unsigned short>& GetLineIndices();
  vector<unsigned short>& GetTriangleIndices();
  
  bool useTexCoords;
  bool useNormals;
  bool useColors;
  
   
  //all subclasses must implement these functions
  virtual void GenerateLineIndices() = 0;
  virtual void GenerateTriangleIndices() = 0;
  virtual int GetVertexCount()  = 0;
  virtual int GetLineIndexCount()  = 0;
  virtual int GetTriangleIndexCount()  = 0;
  
  void PassVertices(Program* program, int mode);
  
  void SetVertexAttributes(bool _useTexCoords, bool _useNormals, bool _useColors);

  vector<float> vertices;
  vector<float> texCoords;
  vector<float> normals;
  vector<float> colors;
  
  vector<unsigned short> lineIndices;
  vector<unsigned short> triangleIndices;
  
protected:
  
  
private:
};

#endif
