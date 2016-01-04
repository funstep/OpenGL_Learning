#include <Render/Model.h>
#include <SFML/Graphics/VertexArray.hpp>
#include <SFML/Graphics/Shader.hpp>
#include <fstream>

using namespace sf;
using namespace OpenGLWrapper;

struct STLTriangle
{
    float normal[3];
    float vertex[3][3];
    unsigned short attribute;
};

Model::Model()
    :_isLoaded(false),
     _isVertexShaderReady(false),
     _isFragmentShaderReady(false)
{

}

Model::Model(std::string &pathToModel)
    :Model()
{
    loadFromFile(pathToModel);
}

Model::Model(std::string &pathToSTLFile,
             std::string &pathToVertexShader,
             std::string &pathToFragmentShader)
    :Model()
{
    loadFromSTLFile(pathToSTLFile);
    loadAndCompileVertexShader(pathToVertexShader);
    loadAndCompileFragmentShader(pathToFragmentShader);
}

Model::~Model()
{

}

bool Model::loadFromFile(std::string &path)
{
    _isLoaded = false;
    _vertises.reset();

    // TODO: write loading from file

    return _isLoaded;
}

bool Model::loadFromSTLFile(std::string &path)
{
    _isLoaded = false;
    _vertises = SharedArray(new std::vector<float>);
    _normals = SharedArray(new std::vector<float>);

    std::fstream file;
    file.open(path, std::ios_base::in);
    if (!(_isLoaded = file.is_open())) {
        return _isLoaded;
    }

    _isLoaded = loadSTLFromStream(file, _vertises, _normals);

    file.close();

    return _isLoaded;
}

bool Model::saveToFile(std::string &path)
{
    // TODO: write implementation

    return false;
}

bool Model::loadAndCompileVertexShader(std::string &path)
{
    _isVertexShaderReady = false;
    _vertexShader.reset();

    // TODO: write loading vertext shader

    return _isVertexShaderReady;
}

bool Model::loadAndCompileFragmentShader(std::string &path)
{
    _isFragmentShaderReady = false;
    _fragmentShader.reset();

    //TODO: write loading fragment shader

    return _isFragmentShaderReady;
}

bool Model::loadSTLFromStream(std::fstream &file, SharedArray vertexArray, SharedArray normalsArray)
{
    int bufferSize = 80;
    char buffer[bufferSize];
    if (file.readsome(buffer, bufferSize * sizeof(char)) != bufferSize) {
         return false;
    }

    unsigned int numberOfTriangles = 0;
    if (file.readsome((char *)&numberOfTriangles, sizeof(unsigned int)) != sizeof(unsigned int)) {
        return false;
    }

    vertexArray->resize(numberOfTriangles*9);
    normalsArray->resize(numberOfTriangles*3);

    STLTriangle triangle;
    for(unsigned int i = 0; i < numberOfTriangles; i++){

        if(file.readsome((char *)&triangle.normal, sizeof(float)*3) != sizeof(float)*3){
            return false;
        }

        if(file.readsome((char *)&triangle.vertex, sizeof(float)*9) != sizeof(float)*9){
            return false;
        }

        if(file.readsome((char *)&triangle.attribute, sizeof(unsigned short)) != sizeof(unsigned short)){
            return false;
        }

        for (int i = 0; i < 3; ++i) {

            for (int j = 0; j < 3; ++j) {
                vertexArray->push_back(triangle.vertex[i][j]);
            }

            normalsArray->push_back(triangle.normal[i]);
        }
    }
}
