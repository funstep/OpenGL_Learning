#ifndef __MODEL_H__
#define __MODEL_H__

#include <Types.h>
#include <string>
#include <vector>

namespace sf {
    class VertexArray;
    class Shader;
}

namespace OpenGLWrapper {

    typedef std::shared_ptr<std::vector<float>> SharedArray;
    typedef std::shared_ptr<sf::Shader> SharedShader;

    class Model
    {
        public:
            Model();
            Model(std::string &pathToModel);
            Model(std::string &pathToSTLFile, std::string &pathToVertexShader, std::string &pathToFragmentShader);
            ~Model();

            // load complete model
            bool loadFromFile(std::string &path);
            // save complete model
            bool saveToFile(std::string &path);

            // load from stl file
            bool loadFromSTLFile(std::string &path);

            // load and compile vertex shader
            bool loadAndCompileVertexShader(std::string &path);
            // load and compile fragment shader
            bool loadAndCompileFragmentShader(std::string &path);

        public:
            READ_ONLY_PROPERTY(SharedArray, vertises)
            READ_ONLY_PROPERTY(SharedArray, normals)
            READ_ONLY_PROPERTY(SharedShader, vertexShader)
            READ_ONLY_PROPERTY(SharedShader, fragmentShader)

            READ_ONLY_PROPERTY(bool, isLoaded)
            READ_ONLY_PROPERTY(bool, isVertexShaderReady)
            READ_ONLY_PROPERTY(bool, isFragmentShaderReady)

        private:
           bool loadSTLFromStream(std::fstream &file, SharedArray vertexArray, SharedArray normalsArray);
    };
}

#endif
