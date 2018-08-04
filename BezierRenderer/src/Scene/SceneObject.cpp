#include "SceneObject.h"

SceneObject::SceneObject()
	:m_mat_tex(MaterialTexture(Material(), Texture("","")))
{}

SceneObject::SceneObject(glm::vec3 origin, glm::mat4 trsnfrm, MaterialTexture mat_tex)
	:m_origin(origin),
	m_mat_tex(mat_tex)
{
	m_transform = trsnfrm;
}

/*SceneObject::SceneObject(glm::vec3 origin, glm::mat4* trsnfrm, MaterialTexture mat_tex)
	:m_origin(origin),
	m_transform(trsnfrm),
	m_mat_tex(mat_tex)
{
}*/

SceneObject::~SceneObject()
{}

void SceneObject::Translate(glm::vec3 t)
{
	m_origin += t;
	m_transform = glm::translate(m_transform, t);
}

void SceneObject::Rotate(glm::vec3 axis, float angle)
{
	m_transform= glm::rotate(m_transform, angle, axis);
}

void SceneObject::Scale(glm::vec3 s)
{
	m_transform= glm::scale(m_transform, s);
}

void SceneObject::MoveTo(glm::vec3 pos)
{
	glm::vec3 translation = pos - m_origin;

	Translate(translation);
}
