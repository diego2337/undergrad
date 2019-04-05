#include <GL/glew.h>
#include <GL/freeglut.h>
#include "GLRenderer.h"
#include "GLImage.h"
#include "MeshReader.h"
#include "MeshSweeper.h"
#include "Scene.h"
#include "Parser.h"
#include "RayTracer.h"

#define WIN_W 1024
#define WIN_H 768

using namespace Graphics;

Parser parse, vtpParse;
GLRenderer* renderer, *vtpRenderer;
RayTracer* rayTracer;
GLImage* frame;
uint timestamp;
bool traceFlag;
Scene* scene, *vtpScene;
Camera *c;
Light *light;
/* Tamanho da imagem */
int largura = 1024, altura = 768;

/* Handle da janela principal */
uint p, f, s, window;

// Mouse globals
int mouseX, mouseY;

// Keyboard globals
const int MAX_KEYS = 256;
bool keys[MAX_KEYS];

// Camera globals
const float CAMERA_RES = 0.01f;
const float ZOOM_SCALE = 1.01f;

// Animation globals
bool animateFlag;
const int UPDATE_RATE = 40;

inline void
printControls()
{
	printf("\n"
		"Camera controls:\n"
		"----------------\n"
		"(w) pan forward  (s) pan backward\n"
		"(q) pan up       (z) pan down\n"
		"(a) pan left     (d) pan right\n"
		"(+) zoom in      (-) zoom out\n"
		"GL render mode controls:\n"
		"------------------------\n"
		"(b) bounds       (n) normals       (x) axes\n"
		"(,) wireframe    (/) Smooth\n\n");
}

static bool drawAxes = false;
static bool drawBounds = false;
static bool drawNormals = false;
static bool drawRay = true;

void
processKeys()
{
	Camera* camera;
	if (mouseX <= largura / 2)
		camera = renderer->getCamera();
	else
		camera = vtpRenderer->getCamera();

	for (int i = 0; i < MAX_KEYS; i++)
	{
		if (!keys[i])
			continue;

		float len = camera->getDistance() * CAMERA_RES;

		switch (i)
		{
			// Camera controls
		case 'w':
			camera->move(0, 0, -len);
			break;
		case 's':
			camera->move(0, 0, +len);
			break;
		case 'q':
			camera->move(0, +len, 0);
			break;
		case 'z':
			camera->move(0, -len, 0);
			break;
		case 'a':
			camera->move(-len, 0, 0);
			break;
		case 'd':
			camera->move(+len, 0, 0);
			break;
		case '-':
			camera->zoom(1.0f / ZOOM_SCALE);
			keys[i] = false;
			break;
		case '+':
			camera->zoom(ZOOM_SCALE);
			keys[i] = false;
			break;
		case 'p':
			camera->changeProjectionType();
			break;
		case 'b':
			drawBounds ^= true;
			if (mouseX <= largura / 2)
			{
				renderer->flags.enable(GLRenderer::DrawSceneBounds, drawBounds);
				renderer->flags.enable(GLRenderer::DrawActorBounds, drawBounds);
			}
			else
			{
				vtpRenderer->flags.enable(GLRenderer::DrawSceneBounds, drawBounds);
				vtpRenderer->flags.enable(GLRenderer::DrawActorBounds, drawBounds);
			}
			break;
		case 'x':
			drawAxes ^= true;
			if (mouseX <= largura / 2)
				renderer->flags.enable(GLRenderer::DrawAxes, drawAxes);
			else
				vtpRenderer->flags.enable(GLRenderer::DrawAxes, drawAxes);
			break;
		case 'n':
			drawNormals ^= true;
			if (mouseX <= largura / 2)
				renderer->flags.enable(GLRenderer::DrawNormals, drawNormals);
			else
				vtpRenderer->flags.enable(GLRenderer::DrawNormals, drawNormals);
			break;
		case ',':
			if (mouseX <= largura / 2)
				renderer->renderMode = GLRenderer::Wireframe;
			else
				vtpRenderer->renderMode = GLRenderer::Wireframe;
			break;
		case '/':
			if (mouseX <= largura / 2)
				renderer->renderMode = GLRenderer::Smooth;
			else
				vtpRenderer->renderMode = GLRenderer::Smooth;
			break;
		}
	}
}

void
initGL(int *argc, char **argv)
{
	glutInit(argc, argv);
	glutInitDisplayMode(GLUT_RGB | GLUT_DEPTH | GLUT_DOUBLE);
	//glutInitContextProfile(GLUT_CORE_PROFILE);
	//glutInitContextVersion(3, 3);
	glutInitWindowSize(largura, altura);
	p = glutCreateWindow(parse.cena->getName().c_str());
	GLSL::init();
	glutReportErrors();
}

void
displayCallback()
{
	processKeys();
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	if (!traceFlag)
	{
			renderer->render();
			//vtpRenderer->displayCP(*renderer->getCamera(), largura, altura);
			//vtpRenderer->render();
	}
	else
	{
		
		if (frame == 0)
			frame = new GLImage(largura/2, altura);
		glViewport(0, 0, largura / 2, altura);
		Camera* camera = renderer->getCamera();
		uint ct = camera->updateView();
		if (timestamp != ct)
		{
			frame->lock(ImageBuffer::Write);
			rayTracer->renderImage(*frame);
			frame->unlock();
			timestamp = ct;
		}
		frame->draw();
		if (drawRay)
		{
			/*glViewport(largura / 2, altura, largura, altura);
			vtpRenderer->render();
			rayTracer->displayRay((REAL)mouseX, (REAL)mouseY, traceFlag, vtpRenderer);*/
		}
	}
	glViewport(largura / 2, altura, largura, altura);
	vtpRenderer->render();
	if (drawRay && mouseX <= 512)
	{
		rayTracer->displayRay((REAL)mouseX, (REAL)mouseY, traceFlag, vtpRenderer);
		//vtpRenderer->displayRays(vec3(0, 0, 10), vec3(0, 3, 0), Color::cyan);
	}
	vtpRenderer->displayCP(*renderer->getCamera(), largura, altura);
	glutSwapBuffers();
}

void
reshapeCallback(int w, int h)
{
	largura = roundupImageWidth(w);
	renderer->setImageOrigin(0, 0);
	renderer->setImageSize(largura / 2, altura = h);
	renderer->getCamera()->setAspectRatio(REAL(largura / 2) / REAL(altura));
	vtpRenderer->setImageOrigin(largura/2, 0);
	vtpRenderer->setImageSize(largura / 2, altura = h);
	vtpRenderer->getCamera()->setAspectRatio(REAL(largura / 2) / REAL(altura));
	if (frame != 0)
	{
		delete frame;
		frame = 0;
		timestamp = 0;
		traceFlag = false;
	}
	printf("Image size: %dx%d\n", w, h);
	/*renderer->setImageSize(w, h);
	renderer->getCamera()->setAspectRatio(REAL(w) / REAL(h));
	vtpRenderer->setImageSize(w / 2, h);
	vtpRenderer->getCamera()->setAspectRatio(REAL(w / 2) / REAL(h));*/
}

void
mouseCallback(int, int, int x, int y)
{
	mouseX = x;
	mouseY = y;
	/* Indica que o traçado de raios foi executado, portanto deve-se exibir os raios de acordo com o pixel da cena selecionado */
	if (traceFlag && mouseX <= 512)
	{
		//vtpRenderer->displayCP(*renderer->getCamera(), largura, altura);
		//rayTracer->displayRay(x, y, traceFlag);
		drawRay = true;
	}
}

void
motionCallback(int x, int y)
{
	Camera* camera;
	if (mouseX <= largura / 2)
	{
		drawRay = false;
		camera = renderer->getCamera();
	}
	else
		camera = vtpRenderer->getCamera();
	float da = camera->getViewAngle() * CAMERA_RES;
	float ay = (mouseX - x) * da;
	float ax = (mouseY - y) * da;

	camera->rotateYX(ay, ax);
	mouseX = x;
	mouseY = y;
	if (mouseX <= largura/2)
		traceFlag = false;
	glutPostRedisplay();
}

void
mouseWheelCallback(int, int dir, int, int y)
{
	if (y == 0)
		return;
	if (dir > 0)
	{
		if (mouseX <= largura / 2)
			renderer->getCamera()->zoom(ZOOM_SCALE);
		else
			vtpRenderer->getCamera()->zoom(ZOOM_SCALE);
	}
	else
	{
		if (mouseX <= largura / 2)
			renderer->getCamera()->zoom(1.0f / ZOOM_SCALE);
		else
			vtpRenderer->getCamera()->zoom(1.0f / ZOOM_SCALE);
	}
	traceFlag = false;
	glutPostRedisplay();
}

void
idleCallback()
{
	static GLint currentTime;
	GLint time = glutGet(GLUT_ELAPSED_TIME);

	if (abs(time - currentTime) >= UPDATE_RATE)
	{
		Camera* camera;
		if (mouseX <= largura / 2)
			camera = renderer->getCamera();
		else
			camera = vtpRenderer->getCamera();

		camera->azimuth(camera->getHeight() * CAMERA_RES);
		currentTime = time;
		traceFlag = false;
		glutPostRedisplay();
	}
}

void
keyboardCallback(unsigned char key, int /*x*/, int /*y*/)
{
	keys[key] = true;
	glutPostRedisplay();
}

void
keyboardUpCallback(unsigned char key, int /*x*/, int /*y*/)
{
	keys[key] = false;
	switch (key)
	{
	case 27:
		exit(EXIT_SUCCESS);
		break;
	case 't':
		traceFlag ^= true;
		glutPostRedisplay();
		break;
	case 'o':
		animateFlag ^= true;
		glutIdleFunc(animateFlag ? idleCallback : 0);
		glutPostRedisplay();
		break;
	}
}

/*void
createScene()
{
	TriangleMesh* s = MeshSweeper::makeSphere();

	scene = new Scene("test");
	scene->addActor(newActor(s, vec3(-3, -3, 0), vec3(1, 1, 1), Color::yellow));
	scene->addActor(newActor(s, vec3(+3, -3, 0), vec3(2, 1, 1), Color::green));
	scene->addActor(newActor(s, vec3(+3, +3, 0), vec3(1, 2, 1), Color::red));
	scene->addActor(newActor(s, vec3(-3, +3, 0), vec3(1, 1, 2), Color::blue));
	s = MeshReader().execute("f-16.obj");
	scene->addActor(newActor(s, vec3(2, -4, -10)));
}*/

int
main(int argc, char **argv)
{
	// CRIA SUBWINDOW, REGISTRA CALLBACK E RENDERIZA
	// init OpenGL
	parse.run(argv[1], &altura, &largura, &c);
	vtpParse.run(argv[1], &altura, &largura, &c);
	initGL(&argc, argv);
	glutDisplayFunc(displayCallback);
	glutReshapeFunc(reshapeCallback);
	glutMouseFunc(mouseCallback);
	glutMotionFunc(motionCallback);
	glutMouseWheelFunc(mouseWheelCallback);
	glutKeyboardFunc(keyboardCallback);
	glutKeyboardUpFunc(keyboardUpCallback);
	// print controls
	printControls();
	// create the scene
	scene = parse.cena;
	vtpScene = vtpParse.cena;
	// create the renderer
	//new Camera(c->getProjectionType(), c->getDirectionOfProjection(), c->getPosition(), c->getViewUp(), c->getViewAngle(), c->getAspectRatio())
	cout << "////////////////////////////" << c->getDirectionOfProjection().x << " " << c->getDirectionOfProjection().y << " " 
		<< c->getDirectionOfProjection().z << "////////////////////" << endl;
	Camera *c2 = new Camera(c->getProjectionType(), c->getPosition(), c->getDirectionOfProjection(),
		c->getViewUp(), c->getViewAngle(), c->getAspectRatio());
	renderer = new GLRenderer(*scene, c2, 0, 0);
	renderer->renderMode = GLRenderer::Smooth;
	rayTracer = new RayTracer(*scene, c2);
	vtpRenderer = new GLRenderer(*vtpScene, new Camera(c2->getProjectionType(), vec3(10, 6, 0), vec3(-3, -2, 0),
		c2->getViewUp(), c2->getViewAngle(), c2->getAspectRatio()), largura / 2, 0);
	vtpRenderer->renderMode = GLRenderer::Smooth;
	vtpRenderer->displayLights(*c2);
	glutMainLoop();
	return 0;
}
