#pragma once
#include "glm/glm.hpp"
#include "../OpenGL/Shader.h"
#include "../OpenGL/Renderer.h"
#include "../OpenGL/VertexBufferLayout.h"
#include "glm/gtc/matrix_transform.hpp"
#include "../OpenGL/Texture.h"
#include "../Utils/Material.h"
#include "../Utils/Vertex.h"

struct MaterialTexture
{
	Texture tex = Texture("", "");
	Material mat;

	MaterialTexture(Material m, Texture t)
	{
		tex = t;
		mat = m;
	}

	MaterialTexture()
	{
		tex = Texture("", "");
		mat = Material();
	}
};

struct SceneTransform
{
	glm::mat4 transform;
	string uniform_name;
};

struct Ray
{
	glm::vec3 origin;
	glm::vec3 direction;
	
	Ray()
	{
		origin = glm::vec3();
		direction = glm::vec3();
	}
};

class SceneObject
{
public:
	SceneObject();
	SceneObject(glm::vec3 origin, glm::mat4 trsnfrm, MaterialTexture mat_tex);
	//SceneObject(glm::vec3 origin, glm::mat4* trsnfrm, MaterialTexture mat_tex);
	~SceneObject();

	virtual void Draw(Renderer renderer, Shader* shader, VertexArray* vArray) = 0;
	void Translate(glm::vec3 t);
	void Rotate(glm::vec3 axis, float angle);
	void Scale(glm::vec3 s);

	inline vector<Vertex> GetVertices() const { return m_vertices; };
	inline vector<unsigned int> GetIndices() const { return m_indices; };
	inline Material GetMaterial() { return m_mat_tex.mat; }
	inline glm::mat4 GetTransform() { return m_transform.transform; }
	inline glm::vec3 GetOrigin() { return m_origin; }
	inline string GetTransformName() { return m_transform.uniform_name; }

	inline void SetMaterial(Material material) { m_mat_tex.mat = material; }
	inline void SetTexture(Texture texture) { m_mat_tex.tex = texture; }
	inline void SetMaterialTexture(MaterialTexture mt) { m_mat_tex = mt; }
	inline void SetTransformName(string s) { m_transform.uniform_name= s; }
	inline void SetTransform(glm::mat4 trnsfrm) { m_transform.transform = trnsfrm; }
	void MoveTo(glm::vec3 pos);


protected:
	vector<Vertex> m_vertices;
	vector<unsigned int> m_indices;
	MaterialTexture m_mat_tex;
	glm::vec3 m_origin;
	SceneTransform m_transform;
};