#include "../src/lpe.h"

#define _MK_PTR(T, n) std::shared_ptr<T> n = std::make_shared<T>()


int main()
{
  lpe::Initialize();

  auto resourceManager = lpe::ServiceLocator::ResourceManager.Get()
                                                             .lock();

  assert(resourceManager);

  _MK_PTR(lpe::render::Texture, t);
  t->SetImage(resourceManager->Load("textures/lpe.jpg"));
  t->SetColor({0, 255, 0, 1});

  _MK_PTR(lpe::render::Material, m);
  m->SetAlbedo(t);

  _MK_PTR(lpe::render::RenderTarget, r);
  r->SetMaterial(m);
  r->SetMesh(resourceManager->Load("models/cube.ply"));
  r->SetVertexShader(resourceManager->Load("shaders/base.vert.spv"));
  r->SetFragmentShader(resourceManager->Load("shaders/base.frag.spv"));

  _MK_PTR(lpe::render::RenderObject, o);
  o->AddTarget(r);

  return 0;
}