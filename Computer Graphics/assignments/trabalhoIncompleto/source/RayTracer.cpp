//[]------------------------------------------------------------------------[]
//|                                                                          |
//|                          GVSG Graphics Library                           |
//|                               Version 1.0                                |
//|                                                                          |
//|              Copyright® 2007-2014, Paulo Aristarco Pagliosa              |
//|              All Rights Reserved.                                        |
//|                                                                          |
//[]------------------------------------------------------------------------[]
//
//  OVERVIEW: RayTracer.cpp
//  ========
//  Source file for simple ray tracer.

#include <map>
#include <iostream>
#include <time.h>
#include "BVH.h"
#include "RayTracer.h"
#include "GlRenderer.h"

using namespace std;
using namespace Graphics;

void
printElapsedTime(const char* s, clock_t time)
{
  printf("%sElapsed time: %.4f s\n", s, (REAL)time / CLOCKS_PER_SEC);
}


//////////////////////////////////////////////////////////
//
// RayTracer implementation
// =========
RayTracer::RayTracer(Scene& scene, Camera* camera):
  Renderer(scene, camera),
  maxRecursionLevel(6),
  minWeight(MIN_WEIGHT)
//[]---------------------------------------------------[]
//|  Constructor                                        |
//[]---------------------------------------------------[]
{
  // TODO: UNCOMMENT THE CODE BELOW
  int n = scene.getNumberOfActors();

  printf("Building aggregates for %d actors...\n", n);

  clock_t t = clock();
  // Todos os modelos de atores na cena
  Array<ModelPtr> models(n);
  map<uint, ModelPtr> aggregates;
  int totalNodes = 0;
  int i = 1;

  for (ActorIterator ait(scene.getActorIterator()); ait; i++)
  {
    const Actor* a = ait++;

    printf("Processing actor %d/%d...\r", i, n);
    if (!a->isVisible())
      continue;

    Primitive* p = dynamic_cast<Primitive*>(a->getModel());
    const TriangleMesh* mesh = p->triangleMesh();

    if (mesh != 0)
    {
      ModelPtr& a = aggregates[mesh->id];

      if (a == 0)
      {
        BVH* bvh = new BVH(std::move(p->refine()));

        totalNodes += bvh->size();
        a = bvh;
      }
      models.add(new ModelInstance(*a, *p));
    }
  }
  printf("Building scene aggregate...\n");
  {
    BVH* bvh = new BVH(std::move(models));

    totalNodes += bvh->size();
    aggregate = bvh;
  }
  printf("BVH(s) built: %d (%d nodes)\n", aggregates.size() + 1, totalNodes);
  printElapsedTime("", clock() - t);
  
}

//
// Auxiliary VRC
//
static vec3 VRC_u;
static vec3 VRC_v;
static vec3 VRC_n;

//
// Auxiliary mapping variables
//
static REAL V_h;
static REAL V_w;
static REAL I_h;
static REAL I_w;

void
RayTracer::render()
//[]---------------------------------------------------[]
//|  Render                                             |
//[]---------------------------------------------------[]
{
  System::warning("Invoke renderImage(image) to run the ray tracer\n");
}

static int64 numberOfRays;
static int64 numberOfHits;

void
RayTracer::renderImage(Image& image)
//[]---------------------------------------------------[]
//|  Run the ray tracer                                 |
//[]---------------------------------------------------[]
{
  clock_t t = clock();

  image.getSize(W, H);
  // init auxiliary VRC
  VRC_n = camera->getViewPlaneNormal();
  VRC_v = camera->getViewUp();
  VRC_u = VRC_v.cross(VRC_n);
  // init auxiliary mapping variables
  I_w = Math::inverse<REAL>(REAL(W));
  I_h = Math::inverse<REAL>(REAL(H));

  REAL height = camera->windowHeight();

  W >= H ? V_w = (V_h = height) * W * I_h : V_h = (V_w = height) * H * I_w;
  scan(image);
  printf("\nNumber of rays: %lu", numberOfRays);
  printf("\nNumber of hits: %lu", numberOfHits);
  printElapsedTime("\nDONE! ", clock() - t);
}

static Ray pixelRay;

inline vec3
VRC_point(REAL x, REAL y)
{
  return V_w * (x * I_w - 0.5f) * VRC_u + V_h * (y * I_h - 0.5f) * VRC_v;
}

void
RayTracer::setPixelRay(REAL x, REAL y)
//[]---------------------------------------------------[]
//|  Set pixel ray                                      |
//|  @param x coordinate of the pixel                   |
//|  @param y cordinates of the pixel                   |
//[]---------------------------------------------------[]
{
  vec3 p = VRC_point(x, y);

  switch (camera->getProjectionType())
  {
    case Camera::Perspective:
      pixelRay.direction = (p - camera->getDistance() * VRC_n).versor();
      break;

    case Camera::Parallel:
      pixelRay.origin = camera->getPosition() + p;
      break;
  }
}

void
RayTracer::scan(Image& image)
//[]---------------------------------------------------[]
//|  Basic scan with optional jitter                    |
//[]---------------------------------------------------[]
{
  // init pixel ray
  pixelRay = Ray(camera->getPosition(), -VRC_n);
  numberOfRays = numberOfHits = 0;

  Pixel* pixels = new Pixel[W];

  for (int j = 0; j < H; j++)
  {
    REAL y = j + 0.5f;

    printf("Scanning line %d of %d\r", j + 1, H);
    for (int i = 0; i < W; i++)
      pixels[i] = shoot(i + 0.5f, y, false, NULL);
    image.write(j, pixels);
  }
  delete []pixels;
}

Color
RayTracer::shoot(REAL x, REAL y, bool traceFlag, GLRenderer *disp)
//[]---------------------------------------------------[]
//|  Shoot a pixel ray                                  |
//|  @param x coordinate of the pixel                   |
//|  @param y cordinates of the pixel                   |
//|  @return RGB color of the pixel                     |
//[]---------------------------------------------------[]
{
  // set pixel ray
  setPixelRay(x, y);
  // trace pixel ray
  Color color = trace(pixelRay, 0, 1.0f, traceFlag, disp);

  // adjust RGB color
  if (color.r > 1.0f)
    color.r = 1.0f;
  if (color.g > 1.0f)
    color.g = 1.0f;
  if (color.b > 1.0f)
    color.b = 1.0f;
  // return pixel color
  return color;
}

Color
RayTracer::trace(const Ray& ray, uint level, REAL weight, bool traceFlag, GLRenderer *disp)
//[]---------------------------------------------------[]
//|  Trace a ray                                        |
//|  @param the ray                                     |
//|  @param recursion level                             |
//|  @param ray weight                                  |
//|  @return color of the ray                           |
//[]---------------------------------------------------[]
{
	//it->distance = ray.operator();
	/*act.current()->getModel()->getMaterial()->surface.specular != Color::black*/
	// TODO: INSERT YOUR CODE HERE - intersect com aggregate - passo 2
	/* Passo 1: Para cada pixel da cena, trace um raio primário em direção ao centro desse pixel. A cor do raio será a cor do pixel.
	Esse passo já foi executado antes de chegarmos no método trace. */
	Color c(Color::black);
	Intersection it;
	/* Passo 2: Se o raio não interceptar nenhum objeto da cena, então a cor dele será a cor de fundo. Caso contrário, seja Ip o ponto de 
	interseção entre o objeto e o raio */
	/* A primeira coisa a se fazer é identificar se o raio atinge algum ator. o aggregate que temos contém toda a cena e é para ele que
	será delegada a responsabilidade de verificar se há interseção ou não */
	if (this->aggregate->intersect(ray, it))// condição que garanta que há interseção da malha
	{
		if (traceFlag && disp != NULL)
		{
			disp->displayRays(ray.origin, ray(it.distance), Color::green);
			disp->drawBoundingBox(it.triangle->boundingBox());
		}
		const Model *obj = (it.object);
		numberOfHits++;
		numberOfRays++;
		//TriangleShape *p = (TriangleShape*)it.object;
		c += this->scene->ambientLight;
		/*cout << it.object->getMaterial()->surface.ambient.r << " " << it.object->getMaterial()->surface.ambient.g
		<< " " << it.object->getMaterial()->surface.ambient.b << endl;*/
		c *= obj->getMaterial()->surface.ambient;
		//cout << c.r << " " << c.g << " " << c.b << endl;
		if (level < this->getMaxRecursionLevel() && weight > this->getMinWeight())
		{
			/* Passo 3: Para toda fonte de luz da cena, trace raios secundários partindo de Ip em direção a essa fonte de luz. Se
			o raio não interceptar nenhum objeto então a cor dele é determinada por um modelo local de iluminação; caso contrário,
			sua cor será uma cor de sombra (preta). */
			for (LightIterator lit = this->scene->getLightIterator(); lit; lit++)
			{
				vec3 l; // Vetor da luz
				REAL Dl; // Distância
				/*puts("------------------");
				cout << ray(it.distance).x << " " << ray(it.distance).y << " " << ray(it.distance).z << endl;*/
				//puts("------------------");
				//cout << lit.current()->position.x << " " << lit.current()->position.y << " " << lit.current()->position.z << endl;
				lit.current()->lightVector(ray(it.distance), l, Dl);
				//cout << l.x << " " << l.y << " " << l.z << endl;
				//cout << Dl << endl;
				Ray secondary(ray(it.distance), -l.versor(), 0.3f, Dl);
				// Como saber quem está interceptando ? - aggregate resolve!
				// Malha de triângulo de algum objeto é interceptado pelo raio secundário
				if (this->aggregate->intersect(secondary, it))
				{
					c += Color::black;
				}
				else
				{
					//puts("55555555555555555555555555555");
					//cout << ray(it.distance).x << " " << ray(it.distance).y << " " << ray(it.distance).z << endl;
					//puts("555555555555555555555555555555");

					/* A cor aqui é dada por um modelo local de iluminação. Em um primeiro momento, antes de entrarmos no laço, já adicionamos
					a luz ambiente; agora, a cada laço somaremos apenas a cor de reflexão especular e a de reflexão difusa */
					/* A cor de reflexão difusa é dada por: I = Od * Il * cos theta */

					//REAL cosTheta = -it.object->normal(it).versor().dot(l.versor());
					//cout << it.p.x << " " << it.p.y << " " << it.p.z << endl;
					//cout << it.triangle->normal(it).x << " " << it.triangle->normal(it).y << " " << it.triangle->normal(it).z << endl;
					REAL cosTheta = -it.triangle->normal(it).versor().dot(l.versor());
					//cout << cosTheta << endl;
					//c += (it.object->getMaterial()->surface.diffuse * lit.current()->getScaledColor(it.distance) * cosTheta);
					/*cout << obj->getMaterial()->surface.diffuse.r << " " <<
					obj->getMaterial()->surface.diffuse.g << " " <<
					obj->getMaterial()->surface.diffuse.b << endl;*/
					/*cout << lit.current()->getScaledColor(Dl).r << " " << lit.current()->getScaledColor(Dl).g <<
					" " << lit.current()->getScaledColor(Dl).b << endl;*/
					/*cout << (obj->getMaterial()->surface.diffuse * lit.current()->getScaledColor(Dl) * cosTheta).r
					<< (obj->getMaterial()->surface.diffuse * lit.current()->getScaledColor(Dl) * cosTheta).g
					<< (obj->getMaterial()->surface.diffuse * lit.current()->getScaledColor(Dl) * cosTheta).b << endl;*/
					c += (obj->getMaterial()->surface.diffuse * lit.current()->getScaledColor(Dl) * cosTheta);

				}
			}
		}
	}
	else
	{
		c += this->scene->backgroundColor;
	}
	if (traceFlag && disp != NULL)
	{
		disp->displayRays(ray.origin, ray(it.distance), Color::blue);
	}
	return c;
}

void RayTracer::displayRay(REAL x, REAL y, bool traceFlag, GLRenderer *disp)
{
	pixelRay = Ray(camera->getPosition(), -VRC_n);
	y = this->H - y;
	this->shoot(x+0.5f, y+0.5f, traceFlag, disp);
}
