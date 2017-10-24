#pragma once
#include "Globals.h"
#include "Component.h"
#include "MathGeoLib.h"
#include <string>
#include <vector>

class GameObject
{
public:
	GameObject();
	~GameObject();

	void preUpdate();
	void Update();
	bool Enable();
	bool Disable();

	void SetName(char* name);

	void ShowHierarchy();
	void ShowInspectorInfo();

	bool isActive() const;
	bool isVisible() const;

	Component* FindComponentByType(Comp_Type type) const;
	Component* AddComponent(Comp_Type type);

	AABB* bounding_box = nullptr;
	void DrawBoundingBox();

private:
	char* name = "CHANGE THIS";
	bool active = false;

	std::vector<Component*> components;
	std::vector<GameObject*> childs;
	
	GameObject* parent = nullptr;

	bool bb_active = false;
};