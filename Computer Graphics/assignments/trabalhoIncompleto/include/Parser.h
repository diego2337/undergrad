#ifndef __PARSER_H
#define __PARSER_H
#include <fstream>
#include <iostream>
#include <string>
#include <map>
#include "rapidxml.hpp"
#include "rapidxml_utils.hpp"
#include "include/Math/Vector3.h"
#include "Graphics/Color.h"
#include "Scene.h"
#include "Math/Real.h"
#include "Math/Matrix4x4.h"
#include "MeshReader.h"
#include "Math/Quaternion.h"
#include "Camera.h"
#include "MeshSweeper.h"

using namespace rapidxml;
using namespace std;
/* Essa classe será responsável por armazenar todos os atributos e elementos contidos no arquivo xml passado pela linha de comando.
   @authors diego, jainor, nicolas
*/
namespace Graphics
{

	class Parser
	{
	public:
		REAL rotation_angle, mesh_exponent,
			sphere_radius, cone_radius, cylinder_radius, cylinder_meridians,
			material_shine, cam_angle, cam_aspect;
		int sphere_meridians, cone_meridians, cylinder_segments, cone_segments, light_fallof, projection , numberOfLights;
		char *scene_name, *mesh_file, *buffer;
		vec3 position, mesh_scale, sphere_center, box_center, box_orientation,
			box_scale, cone_center, cone_height, cylinder_center, cylinder_height, light_color, cam_position,
			cam_to, cam_up;
		vec4 light_pos;
		Quaternion<REAL> *q;
		Color material_ambient, material_diffuse, material_spot;
		//color background, ambient (<- JA ESTAO DEFINIDOS COMO DEFAULT DENTRO DE SCENE.H), mesh_ambient, mesh_diffuse, mesh_spot, light_color;
		xml_document<> doc;
		xml_node<> *ptr;
		std::map<std::string, TriangleMesh*> meshes;
		std::map<std::string, TriangleMesh*>::iterator it;
		TriangleMesh* s;
		Scene *cena;
		Light *l;
		Material *m;
		/* Construtor  */
		Parser()
		{
			cena = new Scene("RT");
			q = new Quaternion<REAL>();
			numberOfLights = 0;
			cam_angle = 90;
			cam_aspect = 1.0f;
			cam_position.set(0, 0, 10);
			cam_to.set(0, 0, 0);
			cam_up.set(0, 1, 0);
			projection = 2;
			mesh_scale.set(1, 1, 1);
			q->identity();
			position.set(0, 0, 0);
		}
		~Parser()
		{
			delete[] buffer;
		}

		/* O método reset reinicializará todos os atributos que temos da nossa classe */
		void reset()
		{
			mesh_scale.set(1, 1, 1);
			position.set(0, 0, 0);
			//q->identity();
			q->set(90, vec3(0, 0, 1));
			sphere_meridians = 1;
			sphere_radius = 1;
			box_center.set(0, 0, 0);
			box_orientation.set(0, 0, 0);
			box_scale.set(1, 1, 1);
			cone_center.set(0, 0, 0);
			cone_radius = 1;
			cone_height.set(0, 1, 0);
			cone_segments = 16;
			cylinder_center.set(0, 0, 0);
			cylinder_radius = 1;
			cylinder_height.set(0, 1, 0);
			cylinder_segments = 16;
			light_color.set(1, 1, 1);
			light_fallof = 0;
			light_pos.set(1, 0, 0);
			material_shine = 0.0f;
			material_spot = Color::white;
			material_ambient = Color::white;
			material_diffuse = Color::white;
			m = MaterialFactory::New(Color::white);
			l = new Light(vec3(light_pos), Color(light_color));
		}

		static Actor* newActor(TriangleMesh*,	Material* = MaterialFactory::New(Color::white),	const vec3 = vec3(1, 1, 1),
			const vec3 = vec3(1, 1, 1),
			const quat = quat::identity());
		/* Vamos converter a string dentro do nó para o tipo vec3, assumindo que existem OBRIGATORIAMENTE 3 elementos x, y, z */
		vec3 toVec3(char* vec)
		{
			std::string s(vec);
			REAL x, y, z;
			int tamanho = 0;
			x = stof(s);
			while (vec[tamanho] != ' ')
				tamanho++;
			tamanho++;
			if (tamanho < strlen(vec))
				y = stof(s.substr(tamanho));
			else
				y = x;
			while (vec[tamanho] != ' ')
				tamanho++;
			tamanho++;
			if (tamanho < strlen(vec))
				z = stof(s.substr(tamanho));
			else
				z = x;
			return vec3(x, y, z);
		}

		vec4 toVec4(char* vec)
		{
			std::string s(vec);
			REAL x, y, z, w;
			int tamanho = 0;
			x = stof(s);
			while (vec[tamanho] != ' ')
				tamanho++;
			tamanho++;
			if (tamanho < strlen(vec))
				y = stof(s.substr(tamanho));
			else
				y = x;
			while (vec[tamanho] != ' ')
				tamanho++;
			tamanho++;
			if (tamanho < strlen(vec))
				z = stof(s.substr(tamanho));
			else
				z = x;
			while (vec[tamanho] != ' ')
				tamanho++;
			tamanho++;
			if (tamanho < strlen(vec))
				w = stof(s.substr(tamanho));
			else
				w = x;
			return vec4(x, y, z, w);
		}

		vec3 toAspect(char* vec)
		{
			std::string s(vec);
			REAL x, y, z;
			int tamanho = 0;
			x = stof(s);
			while (vec[tamanho] != ':')
				tamanho++;
			tamanho++;
			if (tamanho < strlen(vec))
				y = stof(s.substr(tamanho));
			else
				y = x;
			z = x;
			return vec3(x, y, z);
		}

		/* O método abaixo é basicamente igual ao "toVec3", porém ele retorna somente um número real */
		REAL toReal(char* vec)
		{
			std::string s(vec);
			std::string::size_type sz;
			REAL x;
			x = stof(s, &sz);
			return x;
		}

		int toInt(char* vec)
		{
			std::string s(vec);
			int x;
			x = stoi(s);
			return x;
		}

		/* Caso haja uma tag <transform> associada ao ator, faremos sua leitura aqui */
		void readTransform(xml_node<> *aux)
		{
			xml_node<> *rotation = aux->first_node("transform")->first_node("rotation");
			if (aux->first_node("transform")->first_node("position"))
			{
				position = this->toVec3(aux->first_node("transform")->first_node("position")->value());
			}
			if (aux->first_node("transform")->first_node("rotation"))
			{
				if (rotation->first_node("angle"))
				{
					q->set(this->toReal(rotation->first_node("angle")->value()),
						this->toVec3(rotation->first_node("axis")->value()));
				}
				else if (rotation->first_node("axis"))
				{
					q->set(this->toVec3(rotation->first_node("axis")->value()));
				}
			}
			if (aux->first_node("transform")->first_node("scale"))
			{
				mesh_scale = this->toVec3(aux->first_node("transform")->first_node("scale")->value());
			}
		}

		/* Caso haja uma tag <material> associada ao objeto, sua leitura ocorrerá no método abaixo */
		void readMaterial(xml_node<> *aux)
		{
			if (aux->first_node("material")->first_node("ambient"))
			{
				material_ambient = this->toVec3(aux->first_node("material")->first_node("ambient")->value());
				m->surface.ambient = this->toVec3(aux->first_node("material")->first_node("ambient")->value());
			}
			if (aux->first_node("material")->first_node("diffuse"))
			{
				material_diffuse = this->toVec3(aux->first_node("material")->first_node("diffuse")->value());
				m->surface.diffuse = this->toVec3(aux->first_node("material")->first_node("diffuse")->value());
			}
			if (aux->first_node("material")->first_node("spot"))
			{
				material_spot = this->toVec3(aux->first_node("material")->first_node("spot")->value());
				m->surface.spot = this->toVec3(aux->first_node("material")->first_node("spot")->value());
			}
			if (aux->first_node("material")->first_node("shine"))
			{
				material_shine = this->toReal(aux->first_node("material")->first_node("shine")->value());
				m->surface.shine = this->toReal(aux->first_node("material")->first_node("shine")->value());
			}
		}

		void readBuff(char*, char*, int);
		void run(char*, int*, int*, Camera**);
		void readScene();
		void readImage(int*, int*);
		void readCamera(Camera**);

	};
}
#endif
