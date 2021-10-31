#include "sandbox.h"

#include <iostream>
#include "poole/rendering/renderer.h"
#include "poole/rendering/renderer2D.h"
#include "poole/rendering/rendering_primitives.h"
#include "poole/input/input.h"

static constexpr bool TempRenderSeperately = true;

void TestMeshNoIndiciesSolidColor()
{
    using namespace Poole::Rendering;

    if constexpr (TempRenderSeperately)
    {
        StaticMeshNoIndiciesSolidColor4_2DTransform meshNoInd1;
        meshNoInd1.m_verts = std::vector<fvec3>{
            {-0.5f,  -0.5f,  0.0f}, { 0.5f,  -0.5f,  0.0f}, { 0.0f,   0.5f,  0.0f},
        };
        meshNoInd1.m_color = Colors::Green<fcolor4>;
        Renderer::Submit(std::move(meshNoInd1));


        StaticMeshNoIndiciesSolidColor4_2DTransform meshNoInd2;
        meshNoInd2.m_verts = std::vector<fvec3>{
            {-0.75f, -0.75f, 0.0f}, {-0.25f, -0.75f, 0.0f}, {-0.5f,  -0.5f,  0.0f},
        };
        meshNoInd2.m_color = Colors::Pink<fcolor4>;
        Renderer::Submit(std::move(meshNoInd2));


        StaticMeshNoIndiciesSolidColor4_2DTransform meshNoInd3;
        meshNoInd3.m_verts = std::vector<fvec3>{
            {0.75f, 0.75f, 0.0f}, {0.25f, 0.75f, 0.0f}, {0.5f,  0.5f,  0.0f},
        };
        meshNoInd3.m_color = Colors::Cyan<fcolor4>;
        Renderer::Submit(std::move(meshNoInd3));
    }
    else
    {
        StaticMeshNoIndiciesSolidColor4_2DTransform meshNoInd;
        meshNoInd.m_verts = std::vector<fvec3>{
            {-0.5f,  -0.5f,  0.0f}, { 0.5f,  -0.5f,  0.0f}, { 0.0f,  0.5f, 0.0f},
            {-0.75f, -0.75f, 0.0f}, {-0.25f, -0.75f, 0.0f}, {-0.5f, -0.5f, 0.0f},
            { 0.75f,  0.75f, 0.0f}, { 0.25f,  0.75f, 0.0f}, { 0.5f,  0.5f, 0.0f},
        };
        meshNoInd.m_color = Colors::Green<fcolor4>;
        Renderer::Submit(std::move(meshNoInd));
    }
}
void TestMeshSolidColor()
{
    using namespace Poole::Rendering;

    if constexpr (TempRenderSeperately)
    {
        StaticMeshSolidColor4_2DTransform mesh1;
        mesh1.m_verts = std::vector<fvec3>{
            {0.9f,   0.3f, 0.0f}, // top right
            {0.9f,  -0.3f, 0.0f}, // bottom right
            {0.6f,  -0.3f, 0.0f}, // bottom left
            {0.6f,   0.3f, 0.0f}, // top left
        };
        mesh1.m_indices = {
            0, 1, 3, /*first triangle*/ 1, 2, 3, /*second triangle*/
        };
        mesh1.m_color = Colors::Red<fcolor4>;
        Renderer::Submit(std::move(mesh1));


        StaticMeshSolidColor4_2DTransform mesh2;
        mesh2.m_verts = std::vector<fvec3>{
            { 0.9f,  0.9f, 0.0f}, // top right
            { 0.9f,  0.7f, 0.0f}, // bottom right
            { 0.7f,  0.7f, 0.0f}, // bottom left
            { 0.7f,  0.9f, 0.0f}, // top left
        };
        mesh2.m_indices = {
            0, 1, 3, /*first triangle*/ 1, 2, 3, /*second triangle*/
        };
        mesh2.m_color = Colors::Orange<fcolor4>;
        Renderer::Submit(std::move(mesh2));
    }
    else
    {
        StaticMeshSolidColor4_2DTransform mesh;
        mesh.m_verts = std::vector<fvec3>{
            {0.9f,   0.3f, 0.0f}, // top right
            {0.9f,  -0.3f, 0.0f}, // bottom right
            {0.6f,  -0.3f, 0.0f}, // bottom left
            {0.6f,   0.3f, 0.0f}, // top left
        
            { 0.9f,  0.9f, 0.0f}, // top right
            { 0.9f,  0.7f, 0.0f}, // bottom right
            { 0.7f,  0.7f, 0.0f}, // bottom left
            { 0.7f,  0.9f, 0.0f}, // top left
        };
        mesh.m_indices = {
              0,   1,   3, /*first triangle*/   1,   2,   3, /*second triangle*/
            4+0, 4+1, 4+3, /*third triangle*/ 4+1, 4+2, 4+3, /*fourth triangle*/
        };
        mesh.m_color = Colors::Red<fcolor4>;
        Renderer::Submit(std::move(mesh));
    }
}
void TestMeshVertexColor()
{
    using namespace Poole::Rendering;

    if constexpr (TempRenderSeperately)
    {
        StaticMeshVertexColor4_2DTransform meshWithColor1;
        meshWithColor1.m_verts = std::vector<Vertex3Color4>{
            {fvec3{ 0.2f,   0.2f, 0.0f}, /*top right*/      Colors::Yellow<fcolor4>},
            {fvec3{ 0.2f,  -0.2f, 0.0f}, /*bottom right*/   Colors::Green<fcolor4>},
            {fvec3{-0.2f,  -0.2f, 0.0f}, /*bottom left*/    Colors::White<fcolor4>},
            {fvec3{-0.2f,   0.2f, 0.0f}, /*top left*/       Colors::Purple<fcolor4>},
        };
        meshWithColor1.m_indices = {
            0, 1, 3, /*first triangle*/ 1, 2, 3, /*second triangle*/
        };
        meshWithColor1.m_position = { -0.7f, 0.2f };
        Renderer::Submit(std::move(meshWithColor1));


        StaticMeshVertexColor4_2DTransform meshWithColor2;
        meshWithColor2.m_verts = std::vector<Vertex3Color4>{
            {fvec3{-0.7f,  0.9f, 0.0f}, /*top right*/      Colors::Orange<fcolor4>},
            {fvec3{-0.7f,  0.7f, 0.0f}, /*bottom right*/   Colors::Cyan<fcolor4>},
            {fvec3{-0.9f,  0.7f, 0.0f}, /*bottom left*/    Colors::Grey<fcolor4>},
            {fvec3{-0.9f,  0.9f, 0.0f}, /*top left*/       Colors::Pink<fcolor4>},
        };
        meshWithColor2.m_indices = {
            0, 1, 3, /*first triangle*/ 1, 2, 3, /*second triangle*/
        };
        Renderer::Submit(std::move(meshWithColor2));
    }
    else
    {
        StaticMeshVertexColor4_2DTransform meshWithColor;
        meshWithColor.m_verts = std::vector<Vertex3Color4>{
            {fvec3{ 0.2f,   0.2f, 0.0f}, /*top right*/      Colors::Yellow<fcolor4>},
            {fvec3{ 0.2f,  -0.2f, 0.0f}, /*bottom right*/   Colors::Green<fcolor4>},
            {fvec3{-0.2f,  -0.2f, 0.0f}, /*bottom left*/    Colors::White<fcolor4>},
            {fvec3{-0.2f,   0.2f, 0.0f}, /*top left*/       Colors::Purple<fcolor4>},
        
            {fvec3{-0.7f,  0.9f, 0.0f}, /*top right*/      Colors::Orange<fcolor4>},
            {fvec3{-0.7f,  0.7f, 0.0f}, /*bottom right*/   Colors::Cyan<fcolor4>},
            {fvec3{-0.9f,  0.7f, 0.0f}, /*bottom left*/    Colors::Grey<fcolor4>}, 
            {fvec3{-0.9f,  0.9f, 0.0f}, /*top left*/       Colors::Pink<fcolor4>},
        };
        meshWithColor.m_indices = {
              0,   1,   3, /*first triangle*/   1,   2,   3, /*second triangle*/
            4+0, 4+1, 4+3, /*third triangle*/ 4+1, 4+2, 4+3, /*fourth triangle*/
        };
        Renderer::Submit(std::move(meshWithColor));
    }
}

void TempMoveTriangles()
{
    using namespace Poole::Rendering;

    StaticMeshNoIndiciesSolidColor4_2DTransform* Mesh =
        Renderer::GetMesh<StaticMeshNoIndiciesSolidColor4_2DTransform>(0);

    static float P = 0.f;
    P += 0.01f;

    //Mesh->m_position = { cosf(P / 5), sinf(P / 5) };
    //Mesh->m_rotation = P * 0.01f;
    //Mesh->m_scale = { (cosf(P / 25) + 2) / 3, (cosf(P / 25) + 2) / 3 };
    //Mesh->m_shear = { cosf(P), 0 };

    using namespace Poole;
    const auto cursor = Input::GetMousePositionFloat(true, Input::ECursorClamping::None, Input::ECursorNormalization::NegativeOneToOneAspect);
    std::cout << "Cursor Position at (" << cursor.x << " : " << cursor.y << ")\n";
    
    Mesh->m_position = { cursor.x, cursor.y };
}

void Sandbox::BeginApp()
{
    TestMeshNoIndiciesSolidColor();
    TestMeshSolidColor();
    TestMeshVertexColor();
}

void Sandbox::UpdateApp(float /*deltaTime*/)
{
   TempMoveTriangles();

   using namespace Poole::Rendering;
   //Draw the triangle !
   Renderer2D::DrawQuad({ 0, 0.f }, { 0.2f, 0.2f }, Colors::Red<fcolor4>);
   //Draw the triangle !
   Renderer2D::DrawQuad({ 0, 0.8f }, { 0.05f, 0.2f }, Colors::Blue<fcolor4>);
}

void Sandbox::EndApp()
{

}
