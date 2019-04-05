#include "Parser.h"
using namespace Graphics;


Actor*
Parser::newActor(TriangleMesh* mesh, Material* material, const vec3 position, const vec3 size, const quat quaternion)
{
	Primitive* p = new TriangleMeshShape(mesh);
	p->setMaterial(material);
	p->setTransform(position, quaternion, size);
	return new Actor(*p);
}


/* O run irá percorrer toda a árvore xml formada, preenchendo uma cena no processo para devolvê-la como valor de retorno ao final */
void Parser::run(char *f, int *largura, int *altura, Camera **c)
{
	cout << f << endl;
	/* SÓ LÊ EM ANSI */
	ifstream file;
	file.open(f, ifstream::in);
	if (file.is_open())
	{
		file.seekg(0, ios::end);
		int size = (int)file.tellg();
		file.seekg(0, ios::beg);
		buffer = new char[size];
		file.read(buffer, size);
		while (buffer[size] != '>')
		{
			size--;
		}
		buffer[size + 1] = '\0';
		cout << buffer << endl;
		try
		{
			this->doc.parse<0>(buffer);
		}
		catch (parse_error p)
		{
			p.what();
			exit(0);
		}
		file.close();
		ptr = doc.first_node()->first_node();
		for (int i = 0; i < 3, this->ptr; i++, this->ptr = this->ptr->next_sibling())
		{
			if (strcmp(this->ptr->name(), "scene") == 0)
			{
				cout << cena->getName() << endl;
				this->readScene();
			}
			else if (strcmp(this->ptr->name(), "image") == 0)
			{
				this->readImage(largura, altura);
			}
			else if (strcmp(this->ptr->name(), "camera") == 0)
			{
				this->readCamera(c);
			}
		}
		if (projection == 1)
			*c = new Camera((*c)->Parallel, cam_position, (cam_to - cam_position).versor(), cam_up, cam_angle, cam_aspect);
		else
		{
			*c = new Camera((*c)->Perspective, cam_position, (cam_to - cam_position).versor(), cam_up, cam_angle, cam_aspect);
		}
		cout << "////////////////////////////" << (cam_to).z << "////////////////////" << endl;
		if (numberOfLights == 0)
			cena->addLight(l);
		cout << "--------------------------------------" << endl;
		for (map<std::string, TriangleMesh*>::const_iterator i = meshes.begin(); i != meshes.end(); i++)
		{
			cout << i->first << " " << i->second << endl;
		}
		cout << "--------------------------------------" << endl;
	}
}

/* Vamos ler o elemento <scene>, preenchendo a cena a ser criada */
void Parser::readScene()
{
	xml_node<> *aux;
	if (this->ptr->first_attribute("name"))
	{
		cena->setName(this->ptr->first_attribute()->value());
	}
	aux = this->ptr->first_node();
	while (aux != 0)
	{
		this->reset();
		if (strcmp(aux->name(), "background") == 0)
		{
			cena->backgroundColor.setRGB(this->toVec3(aux->value()));
		}
		else if (strcmp(aux->name(), "ambient") == 0)
		{
			cena->ambientLight.setRGB(this->toVec3(aux->value()));
		}
		else if (strcmp(aux->name(), "mesh") == 0)
		{
			// Sugestão: Usar std::map
			it = meshes.find(aux->first_attribute()->value());
			/* Elemento não encontrado */
			if (it == meshes.end())
			{
				s = MeshReader().execute(aux->first_attribute()->value());
				meshes.insert(std::pair<std::string, TriangleMesh*>(aux->first_attribute()->value(), s));
			}
			else /* Elemento encontrado */
			{
				s = it->second;
			}
			for (map<std::string, TriangleMesh*>::const_iterator i = meshes.begin(); i != meshes.end(); i++)
			{
				cout << i->first << " " << i->second << endl;
			}
			/* Indica que há uma matriz TRS definida no arquivo */
			if (aux->first_node("transform"))
			{
				this->readTransform(aux);
			}
			m = MaterialFactory::New(Color::white);
			if (aux->first_node("material"))
			{
				this->readMaterial(aux);
			}
			//if (q->isUnit())
			cena->addActor(newActor(s, m, position, mesh_scale, *q));
		}
		else if (strcmp(aux->name(), "sphere") == 0)
		{
			if (aux->first_node("center"))
			{
				sphere_center = this->toVec3(aux->first_node("center")->value());
			}
			if (aux->first_node("radius"))
			{
				sphere_radius = this->toReal(aux->first_node("radius")->value());
			}
			if (aux->first_node("meridians"))
			{
				sphere_meridians = this->toInt(aux->first_node("meridians")->value());
			}
			if (aux->first_node("transform"))
			{
				this->readTransform(aux);
			}
			if (aux->first_node("material"))
			{
				this->readMaterial(aux);
			}
			it = meshes.find("sphere");
			/* Elemento não encontrado */
			if (it == meshes.end())
			{
				meshes.insert(std::pair<char*, TriangleMesh*>("sphere", s));
			}
			else /* Elemento encontrado */
			{
				s = it->second;
			}
			s = MeshSweeper::makeSphere(sphere_center, sphere_radius, sphere_meridians);
			position = sphere_center;
			cena->addActor(newActor(s, m, position, mesh_scale, *q));
		}
		else if (strcmp(aux->name(), "box") == 0)
		{
			if (aux->first_node("center"))
			{
				box_center = this->toVec3(aux->first_node("center")->value());
			}
			if (aux->first_node("orientation"))
			{
				box_orientation = this->toVec3(aux->first_node("orientation")->value());
			}
			if (aux->first_node("scale"))
			{
				box_scale = this->toVec3(aux->first_node("scale")->value());
			}
			if (aux->first_node("transform"))
			{
				this->readTransform(aux);
			}
			if (aux->first_node("material"))
			{
				this->readMaterial(aux);
			}
			it = meshes.find("box");
			/* Elemento não encontrado */
			if (it == meshes.end())
			{
				meshes.insert(std::pair<char*, TriangleMesh*>("box", s));
			}
			else /* Elemento encontrado */
			{
				s = it->second;
			}
			s = MeshSweeper::makeBox(box_center, Quaternion<REAL>::eulerAngles(box_orientation), box_scale);
			cena->addActor(newActor(s, m, box_center));
		}
		else if (strcmp(aux->name(), "cone") == 0)
		{
			if (aux->first_node("center"))
			{
				cone_center = this->toVec3(aux->first_node("center")->value());
			}
			if (aux->first_node("radius"))
			{
				cone_radius = this->toReal(aux->first_node("radius")->value());
			}
			if (aux->first_node("height"))
			{
				cone_height = this->toVec3(aux->first_node("height")->value());
			}
			if (aux->first_node("transform"))
			{
				this->readTransform(aux);
			}
			if (aux->first_node("material"))
			{
				this->readMaterial(aux);
			}
			it = meshes.find("cone");
			/* Elemento não encontrado */
			if (it == meshes.end())
			{
				meshes.insert(std::pair<char*, TriangleMesh*>("cone", s));
			}
			else /* Elemento encontrado */
			{
				s = it->second;
			}
			s = MeshSweeper::makeCone(cone_center, cone_radius, cone_height, cone_segments);
			cena->addActor(newActor(s, m, cone_center));
		}
		else if (strcmp(aux->name(), "cylinder") == 0)
		{
			if (aux->first_node("center"))
			{
				cylinder_center = this->toVec3(aux->first_node("center")->value());
			}
			if (aux->first_node("radius"))
			{
				cylinder_radius = this->toReal(aux->first_node("radius")->value());
			}
			if (aux->first_node("height"))
			{
				cylinder_height = this->toVec3(aux->first_node("height")->value());
			}
			if (aux->first_node("segments"))
			{
				cylinder_segments = this->toInt(aux->first_node("height")->value());
			}
			if (aux->first_node("transform"))
			{
				this->readTransform(aux);
			}
			if (aux->first_node("material"))
			{
				this->readMaterial(aux);
			}
			it = meshes.find("cylinder");
			/* Elemento não encontrado */
			if (it == meshes.end())
			{
				meshes.insert(std::pair<char*, TriangleMesh*>("cone", s));
			}
			else /* Elemento encontrado */
			{
				s = it->second;
			}
			s = MeshSweeper::makeCylinder(cylinder_center, cylinder_radius, cylinder_height, cylinder_segments);
			cena->addActor(newActor(s, m, cylinder_center));
		}
		else if (strcmp(aux->name(), "light") == 0)
		{
			int directional = 1;
			if (aux->first_node("position"))
			{
				light_pos = this->toVec4(aux->first_node("position")->value());
				if (light_pos.w == 0)
					directional = 0;
				light_pos = this->toVec3(aux->first_node("position")->value());
				l->position = this->toVec3(aux->first_node("position")->value());
			}
			if (aux->first_node("color"))
			{
				light_color = this->toVec3(aux->first_node("color")->value());
				l->color = this->toVec3(aux->first_node("color")->value());
			}
			if (aux->first_node("falloff"))
			{
				light_fallof = this->toInt(aux->first_node("falloff")->value());
			}
			if (directional == 0)
			{
				l->flags = Light::Directional;
			}
			else
			{
				switch (light_fallof)
				{
				case 1:
					l->flags = Light::Linear;
					break;
				case 2:
					l->flags = Light::Squared;
					break;
				default:
					l->flags = 0;
					break;
				}
			}
			cena->addLight(l);
			numberOfLights++;
		}
		aux = aux->next_sibling();
	}
}

/* Nesse método iremos ler apenas o elemento <image> */
void Parser::readImage(int *largura, int *altura)
{
	if (ptr->first_node("width"))
	{
		*largura = this->toInt(ptr->first_node("width")->value());
	}
	if (ptr->first_node("height"))
	{
		*altura = this->toInt(ptr->first_node("height")->value());
	}
}

/* Aqui ocorre a leitura da tag <camera> e suas tags filhas */
void Parser::readCamera(Camera **c)
{
	xml_node<> *aux = this->ptr;
	cout << aux->name() << endl;
	if (aux->first_node("position"))
	{
		cam_position = this->toVec3(aux->first_node("position")->value());		
	}
	if (aux->first_node("to"))
	{
		cam_to = this->toVec3(aux->first_node("to")->value());
	}
	if (aux->first_node("up"))
	{
		cam_up = this->toVec3(aux->first_node("up")->value());
	}
	if (aux->first_node("angle"))
	{
		cam_angle = this->toReal(aux->first_node("angle")->value());
	}
	if (aux->first_node("aspect"))
	{
		vec3 aux2 = this->toAspect(aux->first_node("aspect")->value());
		cam_aspect = aux2.x / aux2.y;
	}
	if (aux->first_node("projection"))
	{
		if (strcmp(aux->first_node("projection")->value(), "parallel") == 0)
		{
			projection = 1;
		}
	}
}