#pragma once
#ifndef __MODULEOBJECTS_H__
#define __MODULEOBJECTS_H__

#include "Module.h"
#include "Globals.h"
#include "ImGui\imgui.h"
#include "Primitive.h"
#include "GL3W\include\glew.h"
#include "WindowManager.h"

enum Type
{
	SPHERE,
	CUBE,
	CYLINDER,
	ARROW,
	AXIS,
	RAY,
	PLANE
};
struct Sphere_object
{
	Sphere_p sphere;
	bool isKynematic = false;
};
/*
uint id_vertices = 0; // id in VRAM
uint num_indices = 0;
uint* indices = nullptr;
uint id_indices = 0; // id in VRAM
uint num_vertices = 0;
float* vertices = nullptr;*/
struct Object_id
{
	uint id = 0;
	uint num_vertices = 0;

	uint index = 0;
	uint num_index = 0;

	GLuint normal;
	Type type;
	Color color;
};

struct Cube_object
{
	Cube_p cube;
	bool isKynematic = false;
};

class ModuleObjects : public Module
{
public:

	ModuleObjects(bool start_enabled = true);
	virtual ~ModuleObjects();

	bool Start();
	void draw_cylinder(GLfloat radius, GLfloat height, GLubyte R, GLubyte G, GLubyte B);
	update_status Update(float dt);
	bool CleanUp();

	void ShowPerformance(int ms_index);

	//void CreateSphere(Sphere_p* sphere, ImVec4 color, bool isKynematic = false);
	//void CreateCube(Cube_p * sphere, ImVec4 color, bool isKynematic = false);



	void CreateSphere(Sphere* sphere,Color color = White, uint definition = 1/*, bool isKynematic = false*/);
	bool Index_vert(float3* vertex_triangulate, uint num_vertex, std::vector<uint>* index, std::vector<float3>* vertex);
	void CreateCube(OBB* cube, Color color = White/*, bool isKynematic = false*/);
	void CreateCylinder();

	void Render(Object_id id /*,ImVec4 color*/);
	void RenderSphere(Object_id id/*, ImVec4 color bool/*, wireframe_mode = false*/);
	void RenderCube(Object_id id/*, ImVec4 color*/);

	void ShowAxis(bool axis);
	void ShowWire(bool wire);

public:

	/*std::vector<Sphere_object> spheres;
	std::list<PhysBody3D*> Body_spheres;*/

	//std::vector<Sphere_mathgeo_object> spheres_mathgeo;
	std::vector<Object_id> sphere_ID;
	//std::list<PhysBody3D*> Body_spheres_mathgeo;

	std::vector<Cube_object> cubes;
	std::list<PhysBody3D*> Body_cubes;

	std::list<Sphere*> math_Sphere;
	std::list<Capsule*> math_Capsule;
	std::list<Plane*> math_Plane;
	std::list<Ray*> math_Ray;

	bool wireframe_mode = false;

};


#endif