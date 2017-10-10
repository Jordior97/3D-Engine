#include "_Sphere.h"
#include "BaseGeometry.h"
#include "GL3W\include\glew.h"

_Sphere::_Sphere(Prim_Type t, const float3 p, const float r, bool k, Color c, uint def, bool w) :BaseGeometry(t, p, k, c, w)
{
	sphere = new Sphere(p, r);
	radius = r;
	SetDefinition(def);
	vertex_array.reserve(definition);
	sphere->Triangulate(vertex_array.data(), NULL, NULL, definition, false);
}

_Sphere::~_Sphere()
{
}

void _Sphere::Init()
{
	sphere_mesh.SetupMesh();
}

void _Sphere::SetDefinition(uint def)
{
	switch (def)
	{
	case 1:
		definition = 24;
		break;
	case 2:
		definition = 96;
		break;
	case 3:
		definition = 384;
		break;
	case 4:
		definition = 1536;
		break;
	case 5:
		definition = 6144;
		break;
	default:
		break;
	}
}

void _Sphere::Draw()
{
	glColor4f(color.r, color.g, color.b, color.a);
	sphere_mesh.Draw();
}

void _Sphere::GenFaceNormals(float3* centers)
{
	//if (sphere != nullptr)
	//{
	//	for (uint i = 0; i < sphere->NumFaces; i++)
	//	{
	//		sphere_mesh.vertices[i].norm = sphere_mesh->FaceNormal(i);
	//	}
	//}
}
