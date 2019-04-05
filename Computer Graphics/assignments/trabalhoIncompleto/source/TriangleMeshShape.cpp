//[]------------------------------------------------------------------------[]
//|                                                                          |
//|                          GVSG Graphics Classes                           |
//|                               Version 1.0                                |
//|                                                                          |
//|              Copyright® 2010-2014, Paulo Aristarco Pagliosa              |
//|              All Rights Reserved.                                        |
//|                                                                          |
//[]------------------------------------------------------------------------[]
//
//  OVERVIEW: TriangleMeshShape.cpp
//  ========
//  Source file for triangle mesh shape.

#include "TriangleMeshShape.h"

using namespace Graphics;


//////////////////////////////////////////////////////////
//
// TriangleShape implementation
// =============
bool
TriangleShape::intersect(const Ray& ray, Intersection& hit) const
//[]---------------------------------------------------[]
//|  Intersect                                          |
//[]---------------------------------------------------[]
{
	hit.triangle = this;
	//puts("intersect");
	/*cout << this->mesh->getData().vertices[this->v[0]].x << this->mesh->getData().vertices[this->v[0]].y << this->mesh->getData().vertices[this->v[0]].z << endl;
	cout << this->mesh->getData().vertices[this->v[1]].x << this->mesh->getData().vertices[this->v[1]].y << this->mesh->getData().vertices[this->v[1]].z << endl;
	cout << this->mesh->getData().vertices[this->v[2]].x << this->mesh->getData().vertices[this->v[2]].y << this->mesh->getData().vertices[this->v[2]].z << endl;*/
	//cout << ray.origin.x << " " << ray.origin.y << " " << ray.origin.z << endl;
	vec3 e1(this->mesh->getData().vertices[this->v[1]] - this->mesh->getData().vertices[this->v[0]]);
	//cout << e1.x << e1.y << e1.z << endl;
	vec3 e2(this->mesh->getData().vertices[this->v[2]] - this->mesh->getData().vertices[this->v[0]]);
	//cout << e2.x << e2.y << e2.z << endl;
	vec3 s1(ray.direction.cross(e2));
	//cout << s1.x << s1.y << s1.z << endl;
	REAL d = s1.dot(e1);
	//cout << d << endl;
	if (isZero(d))
	{
		return false;
	}
	else
	{
		d = 1 / d;
		//cout << d << endl;
		vec3 s = ray.origin - this->mesh->getData().vertices[this->v[0]];
		//cout << s.x << " " << s.y << " " << s.z << endl;
		vec3 s2 = s.cross(e1);
		//cout << s2.x << " " << s2.y << " " << s2.z << endl;
		//cout << s2.dot(e2) << endl;
		if (isZero(s2.dot(e2)))
		{
			return false;
		}
		else
		{
			if (isNegative(d * s2.dot(e2)))
			{
				return false;
			}
			else
			{
				hit.distance = d * s2.dot(e2);
				REAL y = s1.dot(s);
				//if (Math::isZero(y))
				y = y * d;
				if (Math::isNegative(y))
				{
					return false;
				}
				else
				{
					REAL z = s2.dot(ray.direction);
					z = z * d;
					if (Math::isNegative(z))
					{
						return false;
					}
					else
					{
						if ((1 - y - z) > 1.00000000f)
						{
							return false;
						}
						else
						{
							hit.p.set(1 - y - z, y, z);
							return true;
						}
					}
				}
			}
		}
	}
	//mesh->getData().vertices[v[2]];
}

vec3
TriangleShape::normal(const Intersection& hit) const
//[]---------------------------------------------------[]
//|  Normal                                             |
//[]---------------------------------------------------[]
{
	// A mesma ideia do de cima
	return Graphics::triangleInterpolate(hit.p, this->mesh->getData().normals[hit.triangle->v[0]], 
		this->mesh->getData().normals[hit.triangle->v[1]],
		this->mesh->getData().normals[hit.triangle->v[2]]);
  //return vec3::null();
}

const Material*
TriangleShape::getMaterial() const
//[]---------------------------------------------------[]
//|  Get material                                       |
//[]---------------------------------------------------[]
{
  System::warning("TriangleShape::normal() invoked");
  return 0;
}

Bounds3
TriangleShape::boundingBox() const
//[]---------------------------------------------------[]
//|  Bounding box                                       |
//[]---------------------------------------------------[]
{
  // TODO: INSERT YOUR CODE HERE - inflar os pontos do triangulo
	Bounds3 b(this->mesh->getData().vertices[this->v[0]], this->mesh->getData().vertices[this->v[1]]);
	b.inflate(this->mesh->getData().vertices[this->v[2]]);
	return b;
}


//////////////////////////////////////////////////////////
//
// TriangleMeshShape implementation
// =================
Object*
TriangleMeshShape::clone() const
//[]---------------------------------------------------[]
//|  Make copy                                          |
//[]---------------------------------------------------[]
{
  return new TriangleMeshShape((TriangleMesh*)mesh->clone());
}

bool
TriangleMeshShape::canIntersect() const
//[]---------------------------------------------------[]
//|  Can intersect                                      |
//[]---------------------------------------------------[]
{
  return false;
}

Array<ModelPtr>
TriangleMeshShape::refine() const
//[]---------------------------------------------------[]
//|  Refine                                             |
//[]---------------------------------------------------[]
{
  int nt = mesh->getData().numberOfTriangles;
  Array<ModelPtr> a(nt);

  for (int t = 0; t < nt; t++)
    a.add(new TriangleShape(mesh, t));
  return a;
}

bool
TriangleMeshShape::intersect(const Ray&, Intersection&) const
//[]---------------------------------------------------[]
//|  Normal                                             |
//[]---------------------------------------------------[]
{
  System::warning("TriangleMeshShape::intersection() invoked");
  return false;
}

vec3
TriangleMeshShape::normal(const Intersection&) const
//[]---------------------------------------------------[]
//|  Normal                                             |
//[]---------------------------------------------------[]
{
  System::warning("TriangleMeshShape::normal() invoked");
  return vec3::null();
}

const TriangleMesh*
TriangleMeshShape::triangleMesh() const
//[]---------------------------------------------------[]
//|  Triangle mesh                                      |
//[]---------------------------------------------------[]
{
  return mesh;
}

Bounds3
TriangleMeshShape::boundingBox() const
//[]---------------------------------------------------[]
//|  Bounding box                                       |
//[]---------------------------------------------------[]
{
  return Bounds3(bounds, localToWorld);
}
